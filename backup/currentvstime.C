{

   TCanvas *c1 = new TCanvas("trainingcurrent","rate vs dose",10,10,700,500);

   //TString extraText1   = "CSC ME1/1, nominal HV";
   //TString extraText2   = "CSC ME2/1, nominal HV";
   //TString date = "up to Apr. 7, 2017";
   //TLatex latex;
   //latex.SetNDC();
   //latex.SetTextFont(42);
   //latex.SetTextColor(kBlack);

   const int n1 = 4, n2 = 3, n3 = 1, n4 = 10;

   double I1[4] = {3, 1.2, 0.12, 0.1};
   double t1[4] = {0, 5, 10, 15};

   double I2[3] = {3, 1, 0.4};
   double t2[3] = {20, 25, 30};

   double I3[1] = {2};
   double t3[1] = {45};

   double I4[10] = {3, 5, 6, 10, 12, 15, 18, 20, 38, 40};
   double t4[10] = {47, 50, 52, 53, 54, 55, 56, 57, 65, 67};

   TGraph *gr11 = new TGraph(n1, t1, I1);
   TGraph *gr12 = new TGraph(n2, t2, I2);
   TGraph *gr13 = new TGraph(n3, t3, I3);
   TGraph *gr14 = new TGraph(n4, t4, I4);

   c1->cd();
   gr11->SetTitle("; time(mins, starting from 10:50 am); Current (uA)");
   gr11->SetMinimum(0);
   gr11->SetMaximum(50);
   gr11->SetMarkerColor(kRed);
   gr11->SetLineColor(kRed);
   gr11->SetMarkerStyle(22);
   gr11->SetMarkerSize(1.5);
   gr11->Draw("ALP");
   gr11->GetXaxis()->SetLimits(0, 70);
   gr11->Draw("ALP");
   //c1->Update();

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

   gr14->SetMarkerColor(9);
   gr14->SetLineColor(9);
   gr14->SetMarkerStyle(30);
   gr14->Draw("LP same");

   TLegend *leg1 = new TLegend(0.18, 0.5 ,0.58, 0.9, "ME1/1, with 10% CF4");
   leg1->AddEntry(gr11, "HV = 2.3 kV", "lp");
   leg1->AddEntry(gr12, "HV = 2.5 kV", "lp");
   leg1->AddEntry(gr13, "HV = 2.53 kV", "lp"); 
   leg1->AddEntry(gr14, "HV = 2.54 kV", "lp");
   leg1->SetBorderSize(0);
   leg1->Draw();

 
   c1->SaveAs("trainingcurrent.pdf");



 //  TArrow *ar4 = new TArrow(80,200,5,800,0.03,"|>");
 //  ar4->SetAngle(60);
 //  ar4->SetLineWidth(2);
 //  ar4->SetFillColor(2);
 //  ar4->Draw();



}
