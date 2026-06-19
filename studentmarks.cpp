#include <TCanvas.h>
#include <TH1F.h>
#include <TStyle.h>
#include <iostream>

void studentmarks() {
    int scores[30] = {65, 71, 88, 92, 55, 77, 84, 91, 69, 73,
                      82, 95, 60, 87, 78, 50, 66, 74, 81, 89,
                      93, 57, 62, 85, 79, 90, 68, 72, 80, 86};

    TH1F *h1 = new TH1F("h1", "Student Test Scores;Score Range;Number of Students", 10, 0, 100);

    for (int i = 0; i < 30; i++) {
        h1->Fill(scores[i]);
    }

    h1->SetFillColor(kBlue);
    h1->SetLineColor(kBlack);
    h1->SetStats(0);

    TCanvas *c1 = new TCanvas("c1", "Histogram Canvas", 800, 600);
    h1->Draw("HIST");

    c1->SaveAs("student_scores_histogram.png");

    std::cout << "Histogram created and saved as student_scores_histogram.png" << std::endl;
}

