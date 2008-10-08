{
cout <<"Compiling and loading histogram factory..." << endl;
gROOT->LoadMacro("HistoFactory.C+");
cout <<"Compiling and loading analyzer..." << endl;
gROOT->LoadMacro("FermiAnalyzer.C+");
cout <<"Analyze a data tree: data->Process(\"FermiAnalyzer\", \"outputFile.root\")" << endl; 

// Prepare the analyzers:
FermiAnalyzer *analyzer = new FermiAnalyzer();
analyzer->SetNumberOfEvents(100000);
analyzer->SetCrossSection(4.002400e+02);
analyzer->SetMaximumEnergy(256.0);

TTree *data = NULL;
TFile *f0 = new TFile("../runs/inclAl.root");
TFile *f1 = new TFile("../runs/inclOldAl.root");
TFile *f2 = new TFile("../runs/bertiniAl.root");

data = (TTree *) f0->Get("data");
data->Process(analyzer, "resultsAlInclAbla.root");

data = (TTree *) f1->Get("data");
data->Process(analyzer, "resultsAlInclAblaOld.root");

data = (TTree *) f2->Get("data");
data->Process(analyzer, "resultsAlBertini.root");
}
