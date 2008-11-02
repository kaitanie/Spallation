{
cout <<"Compiling and loading histogram factory..." << endl;
gROOT->LoadMacro("HistoFactory.C+");
cout <<"Compiling and loading analyzer..." << endl;
gROOT->LoadMacro("FermiAnalyzer.C+");
cout <<"Analyze a data tree: data->Process(\"FermiAnalyzer\", \"outputFile.root\")" << endl; 

// Prepare the analyzers:
FermiAnalyzer *carbonAnalyzer = new FermiAnalyzer();
carbonAnalyzer->SetNumberOfEvents(100000);
carbonAnalyzer->SetCrossSection(2.22000e+02);
carbonAnalyzer->SetMaximumEnergy(1000.0);

TTree *data = NULL;
TFile *f0 = new TFile("../runs/inclCarbonProton1GeV.root");
TFile *f1 = new TFile("../runs/inclNoFermiCarbonProton1GeV.root");
TFile *f2 = new TFile("../runs/bertiniCarbonProton1GeV.root");
//TFile *f3 = new TFile("binaryCarbonProton1GeV.root");
TFile *f4 = new TFile("../runs/precoFermiCarbonProton1GeV.root");

TFile *stop2 = new TFile("../runs/inclStoppingAt2CarbonProton1GeV.root");
data = (TTree *) stop2->Get("data");
data->Process(carbonAnalyzer,  "resultsStopAt2InclAblaWithFermi.root");

TFile *stop5 = new TFile("../runs/inclStoppingAt5CarbonProton1GeV.root");
data = (TTree *) stop5->Get("data");
data->Process(carbonAnalyzer,  "resultsStopAt5InclAblaWithFermi.root");

TFile *stop10 = new TFile("../runs/inclStoppingAt10CarbonProton1GeV.root");
data = (TTree *) stop10->Get("data");
data->Process(carbonAnalyzer,  "resultsStopAt10InclAblaWithFermi.root");

data = (TTree *) f0->Get("data");
data->Process(carbonAnalyzer, "resultsInclAblaWithFermi.root");

data = (TTree *) f1->Get("data");
data->Process(carbonAnalyzer, "resultsInclAbla.root");

data = (TTree *) f2->Get("data");
data->Process(carbonAnalyzer, "resultsBertini.root");

data = (TTree *) f4->Get("data");
data->Process(carbonAnalyzer, "resultsPrecoFermi.root");

//data = (TTree *) f3->Get("data");
//data->Process(carbonAnalyzer, "resultsBinary.root");

//data = (TTree *) f4->Get("data");
//data->Process(carbonAnalyzer, "resultsPreco.root");

// Higher statistics
carbonAnalyzer->SetNumberOfEvents(1000000); // one million
TFile *f01M = new TFile("../runs/inclCarbonProton1GeV1Mevents.root");
data = (TTree *) f01M->Get("data");
data->Process(carbonAnalyzer, "resultsInclAblaWithFermi1M.root");

TFile *f11M = new TFile("../runs/bertiniCarbonProton1GeV1Mevents.root");
data = (TTree *) f11M->Get("data");
data->Process(carbonAnalyzer, "resultsBertini1M.root");
}

