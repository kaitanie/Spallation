void plot(TH1F *h1 = 0, TH1D *h2 = 0, TH1D *h3 = 0)
{
  if(h1 != 0 && h2 != 0 && h3 == 0) {
    if(h2->GetMaximum() > h1->GetMaximum()) {
      if(h2 != 0) h2->Draw();
      if(h1 != 0) h1->Draw("same");
    } else {
      if(h1 != 0) h1->Draw();
      if(h2 != 0) h2->Draw("same");
    }
    if(h3 != 0) h3->Draw("same");
  } else if(h1 != 0 && h2 != 0 && h3 != 0) {
    if(h1->GetMaximum() > h2->GetMaximum() && h1->GetMaximum() > h3->GetMaximum()) {
      h1->Draw();
      h2->Draw("same");
      h3->Draw("same");
    } else if(h2->GetMaximum() > h1->GetMaximum() && h2->GetMaximum() > h3->GetMaximum()) {
      h2->Draw();
      h1->Draw("same");
      h3->Draw("same");
    } else if(h3->GetMaximum() > h1->GetMaximum() && h3->GetMaximum() > h2->GetMaximum()) {
      h3->Draw();
      h1->Draw("same");
      h2->Draw("same");
    }
  }
}

TH1F* refhist(TString name, TFile *f, EColor c)
{
  TH1F *h = (TH1F *) f->Get(name);
  h->SetLineColor(c);
  return h;
}

TH1D* g4hist(TString name, TFile *f, EColor c)
{
  TH1D *h = (TH1D *) f->Get(name);
  h->SetLineColor(c);
  return h;
}

TCanvas* newTCanvas() {
  TCanvas *tmpcanvas = new TCanvas();
  tmpcanvas->SetLogy(1);
//  tmpcanvas->SetLogx(1);
  return tmpcanvas;
}

void compare(){
  //  TFile *reff = new TFile("c400_c_i43_dres_fb.root");
  TFile *reff = new TFile("run45ref_neutrons_all.root");
  TFile *g4inclf = new TFile("resultsINCL_CC400MeV.root");
  TFile *g4bicf = new TFile("resultsBICIonCC_400MeV.root");
  //  TFile *g4inclf = new TFile("resultsINCL_ABLA_CC400MeV.root");
  //  TFile *g4inclf = new TFile("resultsBICIonCC_400MeV.root");
  
  TCanvas *c1 = newTCanvas();

  TH1F *r1 = refhist("h201", reff, kBlack);
  TH1D *i1 = g4hist("neutronDD2Lin", g4inclf, kRed);
  TH1D *b1 = g4hist("neutronDD2Lin", g4bicf, kBlue);
  plot(r1, i1, b1);
  c1->Print("comparison.ps(");

  TCanvas *c2 = newTCanvas();
  TH1F *r2 = refhist("h202", reff, kBlack);
  TH1D *i2 = g4hist("neutronDD10_5Lin", g4inclf, kRed);
  TH1D *b2 = g4hist("neutronDD10_5Lin", g4bicf, kBlue);
  plot(r2, i2, b2);
  c2->Print("comparison.ps");

  TCanvas *c3 = newTCanvas();
  TH1F *r3 = refhist("h203", reff, kBlack);
  TH1D *i3 = g4hist("neutronDD24_5Lin", g4inclf, kRed);
  TH1D *b3 = g4hist("neutronDD24_5Lin", g4bicf, kBlue);
  plot(r3, i3, b3);
  c3->Print("comparison.ps");

  TCanvas *c4 = newTCanvas();
  TH1F *r4 = refhist("h204", reff, kBlack);
  TH1D *i4 = g4hist("neutronDD41Lin", g4inclf, kRed);
  TH1D *b4 = g4hist("neutronDD41Lin", g4bicf, kBlue);
  plot(r4, i4, b4);
  c4->Print("comparison.ps");

  TCanvas *c5 = newTCanvas();
  TH1F *r5 = refhist("h205", reff, kBlack);
  TH1D *i5 = g4hist("neutronDD55Lin", g4inclf, kRed);
  TH1D *b5 = g4hist("neutronDD55Lin", g4bicf, kBlue);
  plot(r5, i5, b5);
  c5->Print("comparison.ps");

  TCanvas *c6 = newTCanvas();
  TH1F *r6 = refhist("h206", reff, kBlack);
  TH1D *i6 = g4hist("neutronDD71_5Lin", g4inclf, kRed);
  TH1D *b6 = g4hist("neutronDD71_5Lin", g4bicf, kBlue);
  plot(r6, i6, b6);
  c6->Print("comparison.ps");

  TCanvas *c7 = newTCanvas();
  TH1F *r7 = refhist("h207", reff, kBlack);
  TH1D *i7 = g4hist("neutronDD83_5Lin", g4inclf, kRed);
  TH1D *b7 = g4hist("neutronDD83_5Lin", g4bicf, kBlue);
  plot(r7, i7, b7);
  c7->Print("comparison.ps");

  TCanvas *c8 = newTCanvas();
  TH1F *r8 = refhist("h208", reff, kBlack);
  TH1D *i8 = g4hist("neutronDD99Lin", g4inclf, kRed);
  TH1D *b8 = g4hist("neutronDD99Lin", g4bicf, kBlue);
  plot(r8, i8, b8);
  c8->Print("comparison.ps");

  TCanvas *c9 = newTCanvas();
  TH1F *r9 = refhist("h209", reff, kBlack);
  TH1D *i9 = g4hist("neutronDD114Lin", g4inclf, kRed);
  TH1D *b9 = g4hist("neutronDD114Lin", g4bicf, kBlue);
  plot(r9, i9, b9);
  c9->Print("comparison.ps");

  TCanvas *c10 = newTCanvas();
  TH1F *r10 = refhist("h2010", reff, kBlack);
  TH1D *i10 = g4hist("neutronDD128_5Lin", g4inclf, kRed);
  TH1D *b10 = g4hist("neutronDD128_5Lin", g4bicf, kBlue);
  plot(r10, i10, b10);
  c10->Print("comparison.ps");

  TCanvas *c11 = newTCanvas();
  TH1F *r11 = refhist("h2011", reff, kBlack);
  TH1D *i11 = g4hist("neutronDD145Lin", g4inclf, kRed);
  TH1D *b11 = g4hist("neutronDD145Lin", g4bicf, kBlue);
  plot(r11, i11, b11);
  c11->Print("comparison.ps");

  TCanvas *c12 = newTCanvas();
  TH1F *r12 = refhist("h2012", reff, kBlack);
  TH1D *i12 = g4hist("neutronDD155_5Lin", g4inclf, kRed);
  TH1D *b12 = g4hist("neutronDD155_5Lin", g4bicf, kBlue);
  plot(r12, i12, b12);
  c12->Print("comparison.ps");

  TCanvas *c13 = newTCanvas();
  TH1F *r13 = refhist("h2000", reff, kBlack);
  TH1D *i13 = g4hist("neutronEnergyIntegrated", g4inclf, kRed);
  TH1D *b13 = g4hist("neutronEnergyIntegrated", g4bicf, kBlue);
  plot(r13, i13, b13);
  c13->Print("comparison.ps)");
}

