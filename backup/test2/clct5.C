void clct5() {

   TCanvas *c1 = new TCanvas("me11clct5","clct rate vs dose",10,10,600,600);

   const int n1 = 23;

   double charge1[n1] = {1.92, 9.31, 15.85, 15.86, 21.59, 27.48, 27.54, 28.29, 29.63, 31.38, 32.44, 32.93, 33.88, 35.10, 41.86, 48.44, 55.30, 61.30, 66.09, 68.80, 76.03, 90.26, 95.75};

   double clct1[n1] = {175.1, 115.4, 211.6, 165.0, 110.9, 163.8, 112.0, 137.4, 189.1, 99.2, 81.3, 80.4, 105.2, 112.9, 230.5, 182.9, 87.2, 74.2, 126.1, 100.2, 10.3, 7.7, 9.5};


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
   leg1->AddEntry(gr11, "CLCT6 Rate", "apl");
   leg1->SetBorderSize(0);
   leg1->Draw();


   TF1 *f1 = new TF1("f1", "[0]", 0., 70.);
   gr11->Fit("f1", "R");
   cout << f1->GetParameter(0) << endl;;
   f1->Draw("same");


   c1->SaveAs("me11clct5.pdf");

}
