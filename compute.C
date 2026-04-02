#include <TFile.h>
#include <TTree.h>
#include <TLorentzVector.h>
#include <iostream>
#include <cmath>

void compute() {
    // bacume fayly
    TFile *f = TFile::Open("myhist_298712.root");
    if (!f) return;

    // 2. bacumenq treen (PhastHist papki mech)
    TTree *tree = (TTree*)f->Get("PhastHist/ntuple");

    // 3. haytararumenq zangvacner (4 chapani: px, py, pz, E)
    float mu0_p[4], mu1_p[4];
    tree->SetBranchAddress("mu0_p", mu0_p);
    tree->SetBranchAddress("mu1_p", mu1_p);

    const double M_p = 0.938272; // proroni zangvac (GeV)

    // 4. cikly ira depqerov
    for (int i = 0; i < tree->GetEntries(); ++i) {
        tree->GetEntry(i);

        // ogtagorcumenq harmar vektor ROOT 
        TLorentzVector k(mu0_p[0], mu0_p[1], mu0_p[2], mu0_p[3]);   // muqg gorcox myuon
        TLorentzVector kp(mu1_p[0], mu1_p[1], mu1_p[2], mu1_p[3]); // crvac myuon  myuon
        TLorentzVector q = k - kp;                                 // poxancac impuls

        // HASHVARK:
        double Q2 = -q.M2();            // Q^2 = -q^2
        double nu = k.E() - kp.E();     // fotoni energya
        double yB = nu / k.E();         // voch aradzgakan
        double xB = Q2 / (2 * M_p * nu); // Bjorken x
        double W2 = M_p*M_p + 2*M_p*nu - Q2; // hadronayin hamakargi invariant zangvac

        // arachi 10 arjeqneri durs berum
        if (i < 10) {
            std::cout << "Event " << i << " | Q2: " << Q2 << " | xB: " << xB << " | nu: " << nu << std::endl;
        }
        
    }
}
