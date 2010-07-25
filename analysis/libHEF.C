#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <TH1D.h>

class HEF {
public:
  HEF(std::string fname) {
    theFileName = fname;
    isOpen = false;
  };

  ~HEF() {
    if(isOpen) {
      close();
    }
  };
    
  void open() {
    if(isOpen == false) {
      out = new ofstream(theFileName.c_str());
      generateHeaderCode();
      isOpen = true;
    } else {
      cout <<"HEF: File is already open..." << endl;
    }
  };

  void close() {
    if(isOpen) {
      generateClosingCode();
      out->close();
      isOpen = false;
    } else {
      cout <<"HEF: File is not open..." << endl;
    }
  };

  void writeHisto(TH1D *histo) {
    if(isOpen) {
      generateHistoCode(histo);
    } else {
      cout <<"HEF: File is not open..." << endl;
    }
  };

private:
  void generateHeaderCode() {
    std::stringstream entry;
    entry << "(hef-file :comment \"My HEF file\"" << std::endl
	  << " :data [ ;; Open the list of histograms" << std::endl;
    std::string message = entry.str();
    out->write(message.c_str(), message.size());
  }

  void generateHistoCode(TH1D *histo) {
    std::stringstream entry;
    entry << "(hef-histogram :name \"" << histo->GetName() << "\"" << std::endl
	  << ":title \"" << histo->GetTitle() <<"\"" << std::endl
	  << ":data [" <<std::endl;
    for(int i = 1; i <= histo->GetNbinsX(); ++i) {
      entry <<"{:xmin " << histo->GetBinLowEdge(i)
	    << " :xmax " << histo->GetBinLowEdge(i + 1)
	    << " :content " << histo->GetBinContent(i) << "}" << std::endl;
    }
    entry << "] ;; Close the data list" << std::endl;
    entry << ") ;; Close the histogram" << std::endl;
    std::string message = entry.str();
    out->write(message.c_str(), message.size());
  };

  void generateClosingCode() {
    std::stringstream entry;
    entry << "] ;; Closes the data list" << std::endl
	  << ") ;; Closes the HEF file" << std::endl;
    std::string message = entry.str();
    out->write(message.c_str(), message.size());
  };

private:
  std::string theFileName;
  std::ofstream *out;
  Bool_t isOpen;
};
