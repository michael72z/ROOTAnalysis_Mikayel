#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <cmath>

void analyze_hand3() {
    TFile *f = TFile::Open("myhist_298712.root");
    if (!f) { std::cout << "Ֆայլը չգտնվեց:" << std::endl; return; }
    
    TTree *ntuple = (TTree*)f->Get("ntuple");

    Double_t mu0_E, mu0_px, mu0_py, mu0_pz;
    Double_t mu1_E, mu1_px, mu1_py, mu1_pz;
    Double_t Q2_file, W2_file;
    Double_t Mp = 0.938272; 

    ntuple->SetBranchAddress("mu0_E",  &mu0_E);
    ntuple->SetBranchAddress("mu0_px", &mu0_px);
    ntuple->SetBranchAddress("mu0_py", &mu0_py);
    ntuple->SetBranchAddress("mu0_pz", &mu0_pz);
    ntuple->SetBranchAddress("mu1_E",  &mu1_E);
    ntuple->SetBranchAddress("mu1_px", &mu1_px);
    ntuple->SetBranchAddress("mu1_py", &mu1_py);
    ntuple->SetBranchAddress("mu1_pz", &mu1_pz);
    ntuple->SetBranchAddress("Q2", &Q2_file);
    ntuple->SetBranchAddress("W2", &W2_file);

    TH1F *hQ2_file = new TH1F("hQ2_file", "Q^{2} Comparison; Q^{2} [GeV^{2}]; Events", 100, 0, 15);
    TH1F *hQ2_mine = new TH1F("hQ2_mine", "Q^{2} Mine", 100, 0, 15);
    TH1F *hW2_file = new TH1F("hW2_file", "W^{2} Comparison; W^{2} [GeV^{2}]; Events", 100, 0, 300);
    TH1F *hW2_mine = new TH1F("hW2_mine", "W^{2} Mine", 100, 0, 300);

    // Տterminal
    std::cout << "\n--- HAND 3: DOT PRODUCT METHOD (Terminal Results) ---\n";
    printf("%-7s | %-10s | %-10s | %-10s | %-10s\n", "Event", "Q2_File", "Q2_Mine", "W2_File", "W2_Mine");
    std::cout << "----------------------------------------------------------------------\n";

    Long64_t nEntries = ntuple->GetEntries();
    for (Long64_t i = 0; i < nEntries; i++) {
        ntuple->GetEntry(i);

        // (Dot Product)
        double p0 = sqrt(mu0_px*mu0_px + mu0_py*mu0_py + mu0_pz*mu0_pz);
        double p1 = sqrt(mu1_px*mu1_px + mu1_py*mu1_py + mu1_pz*mu1_pz);
        double dot = mu0_px*mu1_px + mu0_py*mu1_py + mu0_pz*mu1_pz;
        double cos_theta = dot / (p0 * p1);
        
        double my_Q2 = 2.0 * mu0_E * mu1_E * (1.0 - cos_theta);
        double my_W2 = Mp*Mp + 2.0 * Mp * (mu0_E - mu1_E) - my_Q2;

        hQ2_file->Fill(Q2_file);
        hQ2_mine->Fill(my_Q2);
        hW2_file->Fill(W2_file);
        hW2_mine->Fill(my_W2);

        // type for only 20 
        if (i < 20) {
            printf("%-7lld | %-10.4f | %-10.4f | %-10.4f | %-10.4f\n", i, Q2_file, my_Q2, W2_file, my_W2);
        }
    }
    std::cout << "----------------------------------------------------------------------\n";
    std::cout << "overall done  " << nEntries << "event։\n";

    // grafik dzevavorum
    TCanvas *c1 = new TCanvas("c1", "Validation Hand 3", 1200, 600);
    c1->Divide(2,1);

    // Q2 Overlay
    c1->cd(1);
    hQ2_file->SetLineColor(kBlack);
    hQ2_file->SetLineWidth(2);
    hQ2_file->Draw();
    hQ2_mine->SetLineColor(kBlue);
    hQ2_mine->SetLineStyle(2);
    hQ2_mine->SetLineWidth(2);
    hQ2_mine->Draw("same");

    TLegend *leg1 = new TLegend(0.6, 0.7, 0.9, 0.9);
    leg1->AddEntry(hQ2_file, "Q2 (File)", "l");
    leg1->AddEntry(hQ2_mine, "Q2 (Calculated)", "l");
    leg1->Draw();

    // W2 Overlay
    c1->cd(2);
    hW2_file->SetLineColor(kBlack);
    hW2_file->SetLineWidth(2);
    hW2_file->Draw();
    hW2_mine->SetLineColor(kRed);
    hW2_mine->SetLineStyle(2);
    hW2_mine->SetLineWidth(2);
    hW2_mine->Draw("same");

    TLegend *leg2 = new TLegend(0.6, 0.7, 0.9, 0.9);
    leg2->AddEntry(hW2_file, "W2 (File)", "l");
    leg2->AddEntry(hW2_mine, "W2 (Calculated)", "l");
    leg2->Draw();

    std::cout << "Grafs are ready, black is file's one and colored one is mine" << std::endl;
}