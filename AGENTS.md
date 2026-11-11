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
