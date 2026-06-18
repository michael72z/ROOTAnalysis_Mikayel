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


