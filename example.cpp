#include <TCanvas.h>
#include <TH1F.h>
#include <TRandom.h>

int main() {
    // Create a histogram
    TH1F *h = new TH1F("h", "Example Histogram", 100, -4, 4);

    // Fill with random Gaussian numbers
    for (int i = 0; i < 10000; i++) {
        h->Fill(gRandom->Gaus());
    }

    // Draw the histogram
    TCanvas *c = new TCanvas("c", "Canvas", 800, 600);
    h->Draw();
    c->SaveAs("histogram.png");

    return 0;
}
