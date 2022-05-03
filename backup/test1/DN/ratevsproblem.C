{
  TCanvas *c1 = new TCanvas("me21ratevsproblem","rate vs problem",10,10,600,600);

  const int n1 = 46;

  double dose[n1] = {17.95,33.83,53.84,62.33,62.36,66.59,69.87,73.12,93.13, 98.86,118.96,124.68,140.28,/*147.37,*/158.52,158.72,158.99,159.00,162.72, 169.92,178.52,186.31,190.61,195.32,197.36, 204.07, 211.80, 219.56, 227.74, 233.97, 240.84, 247.69, 257.44, 263.47, 273.86, 279.19, /*285.78,*/ 285.88, 288.49, 296.40, 306.13, 314.30, 322.94, 324.40, 324.77, 332.99, 340.75, 350};

  std::string dataname[n1] = {"A1053.root","A1252.root","A1382.root","A1458.root","A1574.root","A1663.root","A1737.root","A1754.root","A1974.root","A2003.root","A2314.root","A2463.root","A2539.root",/*"A2713.root",*/"A2856.root","A2937.root","A3058.root","A3123.root","A3308.root","A3376.root","A3570.root","A3643.root","A3771.root","A3911.root","A3998.root","A4319.root","A4505.root","A4548.root","A4780.root","A4909.root","A5076.root","A5209.root","A5345.root","A5437.root","A5579.root","A5666.root",/*"A5692.root",*/"A5698.root","A5762.root","A5865.root","A5965.root","A6085.root","A6208.root","A6236.root","A6310.root","A6411.root","A6504.root","A6598.root"};

  std::string histo[6] = {"ALCT/hAhitL[0][1]", "ALCT/hAhitL[1][1]", "ALCT/hAhitL[2][1]", "ALCT/hAhitL[3][1]", "ALCT/hAhitL[4][1]", "ALCT/hAhitL[5][1]"};

  double l0_n[n1] = {}, l2_n[n1] = {}, l4_n[n1] = {};

  for(int i=0;i<n1;i++){
    TFile *f_temp = new TFile(("../gifRates/me21data/"+dataname[i]).c_str(),"read");
    for(int l=0; l<6; l++){
      TH1F *h_temp = (TH1F*)f_temp->Get(histo[l].c_str());
      if(l==0) l0_n[i] += (h_temp->GetBinContent(8))/30;
      if(l==2) l2_n[i] += (h_temp->GetBinContent(8))/30;
      if(l==4) l4_n[i] += (h_temp->GetBinContent(8))/30;
      delete h_temp;
    }
    delete f_temp;
  }

   TGraph *gr11 = new TGraph(n1, dose, l0_n);
   TGraph *gr12 = new TGraph(n1, dose, l2_n);
   TGraph *gr13 = new TGraph(n1, dose, l4_n);


   c1->cd();

   //gPad->SetLogy();
   gr11->SetTitle("; Accumulated charge [mC/cm]; Dark ALCT rate [Hz]");
   gr11->SetMinimum(0);
   gr11->SetMaximum(10);
   //TGaxis *a = (TGaxis*)gr11->GetYaxis();
   //a->SetMaxDigits(2);
   gr11->SetMarkerColor(kRed);
   gr11->SetLineColor(kRed);
   gr11->SetMarkerStyle(20);
   gr11->SetMarkerSize(1.5);
   gr11->Draw("APL");

   gr12->SetMarkerColor(kGreen);
   gr12->SetLineColor(kGreen);
   gr12->SetMarkerStyle(20);
   gr12->SetMarkerSize(1.5);
   gr12->Draw("PL same");

   gr13->SetMarkerColor(kBlue);
   gr13->SetLineColor(kBlue);
   gr13->SetMarkerStyle(20);
   gr13->SetMarkerSize(1.5);
   gr13->Draw("PL same");

   TLegend *leg1 = new TLegend(0.18, 0.68 ,0.68, 0.88, "ME2/1 dark rates of single wgs");
   leg1->SetNColumns(1);
   leg1->AddEntry(gr11, "sample wg in L1", "pl");
   leg1->AddEntry(gr12, "sample wg in L3", "pl");
   leg1->AddEntry(gr13, "sample wg in L5", "pl");
   leg1->SetBorderSize(0);
   leg1->Draw();


   c1->SaveAs("me21ratevsproblem.pdf");



}
