#include "HistoFactory.h"

ClassImp(HistoFactory)

HistoFactory::HistoFactory()
{

}

HistoFactory::~HistoFactory()
{

}

TH1F* HistoFactory::create1D(TString name, TString title, TString xlabel, TString ylabel, Int_t bins, Float_t xmin, Float_t xmax)
{
  TH1F *histogram;
  histogram = new TH1F(name, title, bins, xmin, xmax);
  histogram->GetXaxis()->SetTitle(xlabel);
  histogram->GetYaxis()->SetTitle(ylabel);
  histogram->SetLineWidth(2);
  return histogram;
}
