#ifndef HistoFactory_h
#define HistoFactory_h 1

#include "TObject.h"
#include "TH1F.h"

class HistoFactory : public TObject {

 public:
  HistoFactory();
  ~HistoFactory();

  TH1F* create1D(TString name, TString title, TString xlabel, TString ylabel, Int_t bins, Float_t xmin, Float_t xmax);

 protected:

 private:

  ClassDef(HistoFactory, 1)
};

#endif
