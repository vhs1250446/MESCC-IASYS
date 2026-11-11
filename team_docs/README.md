# Team Documentation & Architectural Evaluation Rubric

This directory stores internal architectural designs, inter-node interface contracts, and evaluation rubrics for the IASYS Roadwork Challenge 2026.

---

## 1. Project Contract vs. Solution Contract

All agents and contributors must strictly maintain the distinction between the two contract layers:

| Layer | Authority & Location | Modifiable? | Key Responsibilities & Invariants |
| :--- | :--- | :---: | :--- |
| **Project Contract** | Course Brief (`IASYS Roadwork Challenge 2026.pdf`), `docs/`, `roadwork_interfaces` | ❌ **Immutable** | • Kinematic limits: max speed $4.0\text{ m/s}$ ($4.05\text{ m/s}$ violation), $a \le 1.5\text{ m/s}^2$, brake $\le 3.0\text{ m/s}^2$.<br>• Steering limits: $\pm 0.45\text{ rad}$, slew rate $\le 0.6\text{ rad/s}$.<br>• Vehicle model: wheelbase $2.4\text{ m}$, collision radius $0.90\text{ m}$, front at $x+0.9\text{ m}$.<br>• Simulation clock: $20\text{ Hz}$ fixed step ($0.05\text{ s}$) from `/clock`.<br>• Safety rules: Stop line at $x=25.0\text{ m}$; opposing lane ($y+0.9 > 0$) strictly forbidden before $x+0.9 < 25\text{ m}$ or after $x-0.9 > x_{\text{exit}}$.<br>• External topics: `/vehicle/command`, `/lidar/scan`, `/radar/detections`, `/camera/image_raw`, `/infra/roadwork/beacon`. |
| **Solution Contract** | `team_docs/`, `roadwork_solution_msgs/`, node implementations | ✅ **Owned by Team** | • Node decomposition: Sense $\rightarrow$ Plan $\rightarrow$ Act.<br>• Internal topics: `/solution/scene`, `/solution/plan`, `/solution/act_status`.<br>• Custom message definitions, safety timeouts, and recovery logic.<br>• Trajectory generation, waypoint spacing, and tracking controllers. |

---

## 2. Solution Evaluation Rubric

Any proposed architectural design, internal interface definition, or node implementation must be evaluated against the following six criteria before adoption:

| Category | Evaluation Item | Pass (Yes) | Fail (No) |
| :--- | :--- | :--- | :--- |
| **Architectural Separation** | **Command/Report Separation** | Command and feedback paths are split into distinct message pairs (e.g., `Plan` for commands/targets, `ActStatus` for feedback). | Commands and states are mixed into one message, risking race conditions. |
| **Deterministic Data Types** | **Bounded Arrays & Strings** | All variable arrays and strings use fixed upper bounds (e.g., `string<=32` or `PlanPoint[<=250]`) to ensure real-time heap safety and zero reallocation jitter. | Uses unbounded `string` or `float32[]` / `PlanPoint[]`, risking memory allocation jitter. |
| **Safety Lifecycle** | **Explicit Fault States** | Every status enumeration includes a dedicated error/fault value (e.g., `uint8 MODE_FAULT = 255`, `uint8 STATE_FAULT = 255`, `uint8 REASON_FAULT = 255`). | Missing explicit error states; assumes 0 or implicit health values. |
| **Semantic Standards** | **REP-103 / REP-105 Alignment** | All metrics strictly use SI units (metres, radians, seconds) and follow standard coordinate frames (`map` for world, `base_link` for rear axle, $+x$ along road, $+y$ left). | Uses non-standard units (e.g., degrees, km/h) or ambiguous coordinate baselines. |
| **Modularity & Dependencies** | **Pure Interface Package** | The interface package (`roadwork_solution_msgs`) contains zero node source code (`.cpp`, `.py`) and isolates only IDL file types (`.msg`, `.srv`, `.action`). | Mixes interface definitions with node logic, causing cyclic build loops. |
| **Build Configuration** | **Clean Compilation** | The package builds with zero warnings using `colcon build --packages-select <pkg_name>` under `-Wall -Wextra -Wpedantic`. | Compilation fails or triggers downstream compiler warnings. |

---

## 3. Discretization & Kinematics Guidelines

When designing and generating trajectory waypoints:
1. **Nominal Spacing:** Waypoints should have nominal spacing $\Delta s \le 0.5\text{ m}$. Over the $75.2\text{ m}$ course, this requires $\approx 150$ points.
2. **Dense Stopping Zones:** In critical deceleration regions (approaching the stop line at $x=25\text{ m}$ and goal at $x=80.2\text{ m}$), generate denser points ($\Delta s \approx 0.1$–$0.2\text{ m}$) to avoid kinematic quantization at creeping speeds ($v < 1.4\text{ m/s}$).
3. **Exact Boundary Waypoints:** Always insert the exact target stopping pose into the path array (e.g., $x_{\text{rear}} = 23.8\text{ m}$ so vehicle front stays strictly below $25.0\text{ m}$). Never rely on an unaligned periodic grid for safety-critical boundaries.
4. **Array Upper Bound:** Set `PlanPoint[<=250] path` in `Plan.msg` to accommodate nominal and dense points without heap reallocation.
5. **Continuous Lookahead in Act:** Act should interpolate the lookahead point along waypoint chord segments rather than snapping to discrete vertices, preventing steering angle chattering.

---

## 4. Document Index

- [PLAN_ACT_CONTRACT.md](PLAN_ACT_CONTRACT.md): Contract between Plan and Act (`/solution/plan`, `/solution/act_status`).
- *(Future)* `SENSE_PLAN_CONTRACT.md`: Contract between Sense and Plan (`/solution/scene`).
