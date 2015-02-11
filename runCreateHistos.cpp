#include <iostream>
#include <string>
#include <stdlib.h>
#include "createHistos.h"






int main( int argc, char* argv[] ) {
  

  createHistos theHistos("/afs/cern.ch/work/m/micheli/shashlikPerformance/CMSSW_6_2_0_SLHC23_patch1/src/Dumper/dumper/test/outDumper.root");
  

  theHistos.setOutputFile("outFile.root");
  theHistos.bookHistos();
  theHistos.Loop();
  theHistos.writeHistos();

  return 0;
}
