{
cout <<"Compiling and loading histogram factory..." << endl;
gROOT->LoadMacro("HistoFactory.C+");
cout <<"Compiling and loading analyzer..." << endl;
gROOT->LoadMacro("FermiAnalyzer.C+");
cout <<"Analyze a data tree: data->Process(\"FermiAnalyzer\", \"outputFile.root\")" << endl; 

// Prepare the analyzers:
FermiAnalyzer *analyzer = new FermiAnalyzer();
analyzer->SetNumberOfEvents(100000);
analyzer->SetCrossSection(1.031168e+03);
analyzer->SetMaximumEnergy(540.0);

TTree *data = NULL;
TFile *f0 = new TFile("../alpha_al_135/incl.root");

data = (TTree *) f0->Get("data");
data->Process(analyzer, "resultsAlphaOnAlInclAbla.root");
}
