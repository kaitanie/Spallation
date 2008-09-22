{
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
//TFile *f4 = new TFile("precoCarbonProton1GeV.root");

data = (TTree *) f0->Get("data");
data->Process(carbonAnalyzer, "resultsInclAblaWithFermi.root");

data = (TTree *) f1->Get("data");
data->Process(carbonAnalyzer, "resultsInclAbla.root");

data = (TTree *) f2->Get("data");
data->Process(carbonAnalyzer, "resultsBertini.root");

//data = (TTree *) f3->Get("data");
//data->Process(carbonAnalyzer, "resultsBinary.root");

//data = (TTree *) f4->Get("data");
//data->Process(carbonAnalyzer, "resultsPreco.root");
}
