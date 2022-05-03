//#include "TGraph.h"
//#include "TLatex.h"
//#include "TString.h"
//#include "TCanvas.h"
//#include "TLegend.h"

void ratecomparison() {

   TCanvas *c1 = new TCanvas("c1","rate vs dose",10,10,700,500);
   TCanvas *c2 = new TCanvas("c2","rate vs does",10,10,700,500);

   //TString extraText1   = "CSC ME1/1, nominal HV";
   //TString extraText2   = "CSC ME2/1, nominal HV";
   //TString date = "up to Apr. 7, 2017";
   //TLatex latex;
   //latex.SetNDC();
   //latex.SetTextFont(42);
   //latex.SetTextColor(kBlack);

   const int n=38, n1 = 38, n2=37;

   ////////////////////////////////////
   //    alct correction for me11    //
   ////////////////////////////////////
   double dose1[n] = {17.42,25.23,40.40,47.87,50.94,59.38,59.39,59.43,77.94,89.81,95.44,104.24,113.27,120.90,135.62,142.40,152.13,154.06,154.07,154.42,154.58, 158.07, 173.13, 180.46, 186.99, 193.55, 200.14, 207.45, 214.78, 222.52, 228.59, 235.27, 241.72, 250.86, 256.42, 266.13, 271.28, 277.37};
   double dose2[n] = {17.95,33.83,53.84,62.33,62.36,66.59,69.87,73.12,93.13,98.86,118.96,124.68,140.28,147.37,158.52,158.72,158.99,159.00,162.72,169.92,178.52,186.31,190.61,195.32,197.36, 204.07, 211.80, 219.56, 227.74, 233.97, 240.84, 247.69, 257.44, 263.47, 273.86, 279.19, 285.78, 285.88};
   std::string dataname1[n] = {"A1121.root","A1169.root","A1336.root","A1368.root","A1419.root","A1544.root","A1558.root","A1600.root","A1845.root","A1907.root","A2064.root","A2176.root","A2213.root","A2404.root","A2576.root","A2696.root","A2775.root","A2930.root","A2942.root","A2951.root","A3182.root","A3245.root","A3507.root","A3698.root","A3826.root","A4062.root","A4372.root","A4444.root","A4557.root","A4719.root","A4848.root","A5011.root","A5147.root","A5284.root","A5393.root","A5536.root","A5626.root","A5694.root"};
   std::string dataname2[n] = {"A1053.root","A1252.root","A1382.root","A1458.root","A1574.root","A1663.root","A1737.root","A1754.root","A1974.root","A2003.root","A2314.root","A2463.root","A2539.root","A2713.root","A2856.root","A2937.root","A3058.root","A3123.root","A3308.root","A3376.root","A3570.root","A3643.root","A3771.root","A3911.root","A3998.root","A4319.root","A4505.root","A4548.root","A4780.root","A4909.root","A5076.root","A5209.root","A5345.root","A5437.root","A5579.root","A5666.root","A5692.root","A5698.root"};

   std::string histo[6] = {"ALCT/hAhitL[0][1]", "ALCT/hAhitL[1][1]", "ALCT/hAhitL[2][1]", "ALCT/hAhitL[3][1]", "ALCT/hAhitL[4][1]", "ALCT/hAhitL[5][1]"};

   std::string data1[n], data2[n];
   std::fill_n(data1, 38, "gifRates/me11data/");
   std::fill_n(data2, 38, "gifRates/me21data/");

   double N_tot1[n]={0}, N_tot2[n]={0};
   TFile *fi1[n], *fi2[n];
   TH1F *h1[n], *h2[n];
   for(int i=0; i<n; i++){
     data1[i].append(dataname1[i]);
     fi1[i]=new TFile(data1[i].c_str(),"read");
     data2[i].append(dataname2[i]);
     fi2[i]=new TFile(data2[i].c_str(),"read");
   }

   for(int i=0;i<n;i++){
     for(short unsigned int l=0; l<6; l++){
       h1[i] = (TH1F*)fi1[i]->Get(histo[l].c_str());
       N_tot1[i] += h1[i]->GetEntries();
       h2[i] = (TH1F*)fi2[i]->Get(histo[l].c_str());
       N_tot2[i] += h2[i]->GetEntries();
     }
   }

   for(int i=0;i<n;i++){
      N_tot1[i] /= 30;
      N_tot2[i] /= 30;
   }

//dates: 2016::0203, 0211, 0218, 0225, 0303, 0310, 0404, 0415, 0511, 0526, 0615, 0629, 0706, 0713, 0720, 0803, 0810, 0831, 1009, 1019, 1026, 1102, 1109, 1116, 1123;2017::0117, 0125, 0201, 0208, 0215, 0222, 0301, 0308, 0315, 0407, 0419, 0424, 0505
   double charge1[n1] = {0.49, 11.3, 17.6, 25.5, 33.1, 40.9, 51.2, 59.38, 63.97, 77.94, 89.81, 95.44, 104.24, 113.27, 120.90, 135.62, 142.40, 152.13, 154.42, 154.58, 156.55, 163.68, 171.28, 180.46, 186.99, 193.55, 200.14, 207.45, 214.78, 222.52, 228.59, 235.27, 241.72, 250.86, 256.42, 266.13, 271.28, 277.37};
   double alct1[n1] = {764, 783, 783,  759,  789,  787.0,  777,  791, 785, 800, 798, 793, 802, 851, 840, 834, 832, 839, 714.6, 773.5, 845.7, 824.1, 879.3, 903.0, 1011.1, 842.2, 849.7, 870.2, 842.4, 928.6, 1001.2, 1156.2, 888.3, 915.8, 1108.2, 873.6, 980.6, 1414.9};

//dates: 2016::0127, 0203, 0218, 0303, 0310, 0415, 0511, 0515, 0518, 0615, 0629, 0715, 0720, 0803, 0907, 1012, 1019, 1026, 1102, 1109, 1116, 1123, 1216; 2017::0117, 0125, 0201, 0208, 0215, 0222, 0301, 0308, 0315, 0407, 0419, 0424, 0505, 0526
   double charge2[n2] = {0.68, 11.6, 17.95, 33.83, 53.84, 62.36, 66.59, 69.87, 73.12, 93.13, 98.86, 118.96, 124.68, 140.28, 158.52, 158.82, 158.99, 161.09, 168.38, 176.53, 186.31, 191.84, 197.36, 197.54, 204.07, 211.80, 219.56, 227.74, 233.97, 240.84, 247.69, 257.44, 263.47, 273.86, 279.19, 285.78, 285.88};
   double alct2[n2] =   {2620, 2557, 2526.4, 2788.9, 2716.9, 2866.7, 2851.1, 2799.2, 2890.2, 2830.4, 2816.6, 2827.4, 2943.8, 2886.3, 2750.0, 2378.0, 2475.5, 2681.2, 2648.2, 2604.2, 2556.0, 2565.9, 2559.3, 2543.0, 2590.3, 2650.3, 2574.0, 2595.1, 2555.5, 2626.3, 2597.3, 2626.0, 2638.3, 2625.2, 2630.2, 2832.1, 2759.6};




   TGraph *gr11 = new TGraph(n1, charge1, alct1);
   TGraph *gr12 = new TGraph(n, dose1, N_tot1);

   TGraph *gr21 = new TGraph(n2, charge2, alct2);
   TGraph *gr22 = new TGraph(n, dose2, N_tot2);

   c1->cd();
   gr11->SetTitle("; Accumulated charge [mC/cm]; Dark rate [Hz]");
   gr11->SetMinimum(400);
   gr11->SetMaximum(1600);
   gr11->SetMarkerColor(kRed);
   gr11->SetLineColor(kRed);
   gr11->SetMarkerStyle(22);
   gr11->SetMarkerSize(1.5);
   gr11->Draw("AP");

   //latex.DrawLatex(0.5, 0.8, extraText1);
   //latex.DrawLatex(0.5, 0.7, date);
   gr12->SetMarkerColor(kBlue);
   gr12->SetLineColor(kBlue);
   gr12->SetMarkerStyle(23);
   gr12->SetMarkerSize(1.5);
   gr12->Draw("P same");

   TLegend *leg1 = new TLegend(0.18, 0.68 ,0.48, 0.88, "ME1/1");
   leg1->AddEntry(gr11, "TMB dump", "p");
   leg1->AddEntry(gr12, "TEST 11", "p");
   leg1->SetBorderSize(0);
   leg1->Draw();

   c1->SaveAs("me11ratecomparison.root");

   c2->cd();
   gr21->SetTitle("; Acculumated charge [mC/cm]; Dark rate [Hz]");
   gr21->SetMinimum(1500);
   gr21->SetMaximum(5500);
   gr21->SetMarkerColor(kRed);
   gr21->SetLineColor(kRed);
   gr21->SetMarkerStyle(22);
   gr21->SetMarkerSize(1.5);
   gr21->Draw("AP");

   gr22->SetMarkerColor(kBlue);
   gr22->SetLineColor(kBlue);
   gr22->SetMarkerStyle(23);
   gr22->SetMarkerSize(1.5);
   gr22->Draw("P same");

   TLegend *leg2 = new TLegend(0.18, 0.68 ,0.48, 0.88, "ME2/1");
   leg2->AddEntry(gr21, "TMB dump", "p");
   leg2->AddEntry(gr22, "TEST 11", "p");
   leg2->SetBorderSize(0);
   leg2->Draw();

   c2->SaveAs("me21ratecomparison.root");



 //  TArrow *ar4 = new TArrow(80,200,5,800,0.03,"|>");
 //  ar4->SetAngle(60);
 //  ar4->SetLineWidth(2);
 //  ar4->SetFillColor(2);
 //  ar4->Draw();



}
