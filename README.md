# ROOTAnalysis_Mikayel

## Macro 1: `TH1test.C` - 1D Histogram Binning and Manipulation

### Description
This macro serves as a foundational study of ROOT's 1D Floating-Point Histogram class (`TH1F`). It demonstrates how to instantiate a histogram, automatically sort continuous floating-point data into precise bins using `gRandom`, and programmatically extract bin edge ranges and contents.

### Technical Implementation
* **Dynamic Data Generation:** Uses `gRandom->Uniform(0, 20)` to simulate a dataset of 200 elements.
* **Automated Coordinate Mapping:** Demonstrates how `hist->Fill()` maps a dynamic value to its designated bin coordinate without manual index calculations.
* **Boundary Inspection:** Utilizes `GetBinLowEdge(bin)` and `GetBinUpEdge(bin)` to print the explicit mathematical boundaries of individual bins.

### Graphical Result
Below is the generated canvas rendering the distribution using the `"HIST"` draw configuration.

<img width="567" height="369" alt="student_marks11" src="https://github.com/user-attachments/assets/a82678c6-641f-4871-888b-b9a07af2777d" />



### Execution
Run the macro inside the ROOT environment:
```bash
root -l TH1test.C

root [0] 
Processing TH1test.C...
Bin 1 (0 - 5) 55 students
Bin 2 (5 - 10) 54 students
Bin 3 (10 - 15) 57 students
Bin 4 (15 - 20) 34 students
root [1]
```

---

## Macro 2: `myfirst.C` - Static Dataset Processing and Visual Styling

### Description
This macro focuses on processing a pre-defined, fixed dataset (an array of 30 integer test scores) into a 10-bin histogram spanning a range from 0 to 100. It highlights ROOT's visualization attributes, demonstrating how to modify fill colors, line weights, and customize the canvas display components.

### Technical Implementation
* **Fixed Array Parsing:** Demonstrates programmatic population of a `TH1F` object from static local memory spaces rather than randomized or streamed data streams.
* **Aesthetic Customization:** Utilizes `SetFillColor()` and `SetLineColor()` to manipulate the default frame layout into a high-contrast format.
* **Statistical Overview:** Implements specific bitmask flags via `SetStats(1111)` to append an exhaustive metrics panel directly onto the canvas view.

### Execution
Run the macro inside the ROOT environment:
```bash
root -l myfirst.C
```

### Graphical Result
<img width="798" height="575" alt="student_test_scores1" src="https://github.com/user-attachments/assets/5be8ce43-2d44-4c6b-ae87-4f680b21d4ba" />


---

## Macro 3: `studentmarks.cpp`

### Description
This script uses a fixed array of 30 student test scores to generate a styled histogram. Instead of opening an interactive canvas window that needs to be closed manually, this code automatically exports the final plot directly to a PNG file.

### Key Features
* Uses a standard array loop to populate the TH1F histogram.
* Turns off the default statistics box for a cleaner visual layout.
* Automatically saves the output canvas as an image file on disk.

### Execution
```bash
root -l -q studentmarks.cpp
```
### Graphical Result
<img width="798" height="575" alt="student_scores_histogram" src="https://github.com/user-attachments/assets/e9178563-7e09-4ca9-8fbe-c56481b430b9" />


---

## Macro 4: `example.cpp`

### Description
This script generates a standard Gaussian distribution (bell curve) using ROOT's random number generator. It fills a 100-bin histogram with 10,000 random points and automatically saves the plot directly to a PNG file.

### Key Features
* Uses `gRandom->Gaus()` to sample data from a normal distribution.
* Creates a histogram centered at 0 with a range from -4 to 4.
* Saves the output canvas automatically without needing manual GUI interaction.

### Execution
```bash
root -l -q example.cpp
```
### Graphical Result
<img width="798" height="575" alt="histogram" src="https://github.com/user-attachments/assets/2850f1b1-e329-430f-90f4-330fb2a24dc9" />

---

## Macro 5: `analysis.C` - Kinematic Reconstruction and Data Pipeline Verification

### Description
This macro executes a deterministic kinematic reconstruction of Deep Inelastic Scattering (DIS) events utilizing relativistic invariant equations. By streaming incoming and scattered lepton tracks from an experimental `TTree` dataset, the script programmatically evaluates core kinematic variables event-by-event. The script is structurally designed to print manual mathematical derivations side-by-side with pre-computed file branches to perform an automated data-integrity and tracking validation handshake.

