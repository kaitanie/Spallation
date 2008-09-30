void plotCarbon() {
  Bool_t compareStoppint = false;
  Bool_t plotPrecoFermi = false;
  TFile *f0 = new TFile("resultsInclAblaWithFermi.root");
  TFile *f1 = new TFile("resultsInclAbla.root");
  TFile *f2 = new TFile("resultsBertini.root");
  if(plotPrecoFermi) {
    TFile *f4 = new TFile("resultsPrecoFermi.root");
  }
  if(compareStopping) {
    TFile *stop2f = new TFile("resultsInclAblaWithFermiStopAt2.root");
    TFile *stop5f = new TFile("resultsInclAblaWithFermiStopAt5.root");
    TFile *stop10f = new TFile("resultsInclAblaWithFermiStopAt10.root");
  }

  TH1F *chargenumbersInclAblaFermi = (TH1F *) f0->Get("chargenumbers");
  TH1F *massnumbersInclAblaFermi = (TH1F *) f0->Get("massnumbers");
  TH1F *hydrogenIsotopesInclAblaFermi = (TH1F *) f0->Get("hydrogenIsotopes");
  TH1F *heliumIsotopesInclAblaFermi = (TH1F *) f0->Get("heliumIsotopes");
  TH1F *lithiumIsotopesInclAblaFermi = (TH1F *) f0->Get("lithiumIsotopes");
  TH1F *berylliumIsotopesInclAblaFermi = (TH1F *) f0->Get("berylliumIsotopes");
  TH1F *boronIsotopesInclAblaFermi = (TH1F *) f0->Get("boronIsotopes");
  TH1F *carbonIsotopesInclAblaFermi = (TH1F *) f0->Get("carbonIsotopes");
  TH1F *nitrogenIsotopesInclAblaFermi = (TH1F *) f0->Get("nitrogenIsotopes");

  TH1F *chargenumbersInclAbla = (TH1F *) f1->Get("chargenumbers");
  chargenumbersInclAbla->SetLineColor(kRed);
  TH1F *massnumbersInclAbla = (TH1F *) f1->Get("massnumbers");
  massnumbersInclAbla->SetLineColor(kRed);
  TH1F *hydrogenIsotopesInclAbla = (TH1F *) f1->Get("hydrogenIsotopes");
  hydrogenIsotopesInclAbla->SetLineColor(kRed);
  TH1F *heliumIsotopesInclAbla = (TH1F *) f1->Get("heliumIsotopes");
  heliumIsotopesInclAbla->SetLineColor(kRed);
  TH1F *lithiumIsotopesInclAbla = (TH1F *) f1->Get("lithiumIsotopes");
  lithiumIsotopesInclAbla->SetLineColor(kRed);
  TH1F *berylliumIsotopesInclAbla = (TH1F *) f1->Get("berylliumIsotopes");
  berylliumIsotopesInclAbla->SetLineColor(kRed);
  TH1F *boronIsotopesInclAbla = (TH1F *) f1->Get("boronIsotopes");
  boronIsotopesInclAbla->SetLineColor(kRed);
  TH1F *carbonIsotopesInclAbla = (TH1F *) f1->Get("carbonIsotopes");
  carbonIsotopesInclAbla->SetLineColor(kRed);
  TH1F *nitrogenIsotopesInclAbla = (TH1F *) f1->Get("nitrogenIsotopes");
  nitrogenIsotopesInclAbla->SetLineColor(kRed);

  TH1F *chargenumbersBert = (TH1F *) f2->Get("chargenumbers");
  chargenumbersBert->SetLineColor(kGreen);
  TH1F *massnumbersBert = (TH1F *) f2->Get("massnumbers");
  massnumbersBert->SetLineColor(kGreen);
  TH1F *hydrogenIsotopesBert = (TH1F *) f2->Get("hydrogenIsotopes");
  hydrogenIsotopesBert->SetLineColor(kGreen);
  TH1F *heliumIsotopesBert = (TH1F *) f2->Get("heliumIsotopes");
  heliumIsotopesBert->SetLineColor(kGreen);
  TH1F *lithiumIsotopesBert = (TH1F *) f2->Get("lithiumIsotopes");
  lithiumIsotopesBert->SetLineColor(kGreen);
  TH1F *berylliumIsotopesBert = (TH1F *) f2->Get("berylliumIsotopes");
  berylliumIsotopesBert->SetLineColor(kGreen);
  TH1F *boronIsotopesBert = (TH1F *) f2->Get("boronIsotopes");
  boronIsotopesBert->SetLineColor(kGreen);
  TH1F *carbonIsotopesBert = (TH1F *) f2->Get("carbonIsotopes");
  carbonIsotopesBert->SetLineColor(kGreen);
  TH1F *nitrogenIsotopesBert = (TH1F *) f2->Get("nitrogenIsotopes");
  nitrogenIsotopesBert->SetLineColor(kGreen);

  if(plotPrecoFermi) {
    TH1F *chargenumbersPrecoFermi = (TH1F *) f2->Get("chargenumbers");
    chargenumbersPrecoFermi->SetLineColor(kBlue);
    TH1F *massnumbersPrecoFermi = (TH1F *) f2->Get("massnumbers");
    massnumbersPrecoFermi->SetLineColor(kBlue);
    TH1F *hydrogenIsotopesPrecoFermi = (TH1F *) f2->Get("hydrogenIsotopes");
    hydrogenIsotopesPrecoFermi->SetLineColor(kBlue);
    TH1F *heliumIsotopesPrecoFermi = (TH1F *) f2->Get("heliumIsotopes");
    heliumIsotopesPrecoFermi->SetLineColor(kBlue);
    TH1F *lithiumIsotopesPrecoFermi = (TH1F *) f2->Get("lithiumIsotopes");
    lithiumIsotopesPrecoFermi->SetLineColor(kBlue);
    TH1F *berylliumIsotopesPrecoFermi = (TH1F *) f2->Get("berylliumIsotopes");
    berylliumIsotopesPrecoFermi->SetLineColor(kBlue);
    TH1F *boronIsotopesPrecoFermi = (TH1F *) f2->Get("boronIsotopes");
    boronIsotopesPrecoFermi->SetLineColor(kBlue);
    TH1F *carbonIsotopesPrecoFermi = (TH1F *) f2->Get("carbonIsotopes");
    carbonIsotopesPrecoFermi->SetLineColor(kBlue);
    TH1F *nitrogenIsotopesPrecoFermi = (TH1F *) f2->Get("nitrogenIsotopes");
    nitrogenIsotopesPrecoFermi->SetLineColor(kBlue);
  }

  // Mass number distributions:
  TCanvas *c1 = new TCanvas();
  c1->SetLogy();
  massnumbersBert->Draw();
  massnumbersInclAblaFermi->Draw();
  massnumbersInclAbla->Draw("same");
  massnumbersBert->Draw("same");
  if(plotPrecoFermi) massnumbersPrecoFermi->Draw("same");
  plotExpA();

  TLegend *legend = new TLegend(0.7, 0.9, 0.9, 0.7);
  legend->AddEntry(massnumbersInclAbla, "INCL/ABLA", "l");
  legend->AddEntry(massnumbersInclAblaFermi, "INCL/ABLA with Fermi", "l");
  legend->AddEntry(massnumbersBert, "Geant4 Bertini", "l");
  if(plotPrecoFermi)  legend->AddEntry(massnumbersPrecoFermi, "G4 Preco + Fermi", "l");
  legend->Draw();
  c1->SaveAs("Proton1GeVCarbon.ps(");

  TCanvas *c12 = new TCanvas();
  c12->SetLogy();
  chargenumbersBert->Draw();
  chargenumbersInclAblaFermi->Draw();
  chargenumbersInclAbla->Draw("same");
  chargenumbersBert->Draw("same");
  if(plotPrecoFermi) chargenumbersPrecoFermi->Draw("same");
  plotExpZ();
  c12->SaveAs("Proton1GeVCarbon.ps");

  TCanvas *c2 = new TCanvas("c2");
  c2->Divide(3, 3);
  c2->cd(1);
  c2_1->SetLogy();
  hydrogenIsotopesInclAblaFermi->Draw();
  hydrogenIsotopesInclAbla->Draw("same");
  hydrogenIsotopesBert->Draw("same");
  if(plotPrecoFermi) hydrogenIsotopesPrecoFermi->Draw("same");
  plotExpPoint(1);

  c2->cd(2);
  c2_2->SetLogy();
  heliumIsotopesBert->Draw();
  heliumIsotopesInclAblaFermi->Draw("same");
  heliumIsotopesInclAbla->Draw("same");
  if(plotPrecoFermi) heliumIsotopesPrecoFermi->Draw("same");
  plotExpPoint(2);

  c2->cd(3);
  c2_3->SetLogy();
  lithiumIsotopesInclAbla->Draw();
  lithiumIsotopesInclAblaFermi->Draw("same");
  lithiumIsotopesBert->Draw("same");
  if(plotPrecoFermi) lithiumIsotopesPrecoFermi->Draw("same");
  plotExpPoint(3);

  c2->cd(4);
  c2_4->SetLogy();
  berylliumIsotopesBert->Draw();
  berylliumIsotopesInclAblaFermi->Draw("same");
  berylliumIsotopesInclAbla->Draw("same");
  if(plotPrecoFermi) berylliumIsotopesPrecoFermi->Draw("same");
  plotExpPoint(4);

  c2->cd(5);
  c2_5->SetLogy();
  boronIsotopesBert->Draw();
  boronIsotopesInclAblaFermi->Draw("same");
  boronIsotopesInclAbla->Draw("same");
  if(plotPrecoFermi) boronIsotopesPrecoFermi->Draw("same");
  plotExpPoint(5);

  c2->cd(6);
  c2_6->SetLogy();
  carbonIsotopesBert->Draw();
  carbonIsotopesInclAblaFermi->Draw("same");
  carbonIsotopesInclAbla->Draw("same");
  if(plotPrecoFermi) carbonIsotopesPrecoFermi->Draw("same");
  plotExpPoint(6);

  c2->cd(7);
  c2_7->SetLogy();
  nitrogenIsotopesInclAblaFermi->Draw();
  nitrogenIsotopesBert->Draw("same");
  nitrogenIsotopesInclAbla->Draw("same");
  if(plotPrecoFermi) nitrogenIsotopesPrecoFermi->Draw("same");
  plotExpPoint(7);
  c2->SaveAs("Proton1GeVCarbon.ps)");
}

