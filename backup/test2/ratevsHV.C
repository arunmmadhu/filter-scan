{

   TCanvas *c1 = new TCanvas("me11ratevsHV_alct","rate vs dose",10,10,600,600);
   TCanvas *c2 = new TCanvas("me11ratevsHV_clct","rate vs does",10,10,600,600);
   TCanvas *c3 = new TCanvas("me11ratevsHV_tmb","rate vs does",10,10,600,600);
   TCanvas *c4 = new TCanvas("me21ratevsHV_alct","rate vs dose",10,10,600,600);
   TCanvas *c5 = new TCanvas("me21ratevsHV_clct","rate vs does",10,10,600,600);
   TCanvas *c6 = new TCanvas("me21ratevsHV_tmb","rate vs does",10,10,600,600);


   //TString extraText1   = "CSC ME1/1, nominal HV";
   //TString extraText2   = "CSC ME2/1, nominal HV";
   //TString date = "up to Apr. 7, 2017";
   //TLatex latex;
   //latex.SetNDC();
   //latex.SetTextFont(42);
   //latex.SetTextColor(kBlack);


   double voltage1_b[8] = {2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 2.95};
   double alct1_b[8] = {209.2, 338.6, 508.9, 653.6, 737.7, 761.8, 845.7, 885.3};
   double clct1_b[8] = {64.2*1.5, 99.5*1.5, 167.9*1.5, 255.2*1.5, 376.2*1.5, 460.7*1.5, 498.5*1.5, 426.9*1.5};
   double tmb1_b[8] =  {32.0*1.5, 66.0*1.5, 131.6*1.5, 222.7*1.5, 336.3*1.5, 425.0*1.5, 463.1*1.5, 392.8*1.5};

   double voltage1_a[10] = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 2.95};
   double alct1_a[10] = {44.8, 109.7, 190.0, 317.6, 452.9, 623.3, 686.7, 783.2, 1505.3, 2713.9};
   double clct1_a[10] = {374.7, 293.2, 320.4, 364.7, 443.5, 562.5, 686.8, 810.3, 1111.5, 1959.5};
   double tmb1_a[10] =  {1.2, 6.4, 30.9, 77.5, 153.9, 269.6, 400.4, 531.0, 816.2, 1668.8};


   double voltage2_b[11] = {2.8, 2.9, 3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8};
   double alct2_b[11] =   {201.6, 421.5, 726.8, 1144.0, 1592.3, 2046.8, 2328.7, 2540.5, 2635.7, 2898.0, 4573.9};
   double clct2_b[11] =   {46.1*2, 125.0*2, 232.8*2, 393.3*2, 583.6*2, 805.7*2, 961.8*2, 1067.6*2, 1102.8*2, 1210.6*2, 1639.7*2};
   double tmb2_b[11] =    {38.7*2, 115.2*2, 218.1*2, 378.1*2, 566.4*2, 792.8*2, 954.2*2, 1058.2*2, 1078.4*2, 1098.8*2, 1220.9*2};

   double voltage2_a[12] = {2.7, 2.8, 2.9, 3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8};
   double alct2_a[12] =   {67.2, 224.8, 463.6, 767.4, 1173.2, 1636.1, 2069.9, 2350.6, 2444.3, 2544.3, 2814.1, 4032.9};
   double clct2_a[12] =   {11.7, 72.2, 209.2, 383.2, 629.8, 977.7, 1321.7, 1655.2, 1827.3, 1907.1, 2014.0, 2578.6};
   double tmb2_a[12] =    {7.7, 61.4, 194.9, 365.0, 609.6, 946.6, 1301.0, 1639.1, 1809.8, 1866.5, 1851.3, 1993.4};

   TGraph *gralct1_b = new TGraph(8, voltage1_b, alct1_b);
   TGraph *gralct1_a = new TGraph(10, voltage1_a, alct1_a);

   TGraph *grclct1_b = new TGraph(8, voltage1_b, clct1_b);
   TGraph *grclct1_a = new TGraph(10, voltage1_a, clct1_a);

   TGraph *grtmb1_b = new TGraph(8, voltage1_b, tmb1_b);
   TGraph *grtmb1_a = new TGraph(10, voltage1_a, tmb1_a);

   TGraph *gralct2_b = new TGraph(11, voltage2_b, alct2_b);
   TGraph *gralct2_a = new TGraph(12, voltage2_a, alct2_a);

   TGraph *grclct2_b = new TGraph(11, voltage2_b, clct2_b);
   TGraph *grclct2_a = new TGraph(12, voltage2_a, clct2_a);

   TGraph *grtmb2_b = new TGraph(11, voltage2_b, tmb2_b);
   TGraph *grtmb2_a = new TGraph(12, voltage2_a, tmb2_a);


   c1->cd();
   gralct1_a->SetTitle("; High voltage [mC/cm]; Dark alct rate [Hz]");
   gralct1_a->SetMinimum(0);
   gralct1_a->SetMarkerColor(kRed);
   gralct1_a->SetMarkerStyle(22);
   gralct1_a->SetMarkerSize(1.5);
   gralct1_a->Draw("AP");

   gralct1_b->SetMarkerColor(kBlue);
   gralct1_b->SetMarkerStyle(23);
   gralct1_b->SetMarkerSize(1.5);
   gralct1_b->Draw("P same");

   TLegend *leg1 = new TLegend(0.18, 0.68 ,0.48, 0.88, "ME1/1");
   leg1->AddEntry(gralct1_a, "After irradiation", "p");
   leg1->AddEntry(gralct1_b, "Before irradiation", "p");
   leg1->SetBorderSize(0);
   leg1->Draw();

   c2->cd();
   grclct1_a->SetTitle("; High voltage [mC/cm]; Dark clct rate [Hz]");
   grclct1_a->SetMinimum(0);
   grclct1_a->SetMarkerColor(kRed);
   grclct1_a->SetMarkerStyle(22);
   grclct1_a->SetMarkerSize(1.5);
   grclct1_a->Draw("AP");

   grclct1_b->SetMarkerColor(kBlue);
   grclct1_b->SetMarkerStyle(23);
   grclct1_b->SetMarkerSize(1.5);
   grclct1_b->Draw("P same");

   TLegend *leg2 = new TLegend(0.18, 0.68 ,0.48, 0.88, "ME1/1");
   leg2->AddEntry(grclct1_a, "After irradiation", "p");
   leg2->AddEntry(grclct1_b, "Before irradiation", "p");
   leg2->SetBorderSize(0);
   leg2->Draw();

   c3->cd();
   grtmb1_a->SetTitle("; High voltage [mC/cm]; Dark tmb rate [Hz]");
   grtmb1_a->SetMinimum(0);
   grtmb1_a->SetMarkerColor(kRed);
   grtmb1_a->SetMarkerStyle(22);
   grtmb1_a->SetMarkerSize(1.5);
   grtmb1_a->Draw("AP");

   grtmb1_b->SetMarkerColor(kBlue);
   grtmb1_b->SetMarkerStyle(23);
   grtmb1_b->SetMarkerSize(1.5);
   grtmb1_b->Draw("P same");

   TLegend *leg3 = new TLegend(0.18, 0.68 ,0.48, 0.88, "ME1/1");
   leg3->AddEntry(grtmb1_a, "After irradiation", "p");
   leg3->AddEntry(grtmb1_b, "Before irradiation", "p");
   leg3->SetBorderSize(0);
   leg3->Draw();




   c4->cd();
   gralct2_a->SetTitle("; High voltage [mC/cm]; Dark alct rate [Hz]");
   gralct2_a->SetMaximum(4600);
   gralct2_a->SetMarkerColor(kRed);
   gralct2_a->SetMarkerStyle(22);
   gralct2_a->SetMarkerSize(1.5);
   gralct2_a->Draw("AP");

   gralct2_b->SetMarkerColor(kBlue);
   gralct2_b->SetMarkerStyle(23);
   gralct2_b->SetMarkerSize(1.5);
   gralct2_b->Draw("P same");

   TLegend *leg4 = new TLegend(0.18, 0.68 ,0.48, 0.88, "ME2/1");
   leg4->AddEntry(gralct2_a, "After irradiation", "p");
   leg4->AddEntry(gralct2_b, "Before irradiation", "p");
   leg4->SetBorderSize(0);
   leg4->Draw();

   c5->cd();
   grclct2_a->SetTitle("; High voltage [mC/cm]; Dark clct rate [Hz]");
   grclct2_a->SetMarkerColor(kRed);
   grclct2_a->SetMarkerStyle(22);
   grclct2_a->SetMarkerSize(1.5);
   grclct2_a->Draw("AP");

   grclct2_b->SetMarkerColor(kBlue);
   grclct2_b->SetMarkerStyle(23);
   grclct2_b->SetMarkerSize(1.5);
   grclct2_b->Draw("P same");

   TLegend *leg5 = new TLegend(0.18, 0.68 ,0.48, 0.88, "ME2/1");
   leg5->AddEntry(grclct2_a, "After irradiation", "p");
   leg5->AddEntry(grclct2_b, "Before irradiation", "p");
   leg5->SetBorderSize(0);
   leg5->Draw();

   c6->cd();
   grtmb2_a->SetTitle("; High voltage [mC/cm]; Dark tmb rate [Hz]");
   grtmb2_a->SetMarkerColor(kRed);
   grtmb2_a->SetMarkerStyle(22);
   grtmb2_a->SetMarkerSize(1.5);
   grtmb2_a->Draw("AP");

   grtmb2_b->SetMarkerColor(kBlue);
   grtmb2_b->SetMarkerStyle(23);
   grtmb2_b->SetMarkerSize(1.5);
   grtmb2_b->Draw("P same");

   TLegend *leg6 = new TLegend(0.18, 0.68 ,0.48, 0.88, "ME2/1");
   leg6->AddEntry(grtmb2_a, "After irradiation", "p");
   leg6->AddEntry(grtmb2_b, "Before irradiation", "p");
   leg6->SetBorderSize(0);
   leg6->Draw();







   c1->SaveAs("me11ratevsHV_alct.pdf");
   c2->SaveAs("me11ratevsHV_clct.pdf");
   c3->SaveAs("me11ratevsHV_tmb.pdf");
   c4->SaveAs("me21ratevsHV_alct.pdf");
   c5->SaveAs("me21ratevsHV_clct.pdf");
   c6->SaveAs("me21ratevsHV_tmb.pdf");


}
