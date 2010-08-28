{
  gROOT->LoadMacro("../analysis/libAnalysis.C++");
  gROOT->LoadMacro("../analysis/libHEF.C++");

  HEF *hef = new HEF("ddxs.hef");
  hef->open();

  HistoFactory *hf = new HistoFactory();
  // Cross section 8.574241e+02 taken from Geant4:
  CalculationAnalysis *inclAnalysis = new CalculationAnalysis(hf, "INCL42",
							      "./inclion.root",
							      "data", 8.574241e+02,
							      100000);
  CalculationAnalysis *bicAnalysis = new CalculationAnalysis(hf, "G4BIC",
							     "./bic.root",
							     "data", 8.574241e+02,
							     100000);

  
  ViewManager *vm = new ViewManager(3,2);
  Double_t Emax = 1000.0;
  Double_t Emin = 1.0;
  Bool_t logE = true;
  TFile *outputHistos = TFile::Open("outputHistos.xml", "recreate");

  TH1D *htmp[7];
  TH1D *htmpBIC[7];

  htmp[0] = inclAnalysis->fillNeutronDoubleDiffXS(5.0, 2.0, logE, Emin, Emax);
  htmpBIC[0] = bicAnalysis->fillNeutronDoubleDiffXS(5.0, 2.0, logE, Emin, Emax);
  hef->writeHisto(htmp[0]);
  hef->writeHisto(htmpBIC[0]);
  vm->plot(htmp[0]);
  vm->plot(htmpBIC[0], true);

  htmp[1] = inclAnalysis->fillNeutronDoubleDiffXS(10.0, 2.0, logE, Emin, Emax);
  htmpBIC[1] = bicAnalysis->fillNeutronDoubleDiffXS(10.0, 2.0, logE, Emin, Emax);
  hef->writeHisto(htmp[1]);
  hef->writeHisto(htmpBIC[1]);
  vm->plot(htmp[1]);
  vm->plot(htmpBIC[1], true);

  htmp[2] = inclAnalysis->fillNeutronDoubleDiffXS(20.0, 2.0, logE, Emin, Emax);
  htmpBIC[2] = bicAnalysis->fillNeutronDoubleDiffXS(20.0, 2.0, logE, Emin, Emax);
  hef->writeHisto(htmp[2]);
  hef->writeHisto(htmpBIC[2]);
  vm->plot(htmp[2]);
  vm->plot(htmpBIC[2], true);

  htmp[3] = inclAnalysis->fillNeutronDoubleDiffXS(30.0, 2.0, logE, Emin, Emax);
  htmpBIC[3] = bicAnalysis->fillNeutronDoubleDiffXS(30.0, 2.0, logE, Emin, Emax);
  hef->writeHisto(htmp[3]);
  hef->writeHisto(htmpBIC[3]);
  vm->plot(htmp[3]);
  vm->plot(htmpBIC[3], true);


  htmp[4] = inclAnalysis->fillNeutronDoubleDiffXS(40.0, 2.0, logE, Emin, Emax);
  htmpBIC[4] = bicAnalysis->fillNeutronDoubleDiffXS(40.0, 2.0, logE, Emin, Emax);
  hef->writeHisto(htmp[4]);
  hef->writeHisto(htmpBIC[4]);
  vm->plot(htmp[4]);
  vm->plot(htmpBIC[4], true);

  htmp[5] = inclAnalysis->fillNeutronDoubleDiffXS(60.0, 2.0, logE, Emin, Emax);
  htmpBIC[5] = bicAnalysis->fillNeutronDoubleDiffXS(60.0, 2.0, logE, Emin, Emax);
  hef->writeHisto(htmp[5]);
  hef->writeHisto(htmpBIC[5]);
  vm->plot(htmp[5]);
  vm->plot(htmpBIC[5], true);

  htmp[6] = inclAnalysis->fillNeutronDoubleDiffXS(80.0, 2.0, logE, Emin, Emax);
  htmpBIC[6] = bicAnalysis->fillNeutronDoubleDiffXS(80.0, 2.0, logE, Emin, Emax);
  hef->writeHisto(htmp[6]);
  hef->writeHisto(htmpBIC[6]);
  vm->plot(htmp[6]);
  vm->plot(htmpBIC[6], true);

  for(int i = 0; i < 7; ++i) {
    htmp[i]->Write();
    htmpBIC[i]->Write();
  }

  outputHistos->Write();
  outputHistos->Close();
  hef->close();
  delete hef;
}
