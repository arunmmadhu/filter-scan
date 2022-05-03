void DrawHist()
{
  TFile *file1=new TFile("A8149.root");
  
  TH2D  * hists[2][6]; // first is just denoting 2 copies of same histogram with different binning, second is number of layers
  double averages[6];
  
  TString hname;
  
  for(int i=0; i<6;i++){
    hname=to_string(i);
    
    hists[0][i] = (TH2D*)file1->Get("2dRH/Chamber2RecHits["+hname+"]");
    hists[0][i]->GetXaxis()->SetTitle("x-coordinate (cm)");
    hists[0][i]->GetYaxis()->SetTitle("y-coordinate (cm)");
    
    hists[1][i] = (TH2D*)file1->Get("2dRH/Chamber2RecHits["+hname+"]");
    hists[1][i]->Rebin2D(5,5);
    hists[1][i]->GetXaxis()->SetTitle("x-coordinate (cm)");
    hists[1][i]->GetYaxis()->SetTitle("y-coordinate (cm)");
    
  }
  
  
  
  TH2D *hist7 = (TH2D*)file1->Get("2dRH/Chamber2LCTHits");
  hist7->GetXaxis()->SetTitle("WGN");
  hist7->GetYaxis()->SetTitle("Half-Strip No");
  hist7->SetTitle("LCT");
  
  /*
  for(int i=0; i<6;i++){
    int sum(0);
    double total(0.0);
    for(int j=10; j<18;j++){
      for(int k=7; k<40;k++){
        //hists[1][i]->SetBinContent(j,k,10,10);
        sum+=1;
        total+=hists[1][i]->GetBinContent(j,k);
      }
    }
    averages[i]=total/sum;
    std::cout<<averages[i]<<std::endl;
  }
  for(int i=0; i<6;i++){
    int sum(0);
    double total(0.0);
    for(int j=1; j<25;j++){
      for(int k=1; k<46;k++){
        if(hists[1][i]->GetBinContent(j,k)>1.0){
          hists[1][i]->SetBinContent(j,k,(hists[1][i]->GetBinContent(j,k))-averages[i]);
        }
      }
    }
  }
  */
  
  
  
  
  // Draw histograms with colz
  
  TCanvas *c1 = new TCanvas("c1","c1",1280,720);
  c1->Divide(3,2);
  
  for(int i=0; i<6;i++){
    c1->cd(i+1);
    hists[1][i]->Draw("COLZ1");
  }
  
  /*
  c1->cd(1);
  hists[0][0]->Draw("COLZ1");
  c1->cd(2);
  hists[0][1]->Draw("COLZ1");
  c1->cd(3);
  hists[0][2]->Draw("COLZ1");
  c1->cd(4);
  hists[0][3]->Draw("COLZ1");
  c1->cd(5);
  hists[0][4]->Draw("COLZ1");
  c1->cd(6);
  hists[0][5]->Draw("COLZ1");
  */
  
  c1->SaveAs("9.png");
  c1->Close();
  
  
  TCanvas *c2 = new TCanvas("c2","c2",720,720);
  c2->Divide(1,1);
  
  c2->cd(1);
  hist7->Draw("COLZ1");
  c2->SaveAs("10.png");
  c2->Close();
  

  
}