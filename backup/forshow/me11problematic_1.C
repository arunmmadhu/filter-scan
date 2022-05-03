void ratevsproblem()
{
//=========Macro generated from canvas: ratevsproblem/rate vs problem
//=========  (Thu Oct 26 12:15:33 2017) by ROOT version6.02/10
   TCanvas *ratevsproblem = new TCanvas("ratevsproblem", "rate vs problem",1038,369,600,602);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   ratevsproblem->Range(-72.63219,-0.003786194,381.319,0.02533838);
   ratevsproblem->SetFillColor(0);
   ratevsproblem->SetBorderMode(0);
   ratevsproblem->SetBorderSize(2);
   ratevsproblem->SetTickx(1);
   ratevsproblem->SetTicky(1);
   ratevsproblem->SetLeftMargin(0.16);
   ratevsproblem->SetRightMargin(0.02);
   ratevsproblem->SetTopMargin(0.05);
   ratevsproblem->SetBottomMargin(0.13);
   ratevsproblem->SetFrameFillStyle(0);
   ratevsproblem->SetFrameBorderMode(0);
   ratevsproblem->SetFrameFillStyle(0);
   ratevsproblem->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1[44] = {
   17.6,
   25.5,
   33.1,
   40.9,
   51.2,
   59.38,
   63.97,
   77.94,
   89.81,
   95.44,
   104.24,
   113.27,
   120.9,
   135.62,
   142.4,
   152.13,
   154.42,
   154.58,
   156.55,
   163.68,
   171.28,
   180.46,
   186.99,
   193.55,
   200.14,
   207.45,
   214.78,
   222.52,
   228.59,
   235.27,
   241.72,
   250.86,
   256.42,
   271.28,
   277.37,
   279.95,
   287.51,
   297.54,
   305.82,
   314.79,
   316.29,
   316.67,
   324.07,
   340};
   Double_t Graph0_fy1[44] = {
   0.0001062581,
   0.00011865,
   5.2304e-05,
   0.0001736865,
   0.000131051,
   0.0001175878,
   5.840171e-05,
   0.0003519145,
   0.0004271639,
   0.0006866126,
   0.001546332,
   0.001547412,
   0.001151898,
   0.0005939942,
   0.002803539,
   0.002652112,
   0.001398457,
   0.001744453,
   0.000482539,
   0.006490253,
   0.003494231,
   0.006109568,
   0.009463983,
   0.005038326,
   0.004311398,
   0.004387624,
   0.004459587,
   0.005843096,
   0.007313027,
   0.006674027,
   0.005802442,
   0.005489995,
   0.01158099,
   0.008542106,
   0.01375529,
   0.01020715,
   0.01436114,
   0.01448145,
   0.01805482,
   0.01745927,
   0.01730394,
   0.0217158,
   0.01820871,
   0.01551777};
   TGraph *graph = new TGraph(44,Graph0_fx1,Graph0_fy1);
   graph->SetName("Graph0");
   graph->SetTitle("; Accumulated charge [mC/cm]; Normalized dark rate [Hz/cm]");
   graph->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(22);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,0,372.24);
   Graph_Graph1->SetMinimum(0);
   Graph_Graph1->SetMaximum(0.02388215);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);
   Graph_Graph1->SetLineStyle(0);
   Graph_Graph1->SetMarkerStyle(20);
   Graph_Graph1->GetXaxis()->SetTitle(" Accumulated charge [mC/cm]");
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetTitle(" Normalized dark rate [Hz/cm]");
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1->GetYaxis()->SetTitleOffset(1.41);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   graph->Draw("apl");
   
   Double_t Graph1_fx2[44] = {
   17.6,
   25.5,
   33.1,
   40.9,
   51.2,
   59.38,
   63.97,
   77.94,
   89.81,
   95.44,
   104.24,
   113.27,
   120.9,
   135.62,
   142.4,
   152.13,
   154.42,
   154.58,
   156.55,
   163.68,
   171.28,
   180.46,
   186.99,
   193.55,
   200.14,
   207.45,
   214.78,
   222.52,
   228.59,
   235.27,
   241.72,
   250.86,
   256.42,
   271.28,
   277.37,
   279.95,
   287.51,
   297.54,
   305.82,
   314.79,
   316.29,
   316.67,
   324.07,
   340};
   Double_t Graph1_fy2[44] = {
   0.0001541141,
   0.000111315,
   9.518575e-05,
   0.0002475807,
   0.0001264287,
   0.0001089787,
   2.396855e-05,
   0.0001303098,
   0.0001146759,
   9.179934e-05,
   0.0001139284,
   0.0001246004,
   0.0001184435,
   9.458799e-05,
   0.0001054216,
   9.915431e-05,
   0.0001113107,
   0.0001189908,
   7.437811e-05,
   8.278327e-05,
   0.0001091447,
   0.0001101643,
   7.829553e-05,
   9.603153e-05,
   9.202625e-05,
   0.0001099664,
   8.677653e-05,
   0.0001059153,
   7.610436e-05,
   9.66564e-05,
   0.0001566319,
   9.648693e-05,
   9.161518e-05,
   8.942546e-05,
   5.592273e-05,
   0.0001052138,
   5.621311e-05,
   6.981026e-05,
   5.744952e-05,
   5.22641e-05,
   5.534141e-05,
   4.849353e-05,
   6.08209e-05,
   6.335627e-05};
   graph = new TGraph(44,Graph1_fx2,Graph1_fy2);
   graph->SetName("Graph1");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#00ff00");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#00ff00");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(22);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Graph",100,0,372.24);
   Graph_Graph2->SetMinimum(1.607339e-06);
   Graph_Graph2->SetMaximum(0.0002699419);
   Graph_Graph2->SetDirectory(0);
   Graph_Graph2->SetStats(0);
   Graph_Graph2->SetLineStyle(0);
   Graph_Graph2->SetMarkerStyle(20);
   Graph_Graph2->GetXaxis()->SetLabelFont(42);
   Graph_Graph2->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph2->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph2->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph2->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph2->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph2->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph2->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph2->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph2->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph2);
   
   graph->Draw("pl ");
   
   Double_t Graph2_fx3[44] = {
   17.6,
   25.5,
   33.1,
   40.9,
   51.2,
   59.38,
   63.97,
   77.94,
   89.81,
   95.44,
   104.24,
   113.27,
   120.9,
   135.62,
   142.4,
   152.13,
   154.42,
   154.58,
   156.55,
   163.68,
   171.28,
   180.46,
   186.99,
   193.55,
   200.14,
   207.45,
   214.78,
   222.52,
   228.59,
   235.27,
   241.72,
   250.86,
   256.42,
   271.28,
   277.37,
   279.95,
   287.51,
   297.54,
   305.82,
   314.79,
   316.29,
   316.67,
   324.07,
   340};
   Double_t Graph2_fy3[44] = {
   0.0001400133,
   0.0001386195,
   5.956008e-05,
   0.0001750282,
   0.0001702995,
   0.0001983086,
   2.768726e-05,
   0.0002470049,
   0.0003370222,
   0.0003841339,
   0.0004701146,
   0.0007887728,
   0.0007523964,
   0.0008283081,
   0.0006883217,
   0.000171885,
   0.0002482257,
   0.0002072983,
   0.0001706283,
   0.0003500466,
   0.0004770265,
   0.000497579,
   0.0005714632,
   0.0002013083,
   0.0003488754,
   0.0003848191,
   0.0004967694,
   0.0007025833,
   0.0006385985,
   0.0006740054,
   0.0008401532,
   0.0007893085,
   0.0001130085,
   0.0006066596,
   0.0002966522,
   0.0004331621,
   0.0003901483,
   0.0004071594,
   0.0004309216,
   0.0003863962,
   0.0005222157,
   6.747084e-05,
   0.0003861721,
   9.455296e-05};
   graph = new TGraph(44,Graph2_fx3,Graph2_fy3);
   graph->SetName("Graph2");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#ff0000");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3 = new TH1F("Graph_Graph3","Graph",100,0,372.24);
   Graph_Graph3->SetMinimum(0);
   Graph_Graph3->SetMaximum(0.0009213998);
   Graph_Graph3->SetDirectory(0);
   Graph_Graph3->SetStats(0);
   Graph_Graph3->SetLineStyle(0);
   Graph_Graph3->SetMarkerStyle(20);
   Graph_Graph3->GetXaxis()->SetLabelFont(42);
   Graph_Graph3->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph3->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph3->GetXaxis()->SetTitleFont(42);
   Graph_Graph3->GetYaxis()->SetLabelFont(42);
   Graph_Graph3->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph3->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph3->GetYaxis()->SetTitleFont(42);
   Graph_Graph3->GetZaxis()->SetLabelFont(42);
   Graph_Graph3->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph3->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph3);
   
   graph->Draw("pl ");
   
   Double_t Graph3_fx4[44] = {
   17.6,
   25.5,
   33.1,
   40.9,
   51.2,
   59.38,
   63.97,
   77.94,
   89.81,
   95.44,
   104.24,
   113.27,
   120.9,
   135.62,
   142.4,
   152.13,
   154.42,
   154.58,
   156.55,
   163.68,
   171.28,
   180.46,
   186.99,
   193.55,
   200.14,
   207.45,
   214.78,
   222.52,
   228.59,
   235.27,
   241.72,
   250.86,
   256.42,
   271.28,
   277.37,
   279.95,
   287.51,
   297.54,
   305.82,
   314.79,
   316.29,
   316.67,
   324.07,
   340};
   Double_t Graph3_fy4[44] = {
   0.000111005,
   0.000150243,
   4.578935e-05,
   0.0001209151,
   0.0001503276,
   0.0001368825,
   2.060102e-05,
   0.0001378154,
   0.00010311,
   0.0001041907,
   0.0001357722,
   0.0001016949,
   0.0001036579,
   0.000118247,
   0.0001010048,
   0.0001109755,
   0.0001486304,
   9.997402e-05,
   9.098377e-05,
   0.0001241583,
   0.0001050606,
   0.0001192191,
   0.0001028285,
   9.319794e-05,
   9.062423e-05,
   0.0001402187,
   0.0001287945,
   0.0001042804,
   0.0001100613,
   7.594853e-05,
   0.0001005447,
   8.533331e-05,
   7.290673e-05,
   9.615451e-05,
   4.458108e-05,
   0.0001369771,
   7.656114e-05,
   5.536798e-05,
   6.93311e-05,
   6.182533e-05,
   5.437421e-05,
   5.039748e-05,
   5.09886e-05,
   6.662094e-05};
   graph = new TGraph(44,Graph3_fx4,Graph3_fy4);
   graph->SetName("Graph3");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#00ff00");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#00ff00");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph4 = new TH1F("Graph_Graph4","Graph",100,0,372.24);
   Graph_Graph4->SetMinimum(7.628362e-06);
   Graph_Graph4->SetMaximum(0.0001633002);
   Graph_Graph4->SetDirectory(0);
   Graph_Graph4->SetStats(0);
   Graph_Graph4->SetLineStyle(0);
   Graph_Graph4->SetMarkerStyle(20);
   Graph_Graph4->GetXaxis()->SetLabelFont(42);
   Graph_Graph4->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph4->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph4->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph4->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph4->GetXaxis()->SetTitleFont(42);
   Graph_Graph4->GetYaxis()->SetLabelFont(42);
   Graph_Graph4->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph4->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph4->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph4->GetYaxis()->SetTitleOffset(1.25);
   Graph_Graph4->GetYaxis()->SetTitleFont(42);
   Graph_Graph4->GetZaxis()->SetLabelFont(42);
   Graph_Graph4->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph4->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph4->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph4->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph4);
   
   graph->Draw("pl ");
   
   TLegend *leg = new TLegend(0.1996644,0.5122378,0.6744966,0.8811189,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("NULL","ME1/1","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph2","bad WG in L4","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph3","normal WG in L4","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#00ff00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph0","bad WG in L5","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph1","normal WG in L5","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#00ff00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
   ratevsproblem->Modified();
   ratevsproblem->cd();
   ratevsproblem->SetSelected(ratevsproblem);
}
