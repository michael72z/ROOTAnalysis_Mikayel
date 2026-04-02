#include <TFile.h>
#include <TTree.h>
#include <iostream>
#include <cmath>

void fanalysis() {
    TFile *f = TFile::Open("myhist_298712.root");
    if (!f || f->IsZombie()) return;

    TTree *tree = (TTree*)f->Get("ntuple");
    if (!tree) return;

    double mu0_px, mu0_py, mu0_pz, mu0_E;
    double mu1_px, mu1_py, mu1_pz, mu1_E;
    double x_file, y_file, Q2_file, W2_file;

    tree->SetBranchAddress("mu0_px", &mu0_px);
    tree->SetBranchAddress("mu0_py", &mu0_py);
    tree->SetBranchAddress("mu0_pz", &mu0_pz);
    tree->SetBranchAddress("mu0_E", &mu0_E);
    
    tree->SetBranchAddress("mu1_px", &mu1_px);
    tree->SetBranchAddress("mu1_py", &mu1_py);
    tree->SetBranchAddress("mu1_pz", &mu1_pz);
    tree->SetBranchAddress("mu1_E", &mu1_E);

    tree->SetBranchAddress("x", &x_file);
    tree->SetBranchAddress("y", &y_file);
    tree->SetBranchAddress("Q2", &Q2_file);
    tree->SetBranchAddress("W2", &W2_file);

    const double M_p = 0.93827;
    const double m_mu2 = 0.105 * 0.105;

    long long nEntries = tree->GetEntries();
    for (int i = 0; i < 100; ++i) {
        tree->GetEntry(i);

        double nu = mu0_E - mu1_E;
        double dot_prod = mu0_px*mu1_px + mu0_py*mu1_py + mu0_pz*mu1_pz;
        double my_Q2 = 2 * (mu0_E * mu1_E - dot_prod - m_mu2);
        
        double my_xB = my_Q2 / (2 * M_p * nu);
        double my_yB = nu / mu0_E;

        if (i < 5) {
            std::cout << "--- Event " << i << " ---" << std::endl;
            std::cout << "Q2 (calc): " << my_Q2 << " | Q2 (file): " << Q2_file << std::endl;
            std::cout << "xB (calc): " << my_xB << " | x (file): " << x_file << std::endl;
        }
    }
}
