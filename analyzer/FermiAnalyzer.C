#define FermiAnalyzer_cxx
// The class definition in FermiAnalyzer.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("FermiAnalyzer.C")
// Root > T->Process("FermiAnalyzer.C","some options")
// Root > T->Process("FermiAnalyzer.C+")
//

#include "FermiAnalyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include "Riostream.h"
#include "TMath.h"

void FermiAnalyzer::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

  // Create a histogram factory:
  histoFactory = new HistoFactory();

  // Option format:
  // out=output.root:cx=1.2e2:emax=1000
   TString option = GetOption();

   //   TString outputFile
   cout <<"Output file = " << option << endl;
   if(option == "") option = "defaultOutput.root";
   resultsOut = new TFile(option, "RECREATE");

   // Linear spectra:
   neutronEnergyIntegrated = new TH1F("neutronEnergyIntegrated", "Integrated neutron energies", 100, 0.0, 1000.0);
   protonEnergyIntegrated = new TH1F("protonEnergyIntegrated", "Integrated proton energies", 100, 0.0, 1000.0);

   // Initialize double-differential energy spectra:
   //   Float_t emax = 1000.0;
   Float_t emin = 1.0;
   Float_t pmin = 1.0;
   Float_t pmax = TMath::Sqrt(emax*emax + 1000.0*1000.0) + 400.0;

   Float_t xbins[99+1];
   Float_t pxbins[99+1];
   DDLinBinWidth = emax/99.0; 
   Float_t fact=(log(emax)-log(emin))/99;
   Float_t factp=(log(pmax)-log(pmin))/99;
   Int_t index = 99+1;
   for(Int_t i=0;i<99+1;++i) {
     index--;
     xbins[i]=exp(log(emin)+fact*i);
     pxbins[i]=exp(log(pmin)+factp*i);
   }

   ddHistBinWidths = new TH1F("ddHistBinWidths","",99,xbins);
   ddPHistBinWidths = new TH1F("ddPHistBinWidths","",99,pxbins);
   for(Int_t i=0;i<99;++i) {
     ddHistBinWidths->SetBinContent(i,(Double_t)1./(xbins[i+1]-xbins[i]));
     ddPHistBinWidths->SetBinContent(i, (Double_t)1./(pxbins[i+1]-pxbins[i]));
   }
   //   de=1.0;

   // histo = HistoFactory::create1D("name", "title", "xlabel", "ylabel", bins, minx, maxx);
   // histologlog = HistoFactory::create1DLogx("name", "title", "xlabel", "ylabel", bins, minx, maxx);
   chargenumbers = new TH1F("chargenumbers", "Chargenumber distribution", 14, 0.5, 14.5);
   chargenumbers->GetXaxis()->SetTitle("Charge number");
   chargenumbers->GetYaxis()->SetTitle("#sigma (mb)");
   chargenumbers->SetLineWidth(2);
   totalChargeNumbers = histoFactory->create1D("totalChargeNumbers", "Total charge numbers", "Charge number", "#sigma (mb)", 14, 0.5, 14.5);
   massnumbers = new TH1F("massnumbers", "Massnumber distribution", 14, 0.5, 14.5);
   massnumbers->GetXaxis()->SetTitle("Mass number");
   massnumbers->GetYaxis()->SetTitle("#sigma (mb)");
   massnumbers->SetLineWidth(2);
   totalMassNumbers = histoFactory->create1D("totalMassNumbers", "Total mass numbers", "Mass number", "#sigma (mb)", 14, 0.5, 14.5);
   hydrogenIsotopes = new TH1F("hydrogenIsotopes", "Hydrogen isotopes", 14, 0.5, 14.5);
   hydrogenIsotopes->GetXaxis()->SetTitle("Mass number");
   hydrogenIsotopes->GetYaxis()->SetTitle("#sigma (mb)");
   hydrogenIsotopes->SetLineWidth(2);
   heliumIsotopes = new TH1F("heliumIsotopes", "Helium isotopes", 14, 0.5, 14.5);
   heliumIsotopes->GetXaxis()->SetTitle("Mass number");
   heliumIsotopes->GetYaxis()->SetTitle("#sigma (mb)");
   heliumIsotopes->SetLineWidth(2);
   lithiumIsotopes = new TH1F("lithiumIsotopes", "Lithium isotopes", 14, 0.5, 14.5);
   lithiumIsotopes->GetXaxis()->SetTitle("Mass number");
   lithiumIsotopes->GetYaxis()->SetTitle("#sigma (mb)");
   lithiumIsotopes->SetLineWidth(2);
   berylliumIsotopes = new TH1F("berylliumIsotopes", "Beryllium isotopes", 14, 0.5, 14.5);
   berylliumIsotopes->GetXaxis()->SetTitle("Mass number");
   berylliumIsotopes->GetYaxis()->SetTitle("#sigma (mb)");
   berylliumIsotopes->SetLineWidth(2);
   boronIsotopes = new TH1F("boronIsotopes", "Boron isotopes", 14, 0.5, 14.5);
   boronIsotopes->GetXaxis()->SetTitle("Mass number");
   boronIsotopes->GetYaxis()->SetTitle("#sigma (mb)");
   boronIsotopes->SetLineWidth(2);
   carbonIsotopes = new TH1F("carbonIsotopes", "Carbon isotopes", 14, 0.5, 14.5);
   carbonIsotopes->GetXaxis()->SetTitle("Mass number");
   carbonIsotopes->GetYaxis()->SetTitle("#sigma (mb)");
   carbonIsotopes->SetLineWidth(2);
   nitrogenIsotopes = new TH1F("nitrogenIsotopes", "Nitrogen isotopes", 14, 0.5, 14.5);
   nitrogenIsotopes->GetXaxis()->SetTitle("Mass number");
   nitrogenIsotopes->GetYaxis()->SetTitle("#sigma (mb)");
   nitrogenIsotopes->SetLineWidth(2);

   neutronDD0 = new TH1F("neutronDD0", "Angle 0 deg", 99, xbins);
   neutronDD0Lin = new TH1F("neutronDD0Lin", "Angle 0 deg", 99, 0.0, emax);
   neutronDD5 = histoFactory->create1DLogx("neutronDD5", "Angle 5 deg", "Neutron energy (MeV)", "#sigma (mb)",
                                           99, 1.0, emax);
   neutronDD5Lin = histoFactory->create1D("neutronDD5Lin", "Angle 5 deg", "Neutron energy (MeV)", "#sigma (mb)",
                                          99, 0.0, emax);
   neutronDD7_5 = new TH1F("neutronDD7_5", "Angle 7.5 deg", 99, xbins);
   neutronDD7_5Lin = new TH1F("neutronDD7_5Lin", "Angle 7.5 deg", 99, 0.0, emax);
   neutronDD10 = new TH1F("neutronDD10", "Angle 10 deg", 99, xbins);
   neutronDD10Lin = new TH1F("neutronDD10Lin", "Angle 10 deg", 99, 0.0, emax);
   neutronDD11 = new TH1F("neutronDD11", "Angle 11 deg", 99, xbins);
   neutronDD11Lin = new TH1F("neutronDD11Lin", "Angle 11 deg", 99, 0.0, emax);
   neutronDD25 = new TH1F("neutronDD25", "Angle 25 deg", 99, xbins);
   neutronDD25Lin = new TH1F("neutronDD25Lin", "Angle 25 deg", 99, 0.0, emax);
   neutronDD30 = new TH1F("neutronDD30", "Angle 30 deg", 99, xbins);
   neutronDD30Lin = new TH1F("neutronDD30Lin", "Angle 30 deg", 99, 0.0, emax);
   neutronDD50 = new TH1F("neutronDD50", "Angle 50 deg", 99, xbins);
   neutronDD50Lin = new TH1F("neutronDD50Lin", "Angle 50 deg", 99, 0.0, emax);

   protonEnergyIntegratedLogx = new TH1F("protonEnergyIntegratedLogx", "Integrated proton energies", 99, xbins);

   protonDD11 = new TH1F("protonDD11", "Angle 11 deg", 99, xbins);
   protonDD11Lin = new TH1F("protonDD11Lin", "Angle 11 deg", 99, 0.0, emax);
   protonDD13 = histoFactory->create1DLogx("protonDD13", "Angle 13 deg", "Proton energy (MeV)", "#sigma (mb)",
					  99, 1.0, emax);
   protonDD13Lin = histoFactory->create1D("protonDD13Lin", "Angle 13 deg", "Proton energy (MeV)", "#sigma (mb)",
					  99, 0.0, emax);
   protonDD15 = histoFactory->create1DLogx("protonDD15", "Angle 15 deg", "Proton energy (MeV)", "#sigma (mb)",
					  99, 1.0, emax);
   protonDD15Lin = histoFactory->create1D("protonDD15Lin", "Angle 15 deg", "Proton energy (MeV)", "#sigma (mb)",
					  99, 0.0, emax);
   protonDD20 = histoFactory->create1DLogx("protonDD20", "Angle 20 deg", "Proton energy (MeV)", "#sigma (mb)",
					  99, 1.0, emax);
   protonDD20Lin = histoFactory->create1D("protonDD20Lin", "Angle 20 deg", "Proton energy (MeV)", "#sigma (mb)",
					  99, 0.0, emax);
   protonDD25 = histoFactory->create1DLogx("protonDD25", "Angle 25 deg", "Proton energy (MeV)", "#sigma (mb)",
					  99, 1.0, emax);
   protonDD25Lin = histoFactory->create1D("protonDD25Lin", "Angle 25 deg", "Proton energy (MeV)", "#sigma (mb)",
					  99, 0.0, emax);
   protonDD30 = histoFactory->create1DLogx("protonDD30", "Angle 30 deg", "Proton energy (MeV)", "#sigma (mb)",
					  99, 1.0, emax);
   protonDD30Lin = histoFactory->create1D("protonDD30Lin", "Angle 30 deg", "Proton energy (MeV)", "#sigma (mb)",
					  99, 0.0, emax);
   protonDD50 = new TH1F("protonDD50", "Angle 50 deg", 99, xbins);
   protonDD50Lin = new TH1F("protonDD50Lin", "Angle 50 deg", 99, 0.0, emax);

   protonMomentumDD11 = histoFactory->create1DLogx("protonMomentumDD11", "Angle 11 deg", "Proton momentum (MeV/c)",
						   "#sigma", 99, 1.0, pmax);
   protonMomentumDD13 = histoFactory->create1DLogx("protonMomentumDD13", "Angle 13 deg", "Proton momentum (MeV/c)",
						   "#sigma", 99, 1.0, pmax);
   protonMomentumDD15 = histoFactory->create1DLogx("protonMomentumDD15", "Angle 15 deg", "Proton momentum (MeV/c)",
						   "#sigma", 99, 1.0, pmax);
   protonMomentumDD20 = histoFactory->create1DLogx("protonMomentumDD20", "Angle 20 deg", "Proton momentum (MeV/c)",
						   "#sigma", 99, 1.0, pmax);
   protonMomentumDD25 = histoFactory->create1DLogx("protonMomentumDD25", "Angle 25 deg", "Proton momentum (MeV/c)",
						   "#sigma", 99, 1.0, pmax);
   protonMomentumDD30 = histoFactory->create1DLogx("protonMomentumDD30", "Angle 30 deg", "Proton momentum (MeV/c)",
						   "#sigma", 99, 1.0, pmax);
   protonMomentumDD11Lin = histoFactory->create1D("protonMomentumDD11Lin", "Angle 11 deg", "Proton momentum (MeV/c)",
						   "#sigma", 99, 1.0, pmax);
   protonMomentumDD13Lin = histoFactory->create1D("protonMomentumDD13Lin", "Angle 13 deg", "Proton momentum (MeV/c)",
						   "#sigma", 99, 1.0, pmax);
   protonMomentumDD15Lin = histoFactory->create1D("protonMomentumDD15Lin", "Angle 15 deg", "Proton momentum (MeV/c)",
						   "#sigma", 99, 1.0, pmax);
   protonMomentumDD20Lin = histoFactory->create1D("protonMomentumDD20Lin", "Angle 20 deg", "Proton momentum (MeV/c)",
						   "#sigma", 99, 1.0, pmax);
   protonMomentumDD25Lin = histoFactory->create1D("protonMomentumDD25Lin", "Angle 25 deg", "Proton momentum (MeV/c)",
						   "#sigma", 99, 1.0, pmax);
   protonMomentumDD30Lin = histoFactory->create1D("protonMomentumDD30Lin", "Angle 30 deg", "Proton momentum (MeV/c)",
						   "#sigma", 99, 1.0, pmax);
   //   neutronDD21 = new TH1F("neutronDD11", "Neutrons in angle 11 deg", nbins, energies);

   he3EnergyDD30 = histoFactory->create1DLogx("he3EnergyDD30", "Angle 30 deg", "He3 energy (MeV)",
                                              "#sigma (mb)", 99, 1.0, emax);
   he3EnergyDD30Lin = histoFactory->create1D("he3EnergyDD30Lin", "Angle 30 deg", "He3 energy (MeV)",
                                             "#sigma (mb)", 99, 0.0, emax);
   he3EnergyDD45 = histoFactory->create1DLogx("he3EnergyDD45", "Angle 45 deg", "He3 energy (MeV)",
                                              "#sigma (mb)", 99, 1.0, emax);
   he3EnergyDD45Lin = histoFactory->create1D("he3EnergyDD45Lin", "Angle 45 deg", "He3 energy (MeV)",
                                             "#sigma (mb)", 99, 0.0, emax);
   he3EnergyDD75 = histoFactory->create1DLogx("he3EnergyDD75", "Angle 75 deg", "He3 energy (MeV)",
                                              "#sigma (mb)", 99, 1.0, emax);
   he3EnergyDD75Lin = histoFactory->create1D("he3EnergyDD75Lin", "Angle 75 deg", "He3 energy (MeV)",
                                             "#sigma (mb)", 99, 0.0, emax);
   he3EnergyDD105 = histoFactory->create1DLogx("he3EnergyDD105", "Angle 105 deg", "He3 energy (MeV)",
                                               "#sigma (mb)", 99, 1.0, emax);
   he3EnergyDD105Lin = histoFactory->create1D("he3EnergyDD105Lin", "Angle 105 deg", "He3 energy (MeV)",
                                                "#sigma (mb)", 99, 0.0, emax);
   alphaEnergyDD30 = histoFactory->create1DLogx("alphaEnergyDD30", "Angle 30 deg", "Alpha energy (MeV)",
                                              "#sigma (mb)", 99, 1.0, emax);
   alphaEnergyDD30Lin = histoFactory->create1D("alphaEnergyDD30Lin", "Angle 30 deg", "Alpha energy (MeV)",
                                               "#sigma (mb)", 99, 0.0, emax);
   alphaEnergyDD45 = histoFactory->create1DLogx("alphaEnergyDD45", "Angle 45 deg", "Alpha energy (MeV)",
                                               "#sigma (mb)", 99, 1.0, emax);
   alphaEnergyDD45Lin = histoFactory->create1D("alphaEnergyDD45Lin", "Angle 45 deg", "Alpha energy (MeV)",
                                               "#sigma (mb)", 99, 0.0, emax);
   alphaEnergyDD75 = histoFactory->create1DLogx("alphaEnergyDD75", "Angle 75 deg", "Alpha energy (MeV)",
                                                "#sigma (mb)", 99, 1.0, emax);
   alphaEnergyDD75Lin = histoFactory->create1D("alphaEnergyDD75Lin", "Angle 75 deg", "Alpha energy (MeV)",
                                               "#sigma (mb)", 99, 0.0, emax);
   alphaEnergyDD105 = histoFactory->create1DLogx("alphaEnergyDD105", "Angle 105 deg", "Alpha energy (MeV)",
                                                 "#sigma (mb)", 99, 1.0, emax);
   alphaEnergyDD105Lin = histoFactory->create1D("alphaEnergyDD105Lin", "Angle 105 deg", "Alpha energy (MeV)",
                                                "#sigma (mb)", 99, 0.0, emax);
   deuteronEnergyDD30 = histoFactory->create1DLogx("deuteronEnergyDD30", "Angle 30 deg", "Deuteron energy (MeV)",
                                                "#sigma (mb)", 99, 1.0, emax);
   deuteronEnergyDD30Lin = histoFactory->create1D("deuteronEnergyDD30Lin", "Angle 30 deg", "Deuteron energy (MeV)",
                                                "#sigma (mb)", 99, 0.0, emax);
   deuteronEnergyDD45 = histoFactory->create1DLogx("deuteronEnergyDD45", "Angle 45 deg", "Deuteron energy (MeV)",
                                                "#sigma (mb)", 99, 1.0, emax);
   deuteronEnergyDD45Lin = histoFactory->create1D("deuteronEnergyDD45Lin", "Angle 45 deg", "Deuteron energy (MeV)",
                                                "#sigma (mb)", 99, 0.0, emax);
   deuteronEnergyDD75 = histoFactory->create1DLogx("deuteronEnergyDD75", "Angle 75 deg", "Deuteron energy (MeV)",
                                                "#sigma (mb)", 99, 1.0, emax);
   deuteronEnergyDD75Lin = histoFactory->create1D("deuteronEnergyDD75Lin", "Angle 75 deg", "Deuteron energy (MeV)",
                                                "#sigma (mb)", 99, 0.0, emax);
   deuteronEnergyDD105 = histoFactory->create1DLogx("deuteronEnergyDD105", "Angle 105 deg", "Deuteron energy (MeV)",
                                                "#sigma (mb)", 99, 1.0, emax);
   deuteronEnergyDD105Lin = histoFactory->create1D("deuteronEnergyDD105Lin", "Angle 105 deg", "Deuteron energy (MeV)",
                                                "#sigma (mb)", 99, 0.0, emax);
   tritonEnergyDD30 = histoFactory->create1DLogx("tritonEnergyDD30", "Angle 30 deg", "Triton energy (MeV)",
                                                "#sigma (mb)", 99, 1.0, emax);
   tritonEnergyDD30Lin = histoFactory->create1D("tritonEnergyDD30Lin", "Angle 30 deg", "Triton energy (MeV)",
                                                "#sigma (mb)", 99, 0.0, emax);
   tritonEnergyDD45 = histoFactory->create1DLogx("tritonEnergyDD45", "Angle 45 deg", "Triton energy (MeV)",
                                                "#sigma (mb)", 99, 1.0, emax);
   tritonEnergyDD45Lin = histoFactory->create1D("tritonEnergyDD45Lin", "Angle 45 deg", "Triton energy (MeV)",
                                                "#sigma (mb)", 99, 0.0, emax);
   tritonEnergyDD75 = histoFactory->create1DLogx("tritonEnergyDD75", "Angle 75 deg", "Triton energy (MeV)",
                                                "#sigma (mb)", 99, 1.0, emax);
   tritonEnergyDD75Lin = histoFactory->create1D("tritonEnergyDD75Lin", "Angle 75 deg", "Triton energy (MeV)",
                                                "#sigma (mb)", 99, 0.0, emax);
   tritonEnergyDD105 = histoFactory->create1DLogx("tritonEnergyDD105", "Angle 105 deg", "Triton energy (MeV)",
                                                "#sigma (mb)", 99, 1.0, emax);
   tritonEnergyDD105Lin = histoFactory->create1D("tritonEnergyDD105Lin", "Angle 105 deg", "Triton energy (MeV)",
                                                "#sigma (mb)", 99, 0.0, emax);
}

