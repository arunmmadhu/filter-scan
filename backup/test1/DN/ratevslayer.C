#include "TGraph.h"
#include "TLatex.h"
#include "TString.h"
#include "TCanvas.h"
#include "TLegend.h"

void ratevslayer(){
  gStyle->SetOptStat(0);
  TCanvas *c1 = new TCanvas("me11ratevslayer","his1",1);
//  TCanvas *c2 = new TCanvas("me21ratevslayer","his2",1);
  //TCanvas *c3 = new TCanvas("c3","his1",1);
  //TCanvas *c4 = new TCanvas("c4","his2",1);

/*
   TString extraText   = "CSC ME1/1, ALCT:anode hit occupancy per unit wire group in each layer";
   TLatex latex;
   latex.SetNDC();
   latex.SetTextFont(42);
   latex.SetTextColor(kBlack);
*/

  const int n1=42;//, n2=48;
  //2016: 0218, 0225, 0310, 0401, 0404, 0414, 0415, 0418, 0516, 0615, 0629, 0706, 0713, 0720, 0803, 0810, 0831, 0921, 0928, 1009, 1019, 1026, 1109, 1116, 1123; 2017: 0117, 0125, 0201, 0208, 0215, 0222, 0301, 0308, 0315, 0407, 0419, 0424, 0505, 0531, 0607, 0621, 0628
  double dose1[n1] = {17.6, 25.5, 33.1, 40.9, 51.2, 59.38,/* 63.97,*/ 77.94, 89.81, 95.44, 104.24, 113.27, 120.90, 135.62, 142.40, 152.13, 154.42, 154.58, 156.55, /*163.68,*/ 171.28, 180.46, 186.99, 193.55, 200.14, 207.45, 214.78, 222.52, 228.59, 235.27, 241.72, 250.86, 256.42, 266.13, 271.28, 277.37,/* 279.95,*/ 287.51, 297.54, 305.82, 314.79, 316.29, 316.67, 324.07, 340};
//17.42,25.23,40.40,47.87,50.94,59.38,59.39,59.43,77.94,89.81,95.44,104.24,113.27,120.90,135.62,142.40,152.13,154.06,154.07,154.42,154.58, 158.07, 173.13, 180.46, 186.99, 193.55, 200.14, 207.45, 214.78, 222.52, 228.59, 235.27, 241.72, 250.86, 256.42, 266.13, 271.28, 277.37, 279.95, 287.51, 297.54, 305.82, 314.79, 316.29, 316.67, 324.07, 331.54};
  std::string dataname1[n1] = {"A1121.root","A1169.root","A1228.root","A1336.root","A1419.root","A1558.root",/*"A1688.root",*/"A1845.root","A1907.root","A2064.root","A2176.root","A2213.root","A2404.root","A2576.root","A2696.root","A2775.root","A2951.root","A3182.root","A3245.root",/*"A3449.root",*/"A3507.root","A3698.root","A3826.root","A4062.root","A4372.root","A4444.root","A4557.root","A4719.root","A4848.root","A5011.root","A5147.root","A5284.root","A5393.root","A5536.root","A5626.root","A5694.root",/*"A5814.root",*/"A5905.root","A6014.root","A6119.root","A6174.root","A6232.root","A6267.root","A6374.root","A6557.root"};

//"A1121.root","A1169.root","A1336.root","A1368.root","A1419.root","A1544.root","A1558.root","A1600.root","A1845.root","A1907.root","A2064.root","A2176.root","A2213.root","A2404.root","A2576.root","A2696.root","A2775.root","A2930.root","A2942.root","A2951.root","A3182.root","A3245.root","A3507.root","A3698.root","A3826.root","A4062.root","A4372.root","A4444.root","A4557.root","A4719.root","A4848.root","A5011.root","A5147.root","A5284.root","A5393.root","A5536.root","A5626.root","A5694.root","A5814.root","A5905.root","A6014.root","A6119.root","A6174.root","A6232.root","A6267.root","A6374.root","A6557.root"};
  //2016: 0218, 0303, 0404, 0414, 0415, 0511, 0515, 0518, 0615, 0629, 0715, 0720, 0803, 0810, 0907, 0921, 1012, 1019, 1026, 1102, 1109, 1116, 1216; 2017: 0117, 0125, 0201, 0208, 0215, 0222, 0301, 0308, 0315, 0409, 0419, 0424, 0505, 0526, 0531, 0607, 0621, 0628
//  double dose2[n2] = {17.95,33.83,53.84,62.33,62.36,66.59,69.87,73.12,93.13,98.86,118.96,124.68,140.28,147.37,158.52,158.72,158.99,159.00,162.72,169.92,178.52,186.31,190.61,195.32,197.36, 204.07, 211.80, 219.56, 227.74, 233.97, 240.84, 247.69, 257.44, 263.47, 273.86, 279.19, 285.78, 285.88, 288.49, 296.40, 306.13, 314.30, 322.94, 324.40, 324.77, 332.99, 340.75, 350};
//  std::string dataname2[n2] = {"A1053.root","A1252.root","A1382.root","A1458.root","A1574.root","A1663.root","A1737.root","A1754.root","A1974.root","A2003.root","A2314.root","A2463.root","A2539.root","A2713.root","A2856.root","A2937.root","A3058.root","A3123.root","A3308.root","A3376.root","A3570.root","A3643.root","A3771.root","A3911.root","A3998.root","A4319.root","A4505.root","A4548.root","A4780.root","A4909.root","A5076.root","A5209.root","A5345.root","A5437.root","A5579.root","A5666.root","A5692.root","A5698.root","A5762.root","A5865.root","A5965.root","A6085.root","A6208.root","A6236.root","A6310.root","A6411.root","A6504.root","A6598.root"};

  double a1[6][n1];//, a2[6][n2], b1[6][n1], b2[6][n2];
  double sum1=0, sum2=0;

  std::string histo[6] = {"ALCT/hAhitL[0][1]", "ALCT/hAhitL[1][1]", "ALCT/hAhitL[2][1]", "ALCT/hAhitL[3][1]", "ALCT/hAhitL[4][1]", "ALCT/hAhitL[5][1]"};

  std::string histonames1[6] = {"me11layer1","me11layer2","me11layer3","me11layer4","me11layer5","me11layer6"};
//  std::string histonames2[6] = {"me21layer1","me21layer2","me21layer3","me21layer4","me21layer5","me21layer6"};
  std::string data1[n1];//, data2[n2];
  std::fill_n(data1, 42, "../gifRates/me11data/test1/");
//  std::fill_n(data2, 48, "gifRates/me21data/");

  int i;
  TFile *fi1[n1];//, *fi2[n2];
  TH1F *h1[n1];//, *h2[n2];

  for(i=0; i<n1; i++){
    data1[i].append(dataname1[i]);
    fi1[i]=new TFile(data1[i].c_str(),"read");
  }
//  for(i=0; i<n2; i++){
//    data2[i].append(dataname2[i]);
//    fi2[i]=new TFile(data2[i].c_str(),"read");
//  }
//  TFile *f = new TFile("histo2Dme11.root","RECREATE");  
  for(short unsigned int l=0; l<6; l++){
    for(i=0;i<n1;i++){
      h1[i] = (TH1F*)fi1[i]->Get(histo[l].c_str());
      a1[l][i] = (h1[i]->GetEntries())/30000;
      if(l==0 ) sum1 += a1[l][i];
    }
//    for(i=0;i<n2;i++){
//      h2[i] = (TH1F*)fi2[i]->Get(histo[l].c_str());
//      a2[l][i] = (h2[i]->GetEntries())/30;
//      if(l==0 ) sum2 += a2[l][i];
//    }

  }
  /*sum1 /= n;
  sum2 /= n;
  for(int l=0; l<6; l++){
    for(i=0; i<n; i++){
      b1[l][i] = a1[l][i]/sum1;
      b2[l][i] = a2[l][i]/sum2;
    }
  }*/
  

  TGraph *gr11 = new TGraph(n1, dose1, a1[0]);
  TGraph *gr12 = new TGraph(n1, dose1, a1[1]);
  TGraph *gr13 = new TGraph(n1, dose1, a1[2]);
  TGraph *gr14 = new TGraph(n1, dose1, a1[3]);
  TGraph *gr15 = new TGraph(n1, dose1, a1[4]);
  TGraph *gr16 = new TGraph(n1, dose1, a1[5]);
/*
  TGraph *gr21 = new TGraph(n2, dose2, a2[0]);
  TGraph *gr22 = new TGraph(n2, dose2, a2[1]);
  TGraph *gr23 = new TGraph(n2, dose2, a2[2]);
  TGraph *gr24 = new TGraph(n2, dose2, a2[3]);
  TGraph *gr25 = new TGraph(n2, dose2, a2[4]);
  TGraph *gr26 = new TGraph(n2, dose2, a2[5]);

  TGraph *gt11 = new TGraph(n, dose1, b1[0]);
  TGraph *gt12 = new TGraph(n, dose1, b1[1]);
  TGraph *gt13 = new TGraph(n, dose1, b1[2]);
  TGraph *gt14 = new TGraph(n, dose1, b1[3]);
  TGraph *gt15 = new TGraph(n, dose1, b1[4]);
  TGraph *gt16 = new TGraph(n, dose1, b1[5]);

  TGraph *gt21 = new TGraph(n, dose1, b2[0]);
  TGraph *gt22 = new TGraph(n, dose1, b2[1]);
  TGraph *gt23 = new TGraph(n, dose1, b2[2]);
  TGraph *gt24 = new TGraph(n, dose1, b2[3]);
  TGraph *gt25 = new TGraph(n, dose1, b2[4]);
  TGraph *gt26 = new TGraph(n, dose1, b2[5]);
*/


  c1->cd();
  gr11->SetTitle("; Accumulated charge [mC/cm]; Anode single hits rate [kHz]");
  gr11->SetMinimum(0);
  gr11->SetMaximum(1.6);
  gr11->SetMarkerColor(401);
  gr11->SetLineColor(401);
  gr11->SetMarkerStyle(22);
  gr11->Draw("ALP");
  gr12->SetMarkerColor(866);
  gr12->SetLineColor(866);
  gr12->SetMarkerStyle(22);
  gr12->Draw("LP same");
  gr13->SetMarkerColor(629);
  gr13->SetLineColor(629);
  gr13->SetMarkerStyle(22);
  gr13->Draw("LP same");
  gr14->SetMarkerColor(418);
  gr14->SetLineColor(418);
  gr14->SetMarkerStyle(22);
  gr14->Draw("LP same");
  gr15->SetMarkerColor(882);
  gr15->SetLineColor(882);
  gr15->SetMarkerStyle(22);
  gr15->Draw("LP same");
  gr16->SetMarkerColor(795);
  gr16->SetLineColor(795);
  gr16->SetMarkerStyle(22);
  gr16->Draw("LP same");
  TLegend *leg1 = new TLegend(0.28, 0.65, 0.58, 0.90);
  leg1->SetHeader("ME1/1");
  leg1->SetNColumns(3);
  leg1->AddEntry(gr11, "L1", "p");
  leg1->AddEntry(gr12, "L2", "p");
  leg1->AddEntry(gr13, "L3", "p");
  leg1->AddEntry(gr14, "L4", "p");
  leg1->AddEntry(gr15, "L5", "p");
  leg1->AddEntry(gr16, "L6", "p");
  leg1->SetBorderSize(0);
  leg1->Draw();


/*
    TArrow *ar1 = new TArrow(331.54,200,331.54,620,0.02,"|>");
    ar1->SetAngle(60);
    ar1->SetLineWidth(1);
    ar1->Draw();



  c2->cd();
  gr21->SetTitle("; Accumulated charge [mC/cm]; Dark rate [Hz]");
  gr21->SetMinimum(300);
  gr21->SetMaximum(1000);
  gr21->SetMarkerColor(401);
  gr21->SetLineColor(401);
  gr21->SetMarkerStyle(22);
  gr21->Draw("ALP");
  gr22->SetMarkerColor(866);
  gr22->SetLineColor(866);
  gr22->SetMarkerStyle(22);
  gr22->Draw("LP same");
  gr23->SetMarkerColor(629);
  gr23->SetLineColor(629);
  gr23->SetMarkerStyle(22);
  gr23->Draw("LP same");
  gr24->SetMarkerColor(418);
  gr24->SetLineColor(418);
  gr24->SetMarkerStyle(22);
  gr24->Draw("LP same");
  gr25->SetMarkerColor(882);
  gr25->SetLineColor(882);
  gr25->SetMarkerStyle(22);
  gr25->Draw("LP same");
  gr26->SetMarkerColor(795);
  gr26->SetLineColor(795);
  gr26->SetMarkerStyle(22);
  gr26->Draw("LP same");
  TLegend *leg2 = new TLegend(0.58, 0.68, 0.8, 0.88);
  leg2->SetHeader("ME21");
  leg2->AddEntry(gr21, "layer1", "p");
  leg2->AddEntry(gr22, "layer2", "p");
  leg2->AddEntry(gr23, "layer3", "p");
  leg2->AddEntry(gr24, "layer4", "p");
  leg2->AddEntry(gr25, "layer5", "p");
  leg2->AddEntry(gr26, "layer6", "p");
  leg2->SetBorderSize(0);
  leg2->Draw();

  c3->cd();
  gt11->SetTitle("; Accumulated charge [mC/cm]; Rate ratio to layer1");
  gt11->SetMinimum(0);
  gt11->SetMaximum(3);
  gt11->SetMarkerColor(3);
  gt11->SetMarkerStyle(22);
  gt11->Draw("ALP");
  gt12->SetMarkerColor(1);
  gt12->SetMarkerStyle(22);
  gt12->Draw("LP same");
  gt13->SetMarkerColor(2);
  gt13->SetMarkerStyle(22);
  gt13->Draw("LP same");
  gt14->SetMarkerColor(4);
  gt14->SetMarkerStyle(22);
  gt14->Draw("LP same");
  gt15->SetMarkerColor(6);
  gt15->SetMarkerStyle(22);
  gt15->Draw("LP same");
  gt16->SetMarkerColor(8);
  gt16->SetMarkerStyle(22);
  gt16->Draw("LP same");
  TLegend *leg3 = new TLegend(0.18, 0.68, 0.48, 0.88);
  leg3->SetHeader("ME11 update to Mar. 8, 2017");
  leg3->AddEntry(gt11, "layer1", "p");
  leg3->AddEntry(gt12, "layer2", "p");
  leg3->AddEntry(gt13, "layer3", "p");
  leg3->AddEntry(gt14, "layer4", "p");
  leg3->AddEntry(gt15, "layer5", "p");
  leg3->AddEntry(gt16, "layer6", "p");
  leg3->Draw();


  c4->cd();
  gt21->SetTitle("; Accumulated charge [mC/cm]; Rate ratio to layer1");
  gt21->SetMinimum(0);
  gt21->SetMaximum(3);
  gt21->SetMarkerColor(3);
  gt21->SetMarkerStyle(22);
  gt21->Draw("ALP");
  gt22->SetMarkerColor(1);
  gt22->SetMarkerStyle(22);
  gt22->Draw("LP same");
  gt23->SetMarkerColor(2);
  gt23->SetMarkerStyle(22);
  gt23->Draw("LP same");
  gt24->SetMarkerColor(4);
  gt24->SetMarkerStyle(22);
  gt24->Draw("LP same");
  gt25->SetMarkerColor(6);
  gt25->SetMarkerStyle(22);
  gt25->Draw("LP same");
  gt26->SetMarkerColor(8);
  gt26->SetMarkerStyle(22);
  gt26->Draw("LP same");
  TLegend *leg4 = new TLegend(0.58, 0.68, 0.88, 0.88);
  leg4->SetHeader("ME21 update to Mar. 8, 2017");
  leg4->AddEntry(gt21, "layer1", "p");
  leg4->AddEntry(gt22, "layer2", "p");
  leg4->AddEntry(gt23, "layer3", "p");
  leg4->AddEntry(gt24, "layer4", "p");
  leg4->AddEntry(gt25, "layer5", "p");
  leg4->AddEntry(gt26, "layer6", "p");
  leg4->Draw();
*/


//   c1->cd();
//   latex.DrawLatex(0.1, 0.3, extraText);

 
//  TH1D * projh2X = histo2DL[0]->ProjectionX();
//  TH1D * projh2Y = histo2DL[0]->ProjectionY();
//  c1->cd(7);
//  projh2X->Draw();
//  c1->cd(8);
//  projh2Y->Draw();
//  c1->cd(9);
//  histo2DL[0]->Draw("lego");
  c1->SaveAs("me11layer_1.pdf");
  //c1->SaveAs("me11layer_1.C");
//  c2->SaveAs("me21ratevslayer.root");
//  c3->SaveAs("me11ratevslayerratio.pdf");
//  c4->SaveAs("me21ratevslayerratio.pdf");
//  f->Write();
//  c1->Close();
//  f->Close();
}
