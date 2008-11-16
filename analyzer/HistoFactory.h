#ifndef HistoFactory_h
#define HistoFactory_h 1

#include "TObject.h"
#include "TH1F.h"

class HistoFactory : public TObject {

 public:
  HistoFactory();
  ~HistoFactory();

  void setGlobalHistoColor(Int_t color);
  void setStyle(TH1F *histogram, TString xlabel, TString ylabel);
  TH1F* create1D(TString name, TString title, TString xlabel, TString ylabel, Int_t bins, Float_t xmin, Float_t xmax);
  TH1F* create1DLogx(TString name, TString title, TString xlabel, TString ylabel, Int_t bins, Float_t xmin, Float_t xmax);

 protected:

 private:
  Int_t theGlobalHistoColor;
  ClassDef(HistoFactory, 1)
};

#endif
