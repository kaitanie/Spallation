void plotPbProton1200() {
  TFile *dataincl = new TFile("resultsPbProton1200InclAbla.root");
  TFile *databert = new TFile("resultsPbProton1200Bertini.root");
  TH1F *neutronDD10 = (TH1F *) dataincl->Get("neutronDD10");
  TH1F *neutronDD10Lin = (TH1F *) dataincl->Get("neutronDD10Lin");
  TH1F *neutronDD25 = (TH1F *) dataincl->Get("neutronDD25");
  TH1F *neutronDD25Lin = (TH1F *) dataincl->Get("neutronDD25Lin");

  TH1F *neutronDD10bert = (TH1F *) databert->Get("neutronDD10");
  neutronDD10bert->SetLineColor(kGreen);
  TH1F *neutronDD10Linbert = (TH1F *) databert->Get("neutronDD10Lin");
  neutronDD10Linbert->SetLineColor(kGreen);
  TH1F *neutronDD25bert = (TH1F *) databert->Get("neutronDD25");
  neutronDD25bert->SetLineColor(kGreen);
  TH1F *neutronDD25Linbert = (TH1F *) databert->Get("neutronDD25Lin");
  neutronDD25Linbert->SetLineColor(kGreen);

  TCanvas *c1 = new TCanvas();
  c1->SetLogy();
  c1->SetLogx();
  neutronDD10->Draw();
  neutronDD10bert->Draw("same");
  plotExpTheta("p1200pb20_010", "./", 1.0);

  TCanvas *c2 = new TCanvas();
  c2->SetLogy();
  neutronDD10Lin->Draw();
  neutronDD10Linbert->Draw("same");
  plotExpTheta("p1200pb20_010", "./", 1.0);

  TCanvas *c3 = new TCanvas();
  c3->SetLogy();
  c3->SetLogx();
  neutronDD25->Draw();
  neutronDD25bert->Draw("same");
  plotExpTheta("p1200pb20_025", "./", 1.0);

  TCanvas *c4 = new TCanvas();
  c4->SetLogy();
  neutronDD25Lin->Draw();
  neutronDD25Linbert->Draw("same");
  plotExpTheta("p1200pb20_025", "./", 1.0);
}

void plotExpTheta(Char_t* file_name, Char_t* racine, Float_t fnor)
  // Read experimental data from file: file_name (in path: racine)

  // Cross sections and errors are multiplied by fnor and plotted in a
  // TGraphErrors
{
  // Experimental points
  Char_t toto[256];
  Int_t e;
  Float_t e_n[100];
  Float_t sig[100];
  Float_t dsig[100];
  Float_t de_n[100];
  Int_t c,iexp=0;

  //Concatenation Racine+File_Name
  e=sprintf(toto,"%s%s",racine,file_name);
  cout<<toto<<endl;

  FILE* fexp160 =  fopen(toto,"r");

  iexp=0;
  do {
    c=fscanf(fexp160,"%f %f %f %f ",&e_n[iexp],&de_n[iexp],&sig[iexp],&dsig[iexp]);
    if(c==EOF) break;
    sig[iexp]=fnor*sig[iexp];
    dsig[iexp]=fnor*dsig[iexp];
    cout<<e_n[iexp]<<"  "<<sig[iexp]<<"  "<<dsig[iexp]<<endl;
    iexp=iexp+1;
    if(iexp>100) cout<<"More experimental values than the dimension"<<endl;
  }
  while(1);

  TGraphErrors* grexp160= new TGraphErrors(iexp,e_n,sig,de_n,dsig);
  grexp160->SetMarkerColor(4);
  grexp160->SetMarkerStyle(21);
  grexp160->SetMarkerSize(0.4);

  grexp160->Draw("PZ");
  return;
}
