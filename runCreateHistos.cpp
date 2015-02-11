#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "createHistos.h"

using namespace std;



int main( int argc, char* argv[] ) {



  if(argc<2 || argc>3) {
    cout << "Usage:  ./tmp/runCreateHistos listfile outputfile\n"
	 << "  listfile:    list of root files incusing protocol eg dcap:/// .....\n"
	 << "  outputfile:  name of output root file  eg output.root\n"
	 << endl;
    exit(-1);
  }


  
  // Input list
  char listName[500];
  sprintf(listName,argv[1]); 
  
  // Output filename (.root)  
  TString OutputFileName(argv[2]);
  
  // Name of input tree objects in (.root) files 
  char treeName[100] = "tree";

  //creating  TChain
  TChain *chain = new TChain(treeName);
  char pName[500];
  ifstream is(listName);
  if(! is.good()) {
    cout << "int main() >> ERROR : file " << listName << " not read" << endl;
    is.close();
    exit(-1);
  }
  cout << "Reading list : " << listName << " ......." << endl;
  
  while( is.getline(pName, 500, '\n') ) {
    if (pName[0] == '#') continue;
    chain->Add(pName); 
  }
  is.close();
  

  createHistos theHistos(chain);
  

  theHistos.setOutputFile(OutputFileName);
  theHistos.bookHistos();
  theHistos.Loop();
  theHistos.writeHistos();

  return 0;
}
