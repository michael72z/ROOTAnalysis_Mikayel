#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TString.h>
#include <TStyle.h>

void AnalyzeQ2Errors() {
    gStyle->SetOptStat("emr"); 

    TFile *f = TFile::Open("myhist_298712.root");
    if (!f) {
        std::cout << "Error: File not found!" << std::endl;
        return;
    }
    
    TTree *ntuple = (TTree*)f->Get("ntuple");

    Double_t mu0_E, mu0_px, mu0_py, mu0_pz;
    Double_t mu1_E, mu1_px, mu1_py, mu1_pz;
    Double_t Q2_file;

    ntuple->SetBranchAddress("mu0_E",  &mu0_E);
    ntuple->SetBranchAddress("mu0_px", &mu0_px);
    ntuple->SetBranchAddress("mu0_py", &mu0_py);
    ntuple->SetBranchAddress("mu0_pz", &mu0_pz);
    ntuple->SetBranchAddress("mu1_E",  &mu1_E);
    ntuple->SetBranchAddress("mu1_px", &mu1_px);
    ntuple->SetBranchAddress("mu1_py", &mu1_py);
    ntuple->SetBranchAddress("mu1_pz", &mu1_pz);
    ntuple->SetBranchAddress("Q2", &Q2_file);

    Long64_t nEntries = ntuple->GetEntries();
    const int nBins = 6;

    // Qayl 1: hashvarkumenq mijakayqeri sahmannery vor apahovenq motavor +-20k event amen binum
    std::vector<double> q2_values;
    q2_values.reserve(nEntries);
    
    for (Long64_t i = 0; i < nEntries; i++) {
        ntuple->GetEntry(i);
        q2_values.push_back(Q2_file);
    }
    
    std::sort(q2_values.begin(), q2_values.end());
    
    double edges[nBins + 1];
    edges[0] = q2_values.front(); 
    for (int i = 1; i < nBins; i++) {
        Long64_t index = (nEntries * i) / nBins;
        edges[i] = q2_values[index];
    }
    edges[nBins] = q2_values.back() + 0.1; 

    // Qayl 2: stexcumenq 12 hat 1D histogramner
    TH1F* hAbsErr[nBins];
    TH1F* hRelErr[nBins];
    
    double abs_limit = 0.015; 
    double rel_limit = 0.015; 

    for(int i = 0; i < nBins; i++){
        TString nameAbs = Form("hAbsErr_bin%d", i+1);
        TString titleAbs = Form("Abs Error (Bin %d: %.2f-%.2f GeV^{2}); |Q^{2}_{file} - Q^{2}_{mine}|; Events", i+1, edges[i], edges[i+1]);
        hAbsErr[i] = new TH1F(nameAbs, titleAbs, 100, 0, abs_limit);
        
        TString nameRel = Form("hRelErr_bin%d", i+1);
        TString titleRel = Form("Rel Error (Bin %d: %.2f-%.2f GeV^{2}); |Q^{2}_{file} - Q^{2}_{mine}| / Q^{2}_{file}; Events", i+1, edges[i], edges[i+1]);
        hRelErr[i] = new TH1F(nameRel, titleRel, 100, 0, rel_limit);
    }

    // Qayl 3: ciklnamer vrtex Q1 in hamapatasxan lcvumen sxalnery
    for (Long64_t i = 0; i < nEntries; i++) {
        ntuple->GetEntry(i);

        double p0 = sqrt(mu0_px*mu0_px + mu0_py*mu0_py + mu0_pz*mu0_pz);
        double p1 = sqrt(mu1_px*mu1_px + mu1_py*mu1_py + mu1_pz*mu1_pz);
        double dot = mu0_px*mu1_px + mu0_py*mu1_py + mu0_pz*mu1_pz;
        double cos_theta = dot / (p0 * p1);
        
        double my_Q2 = 2.0 * mu0_E * mu1_E * (1.0 - cos_theta);

        double abs_err = std::abs(Q2_file - my_Q2);           
        double rel_err = 0;
        if (Q2_file > 0) {
            rel_err = abs_err / Q2_file; 
        }

        int bin_idx = -1;
        for(int b = 0; b < nBins; b++){
            if(Q2_file >= edges[b] && Q2_file < edges[b+1]){
                bin_idx = b;
                break;
            }
        }
        
        if(bin_idx != -1){
            hAbsErr[bin_idx]->Fill(abs_err);
            hRelErr[bin_idx]->Fill(rel_err);
        }
    }

    // Qayl 4: Nkarumenq histogramy 6x2 i vra
    TCanvas *c1 = new TCanvas("c1", "Q2 Error Distributions", 1800, 800);
    c1->Divide(6, 2); 

    for (int i = 0; i < nBins; i++) {
        c1->cd(i + 1);
        hAbsErr[i]->SetLineColor(kBlue);
        hAbsErr[i]->SetFillColorAlpha(kBlue, 0.3);
        hAbsErr[i]->Draw();
        
        c1->cd(i + 7);
        hRelErr[i]->SetLineColor(kRed);
        hRelErr[i]->SetFillColorAlpha(kRed, 0.3);
        hRelErr[i]->Draw();
    }
}
