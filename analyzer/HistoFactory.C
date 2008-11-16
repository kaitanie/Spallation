#include <Riostream.h>
#include "HistoFactory.h"

ClassImp(HistoFactory)

HistoFactory::HistoFactory()
{

}

HistoFactory::~HistoFactory()
{

}

void HistoFactory::setGlobalHistoColor(Int_t color)
{
  theGlobalHistoColor = color;
}

void HistoFactory::setStyle(TH1F *histogram, TString xlabel, TString ylabel)
{
  histogram->GetXaxis()->SetTitle(xlabel);
  histogram->GetYaxis()->SetTitle(ylabel);
  histogram->SetLineWidth(2);
}

TH1F* HistoFactory::create1D(TString name, TString title, TString xlabel, TString ylabel, Int_t bins, Float_t xmin, Float_t xmax)
{
  TH1F *histogram;
  histogram = new TH1F(name, title, bins, xmin, xmax);
  setStyle(histogram, xlabel, ylabel);
  return histogram;
}

TH1F* HistoFactory::create1DLogx(TString name, TString title, TString xlabel, TString ylabel, const Int_t bins, Float_t xmin, Float_t xmax)
{
  TH1F *histogram;
  if(xmin <= 0.0) {
    cout <<"HistoFactory: Error. Logarithmic x-axis minimum value <= 0!" << endl;
    xmin = 1.0;
  }
  Float_t xbins[bins+1];
  //   DDLinBinWidth = emax/Float_t(bins);
  const Float_t fact=(log(xmax)-log(xmin))/bins;
  for(Int_t i=0; i<bins+1; ++i) {
    xbins[i] = exp(log(xmin) + fact*i);
  }

  histogram = new TH1F(name, title, 99, xbins);
  setStyle(histogram, xlabel, ylabel);

  return histogram;
}
