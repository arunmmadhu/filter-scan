void clct1() {

   TCanvas *c1 = new TCanvas("me11clct1","clct rate vs dose",10,10,600,600);

   const int n1 = 23;

   double charge1[n1] = {1.92, 9.31, 15.85, 15.86, 21.59, 27.48, 27.54, 28.29, 29.63, 31.38, 32.44, 32.93, 33.88, 35.10, 41.86, 48.44, 55.30, 61.30, 66.09, 68.80, 76.03, 90.26, 95.75};

   double clct1[n1] = {196.5, 174.6, 183.0, 165.9, 160.1, 159.3, 164.8, 154.9, 163.8, 166.0, 164.0, 160.8, 160.3, 155.9, 162.7, 173.6, 172.8, 31.9, 29.6, 154.6, 179.6, 163.0, 171.5};


   TGraph *gr11 = new TGraph(n1, charge1, clct1);


   c1->cd();
   gr11->SetTitle("; Accumulated charge [mC/cm]; Dark rate [Hz]");
   gr11->SetMinimum(0);
   gr11->SetMaximum(300);
   gr11->GetYaxis()->SetTitleOffset(1.50);
   //TGaxis *a = (TGaxis*)gr11->GetYaxis();
   //a->SetMaxDigits(2);
   gr11->SetMarkerColor(kBlue);
   gr11->SetLineColor(kBlue);
   gr11->SetMarkerStyle(22);
   gr11->SetMarkerSize(1.5);
   gr11->Draw("APL");


   TLegend *leg1 = new TLegend(0.55, 0.68 ,0.88, 0.88, "ME1/1");
   leg1->AddEntry(gr11, "CLCT2 Rate", "apl");
   leg1->SetBorderSize(0);   
leg1->Draw();


   //TF1 *f1 = new TF1("f1", "[0]", 0., 100.);
   //gr11->Fit("f1", "R");
   //cout << f1->GetParameter(0) << endl;;
   //f1->Draw("same");


   c1->SaveAs("me11clct1.pdf");

}
