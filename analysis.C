#include <TFile.h>
#include <TTree.h>
#include <iostream>
#include <cmath>

void final_analysis() {
    TFile *f = TFile::Open("myhist_298712.root");
    //PhastHist/ntuple
    TTree *tree = (TTree*)f->Get("ntuple");

    //(4 units: px, py, pz, E)
    double mu0_p[4], mu1_p[4];
    
    // sahmanumenq popoxakanner vorornq arten kan faylum
    double x_file, y_file, Q2_file, W2_file;

    // kapumenq chyuxery 
    tree->SetBranchAddress("mu0_p", mu0_p);
    tree->SetBranchAddress("mu1_p", mu1_p);
    tree->SetBranchAddress("x", &x_file);
    tree->SetBranchAddress("y", &y_file);
    tree->SetBranchAddress("Q2", &Q2_file);
    tree->SetBranchAddress("W2", &W2_file);

    const double M_p = 0.93827; // protoni massa 

    for (int i = 0; i < 100; ++i) { // kamayakanenq vercnum 100
        tree->GetEntry(i);

        // inqnersenq hashvum:
        double E0 = mu0_p[3];
        double E1 = mu1_p[3];
        
        // nu arachnayin energia 
        double nu = E0 - E1;
        
        // Q2 = 2 * (E0*E1 - (px0*px1 + py0*py1 + pz0*pz1) - m_mu^2)
        double dot_prod = mu0_p[0]*mu1_p[0] + mu0_p[1]*mu1_p[1] + mu0_p[2]*mu1_p[2];
        double my_Q2 = 2 * (E0 * E1 - dot_prod - 0.105*0.105);
        
        double my_xB = my_Q2 / (2 * M_p * nu);
        double my_yB = nu / E0;

        // dursenq berum u hamematumenq faylini mech
        if (i < 5) {
            std::cout << "--- Event " << i << " ---" << std::endl;
            std::cout << "Q2 (calc): " << my_Q2 << " | Q2 (file): " << Q2_file << std::endl;
            std::cout << "xB (calc): " << my_xB << " | x (file): " << x_file << std::endl;
        }
    }
}

