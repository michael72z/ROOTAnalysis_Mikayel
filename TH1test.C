// void TH1test()
// {
//     TH1F *hist = new TH1F("hist", "Histogram sample title;X Axis;Y Axis", 100, 0, 100);
//     hist->Fill(10);

//     TCanvas *c1 = new TCanvas();
//     hist->Draw();
// }

// void TH1test()
// {   
//     int customers[13] = {12, 18, 25, 33, 41, 55, 62, 48, 39, 30, 27, 20, 15};

//     TH1F *hist = new TH1F("hist", "Histogram sample title;Hour index (8-12); Number of customers", 13, 8, 20);
//     hist->Fill(10);

    
//     for (int i = 0; i < 13; i++) 
//     {
//     hist->SetBinContent(i + 1, customers[i]);
//     }

//     TCanvas *c1 = new TCanvas();
//     hist->Draw();
// }

void TH1test()
{
    TH1F *hist = new TH1F("marks", "Student Marks Distribution", 4, 0, 20);

    // generat 200 random marks between 0 and 20 for demo
    float marks[200];
    for (int i = 0; i < 200; i++) {
        marks[i] = gRandom->Uniform(0, 20);
        hist->Fill(marks[i]); // ROOT automatically puts it in the correct bin
    }

    TCanvas *c1 = new TCanvas("c1", "Marks Histogram", 800, 600);
    hist->Draw("HIST");

    // print how many students in each bin
    for (int bin = 1; bin <= 4; bin++) {
        std::cout << "Bin " << bin 
                  << " (" << hist->GetXaxis()->GetBinLowEdge(bin) 
                  << " - " << hist->GetXaxis()->GetBinUpEdge(bin) << ") "
                  << hist->GetBinContent(bin) << " students" << std::endl;
    }
}
