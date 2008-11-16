{
cout <<"Compiling and loading histogram factory..." << endl;
gROOT->LoadMacro("HistoFactory.C+");
cout <<"Compiling and loading analyzer..." << endl;
gROOT->LoadMacro("FermiAnalyzer.C+");
cout <<"Analyze a data tree: data->Process(\"FermiAnalyzer\", \"outputFile.root\")" << endl; 

// Prepare the analyzers:
FermiAnalyzer *carbonAnalyzer = new FermiAnalyzer();
carbonAnalyzer->SetNumberOfEvents(100000);
carbonAnalyzer->SetCrossSection(9.799672e+02);
carbonAnalyzer->SetMaximumEnergy(1000.0);

TTree *data = NULL;
TFile *f0 = new TFile("../c_c_290/inclion.root");
TFile *f1 = new TFile("../c_c_290/bic.root");

data = (TTree *) f0->Get("data");
data->Process(carbonAnalyzer, "resultsInclIonCC_290MeV.root");

data = (TTree *) f1->Get("data");
data->Process(carbonAnalyzer, "resultsBICIonCC_290MeV.root");
}