void FermiAnalyzer::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t FermiAnalyzer::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either FermiAnalyzer::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
  fChain->GetEntry(entry);
  //  Int_t numberOfEvents = 100000;
  Float_t dTheta = 2.0;
  Float_t weight = 1.0;
  //  Float_t crossSection = 2.220000e+02;
  if(A == 1 && Z == 0) {
    neutronEnergyIntegrated->Fill(kinE, GetWeight(crossSection, numberOfEvents));

    if(theta > (0.0 - dTheta) && theta < (0.0 + dTheta)) {
      weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 0.0, dTheta);
      neutronDD0->Fill(kinE, weight);
      neutronDD0Lin->Fill(kinE, weight/DDLinBinWidth);
    }

    if(theta > (5.0 - dTheta) && theta < (5.0 + dTheta)) {
      weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 5.0, dTheta);
      neutronDD5->Fill(kinE, weight);
      neutronDD5Lin->Fill(kinE, weight/DDLinBinWidth);
    }

    if(theta > (7.5 - dTheta) && theta < (7.5 + dTheta)) {
      weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 7.5, dTheta);
      neutronDD7_5->Fill(kinE, weight);
      neutronDD7_5Lin->Fill(kinE, weight/DDLinBinWidth);
    }

    if(theta > (10.0 - dTheta) && theta < (10.0 + dTheta)) {
      weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 10.0, dTheta);
      neutronDD10->Fill(kinE, weight);
      neutronDD10Lin->Fill(kinE, weight/DDLinBinWidth);
    }

    if(theta > (11.0 - dTheta) && theta < (11.0 + dTheta)) {
      weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 11.0, dTheta);
      neutronDD11->Fill(kinE, weight);
      neutronDD11Lin->Fill(kinE, weight/DDLinBinWidth);
    }

    if(theta > (25.0 - dTheta) && theta < (25.0 + dTheta)) {
      weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 25.0, dTheta);
      neutronDD25->Fill(kinE, weight);
      neutronDD25Lin->Fill(kinE, weight/DDLinBinWidth);
    }

    if(theta > (30.0 - dTheta) && theta < (30.0 + dTheta)) {
      weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 30.0, dTheta);
      neutronDD30->Fill(kinE, weight);
      neutronDD30Lin->Fill(kinE, weight/DDLinBinWidth);
    }

    if(theta > (50.0 - dTheta) && theta < (50.0 + dTheta)) {
      weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 50.0, dTheta);
      neutronDD50->Fill(kinE, weight);
      neutronDD50Lin->Fill(kinE, weight/DDLinBinWidth);
    }
  }
  if(A == 1 && Z == 1) {
    protonEnergyIntegrated->Fill(kinE, GetWeight(crossSection, numberOfEvents));
    protonEnergyIntegratedLogx->Fill(kinE, GetWeight(crossSection, numberOfEvents));
    if(theta > (11.0 - dTheta) && theta < (11.0 + dTheta)) {
      weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 11.0, dTheta);
      protonDD11->Fill(kinE, weight);
      protonMomentumDD11->Fill(mom, weight);
      protonDD11Lin->Fill(kinE, weight/DDLinBinWidth);
      protonMomentumDD11Lin->Fill(mom, weight);
    }

    if(theta > (13.0 - dTheta) && theta < (13.0 + dTheta)) {
      weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 13.0, dTheta);
      protonDD13->Fill(kinE, weight);
      protonMomentumDD13->Fill(mom, weight);
      protonDD13Lin->Fill(kinE, weight/DDLinBinWidth);
      protonMomentumDD13Lin->Fill(mom, weight);
    }

    if(theta > (15.0 - dTheta) && theta < (15.0 + dTheta)) {
      weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 15.0, dTheta);
      protonDD15->Fill(kinE, weight);
      protonMomentumDD15->Fill(mom, weight);
      protonDD15Lin->Fill(kinE, weight/DDLinBinWidth);
      protonMomentumDD15Lin->Fill(mom, weight);
    }

    if(theta > (20.0 - dTheta) && theta < (20.0 + dTheta)) {
      weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 20.0, dTheta);
      protonDD20->Fill(kinE, weight);
      protonMomentumDD20->Fill(mom, weight);
      protonDD20Lin->Fill(kinE, weight/DDLinBinWidth);
      protonMomentumDD20Lin->Fill(mom, weight);
    }

    if(theta > (25.0 - dTheta) && theta < (25.0 + dTheta)) {
      weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 25.0, dTheta);
      protonDD25->Fill(kinE, weight);
      protonMomentumDD25->Fill(mom, weight);
      protonDD25Lin->Fill(kinE, weight/DDLinBinWidth);
      protonMomentumDD25Lin->Fill(mom, weight);
    }

    if(theta > (30.0 - dTheta) && theta < (30.0 + dTheta)) {
      weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 30.0, dTheta);
      protonDD30->Fill(kinE, weight);
      protonMomentumDD30->Fill(mom, weight);
      protonDD30Lin->Fill(kinE, weight/DDLinBinWidth);
      protonMomentumDD30Lin->Fill(mom, weight);
    }

    if(theta > (50.0 - dTheta) && theta < (50.0 + dTheta)) {
      weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 50.0, dTheta);
      protonDD50->Fill(kinE, weight);
      protonMomentumDD30->Fill(mom, weight);
      protonDD50Lin->Fill(kinE, weight/DDLinBinWidth);
    }
  }
  //massnumbers->Fill(A);
  totalMassNumbers->Fill(A, GetWeight(crossSection, numberOfEvents));
  totalChargeNumbers->Fill(Z, GetWeight(crossSection, numberOfEvents));
  if(Z == 7) {
    nitrogenIsotopes->Fill(A, GetWeight(crossSection, numberOfEvents));
    chargenumbers->Fill(Z, GetWeight(crossSection, numberOfEvents));
  }
  if(Z == 6) {
    carbonIsotopes->Fill(A, GetWeight(crossSection, numberOfEvents));
    chargenumbers->Fill(Z, GetWeight(crossSection, numberOfEvents));
  }
  if(Z == 5) {
    boronIsotopes->Fill(A, GetWeight(crossSection, numberOfEvents));
    chargenumbers->Fill(Z, GetWeight(crossSection, numberOfEvents));
  }
  if(Z == 4) {
    berylliumIsotopes->Fill(A, GetWeight(crossSection, numberOfEvents));
    chargenumbers->Fill(Z, GetWeight(crossSection, numberOfEvents));
  }
  if(Z == 3) {
    lithiumIsotopes->Fill(A, GetWeight(crossSection, numberOfEvents));
    chargenumbers->Fill(Z, GetWeight(crossSection, numberOfEvents));
  }
  if(Z == 2) {
    heliumIsotopes->Fill(A, GetWeight(crossSection, numberOfEvents));
    chargenumbers->Fill(Z, GetWeight(crossSection, numberOfEvents));
    if(A == 3) {  // Helium3
    	if(theta > (30.0 - dTheta) && theta < (30.0 + dTheta)) {
		weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 30.0, dTheta);
		he3EnergyDD30->Fill(kinE, weight);
		he3EnergyDD30Lin->Fill(kinE, GetWeight(crossSection, numberOfEvents));	
	}
    	if(theta > (45.0 - dTheta) && theta < (45.0 + dTheta)) {
		weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 45.0, dTheta);
		he3EnergyDD45->Fill(kinE, weight);
		he3EnergyDD45Lin->Fill(kinE, GetWeight(crossSection, numberOfEvents));	
	}
    	if(theta > (75.0 - dTheta) && theta < (75.0 + dTheta)) {
		weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 75.0, dTheta);
		he3EnergyDD75->Fill(kinE, weight);
		he3EnergyDD75Lin->Fill(kinE, GetWeight(crossSection, numberOfEvents));	
	}
    	if(theta > (105.0 - dTheta) && theta < (105.0 + dTheta)) {
		weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 105.0, dTheta);
		he3EnergyDD105->Fill(kinE, weight);
		he3EnergyDD105Lin->Fill(kinE, GetWeight(crossSection, numberOfEvents));	
	}
    }
    if(A == 4) {  // Alphas
    	if(theta > (30.0 - dTheta) && theta < (30.0 + dTheta)) {
		weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 30.0, dTheta);
		alphaEnergyDD30->Fill(kinE, weight);
		alphaEnergyDD30Lin->Fill(kinE, GetWeight(crossSection, numberOfEvents));	
	}
    	if(theta > (45.0 - dTheta) && theta < (45.0 + dTheta)) {
		weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 45.0, dTheta);
		alphaEnergyDD45->Fill(kinE, weight);
		alphaEnergyDD45Lin->Fill(kinE, GetWeight(crossSection, numberOfEvents));	
	}
    	if(theta > (75.0 - dTheta) && theta < (75.0 + dTheta)) {
		weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 75.0, dTheta);
		alphaEnergyDD75->Fill(kinE, weight);
		alphaEnergyDD75Lin->Fill(kinE, GetWeight(crossSection, numberOfEvents));	
	}
    	if(theta > (105.0 - dTheta) && theta < (105.0 + dTheta)) {
		weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 105.0, dTheta);
		alphaEnergyDD105->Fill(kinE, weight);
		alphaEnergyDD105Lin->Fill(kinE, GetWeight(crossSection, numberOfEvents));	
	}
    }
  }
  if(Z == 1) {
    hydrogenIsotopes->Fill(A, GetWeight(crossSection, numberOfEvents));
    chargenumbers->Fill(Z, GetWeight(crossSection, numberOfEvents));
    if(A == 2) {  // Deuterons
    	if(theta > (30.0 - dTheta) && theta < (30.0 + dTheta)) {
		weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 30.0, dTheta);
		deuteronEnergyDD30->Fill(kinE, weight);
		deuteronEnergyDD30Lin->Fill(kinE, GetWeight(crossSection, numberOfEvents));	
	}
    	if(theta > (45.0 - dTheta) && theta < (45.0 + dTheta)) {
		weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 45.0, dTheta);
		deuteronEnergyDD45->Fill(kinE, weight);
		deuteronEnergyDD45Lin->Fill(kinE, GetWeight(crossSection, numberOfEvents));	
	}
    	if(theta > (75.0 - dTheta) && theta < (75.0 + dTheta)) {
		weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 75.0, dTheta);
		deuteronEnergyDD75->Fill(kinE, weight);
		deuteronEnergyDD75Lin->Fill(kinE, GetWeight(crossSection, numberOfEvents));	
	}
    	if(theta > (105.0 - dTheta) && theta < (105.0 + dTheta)) {
		weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 105.0, dTheta);
		deuteronEnergyDD105->Fill(kinE, weight);
		deuteronEnergyDD105Lin->Fill(kinE, GetWeight(crossSection, numberOfEvents));	
	}
    }
    if(A == 3) {  // Tritons
    	if(theta > (30.0 - dTheta) && theta < (30.0 + dTheta)) {
		weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 30.0, dTheta);
		tritonEnergyDD30->Fill(kinE, weight);
		tritonEnergyDD30Lin->Fill(kinE, GetWeight(crossSection, numberOfEvents));	
	}
    	if(theta > (45.0 - dTheta) && theta < (45.0 + dTheta)) {
		weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 45.0, dTheta);
		tritonEnergyDD45->Fill(kinE, weight);
		tritonEnergyDD45Lin->Fill(kinE, GetWeight(crossSection, numberOfEvents));	
	}
    	if(theta > (75.0 - dTheta) && theta < (75.0 + dTheta)) {
		weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 75.0, dTheta);
		tritonEnergyDD75->Fill(kinE, weight);
		tritonEnergyDD75Lin->Fill(kinE, GetWeight(crossSection, numberOfEvents));	
	}
    	if(theta > (105.0 - dTheta) && theta < (105.0 + dTheta)) {
		weight = GetDoubleDifferentialWeight(crossSection, numberOfEvents, 105.0, dTheta);
		tritonEnergyDD105->Fill(kinE, weight);
		tritonEnergyDD105Lin->Fill(kinE, GetWeight(crossSection, numberOfEvents));	
	}
    }
  }
  return kTRUE;
}

