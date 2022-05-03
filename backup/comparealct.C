{

   TCanvas *c1 = new TCanvas("comparealct","rate vs dose",10,10,700,500);

   //TString extraText1   = "CSC ME1/1, nominal HV";
   //TString extraText2   = "CSC ME2/1, nominal HV";
   //TString date = "up to Apr. 7, 2017";
   //TLatex latex;
   //latex.SetNDC();
   //latex.SetTextFont(42);
   //latex.SetTextColor(kBlack);

   const int n1 = 9, n2 = 4, n3 = 9;

   double I1[9] = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9};
   double t1[9] = {53.7, 144.3, 238.6, 386.9, 568.3, 162409.7, 1066584.4, 718003.1, 581601.0};

   double I2[4] = {2.5, 2.7, 2.8, 2.9};
   double t2[4] = {578.0, 805.7, 996.6, 2747.2};

   double I3[9] = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9};
   double t3[9] = {67.4, 132.4, 238.0, 363.5, 528.5, 665.1, 717.2, 869.3, 2881.0};

   //double I4[10] = {3, 5, 6, 10, 12, 15, 18, 20, 38, 40};
   //double t4[10] = {47, 50, 52, 53, 54, 55, 56, 57, 65, 67};

   TGraph *gr11 = new TGraph(n1, I1, t1);
   TGraph *gr12 = new TGraph(n2, I2, t2);
   TGraph *gr13 = new TGraph(n3, I3, t3);
   //TGraph *gr14 = new TGraph(n4, t4, I4);

   c1->cd(); c1->SetLogy();
   gr11->SetTitle("; High Voltage(kV); ALCT dark rates(Hz)");
   gr11->SetMinimum(0.1);
   //gr11->SetMaximum(50);
   gr11->SetMarkerColor(kRed);
   gr11->SetLineColor(kRed);
   gr11->SetMarkerStyle(22);
   gr11->SetMarkerSize(1.5);
   gr11->Draw("ALP");
   //gr11->GetXaxis()->SetLimits(0, 70);
   //gr11->Draw("ALP");

   //latex.DrawLatex(0.5, 0.8, extraText1);
   //latex.DrawLatex(0.5, 0.7, date);
   gr12->SetMarkerColor(kBlue);
   gr12->SetLineColor(kBlue);
   gr12->SetMarkerStyle(23);
   gr12->SetMarkerSize(1.5);
   gr12->Draw("LP same");

   gr13->SetMarkerColor(kGreen);
   gr13->SetLineColor(kGreen);
   gr13->SetMarkerStyle(20);
   gr13->SetMarkerSize(1.5);
   gr13->Draw("LP same");

   //gr14->SetMarkerColor(9);
   //gr14->SetLineColor(9);
   //gr14->SetMarkerStyle(30);
   //gr14->Draw("LP same");

   TLegend *leg1 = new TLegend(0.18, 0.60 ,0.58, 0.90, "ME1/1, with 10% CF4");
   leg1->AddEntry(gr11, "alct rate on Aug. 2", "lp");
   leg1->AddEntry(gr12, "alct rate on Aug. 30 before training", "lp");
   leg1->AddEntry(gr13, "alct rate on Aug. 30 after training", "lp"); 
   //leg1->AddEntry(gr14, "HV = 2.54 kV", "lp");
   leg1->SetBorderSize(0);
   leg1->Draw();

 
   c1->SaveAs("comparealct.pdf");



 //  TArrow *ar4 = new TArrow(80,200,5,800,0.03,"|>");
 //  ar4->SetAngle(60);
 //  ar4->SetLineWidth(2);
 //  ar4->SetFillColor(2);
 //  ar4->Draw();



}
