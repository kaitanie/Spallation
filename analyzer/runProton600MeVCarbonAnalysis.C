{
cout <<"Compiling and loading histogram factory..." << endl;
gROOT->LoadMacro("HistoFactory.C+");
cout <<"Compiling and loading analyzer..." << endl;
gROOT->LoadMacro("FermiAnalyzer.C+");
cout <<"Analyze a data tree: data->Process(\"FermiAnalyzer\", \"outputFile.root\")" << endl; 

// Prepare the analyzers:
FermiAnalyzer *carbonAnalyzer = new FermiAnalyzer();
carbonAnalyzer->SetNumberOfEvents(1000000);
carbonAnalyzer->SetCrossSection(2.22000e+02);
carbonAnalyzer->SetMaximumEnergy(600.0);

TTree *data = NULL;
TFile *f0 = new TFile("../runs/inclCarbonProton600MeV.root");
//TFile *f1 = new TFile("../runs/inclNoFermiCarbonProton800MeV.root");
TFile *f2 = new TFile("../runs/bertiniCarbonProton600MeV.root");
//TFile *f3 = new TFile("binaryCarbonProton1GeV.root");

data = (TTree *) f0->Get("data");
data->Process(carbonAnalyzer, "resultsInclAblaWithFermi600MeV.root");

//data = (TTree *) f1->Get("data");
//data->Process(carbonAnalyzer, "resultsInclAbla.root");

data = (TTree *) f2->Get("data");
data->Process(carbonAnalyzer, "resultsBertini600MeV.root");

//data = (TTree *) f3->Get("data");
//data->Process(carbonAnalyzer, "resultsBinary.root");

//data = (TTree *) f4->Get("data");
//data->Process(carbonAnalyzer, "resultsPreco.root");
}