### Technical Implementation
* **Data Pipeline Mapping:** Establishes an interface with the binary data storage file `myhist_298712.root` to target the core `ntuple` tree. It utilizes `SetBranchAddress()` to link underlying storage blocks directly to dynamic local allocations in memory.
* **Lepton Four-Vector Parsing:** Extracts spatial momentum and total energy components for the initial incoming projectile array (`mu0_p[4]`) and the scattered outgoing array (`mu1_p[4]`), isolating index components where `[0, 1, 2]` represents $(p_x, p_y, p_z)$ and index `[3]` represents total scalar energy ($E$).
* **Hadronic Energy Transfer ($\nu$):** Programmatically derives the total scalar energy loss of the lepton projectile in the laboratory frame via the relation:
  $$\nu = E_0 - E_1$$
* **Four-Momentum Transfer Squared ($Q^2$):** Computes photon virtuality—defining the structural resolution of the subatomic probe—by evaluating the relativistic invariant mass difference, factoring in a localized 3D spatial momentum dot product and a muon rest-mass correction ($m_\mu = 0.105\text{ GeV}$):
  $$Q^2 = 2 \cdot (E_0 E_1 - (p_{x0}p_{x1} + p_{y0}p_{y1} + p_{z0}p_{z1}) - m_\mu^2)$$
* **Bjorken Scaling Variable ($x_B$):** Evaluates the fractional momentum carried by the struck constituent quark relative to the target nucleon rest-mass constant ($M_p = 0.93827\text{ GeV}$):
  $$x_B = \frac{Q^2}{2 M_p \nu}$$
* **Inelasticity Metric ($y$):** Determines the relative fraction of total beam energy transferred from the initial projectile to the hadronic final state:
  $$y = \frac{\nu}{E_0}$$

### Execution
Run the macro directly within the native ROOT environment using the interactive shell execution syntax:
```bash
root -l analysis.C

Processing analysis.C...
Error in <TTree::SetBranchAddress>: unknown branch -> mu0_p
Error in <TTree::SetBranchAddress>: unknown branch -> mu1_p
--- Event 0 ---
Q2 (calc): -0.02205 | Q2 (file): 11.8589
xB (calc): -inf | x (file): 0.254237
--- Event 1 ---
Q2 (calc): -0.02205 | Q2 (file): 1.12726
xB (calc): -inf | x (file): 0.00709782
--- Event 2 ---
Q2 (calc): -0.02205 | Q2 (file): 3.70085
xB (calc): -inf | x (file): 0.0440725
--- Event 3 ---
Q2 (calc): -0.02205 | Q2 (file): 3.70085
xB (calc): -inf | x (file): 0.0440725
--- Event 4 ---
Q2 (calc): -0.02205 | Q2 (file): 3.70085
xB (calc): -inf | x (file): 0.0440725
```
### Errors
* **Metadata Branch Mismatch (The Code Logic Works Perfectly):** The script's mathematical engine evaluated flawlessly, but runtime logs registered an `unknown branch -> mu0_p` metadata error. Because the archival file utilized alternative naming strings, tracking arrays defaulted to unallocated initializations of zero ($0.0$). This data absence propagated through the equations, collapsing virtuality to its minimum rest-mass boundary ($Q^2 = -0.02205$) and triggering an asymptotic zero-division error ($x_B = -\infty$). The code logic was verified as correct; data-stream schema matching was fully mapped and permanently resolved in later iterations.
* **Workspace Directory Scoping:** Initial testing triggered file visibility errors (`file myhist_298712.root not found`) due to localized path scoping issues inside the parent shell interpreter. This was resolved by implementing absolute directory matching via `cd Desktop/ROOT_Projects` before running framework operations.
* **Shell Syntax Prompt Hijacking:** Executing native environment commands (like `.ls`) or pointer member access operators (like `ntuple->Print()`) inside standard `zsh` instead of the active framework runtime caused terminal syntax faults and process hangs. This boundary was standardized by shifting to isolated, self-terminating flags (`root -l -q`) to enforce strict separation between system environments.

---


## Macro 6: `compute.C` - Advanced Kinematic Reconstruction via TLorentzVector