void plotExpZ() {
  ifstream in("data/p1000MeVC/carbone.dat");
  Int_t A, Z;
  Float_t CX, error;
  Int_t foundIndex = 0;
  Int_t points = 0;
  const Int_t maxPoints = 100;
  Float_t graphZ[maxPoints], graphdZ[maxPoints],
    grapherror[maxPoints], graphCX[maxPoints];
  for(Int_t i = 0; i < maxPoints; i++) {
    graphZ[i] = 0;
    graphdZ[i] = 0;
    graphCX[i] = 0;
    grapherror[i] = 0;
  }
  while(1) {
    in >> Z >> A >> CX >> error;
    if(!in.good()) break;
    foundIndex = 0;
    if(points == 0) {
      points++;
      graphZ[points-1] = Z;
      graphCX[points-1] = CX;
    } else {
      for(Int_t i = 0; i < points; i++) {
	if(graphZ[i] == Z) {
	  graphCX[i] += CX;
	  foundIndex = 1;
	  break;
	}
      }
      if(foundIndex == 0) {
	points++;
	graphZ[points-1] = Z;
	graphCX[points-1] = CX;
	cout <<"Added A = " << Z << "  CX = " << CX << " points = " << points << endl;
	foundIndex = 1;
      }
    }
  }
  in.close();

  TGraphErrors* grexp160= new TGraphErrors(points, graphZ, graphCX, graphdZ, grapherror);
  grexp160->SetMarkerColor(4);
  grexp160->SetMarkerStyle(21);
  grexp160->SetMarkerSize(0.5);

  grexp160->Draw("PZ");
}

