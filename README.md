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


## Macro 5: `TH1test.C` - 1D Histogram Binning and Manipulation

# Deep Inelastic Scattering (DIS) Kinematic Reconstruction

## Overview
This repository contains an advanced high-energy physics analysis script (`analysis.C`) designed to reconstruct the kinematics of **Deep Inelastic Scattering (DIS)** events. 

The core objective of this macro is data verification and integrity validation. By processing raw particle track arrays, the script manually reconstructs fundamental Lorentz-invariant variables event-by-event and cross-checks them directly against pre-computed experimental data branches stored within a framework ROOT file.

---

## Physics Context
In a typical DIS event, a high-energy incoming lepton (in this case, a muon, $\mu$) collides with a stationary nucleon target (a proton, $p$). The interaction is mediated by the exchange of a virtual photon ($\gamma^*$), which probes the internal structure of the proton, scattering the lepton and breaking the nucleon apart into a hadronic final state.

By measuring only the incoming and outgoing properties of the muon, we can completely map out the physics of the entire interaction.

---

## Kinematic Variables & Mathematical Framework

The script tracks and extracts two principal four-vectors for each event:
* **Initial Lepton ($\mu_0$):** $k = (p_{x0}, p_{y0}, p_{z0}, E_0)$
* **Scattered Lepton ($\mu_1$):** $k' = (p_{x1}, p_{y1}, p_{z1}, E_1)$

Using these raw components, the macro evaluates the following fundamental physical quantities:

### 1. Photon Virtuality ($Q^2$)
Represents the momentum transfer squared. It dictates the spatial resolution of our structural probe—higher values allow us to "see" deeper inside the proton.
$$Q^2 = -q^2 = 2 \cdot (E_0 E_1 - \vec{p}_0 \cdot \vec{p}_1 - m_\mu^2)$$

### 2. Hadronic Energy Transfer ($\nu$)
The total energy lost by the lepton in the laboratory frame, which is transferred directly to the target proton system.
$$\nu = E_0 - E_1$$

### 3. Bjorken Scaling Variable ($x_B$)
A dimensionless scaling value representing the fraction of the proton's total momentum carried by the specific struck quark.
$$x_B = \frac{Q^2}{2 M_p \nu}$$

### 4. Inelasticity ($y$)
The fraction of the incoming lepton's energy transferred to the hadronic system in the target rest frame.
$$y = \frac{\nu}{E_0}$$

| Constant | Description | Value |
| :--- | :--- | :--- |
| $M_p$ | Proton Mass Target | `0.93827 GeV` |
| $m_\mu$ | Muon Mass | `0.10566 GeV` |

---

## Code Workflow & Architecture

1. **Data Pipeline Mapping:** Connects to the binary storage file `myhist_298712.root` and targets the core data table (`ntuple`).
2. **Memory Binding:** Uses `SetBranchAddress` to map raw storage blocks directly to dynamic local arrays in memory.
3. **Kinematic Loops:** Iterates event-by-event to calculate isolated 3D dot products, scalar energy balances, and relativistic invariants.
4. **Data Verification Handshake:** Prints calculated metrics side-by-side with pre-compiled file results (`Q2_file` vs `my_Q2`) to instantly guarantee tracking and reconstruction alignment.

---

## Technical Execution Guide

### Prerequisites
Ensure that **ROOT** is correctly compiled and sourced in your environment.

### Step-by-Step Execution
1. Navigate directly to your local workspace directory:
   ```bash
   cd Desktop/ROOT_Projects