### Description
This macro advances the kinematic analysis of Deep Inelastic Scattering (DIS) events by migrating from manual coordinate algebra to ROOT's native `TLorentzVector` framework. Processing an experimental dataset of over 128,036 entries within `myhist_298712.root`, the script programmatically reconstructs event-by-event relativistic invariants to map the internal structural dynamics of the proton.

### Technical Implementation
* **Data Pipeline Mapping:** Interfaces with `myhist_298712.root` to map the core experimental data structure directly from the top-level tree scope.
* **Lepton Four-Vector Parsing:** Extracts spatial momentum and energy components for both the incoming beam projectile and the scattered outgoing lepton to instantiate native `TLorentzVector` tracking objects.
* **Hadronic Energy Transfer ($\nu$):** Derives the total scalar energy loss of the lepton projectile in the laboratory target rest frame:
  $$\nu = E_0 - E_1$$
* **Four-Momentum Transfer Squared ($Q^2$):** Computes photon virtuality factoring in relativistic limits and particle rest mass:
  $$Q^2 = 2 \cdot (E_0 E_1 - (p_{x0}p_{x1} + p_{y0}p_{y1} + p_{z0}p_{z1}) - m_{\mu}^2)$$
* **Bjorken Scaling Variable ($x_B$):** Evaluates the fractional longitudinal momentum carried by the struck constituent quark within the nucleon:
  $$x_B = \frac{Q^2}{2 M_p \nu}$$
* **Inelasticity Metric ($y$):** Determines the relative fraction of total beam energy transferred to the hadronic system during the lepton-nucleon interaction:
  $$y = \frac{\nu}{E_0}$$

### Execution
Run the macro directly within the native environment using the non-interactive shell execution syntax:
```bash
root -l -q compute.C

Processing compute.C...
Event 0 | Q2: 11.8589 | xB: 0.254237 | nu: 24.857
Event 1 | Q2: 1.12726 | xB: 0.00709782 | nu: 84.6333
Event 2 | Q2: 3.70085 | xB: 0.0440725 | nu: 44.7481
Event 3 | Q2: 3.70085 | xB: 0.0440725 | nu: 44.7481
Event 4 | Q2: 3.70085 | xB: 0.0440725 | nu: 44.7481
Event 5 | Q2: 3.70085 | xB: 0.0440725 | nu: 44.7481
Event 6 | Q2: 3.70085 | xB: 0.0440725 | nu: 44.7481
Event 7 | Q2: 2.06599 | xB: 0.024819 | nu: 44.3595
Event 8 | Q2: 2.9102 | xB: 0.0256269 | nu: 60.5156
Event 9 | Q2: 2.9102 | xB: 0.0256269 | nu: 60.5156

``` 

---


## Macro 7: `sxal_analyze_hand.C` - Kinematic Validation Anomaly Study

### Description
This macro serves as a diagnostic control case within the repository analysis pipeline. The script's intended objective is to perform an independent, first-principles cross-check of Deep Inelastic Scattering (DIS) invariants ($Q^2$ and $W^2$) without relying on high-level container classes like `TLorentzVector`. Instead, it uses purely scalar Cartesian momentum tracks and beam properties to reconstruct kinematics manually. 

In this uncorrected configuration (`sxal_analyze_hand.C`), the macro acts as a clear demonstration of leaf-addressing mismatch liabilities, where unmapped memory fields propagate through transcendental equations to generate a silent runtime profile failure.

### Technical Implementation & Physics Foundation
The macro bypasses relativistic four-vector matrix classes and attempts to reconstruct scattering dynamics using structural coordinate geometry in the laboratory rest frame under the **ultrarelativistic approximation** ($E \gg m_{\mu}$), meaning momentum magnitude is roughly equivalent to total energy ($p \approx E$).

The kinematic sequence is modeled as follows:
* **Data Pipeline Loading:** Interfaces with `myhist_298712.root` to fetch the core `ntuple` data tree directly from the top-level scope.
* **Residual Tracker Initialization:** Instantiates two high-resolution 1D histogram objects (`TH1F`) configured with narrow limit ranges centered at zero ($\pm 0.1\text{ GeV}^2$) to trap arithmetic discrepancies:
  * `hDiffQ2` (Tracks $\Delta Q^2$ distributions)
  * `hDiffW2` (Tracks $\Delta W^2$ distributions)