Float_t FermiAnalyzer::GetDoubleDifferentialWeight(Float_t crossSection, Int_t numberOfEvents, Float_t theta, Float_t dTheta)
{
  Float_t weight = 0.0;
  if((theta - dTheta) > 0.0) {
    weight = crossSection/(numberOfEvents * 2.0*TMath::Pi()*(TMath::Cos(TMath::DegToRad()*(0.0)) - TMath::Cos(TMath::DegToRad()*(theta + dTheta))));
  } else if ((theta + dTheta) > 180.0) {
    weight = crossSection/(numberOfEvents * 2.0*TMath::Pi()*(TMath::Cos(TMath::DegToRad()*(theta - dTheta)) - TMath::Cos(TMath::DegToRad()*(180.0))));
  } else {
    weight = crossSection/(numberOfEvents * 2.0*TMath::Pi()*(TMath::Cos(TMath::DegToRad()*(theta - dTheta)) - TMath::Cos(TMath::DegToRad()*(theta + dTheta))));
  }

  if(weight <= 0.0) { // Weight of 0 or less is probably not a good sign!
    cout <<"Analyzer: (File " << __FILE__ << " line " << __LINE__ << ") WARNING! weight = " << weight << endl;
  }
  return weight;
}

Float_t FermiAnalyzer::GetWeight(Float_t crossSection, Int_t numberOfEvents)
{
  return crossSection/double(numberOfEvents);
}

