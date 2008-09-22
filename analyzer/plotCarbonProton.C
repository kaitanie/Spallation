void plotCarbon() {
TFile *f0 = new TFile("resultsInclAblaWithFermi.root");
TFile *f1 = new TFile("resultsInclAbla.root");
TFile *f2 = new TFile("resultsBertini.root");

TH1F *massnumbersInclAblaFermi = (TH1F *) f0->Get("massnumbers");
TH1F *hydrogenIsotopesInclAblaFermi = (TH1F *) f0->Get("hydrogenIsotopes");
TH1F *heliumIsotopesInclAblaFermi = (TH1F *) f0->Get("heliumIsotopes");
TH1F *lithiumIsotopesInclAblaFermi = (TH1F *) f0->Get("lithiumIsotopes");
TH1F *berylliumIsotopesInclAblaFermi = (TH1F *) f0->Get("berylliumIsotopes");
TH1F *boronIsotopesInclAblaFermi = (TH1F *) f0->Get("boronIsotopes");
TH1F *carbonIsotopesInclAblaFermi = (TH1F *) f0->Get("carbonIsotopes");
TH1F *nitrogenIsotopesInclAblaFermi = (TH1F *) f0->Get("nitrogenIsotopes");

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

// Mass number distributions:
 TCanvas *c1 = new TCanvas();
 c1->SetLogy();
 massnumbersBert->Draw();
 massnumbersInclAblaFermi->Draw();
 massnumbersInclAbla->Draw("same");
 massnumbersBert->Draw("same");

 TLegend *legend = new TLegend(0.7, 0.9, 0.9, 0.7);
 legend->AddEntry(massnumbersInclAbla, "INCL/ABLA", "l");
 legend->AddEntry(massnumbersInclAblaFermi, "INCL/ABLA with Fermi", "l");
 legend->AddEntry(massnumbersBert, "Geant4 Bertini", "l");
 legend->Draw();
 c1->SaveAs("Proton1GeVCarbon.ps(");

 TCanvas *c2 = new TCanvas("c2");
 c2->Divide(3, 3);
 c2->cd(1);
 c2_1->SetLogy();
 hydrogenIsotopesInclAblaFermi->Draw();
 hydrogenIsotopesInclAbla->Draw("same");
 hydrogenIsotopesBert->Draw("same");
 plotExpPoint(1);

 c2->cd(2);
 c2_2->SetLogy();
 heliumIsotopesBert->Draw();
 heliumIsotopesInclAblaFermi->Draw("same");
 heliumIsotopesInclAbla->Draw("same");
 plotExpPoint(2);

 c2->cd(3);
 c2_3->SetLogy();
 lithiumIsotopesInclAblaFermi->Draw();
 lithiumIsotopesBert->Draw("same");
 lithiumIsotopesInclAbla->Draw("same");
 plotExpPoint(3);

 c2->cd(4);
 c2_4->SetLogy();
 berylliumIsotopesBert->Draw();
 berylliumIsotopesInclAblaFermi->Draw("same");
 berylliumIsotopesInclAbla->Draw("same");
 plotExpPoint(4);

 c2->cd(5);
 c2_5->SetLogy();
 boronIsotopesBert->Draw();
 boronIsotopesInclAblaFermi->Draw("same");
 boronIsotopesInclAbla->Draw("same");
 plotExpPoint(5);

 c2->cd(6);
 c2_6->SetLogy();
 carbonIsotopesBert->Draw();
 carbonIsotopesInclAblaFermi->Draw("same");
 carbonIsotopesInclAbla->Draw("same");
 plotExpPoint(6);

 c2->cd(7);
 c2_7->SetLogy();
 nitrogenIsotopesInclAblaFermi->Draw();
 nitrogenIsotopesBert->Draw("same");
 nitrogenIsotopesInclAbla->Draw("same");
 plotExpPoint(7);
 c2->SaveAs("Proton1GeVCarbon.ps)");
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
