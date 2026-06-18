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

### Graphical Result<img width="798" height="575" alt="student_test_scores1" src="https://github.com/user-attachments/assets/5be8ce43-2d44-4c6b-ae87-4f680b21d4ba" />
