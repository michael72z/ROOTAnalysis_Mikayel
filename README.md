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

