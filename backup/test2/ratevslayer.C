{
  TCanvas *c1 = new TCanvas("me11ratevslayer","rate vs layer",10,10,600,600);
  const int n1 = 28;

  double dose[n1] = {1.92, 9.31, 15.85, 15.86, 21.59, 27.48, 27.54, 28.29, 29.63, 31.38, 32.44, 32.93, 33.88, 35.10, 41.86, 48.44, 55.30, 61.30, 66.09, 68.8, 76.03, 90.26, 97.65, 104.17, 110.26, 115.64, 121.71, 126.25};

  std::string dataname[n1] = {"A6745.root","A6790.root","A6829.root","A6869.root","A6928.root","A7001.root","A7042.root","A7079.root","A7136.root","A7183.root","A7269.root","A7314.root","A7401.root","A7450.root","A7503.root","A7558.root","A7608.root","A7647.root","A7690.root","A7756.root","A7801.root","A7843.root","A7889.root","A7944.root","A7992.root","A8038.root","A8086.root","A8132.root"};

  double a[6][n1];

  std::string histo[6] = {"ALCT/hAhitL[0][1]", "ALCT/hAhitL[1][1]", "ALCT/hAhitL[2][1]", "ALCT/hAhitL[3][1]", "ALCT/hAhitL[4][1]", "ALCT/hAhitL[5][1]"};

  for(i=0;i<n1;i++){
    TFile *f_temp = new TFile(("../gifRates/me11data/"+dataname[i]).c_str(),"read");
    for(int l=0; l<6; l++){
      TH1F *h_temp = (TH1F*)f_temp->Get(histo[l].c_str());
      a[l][i] = (h_temp->GetEntries())/30000;
      delete h_temp;
    }
    delete f_temp;
  }

  TGraph *gr11 = new TGraph(n1, dose, a[0]);
  TGraph *gr12 = new TGraph(n1, dose, a[1]);
  TGraph *gr13 = new TGraph(n1, dose, a[2]);
  TGraph *gr14 = new TGraph(n1, dose, a[3]);
  TGraph *gr15 = new TGraph(n1, dose, a[4]);
  TGraph *gr16 = new TGraph(n1, dose, a[5]);

  c1->cd();
  gr11->SetTitle("; Accumulated charge [mC/cm]; Dark ALCT rate in each layer[kHz]");
  gr11->SetMinimum(0);
  gr11->SetMaximum(1);
  gr11->SetMarkerColor(401);
  gr11->SetMarkerSize(1.5);
  gr11->SetLineColor(401);
  gr11->SetMarkerStyle(22);
  gr11->Draw("ALP");
  gr12->SetMarkerColor(866);
  gr12->SetMarkerSize(1.5);
  gr12->SetLineColor(866);
  gr12->SetMarkerStyle(22);
  gr12->Draw("LP same");
  gr13->SetMarkerColor(629);
  gr13->SetMarkerSize(1.5);
  gr13->SetLineColor(629);
  gr13->SetMarkerStyle(22);
  gr13->Draw("LP same");
  gr14->SetMarkerColor(418);
  gr14->SetMarkerSize(1.5);
  gr14->SetLineColor(418);
  gr14->SetMarkerStyle(22);
  gr14->Draw("LP same");
  gr15->SetMarkerColor(882);
  gr15->SetMarkerSize(1.5);
  gr15->SetLineColor(882);
  gr15->SetMarkerStyle(22);
  gr15->Draw("LP same");
  gr16->SetMarkerColor(795);
  gr16->SetMarkerSize(1.5);
  gr16->SetLineColor(795);
  gr16->SetMarkerStyle(22);
  gr16->Draw("LP same");
  TLegend *leg1 = new TLegend(0.20, 0.65, 0.60, 0.85);
  leg1->SetNColumns(3);
  leg1->SetHeader("ME1/1 dark rate in layer");
  leg1->AddEntry(gr11, "L1", "pl");
  leg1->AddEntry(gr12, "L2", "pl");
  leg1->AddEntry(gr13, "L3", "pl");
  leg1->AddEntry(gr14, "L4", "pl");
  leg1->AddEntry(gr15, "L5", "pl");
  leg1->AddEntry(gr16, "L6", "pl");
  leg1->SetBorderSize(0);
  leg1->Draw("same");

/*
    TArrow *ar1 = new TArrow(331.54,200,331.54,620,0.02,"|>");
    ar1->SetAngle(60);
    ar1->SetLineWidth(1);
    ar1->Draw();
*/



 
  c1->SaveAs("me11ratevslayer.pdf");


}
