{
  gROOT->LoadMacro("../analysis/libAnalysis.C++");
  gROOT->LoadMacro("../analysis/libHEF.C++");

  HEF *hef = new HEF("ddxs.hef");
  hef->open();

  HEF *hefZ = new HEF("z.hef");
  hefZ->open();

  HistoFactory *hf = new HistoFactory();

  CalculationAnalysis *inclAnalysis = new CalculationAnalysis(hf, "INCL42",
							      "./inclion.root",
							      "data", 1.548368e+03,
							      100000);
  CalculationAnalysis *bicAnalysis = new CalculationAnalysis(hf, "G4BIC",
							     "./bic.root",
							     "data",1.548368e+03,
							     100000);

  
  ViewManager *vm = new ViewManager(3,2);
  Double_t Emax = 1000.0;
  Double_t Emin = 1.0;
  Bool_t logE = true;
  TFile *outputHistos = new TFile("outpuHistos.root", "RECREATE");

  // TH1D *htmp[6];
  // TH1D *htmpBIC[6];
  // htmp[0] = inclAnalysis->fillNeutronDoubleDiffXS(1.0, 1.0, logE, Emin, Emax);
  // htmpBIC[0] = bicAnalysis->fillNeutronDoubleDiffXS(1.0, 1.0, logE, Emin, Emax);
  // hef->writeHisto(htmp[0]);
  // hef->writeHisto(htmpBIC[0]);
  // vm->plot(htmp[0]);
  // vm->plot(htmpBIC[0], true);

  // htmp[1] = inclAnalysis->fillNeutronDoubleDiffXS(15.0, 2.0, logE, Emin, Emax);
  // htmpBIC[1] = bicAnalysis->fillNeutronDoubleDiffXS(15.0, 2.0, logE, Emin, Emax);
  // hef->writeHisto(htmp[1]);
  // hef->writeHisto(htmpBIC[1]);
  // vm->plot(htmp[1]);
  // vm->plot(htmpBIC[1], true);

  // htmp[2] = inclAnalysis->fillNeutronDoubleDiffXS(30.0, 2.0, logE, Emin, Emax);
  // htmpBIC[2] = bicAnalysis->fillNeutronDoubleDiffXS(30.0, 2.0, logE, Emin, Emax);
  // hef->writeHisto(htmp[2]);
  // hef->writeHisto(htmpBIC[2]);
  // vm->plot(htmp[2]);
  // vm->plot(htmpBIC[2], true);

  // htmp[3] = inclAnalysis->fillNeutronDoubleDiffXS(50.0, 2.0, logE, Emin, Emax);
  // htmpBIC[3] = bicAnalysis->fillNeutronDoubleDiffXS(50.0, 2.0, logE, Emin, Emax);
  // hef->writeHisto(htmp[3]);
  // hef->writeHisto(htmpBIC[3]);
  // vm->plot(htmp[3]);
  // vm->plot(htmpBIC[3], true);

  // htmp[4] = inclAnalysis->fillNeutronDoubleDiffXS(80.0, 2.0, logE, Emin, Emax);
  // htmpBIC[4] = bicAnalysis->fillNeutronDoubleDiffXS(80.0, 2.0, logE, Emin, Emax);
  // hef->writeHisto(htmp[4]);
  // hef->writeHisto(htmpBIC[4]);
  // vm->plot(htmp[4]);
  // vm->plot(htmpBIC[4], true);

  // htmp[5] = inclAnalysis->fillNeutronDoubleDiffXS(110.0, 2.0, logE, Emin, Emax);
  // htmpBIC[5] = bicAnalysis->fillNeutronDoubleDiffXS(110.0, 2.0, logE, Emin, Emax);
  // hef->writeHisto(htmp[5]);
  // hef->writeHisto(htmpBIC[5]);
  // vm->plot(htmp[5]);
  // vm->plot(htmpBIC[5], true);

  ViewManager *vmZ = new ViewManager(1,1);
  TH1D *Zincl = inclAnalysis->fillZDistribution(-0.5, 20.5);
  TH1D *Zbic = bicAnalysis->fillZDistribution(-0.5, 20.5);
  vm->plot(Zincl);
  vm->plot(Zbic, true);

  hefZ->writeHisto(Zincl);
  hefZ->writeHisto(Zbic);

  outputHistos->Write();
  outputHistos->Close();
  hef->close();
  hefZ->close();
  delete hef;
}
