void analyze_hand() {
    // 1. i opened the root file 
    TFile *f = TFile::Open("myhist_298712.root");
    if (!f) { cout << "File not found!" << endl; return; }

    TTree *ntuple = (TTree*)f->Get("ntuple");

    // 2. sahmaneci popoxakanner faylic kardalu hamara!!
    double P_beam, mu0_E, mu0_px, mu0_py, mu0_pz, Q2_file, W2_file;
    double Mp = 0.93827; // protoni zangvacy (GeV)

    ntuple->SetBranchAddress("P_beam", &P_beam); // ynknox masniki kam pnji impulsn e kam energyan
    ntuple->SetBranchAddress("mu0_E", &mu0_E); // crvac masniki(myuon or elctron) energyan
    ntuple->SetBranchAddress("mu0_px", &mu0_px); // crvac masniki energyayi proyekcian on X axis 
    ntuple->SetBranchAddress("mu0_py", &mu0_py); // crvac masniki energyayi proyekcian on Y axis 
    ntuple->SetBranchAddress("mu0_pz", &mu0_pz); // crvac masniki energyayi proyekcian on Z axis 
    ntuple->SetBranchAddress("Q2", &Q2_file); // fayli michi trvacy
    ntuple->SetBranchAddress("W2", &W2_file); // fayli michi trvacy

    // 3. Stexcumem histogramner vor hamematem
   TH1F *hDiffQ2 = new TH1F("hDiffQ2", "Q2 Comparison; Delta Q2; Events", 100, -0.1, 0.1);
   TH1F *hDiffW2 = new TH1F("hDiffW2", "W2 Comparison; Delta W2; Events", 100, -0.1, 0.1);

    cout << "Processing events..." << endl;

    // 4. loop bolor eventneri vrayov
    for (int i=0; i < ntuple->GetEntries(); i++) {
        ntuple->GetEntry(i);

        // --- im hashvarknery (yst grataxtaki banadzevi) ---
        
        // A. Hashvumem lriv impulsn u cos (thetan)
        double p_total = sqrt(mu0_px*mu0_px + mu0_py*mu0_py + mu0_pz*mu0_pz);
        double cos_theta = mu0_pz / p_total;

        // B. Q2 = 2 * E * E' * (1 - cos(theta))
        double my_Q2 = 2 * P_beam * mu0_E * (1 - cos_theta);

        // C. W2 = Mp^2 + 2*Mp*(E - E') - Q2
        double my_W2 = Mp*Mp + 2*Mp*(P_beam - mu0_E) - my_Q2;

        // լU lcnumem tarberutyan histogramis mech
        hDiffQ2->Fill(my_Q2 - Q2_file);
        hDiffW2->Fill(my_W2 - W2_file);
    }

    // 5. Showem anum resultnery 
    TCanvas *c1 = new TCanvas("c1", "Comparison", 800, 400);
    c1->Divide(2,1);
    
    c1->cd(1); hDiffQ2->Draw();
    c1->cd(2); hDiffW2->Draw();

    cout << "Done! If histograms are centered at 0, your proof is correct." << endl;
}