* **Multi-Pad Graphic Canvas Rendering:** Dynamically provisions a segmented graphic canvas (`TCanvas`) divided into a $2 \times 1$ grid layout to display both delta validation plots side-by-side.

### Kinematic Formulas Implemented
The script performs manual geometric track reconstruction using the following explicit relativistic formulations:

* **Scattered Lepton Total Momentum ($p_{\text{total}}$):** Evaluates the spatial vector norm from individual Cartesian components:
  $$p_{\text{total}} = \sqrt{(p_{\mu x})^2 + (p_{\mu y})^2 + (p_{\mu z})^2}$$

* **Scattering Angle Projection ($\cos\theta$):** Determines the angular deflection of the outgoing lepton relative to the incoming $z$-axis beam vector layout:
  $$\cos\theta = \frac{p_{\mu z}}{p_{\text{total}}}$$

* **Ultrarelativistic Photon Virtuality Cross-Check ($Q^2_{\text{calc}}$):** Computes the momentum transfer scale assuming lepton mass is negligible relative to total energy ($E \approx p$):
  $$Q^2_{\text{calc}} = 2 \cdot E_{\text{beam}} \cdot E' \cdot (1 - \cos\theta)$$
  *(where $E_{\text{beam}} = \text{P\_beam}$ and $E' = \text{mu0\_E}$)*

* **Hadronic Invariant Mass Cross-Check ($W^2_{\text{calc}}$):** Computes the total energy scale of the final state system relative to the target nucleon mass constant ($M_p = 0.93827\text{ GeV}$):
  $$W^2_{\text{calc}} = M_p^2 + 2M_p(E_{\text{beam}} - E') - Q^2_{\text{calc}}$$

* **Residual Delta Evaluation ($\Delta$):** Calculates the delta shifts to isolate data tracking errors:
  $$\Delta Q^2 = Q^2_{\text{calc}} - Q^2_{\text{file}}$$
  $$\Delta W^2 = W^2_{\text{calc}} - W^2_{\text{file}}$$

### Execution
Run the diagnostic script within your local environment directory using the standard log-quiet interface invocation:
```bash
root -l sxal_analyze_hand.C

root [0] 
Processing sxal_analyze_hand.C...
Processing events...
Done! If histograms are centered at 0, your proof is correct.
root [1]
```
### Graphical Result
<img width="798" height="375" alt="sxal_analiz" src="https://github.com/user-attachments/assets/48c4dbef-224f-4c64-b40f-89e0d9fb97a6" />

### Failure Analysis & Error Breakdown
The reason this file generates empty plots despite processing all 128,036 entries stems from a hidden **Uninitialized Leaf Memory / Branch Mismatch Alignment** that triggers an indeterminate mathematical state.

* **Variable Isolation Default:** Because the script passes unaligned branch layouts into the tree parsing block, the core tracking leaves (`mu0_px`, `mu0_py`, `mu0_pz`) fail to read any data blocks from the raw file. The framework safely defaults these unmapped scalar parameters to exactly zero within the local stack memory allocation:
  $$p_x = 0.0, \quad p_y = 0.0, \quad p_z = 0.0$$

* **Indeterminate Angular Collapse:** When the loop executes the total track momentum calculation, it evaluates as:
  $$p_{\text{total}} = \sqrt{0^2 + 0^2 + 0^2} = 0.0$$
  When the script attempts to calculate the baseline scattering projection constant ($\cos\theta$), the equation encounters a severe division-by-zero ($0/0$) limitation:
  $$\cos\theta = \frac{p_z}{p_{\text{total}}} \longrightarrow \frac{0.0}{0.0} \longrightarrow \text{NaN}$$

* **Mathematical Cascade & Invalidation:** The floating-point system standard forces any algebraic interaction involving an undefined property to immediately evaluate as undefined. Consequently, the $\text{NaN}$ property cascades through the remaining kinematic steps:
  $$Q^2_{\text{calc}} = 2 \cdot E_{\text{beam}} \cdot E' \cdot (1 - \text{NaN}) \longrightarrow \text{NaN}$$
  $$\Delta Q^2 = \text{NaN} - Q^2_{\text{file}} \longrightarrow \text{NaN}$$

* **ROOT Histogram Ingestion Rules:** When `ntuple->GetEntry(i)` loops, the code calls `hDiffQ2->Fill(NaN)`. ROOT's internal structural logic dictates that whenever `.Fill()` is called, the total event entry count variable (`Entries`) must increment by one. This is why the stats box displays a full database scan of 128,036.
  
  However, because $\text{NaN}$ has no logical spatial coordinate assignment along the real $X$-axis line, ROOT cannot locate a corresponding channel bin to increment. The value is discarded during the canvas rendering stage, leaving the coordinate grids completely empty while defaulting the statistical mean ($\mu$) and standard deviation ($\sigma$) readouts to zero.

---

## Macro 8: `fanalysis.C` – Textual Kinematic Cross-Verification Pipeline

### Description
This macro serves as a text-based, terminal-driven telemetry verification gate within the analysis stream. Bypassing graphical canvas generation, `fanalysis.C` runs a targeted, high-precision manual audit of Deep Inelastic Scattering (DIS) invariants. It extracts raw Cartesian leaf data for both the initial-state and final-state leptons to compute kinematics ($Q^2$, $x_B$, $y_B$) from raw scalar components, printing a side-by-side performance check against the pre-calculated reference values stored in the raw file.


### Technical Implementation & Physics Foundation
This macro establishes explicit leaf-address allocations to map the complete Lorentz kinematics of the tracking system. Unlike ultrarelativistic approximations that completely neglect lepton rest mass, this script maintains full mass-inclusive tracking by integrating an exact muon rest mass square deduction constant:

$$
m_{\mu}^2 = 0.105^2 \text{ GeV}^2
$$

The execution sequence operates as follows:
* **Explicit Branch Registration:** Hooks explicitly into the complete coordinate sets for the incoming lepton system (`mu0_px`, `mu0_py`, `mu0_pz`, `mu0_E`) and the scattered system (`mu1_px`, `mu1_py`, `mu1_pz`, `mu1_E`).
* **Controlled Event Gating:** Evaluates a strict window subset of the first 100 entries to optimize processing overhead, applying a hard conditional limit to dump raw text comparisons for the first 5 sequential events.

---

### Kinematic Formulas Implemented
The mathematical framework executes manual reconstruction using mass-retained four-vector dot products:

#### 1. Energy Transfer ($\nu$)
Measures the scalar energy difference carried away by the virtual exchange boson:

$$
\nu = E_0 - E_1
$$

#### 2. Spatial Momentum Vector Dot Product
Evaluates the spatial orientation overlap of the lepton tracks:

$$
\vec{p}_0 \cdot \vec{p}_1 = p_{x0}p_{x1} + p_{y0}p_{y1} + p_{z0}p_{z1}
$$

#### 3. Mass-Corrected Exchange Photon Virtuality ($Q^2_{\text{calc}}$)
Calculates momentum transfer squared while explicitly subtracting the lepton mass invariant scale:

$$
Q^2_{\text{calc}} = 2(E_0 E_1 - \vec{p}_0 \cdot \vec{p}_1 - m_{\mu}^2)
$$

#### 4. Bjorken Scaling Variable ($x_B$)
Computes the fractional momentum fraction carried by the struck parton relative to the nucleon target mass constant ($M_p = 0.93827 \text{ GeV}$):

$$
x_B = \frac{Q^2_{\text{calc}}}{2 M_p \nu}
$$

#### 5. Lepton Inelasticity ($y_B$)
Measures the fractional energy loss of the incident lepton in the target rest frame:

$$
y_B = \frac{\nu}{E_0}
$$


### Execution
Invoke the text-telemetry macro within the terminal environment directly through the log-quiet command interface:
```bash
root -l fanalysis.C

root [0] 
Processing fanalysis.C...
--- Event 0 ---
Q2 (calc): 11.8592 | Q2 (file): 11.8589
xB (calc): 0.254243 | x (file): 0.254237
--- Event 1 ---
Q2 (calc): 1.12754 | Q2 (file): 1.12726
xB (calc): 0.00709958 | x (file): 0.00709782
--- Event 2 ---
Q2 (calc): 3.70113 | Q2 (file): 3.70085
xB (calc): 0.0440759 | x (file): 0.0440725
--- Event 3 ---
Q2 (calc): 3.70113 | Q2 (file): 3.70085
xB (calc): 0.0440759 | x (file): 0.0440725
--- Event 4 ---
Q2 (calc): 3.70113 | Q2 (file): 3.70085
xB (calc): 0.0440759 | x (file): 0.0440725
root [1]
```

---


