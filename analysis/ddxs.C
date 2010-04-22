{
  gROOT->LoadMacro("libAnalysis.C++");

  HistoFactory *hf = new HistoFactory();
  // Cross section 1.025181e+03 taken from Geant4
  CalculationAnalysis *inclAnalysis = new CalculationAnalysis(hf, "../c_c_135/inclion.root",
							      "data", 9.009522e+02,
							      100000);
  CalculationAnalysis *bicAnalysis = new CalculationAnalysis(hf, "../c_c_135/bic.root",
							     "data", 9.009522e+02,
							     100000);

  
  ViewManager *vm = new ViewManager(3,2);
  Double_t Emax = 1000.0;
  Double_t Emin = 1.0;
  Bool_t logE = true;
  vm->plot(inclAnalysis->fillNeutronDoubleDiffXS(1.0, 1.0, logE, Emin, Emax));
  vm->plot(bicAnalysis->fillNeutronDoubleDiffXS(1.0, 1.0, logE, Emin, Emax), true);
  ThreeColumnReader *r0deg =
    new ThreeColumnReader("/home/mael/doc/expdata/exp_data/data_romano/C_C_0deg");
  vm->plot(r0deg->getGraph(), true);

  vm->plot(inclAnalysis->fillNeutronDoubleDiffXS(15.0, 2.0, logE, Emin, Emax));
  vm->plot(bicAnalysis->fillNeutronDoubleDiffXS(15.0, 2.0, logE, Emin, Emax), true);
  ThreeColumnReader *r15deg =
    new ThreeColumnReader("/home/mael/doc/expdata/exp_data/data_romano/C_C_15deg");
  vm->plot(r15deg->getGraph(), true);

  vm->plot(inclAnalysis->fillNeutronDoubleDiffXS(30.0, 2.0, logE, Emin, Emax));
  vm->plot(bicAnalysis->fillNeutronDoubleDiffXS(30.0, 2.0, logE, Emin, Emax), true);
  ThreeColumnReader *r30deg =
    new ThreeColumnReader("/home/mael/doc/expdata/exp_data/data_romano/C_C_30deg");
  vm->plot(r30deg->getGraph(), true);

  vm->plot(inclAnalysis->fillNeutronDoubleDiffXS(50.0, 2.0, logE, Emin, Emax));
  vm->plot(bicAnalysis->fillNeutronDoubleDiffXS(50.0, 2.0, logE, Emin, Emax), true);
  ThreeColumnReader *r50deg =
    new ThreeColumnReader("/home/mael/doc/expdata/exp_data/data_romano/C_C_50deg");
  vm->plot(r50deg->getGraph(), true);

  vm->plot(inclAnalysis->fillNeutronDoubleDiffXS(80.0, 2.0, logE, Emin, Emax));
  vm->plot(bicAnalysis->fillNeutronDoubleDiffXS(80.0, 2.0, logE, Emin, Emax), true);
  ThreeColumnReader *r80deg =
    new ThreeColumnReader("/home/mael/doc/expdata/exp_data/data_romano/C_C_80deg");
  vm->plot(r80deg->getGraph(), true);

  vm->plot(inclAnalysis->fillNeutronDoubleDiffXS(110.0, 2.0, logE, Emin, Emax));
  vm->plot(bicAnalysis->fillNeutronDoubleDiffXS(110.0, 2.0, logE, Emin, Emax), true);
  ThreeColumnReader *r110deg =
    new ThreeColumnReader("/home/mael/doc/expdata/exp_data/data_romano/C_C_110deg");
  vm->plot(r110deg->getGraph(), true);
}
