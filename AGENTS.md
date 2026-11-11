# IASYS Project Rules & Engineering Guardrails

## 1. Project Contract vs. Solution Contract Boundary
- **Project Contract (External & Immutable):**
  - Source: `IASYS Roadwork Challenge 2026.pdf`, `docs/INTERFACES.md`, `roadwork_interfaces`, simulator step (0.05 s), vehicle kinematics, and safety rules.
  - Invariant: Never modify `roadwork_interfaces` or external message contracts. Do not violate physical or evaluator constraints.
- **Solution Contract (Internal & Team-Owned):**
  - Source: `team_docs/PLAN_ACT_CONTRACT.md`, `team_docs/README.md`, `roadwork_solution_msgs`.
  - Invariant: All inter-node communication (Sense, Plan, Act) must use team-owned solution messages, documented QoS, and explicit expiry policies.

## 2. Architectural & Interface Evaluation Rubric
When designing or evaluating internal interfaces, state machines, or contracts, evaluate against the 6 criteria defined in `team_docs/README.md`:
1. **Command/Report Separation:** Separate command topics from telemetry/status reports.
2. **Deterministic Data Types:** Enforce upper bounds on all arrays and strings (`PlanPoint[<=250]`, `string<=32`) to prevent heap allocation jitter.
3. **Safety Lifecycle:** Define explicit dedicated fault/error states (`uint8 FAULT = 255`) and numerical reason enumerations.
4. **Semantic Standards:** Strictly follow REP-103 (SI units, right-hand rule) and REP-105 (`map` and `base_link` frames).
5. **Modularity & Dependencies:** Interface packages must contain only IDL definitions (no node code or circular dependencies).
6. **Build Configuration:** Code must compile cleanly under `-Wall -Wextra -Wpedantic` with zero warnings.

## 3. Kinematic Discretization & Boundary Rigor
- Do not blindly assume fixed waypoint spacing (e.g. 0.5 m) is sufficient for all conditions.
- Always verify velocity quantization at low speeds ($v < 1.4\text{ m/s}$) and ensure exact boundary waypoints are inserted for critical stopping poses (e.g., stopping front before $x = 25.0\text{ m}$).

## 4. ACT Node Test Data & Plan Fixtures (Location & Generation)
- **Data Location:**
  - YAML test plans: `src/roadwork_student/test_data/plan/yaml/*.yaml`
  - JSON test plans: `src/roadwork_student/test_data/plan/json/*.json`
  - Full documentation & expected state/reason table: `src/roadwork_student/test_data/plan/README.md`
- **What is Included:**
  - Strictly PLAN node outputs (`roadwork_solution_msgs/msg/Plan` on `/solution/plan`).
  - Contains 14 distinct contract scenarios: Nominal tracking, Reduced speed (3.0 m/s), Stop-line hold ($x=23.8\text{ m}$), Stop-line cleared, MODE_STOP, MODE_FAULT, Expired plan, Future stamp, Stale scene, Empty path, NaN coordinates/speed, New sequence recovery, and Overspeed clamping.
- **How to (Re)generate Data:**
  - Run `python3 scripts/generate_plan_test_data.py`.
  - The generator strictly enforces:
    - Upper bound $\le 250$ points (generates exactly 194 points).
    - Exact stopping boundary waypoint at $x=23.8\text{ m}$ (front $x+0.9=24.7\text{ m} < 25.0\text{ m}$).
    - Exact goal waypoint at $(80.2, -1.75)$ with $v=0.0\text{ m/s}$.
    - Quintic polynomial lateral spline ensuring opposing lane occupancy only within $x \in [26.0, 63.0]\text{ m}$.
    - Kinematic limits: $a \le 1.5\text{ m/s}^2$, $a_{\text{brake}} \le 2.0\text{ m/s}^2$, $v_{\text{cruise}} = 3.8\text{ m/s}$.
- **How to Stream / Publish Data to ACT:**
  - Using helper script (with QoS: reliable, volatile, depth 1 at 10 Hz):
    ```bash
    # Stream nominal plan with live sim stamps:
    python3 scripts/publish_test_plan.py --file src/roadwork_student/test_data/plan/yaml/01_nominal_full_course.yaml --live-stamps
    # Publish single message once (e.g. for edge case testing):
    python3 scripts/publish_test_plan.py --file src/roadwork_student/test_data/plan/yaml/07_expired_valid_until.yaml --once
    ```
  - Using ROS 2 CLI:
    ```bash
    ros2 topic pub --stdin /solution/plan roadwork_solution_msgs/msg/Plan \
      --qos-reliability reliable --qos-durability volatile --qos-depth 1 \
      < src/roadwork_student/test_data/plan/yaml/01_nominal_full_course.yaml
    ```

## 5. No Over-Engineering — Scope Discipline

Every interface, message field, algorithm, and node feature must be **traceable to a specific
requirement in the Project Contract** (`IASYS Roadwork Challenge 2026.pdf`, `docs/INTERFACES.md`,
`docs/SCENARIOS.md`) or to an explicitly named delivery milestone (D1 or D2).

Before adding any element ask:
1. **Which scenario (S1–S5) or delivery (D1/D2) requires this?**
   If the answer is "none" or "it might be useful later", do not add it.
2. **Can it be computed trivially from fields already in the message?**
   If yes, drop it; leave the arithmetic to the subscriber.
3. **Does it require the implementer to invent a metric or algorithm not described in the PDF?**
   If yes, the contract is under-specified. Define the computation rule explicitly or drop the field.
4. **Is the complexity appropriate for the delivery milestone?**
   D1 covers S1–S2 only. Do not design D2 features into D1 interfaces.

### Specific guardrails derived from the PDF

- **Camera:** No confidence score is provided by the simulator. Any `confidence` field in an
  internal message must name its exact computation rule (e.g., "fraction of pixels matching the
  winning colour class"). A floating-point score with an arbitrary threshold (e.g., "> 0.8") that
  is not grounded in the PDF's sensor model is over-engineering.
- **Radar:** Ego-velocity correction must be assigned to exactly one node and stated explicitly.
  Leaving it as an "open question" across a node boundary is a contract defect, not a design choice.
- **Beacon:** `valid_for = 1.2 s` is a fixed project-contract constant. Never publish a derived
  `valid_until` timestamp when the subscriber can compute `stamp + 1.2 s` in one line.
- **Sensor status:** A dedicated status/health message for a source node is only justified when
  that node has an upstream input that can stall it (like Act waiting on Plan). Sense is a
  terminal source node; collapse health reporting into a `string<=32` state field on the primary
  message until D2 diagnostics prove otherwise.
- **Decision logic belongs to its node.** Entry-permission conditions, yield logic, and recovery
  policies belong in the node's own contract document, not in the upstream interface contract.
  An interface contract owns *wire format and validity semantics*, not the downstream node's
  decision algorithm.
