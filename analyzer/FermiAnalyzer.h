//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Sep 18 11:44:47 2008 by ROOT version 5.20/00
// from TTree data/test30 data
// found on file: CarbonFermiBreakUp.root
//////////////////////////////////////////////////////////

#ifndef FermiAnalyzer_h
#define FermiAnalyzer_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TH1F.h>
#include <TH1I.h>

#include "HistoFactory.h"

class FermiAnalyzer : public TSelector {
public :
  FermiAnalyzer(TString &outputFile);

   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Histogram factory:
   HistoFactory *histoFactory;

// Output file:
 TString *outputFileName; 
 TFile *resultsOut;
 TH1F *neutronEnergyIntegrated;
 TH1F *protonEnergyIntegratedLogx;
 TH1F *protonEnergyIntegrated;
 TH1F *ddHistBinWidths;
 TH1F *ddPHistBinWidths;
 TH1F *chargenumbers;
 TH1F *massnumbers;
 TH1F *hydrogenIsotopes;
 TH1F *heliumIsotopes;
 TH1F *lithiumIsotopes;
 TH1F *berylliumIsotopes;
 TH1F *boronIsotopes;
 TH1F *carbonIsotopes;
 TH1F *nitrogenIsotopes;
 TH1F *neutronDD0;
 TH1F *neutronDD0Lin;
 TH1F *neutronDD7_5;
 TH1F *neutronDD7_5Lin;
 TH1F *neutronDD10;
 TH1F *neutronDD10Lin;
 TH1F *neutronDD11;
 TH1F *neutronDD11Lin;
 TH1F *neutronDD25;
 TH1F *neutronDD25Lin;
 TH1F *neutronDD30;
 TH1F *neutronDD30Lin;
 TH1F *neutronDD50;
 TH1F *neutronDD50Lin;

 TH1F *protonDD11;
 TH1F *protonDD11Lin;
 TH1F *protonDD13;
 TH1F *protonDD13Lin;
 TH1F *protonDD15;
 TH1F *protonDD15Lin;
 TH1F *protonDD20;
 TH1F *protonDD20Lin;
 TH1F *protonDD25;
 TH1F *protonDD25Lin;
 TH1F *protonDD30;
 TH1F *protonDD30Lin;
 TH1F *protonDD50;
 TH1F *protonDD50Lin;

 TH1F *protonMomentumDD11;
 TH1F *protonMomentumDD13;
 TH1F *protonMomentumDD15;
 TH1F *protonMomentumDD20;
 TH1F *protonMomentumDD25;
 TH1F *protonMomentumDD30;
 TH1F *protonMomentumDD11Lin;
 TH1F *protonMomentumDD13Lin;
 TH1F *protonMomentumDD15Lin;
 TH1F *protonMomentumDD20Lin;
 TH1F *protonMomentumDD25Lin;
 TH1F *protonMomentumDD30Lin;

 Float_t minE, maxE;
 Float_t DDLinBinWidth;
   // Declaration of leaf types
   Int_t           A;
   Int_t           Z;
   Float_t         totE;
   Float_t         kinE;
   Float_t         mom;
   Float_t         theta;
   Float_t         phi;

   // List of branches
   TBranch        *b_A;   //!
   TBranch        *b_Z;   //!
   TBranch        *b_totE;   //!
   TBranch        *b_kinE;   //!
   TBranch        *b_mom;   //!
   TBranch        *b_theta;   //!
   TBranch        *b_phi;   //!

   FermiAnalyzer(TTree * /*tree*/ =0) { }
   virtual ~FermiAnalyzer() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();
   Float_t crossSection, emax;
   Int_t numberOfEvents;

   // Analysis helper methods
   Float_t GetDoubleDifferentialWeight(Float_t crossSection, Int_t numberOfEvents, Float_t theta, Float_t dTheta);
   Float_t GetWeight(Float_t crossSection, Int_t numberOfEvents);

   void SetCrossSection(Float_t cx) {
     crossSection = cx;
   }
   void SetNumberOfEvents(Int_t events) {
     numberOfEvents = events;
   }
   void SetMaximumEnergy(Float_t maxe) {
     emax = maxe;
   }
   ClassDef(FermiAnalyzer,0);
};

#endif

#ifdef FermiAnalyzer_cxx

FermiAnalyzer::FermiAnalyzer(TString &outputFile)
{
  outputFileName = new TString(outputFile);
}

void FermiAnalyzer::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("A", &A, &b_A);
   fChain->SetBranchAddress("Z", &Z, &b_Z);
   fChain->SetBranchAddress("totE", &totE, &b_totE);
   fChain->SetBranchAddress("kinE", &kinE, &b_kinE);
   fChain->SetBranchAddress("mom", &mom, &b_mom);
   fChain->SetBranchAddress("theta", &theta, &b_theta);
   fChain->SetBranchAddress("phi", &phi, &b_phi);
}

Bool_t FermiAnalyzer::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef FermiAnalyzer_cxx