void plotExpA() {
  ifstream in("data/p1000MeVC/carbone.dat");
  Int_t A, Z;
  Float_t CX, error;
  Int_t foundIndex = 0;
  Int_t points = 0;
  const Int_t maxPoints = 100;
  Float_t graphA[maxPoints], graphdA[maxPoints],
    grapherror[maxPoints], graphCX[maxPoints];
  for(Int_t i = 0; i < maxPoints; i++) {
    graphA[i] = 0;
    graphdA[i] = 0;
    graphCX[i] = 0;
    grapherror[i] = 0;
  }
  while(1) {
    in >> Z >> A >> CX >> error;
    if(!in.good()) break;
    foundIndex = 0;
    if(points == 0) {
      points++;
      graphA[points-1] = A;
      graphCX[points-1] = CX;
    } else {
      for(Int_t i = 0; i < points; i++) {
	if(graphA[i] == A) {
	  graphCX[i] += CX;
	  foundIndex = 1;
	  break;
	}
      }
      if(foundIndex == 0) {
	points++;
	graphA[points-1] = A;
	graphCX[points-1] = CX;
	cout <<"Added Z = " << Z << "  CX = " << CX << " points = " << points << endl;
	foundIndex = 1;
      }
    }
  }
  in.close();

  TGraphErrors* grexp160= new TGraphErrors(points, graphA, graphCX, graphdA, grapherror);
  grexp160->SetMarkerColor(4);
  grexp160->SetMarkerStyle(21);
  grexp160->SetMarkerSize(0.5);

  grexp160->Draw("PZ");
}

void plotExpPoint(Int_t theZ) {
  ifstream in("data/p1000MeVC/carbone.dat");
  Int_t A, Z;
  Float_t CX, error;
  const Int_t maxPoints = 100;
  Float_t graphA[maxPoints], graphdA[maxPoints],
    grapherror[maxPoints], graphCX[maxPoints];
  Int_t i = 0;
  while(1) {
    in >> Z >> A >> CX >> error;
    if(!in.good()) break;
    if(Z == theZ) { // Add the relevant points to the graph.
      graphA[i] = A;
      graphCX[i] = CX;
      graphdA[i] = 0.0;
      grapherror[i] = error;
      i++;
    }
  }
  in.close();

  TGraphErrors* grexp160= new TGraphErrors(i, graphA, graphCX, graphdA, grapherror);
  grexp160->SetMarkerColor(4);
  grexp160->SetMarkerStyle(21);
  grexp160->SetMarkerSize(0.4);

  grexp160->Draw("PZ");
}
