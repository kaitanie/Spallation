{
cout <<"Compiling and loading histogram factory..." << endl;
gROOT->LoadMacro("HistoFactory.C+");
cout <<"Compiling and loading analyzer..." << endl;
gROOT->LoadMacro("FermiAnalyzer.C+");
cout <<"Analyze a data tree: data->Process(\"FermiAnalyzer\", \"outputFile.root\")" << endl; 

// Prepare the analyzers:
FermiAnalyzer *carbonAnalyzer = new FermiAnalyzer();
carbonAnalyzer->SetNumberOfEvents(100000);
carbonAnalyzer->SetCrossSection(1.905000e+03); // 1.905000e+03 mb
carbonAnalyzer->SetMaximumEnergy(1200.0);

TTree *data = NULL;
TFile *f0 = new TFile("../runs/inclPbProton1200.root");
TFile *f1 = new TFile("../runs/bertiniPbProton1200.root");

data = (TTree *) f0->Get("data");
data->Process(carbonAnalyzer, "resultsPbProton1200InclAbla.root");

data = (TTree *) f1->Get("data");
data->Process(carbonAnalyzer, "resultsPbProton1200Bertini.root");
}
