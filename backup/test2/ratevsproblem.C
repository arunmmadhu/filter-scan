{
  TCanvas *c1 = new TCanvas("me11ratevsproblem","rate vs problem",10,10,600,600);

  const int n1 = 28;

  double dose[n1] = {1.92, 9.31, 15.85, 15.86, 21.59, 27.48, 27.54, 28.29, 29.63, 31.38, 32.44, 32.93, 33.88, 35.10, 41.86, 48.44, 55.30, 61.30, 66.09, 68.8, 76.03, 90.26, 97.65, 104.17, 110.26, 115.64, 121.71, 126.25};

  std::string dataname[n1] = {"A6745.root","A6790.root","A6829.root","A6869.root","A6928.root","A7001.root","A7042.root","A7079.root","A7136.root","A7183.root","A7269.root","A7314.root","A7401.root","A7450.root","A7503.root","A7558.root","A7608.root","A7647.root","A7690.root","A7756.root","A7801.root","A7843.root","A7889.root","A7944.root","A7992.root","A8038.root","A8086.root","A8132.root"};

  std::string histo[6] = {"ALCT/hAhitL[0][1]", "ALCT/hAhitL[1][1]", "ALCT/hAhitL[2][1]", "ALCT/hAhitL[3][1]", "ALCT/hAhitL[4][1]", "ALCT/hAhitL[5][1]"};

  double l4_p[n1] = {}, l4_n[n1] = {}, l5_p[n1] = {}, l5_n[n1] = {}; 

  for(int i=0;i<n1;i++){
    TFile *f_temp = new TFile(("../gifRates/me11data/"+dataname[i]).c_str(),"read");
    for(int l=0; l<6; l++){
      TH1F *h_temp = (TH1F*)f_temp->Get(histo[l].c_str());
      //if(l==3) {l4_p[i] += (h_temp->GetBinContent(2))/30000; l4_n[i] += (h_temp->GetBinContent(3))/30000;}
      if(l==4) {l5_p[i] += (h_temp->GetBinContent(7))/30000; l5_n[i] += (h_temp->GetBinContent(8))/30000;}
      delete h_temp;
    }
    delete f_temp;
  }

   TGraph *gr11 = new TGraph(n1, dose, l5_p);
   TGraph *gr12 = new TGraph(n1, dose, l5_n);


   c1->cd();

   gPad->SetLogy();
   gr11->SetTitle("; Accumulated charge [mC/cm]; Dark ALCT rate [kHz]");
   gr11->GetYaxis()->SetTitleOffset(1.3);
   gr11->SetMinimum(0);
   gr11->SetMaximum(0.8);
   //TGaxis *a = (TGaxis*)gr11->GetYaxis();
   //a->SetMaxDigits(2);
   gr11->SetMarkerColor(kRed);
   gr11->SetLineColor(kRed);
   gr11->SetMarkerStyle(24);
   gr11->SetMarkerSize(1.5);
   gr11->Draw("APL");

   gr12->SetMarkerColor(kGreen);
   gr12->SetLineColor(kGreen);
   gr12->SetMarkerStyle(24);
   gr12->SetMarkerSize(1.5);
   gr12->Draw("PL same");



   TLegend *leg1 = new TLegend(0.20, 0.35 ,0.80, 0.60, "ME1/1 dark rate of bad wgs");
   //leg1->SetNColumns(2);
   leg1->AddEntry(gr11, "problem wg in L5", "pl");
   leg1->AddEntry(gr12, "nearby normal wg in L5", "pl");
   leg1->SetBorderSize(0);
   leg1->Draw();


   c1->SaveAs("me11ratevsproblem.pdf");



}