void FermiAnalyzer::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void FermiAnalyzer::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

  protonEnergyIntegratedLogx->Multiply(protonEnergyIntegratedLogx, ddHistBinWidths, 1.0, 1.0);
  neutronDD0->Multiply(neutronDD0, ddHistBinWidths, 1.0, 1.0);
  neutronDD5->Multiply(neutronDD5, ddHistBinWidths, 1.0, 1.0);
  neutronDD7_5->Multiply(neutronDD7_5, ddHistBinWidths, 1.0, 1.0);
  neutronDD10->Multiply(neutronDD10, ddHistBinWidths, 1.0, 1.0);
  neutronDD11->Multiply(neutronDD11, ddHistBinWidths, 1.0, 1.0);
  neutronDD25->Multiply(neutronDD25, ddHistBinWidths, 1.0, 1.0);
  neutronDD30->Multiply(neutronDD30, ddHistBinWidths, 1.0, 1.0);
  neutronDD50->Multiply(neutronDD50, ddHistBinWidths, 1.0, 1.0);

  protonDD11->Multiply(protonDD11, ddHistBinWidths, 1.0, 1.0);
  protonDD13->Multiply(protonDD13, ddHistBinWidths, 1.0, 1.0);
  protonDD15->Multiply(protonDD15, ddHistBinWidths, 1.0, 1.0);
  protonDD20->Multiply(protonDD20, ddHistBinWidths, 1.0, 1.0);
  protonDD25->Multiply(protonDD25, ddHistBinWidths, 1.0, 1.0);
  protonDD30->Multiply(protonDD30, ddHistBinWidths, 1.0, 1.0);
  protonDD50->Multiply(protonDD50, ddHistBinWidths, 1.0, 1.0);

  protonMomentumDD11->Multiply(protonMomentumDD11, ddPHistBinWidths, 1.0, 1.0);
  protonMomentumDD13->Multiply(protonMomentumDD13, ddPHistBinWidths, 1.0, 1.0);
  protonMomentumDD15->Multiply(protonMomentumDD15, ddPHistBinWidths, 1.0, 1.0);
  protonMomentumDD20->Multiply(protonMomentumDD20, ddPHistBinWidths, 1.0, 1.0);
  protonMomentumDD25->Multiply(protonMomentumDD25, ddPHistBinWidths, 1.0, 1.0);
  protonMomentumDD30->Multiply(protonMomentumDD30, ddPHistBinWidths, 1.0, 1.0);

  he3EnergyDD30->Multiply(he3EnergyDD30, ddHistBinWidths, 1.0, 1.0);
  he3EnergyDD45->Multiply(he3EnergyDD45, ddHistBinWidths, 1.0, 1.0);  
  he3EnergyDD75->Multiply(he3EnergyDD75, ddHistBinWidths, 1.0, 1.0);
  he3EnergyDD105->Multiply(he3EnergyDD105, ddHistBinWidths, 1.0, 1.0);

  alphaEnergyDD30->Multiply(alphaEnergyDD30, ddHistBinWidths, 1.0, 1.0);
  alphaEnergyDD45->Multiply(alphaEnergyDD45, ddHistBinWidths, 1.0, 1.0);  
  alphaEnergyDD75->Multiply(alphaEnergyDD75, ddHistBinWidths, 1.0, 1.0);
  alphaEnergyDD105->Multiply(alphaEnergyDD105, ddHistBinWidths, 1.0, 1.0);

  deuteronEnergyDD30->Multiply(deuteronEnergyDD30, ddHistBinWidths, 1.0, 1.0);
  deuteronEnergyDD45->Multiply(deuteronEnergyDD45, ddHistBinWidths, 1.0, 1.0);  
  deuteronEnergyDD75->Multiply(deuteronEnergyDD75, ddHistBinWidths, 1.0, 1.0);
  deuteronEnergyDD105->Multiply(deuteronEnergyDD105, ddHistBinWidths, 1.0, 1.0);

  tritonEnergyDD30->Multiply(tritonEnergyDD30, ddHistBinWidths, 1.0, 1.0);
  tritonEnergyDD45->Multiply(tritonEnergyDD45, ddHistBinWidths, 1.0, 1.0);  
  tritonEnergyDD75->Multiply(tritonEnergyDD75, ddHistBinWidths, 1.0, 1.0);
  tritonEnergyDD105->Multiply(tritonEnergyDD105, ddHistBinWidths, 1.0, 1.0);

  // Combine the mass distributions in the isotope production plots:
  massnumbers->Add(hydrogenIsotopes);
  massnumbers->Add(heliumIsotopes);
  massnumbers->Add(lithiumIsotopes);
  massnumbers->Add(berylliumIsotopes);
  massnumbers->Add(boronIsotopes);
  massnumbers->Add(carbonIsotopes);
  massnumbers->Add(nitrogenIsotopes);

  resultsOut->Write();
  resultsOut->Close();
}
