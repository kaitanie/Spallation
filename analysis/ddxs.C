{
  gROOT->LoadMacro("libAnalysis.C++");
  gROOT->LoadMacro("libHEF.C++");

  HEF *hef = new HEF("ddxs.hef");
  hef->open();

  HistoFactory *hf = new HistoFactory();
  // Cross section 1.025181e+03 taken from Geant4
  CalculationAnalysis *inclAnalysis = new CalculationAnalysis(hf, "INCL42",
							      "../c_c_290/inclion.root",
							      "data", 9.009522e+02,
							      100000);
  CalculationAnalysis *bicAnalysis = new CalculationAnalysis(hf, "G4BIC",
							     "../c_c_290/bic.root",
							     "data", 9.009522e+02,
							     100000);

  
  ViewManager *vm = new ViewManager(3,2);
  Double_t Emax = 1000.0;
  Double_t Emin = 1.0;
  Bool_t logE = true;
  TFile *outputHistos = new TFile("outpuHistos.root", "RECREATE");

  TH1D *htmp[6];
  htmp[0] = inclAnalysis->fillNeutronDoubleDiffXS(1.0, 1.0, logE, Emin, Emax);
  hef->writeHisto(htmp[0]);
  vm->plot(htmp[0]);
  vm->plot(bicAnalysis->fillNeutronDoubleDiffXS(1.0, 1.0, logE, Emin, Emax), true);

  htmp[1] = inclAnalysis->fillNeutronDoubleDiffXS(15.0, 2.0, logE, Emin, Emax);
  hef->writeHisto(htmp[1]);
  vm->plot(htmp[1]);
  vm->plot(bicAnalysis->fillNeutronDoubleDiffXS(15.0, 2.0, logE, Emin, Emax), true);

  htmp[2] = inclAnalysis->fillNeutronDoubleDiffXS(30.0, 2.0, logE, Emin, Emax);
  hef->writeHisto(htmp[2]);
  vm->plot(htmp[2]);
  vm->plot(bicAnalysis->fillNeutronDoubleDiffXS(30.0, 2.0, logE, Emin, Emax), true);

  htmp[3] = inclAnalysis->fillNeutronDoubleDiffXS(50.0, 2.0, logE, Emin, Emax);
  hef->writeHisto(htmp[3]);
  vm->plot(htmp[3]);
  vm->plot(bicAnalysis->fillNeutronDoubleDiffXS(50.0, 2.0, logE, Emin, Emax), true);

  htmp[4] = inclAnalysis->fillNeutronDoubleDiffXS(80.0, 2.0, logE, Emin, Emax);
  hef->writeHisto(htmp[4]);
  vm->plot(htmp[4]);
  vm->plot(bicAnalysis->fillNeutronDoubleDiffXS(80.0, 2.0, logE, Emin, Emax), true);

  htmp[5] = inclAnalysis->fillNeutronDoubleDiffXS(110.0, 2.0, logE, Emin, Emax);
  hef->writeHisto(htmp[5]);
  vm->plot(htmp[5]);
  vm->plot(bicAnalysis->fillNeutronDoubleDiffXS(110.0, 2.0, logE, Emin, Emax), true);

  outputHistos->Write();
  outputHistos->Close();
  hef->close();
  delete hef;
}
