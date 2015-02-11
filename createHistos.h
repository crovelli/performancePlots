//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Feb 11 14:48:32 2015 by ROOT version 5.34/07
// from TTree tree/tree
// found on file: outDumper.root
//////////////////////////////////////////////////////////

#ifndef createHistos_h
#define createHistos_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "TH1D.h"
#include "TH2D.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TPaveText.h"
#include "TLegend.h"
#include "TTree.h"
#include "TRandom.h"
#include "TMath.h"
#include "TLorentzVector.h"
#include "TObject.h"
#include "TString.h"
#include "TChain.h"

// Header file for the classes stored in the TTree if any.
#define MAXPARTICLESTOSAVE 100
#define MAXPHOTONSTOSAVE 20
#define MAXSCTOSAVE 200
#define MAXBCTOSAVE 200
#define MAXPFCANDTOSAVE 200


// Fixed size dimensions of array or collections stored in the TTree if any.

class createHistos {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   std::map<TString,TH1F*> histos_;
   //   TFile* inputFile_;
   TFile* outputFile_;

   // Declaration of leaf types
   Int_t           nvtx;
   Float_t         vertexx[200];   //[nvtx]
   Float_t         vertexy[200];   //[nvtx]
   Float_t         vertexz[200];   //[nvtx]
   Float_t         rho;
   Int_t           phon;
   Float_t         phopt[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoeta[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phophi[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoe[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoesc[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoetasc[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phophisc[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoxsc[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoysc[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phozsc[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoxcalo[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoycalo[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phozcalo[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phohasPixelSeed[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoisEB[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoisEE[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoisEBEEGap[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoE9[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoE25[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phojurECAL[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         photwrHCAL[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoHoverE[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phohlwTrack[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phosiEtaiEtaZS[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phosiEtaiEtaNoZS[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phosiEtaiEtaWrong[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phosiPhiiPhiZS[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phosiPhiiPhiNoZS[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phosiPhiiPhiWrong[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phosMajZS[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phosMajNoZS[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phosMinZS[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phosMinNoZS[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoalphaZS[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoalphaNoZS[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoscetawid[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoscphiwid[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phojurECAL03[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         photwrHCAL03[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phohlwTrack03[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phopfCandPt[MAXPFCANDTOSAVE][MAXPHOTONSTOSAVE];
   Float_t         phopfCandEta[MAXPFCANDTOSAVE][MAXPHOTONSTOSAVE];
   Float_t         phopfCandPhi[MAXPFCANDTOSAVE][MAXPHOTONSTOSAVE];
   Float_t         phopfCandVtx[MAXPFCANDTOSAVE][MAXPHOTONSTOSAVE];
   Float_t         phopfCandType[MAXPFCANDTOSAVE][MAXPHOTONSTOSAVE];
   Float_t         phoptiso004[MAXPHOTONSTOSAVE];   //[phon]
   Int_t           phontrkiso004[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoptiso035[MAXPHOTONSTOSAVE];   //[phon]
   Int_t           phontrkiso035[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoptiso04[MAXPHOTONSTOSAVE];   //[phon]
   Int_t           phontrkiso04[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoPfSumChargedHadronPt[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoPfSumNeutralHadronEt[MAXPHOTONSTOSAVE];   //[phon]
   Float_t         phoPfSumPhotonEt[MAXPHOTONSTOSAVE];   //[phon]
   Int_t           pfSCn;
   Float_t         pfSCeta[MAXSCTOSAVE];   //[pfSCn]
   Float_t         pfSCphi[MAXSCTOSAVE];   //[pfSCn]
   Float_t         pfSCe[MAXSCTOSAVE];   //[pfSCn]
   Int_t           pfSCnBC[MAXSCTOSAVE];   //[pfSCn]
   Float_t         pfSCnXtals[MAXSCTOSAVE];   //[pfSCn]
   Float_t         pfSCbcEta[MAXBCTOSAVE][MAXSCTOSAVE];
   Float_t         pfSCbcPhi[MAXBCTOSAVE][MAXSCTOSAVE];
   Float_t         pfSCbcE[MAXBCTOSAVE][MAXSCTOSAVE];
   Int_t           multi5x5SCn;
   Float_t         multi5x5SCeta[MAXSCTOSAVE];   //[multi5x5SCn]
   Float_t         multi5x5SCphi[MAXSCTOSAVE];   //[multi5x5SCn]
   Float_t         multi5x5SCe[MAXSCTOSAVE];   //[multi5x5SCn]
   Float_t         multi5x5SCnBC[MAXSCTOSAVE];   //[multi5x5SCn]
   Float_t         multi5x5SCnXtals[MAXSCTOSAVE];   //[multi5x5SCn]
   Int_t           hybridSCn;
   Float_t         hybridSCeta[MAXSCTOSAVE];   //[hybridSCn]
   Float_t         hybridSCphi[MAXSCTOSAVE];   //[hybridSCn]
   Float_t         hybridSCe[MAXSCTOSAVE];   //[hybridSCn]
   Float_t         hybridSCnBC[MAXSCTOSAVE];   //[hybridSCn]
   Float_t         hybridSCnXtals[MAXSCTOSAVE];   //[hybridSCn]
   Int_t           elen;
   Float_t         elepx[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elepy[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elepz[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elevx[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elevy[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elevz[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elept[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleeta[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elephi[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elee[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleecalEnergy[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eletrackPatVtx[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eletrackAtVtxPt[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eletrackAtVtxEta[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eletrackAtVtxPhi[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eletrackAtCaloPt[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eletrackAtCaloEta[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eletrackAtCaloPhi[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleesc[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleetasc[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elephisc[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elexsc[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleysc[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elezsc[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elexcalo[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleycalo[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elezcalo[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleisEB[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleisEE[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleisEBEEGap[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleE9[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleE25[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elecharge[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleFbrem[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleScFbrem[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elePfScFbrem[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleESeedClusterOverPout[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eledist[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eledcot[MAXPHOTONSTOSAVE];   //[elen]
   Int_t           elemisHits[MAXPHOTONSTOSAVE];   //[elen]
   Int_t           elematchedConv[MAXPHOTONSTOSAVE];   //[elen]
   Int_t           eleseedType[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleEoP[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleOneOverEMinusOneOverP[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eler9[MAXPHOTONSTOSAVE];   //[elen]
   Int_t           elenSubClusters[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eletrkIso[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleecalIso[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elehcalIso[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eletrkIso03[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleecalIso03[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elehcalIso03[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elesiEtaiEtaZS[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elesiEtaiEtaNoZS[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elesiEtaiEtaWrong[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elesiPhiiPhiZS[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elesiPhiiPhiNoZS[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elesiPhiiPhiWrong[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elesMajZS[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elesMajNoZS[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elesMinZS[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elesMinNoZS[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elealphaZS[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elealphaNoZS[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elepfCandPt[MAXPFCANDTOSAVE][MAXPHOTONSTOSAVE];
   Float_t         elepfCandEta[MAXPFCANDTOSAVE][MAXPHOTONSTOSAVE];
   Float_t         elepfCandPhi[MAXPFCANDTOSAVE][MAXPHOTONSTOSAVE];
   Float_t         elepfCandVtx[MAXPFCANDTOSAVE][MAXPHOTONSTOSAVE];
   Float_t         elepfCandType[MAXPFCANDTOSAVE][MAXPHOTONSTOSAVE];
   Float_t         eledEtaIn[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eledPhiIn[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleHoE[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elepFlowMVA[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleScEnergy[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleScEta[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         eleScPhi[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elePfSumChargedHadronPt[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elePfSumNeutralHadronEt[MAXPHOTONSTOSAVE];   //[elen]
   Float_t         elePfSumPhotonEt[MAXPHOTONSTOSAVE];   //[elen]
   Int_t           gpn;
   Float_t         gppt[MAXPARTICLESTOSAVE];   //[gpn]
   Float_t         gpeta[MAXPARTICLESTOSAVE];   //[gpn]
   Float_t         gpphi[MAXPARTICLESTOSAVE];   //[gpn]
   Int_t           gpidMC[MAXPARTICLESTOSAVE];   //[gpn]
   Int_t           gpstatusMC[MAXPARTICLESTOSAVE];   //[gpn]
   Int_t           gpmotherIdMC[MAXPARTICLESTOSAVE];   //[gpn]
   Int_t           gphon;
   Float_t         gphopt[MAXPHOTONSTOSAVE];   //[gphon]
   Float_t         gphoeta[MAXPHOTONSTOSAVE];   //[gphon]
   Float_t         gphophi[MAXPHOTONSTOSAVE];   //[gphon]
   Int_t           gphoindex[MAXPHOTONSTOSAVE];   //[gphon]
   Int_t           gelen;
   Float_t         gelept[MAXPHOTONSTOSAVE];   //[gelen]
   Float_t         geleeta[MAXPHOTONSTOSAVE];   //[gelen]
   Float_t         gelephi[MAXPHOTONSTOSAVE];   //[gelen]
   Float_t         gelefbrem80[MAXPHOTONSTOSAVE];   //[gelen]
   Float_t         gelefbrem120[MAXPHOTONSTOSAVE];   //[gelen]
   Int_t           geleindex[MAXPHOTONSTOSAVE];   //[gelen]
   Float_t         truePU;
   Int_t           bxPU[16];

   // List of branches
   TBranch        *b_nvtx;   //!
   TBranch        *b_vertexx;   //!
   TBranch        *b_vertexy;   //!
   TBranch        *b_vertexz;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_phon;   //!
   TBranch        *b_phopt;   //!
   TBranch        *b_phoeta;   //!
   TBranch        *b_phophi;   //!
   TBranch        *b_phoe;   //!
   TBranch        *b_phoesc;   //!
   TBranch        *b_phoetasc;   //!
   TBranch        *b_phophisc;   //!
   TBranch        *b_phoxsc;   //!
   TBranch        *b_phoysc;   //!
   TBranch        *b_phozsc;   //!
   TBranch        *b_phoxcalo;   //!
   TBranch        *b_phoycalo;   //!
   TBranch        *b_phozcalo;   //!
   TBranch        *b_phohasPixelSeed;   //!
   TBranch        *b_phoisEB;   //!
   TBranch        *b_phoisEE;   //!
   TBranch        *b_phoisEBEEGap;   //!
   TBranch        *b_phoE9;   //!
   TBranch        *b_phoE25;   //!
   TBranch        *b_phojurECAL;   //!
   TBranch        *b_photwrHCAL;   //!
   TBranch        *b_phoHoverE;   //!
   TBranch        *b_phohlwTrack;   //!
   TBranch        *b_phosiEtaiEtaZS;   //!
   TBranch        *b_phosiEtaiEtaNoZS;   //!
   TBranch        *b_phosiEtaiEtaWrong;   //!
   TBranch        *b_phosiPhiiPhiZS;   //!
   TBranch        *b_phosiPhiiPhiNoZS;   //!
   TBranch        *b_phosiPhiiPhiWrong;   //!
   TBranch        *b_phosMajZS;   //!
   TBranch        *b_phosMajNoZS;   //!
   TBranch        *b_phosMinZS;   //!
   TBranch        *b_phosMinNoZS;   //!
   TBranch        *b_phoalphaZS;   //!
   TBranch        *b_phoalphaNoZS;   //!
   TBranch        *b_phoscetawid;   //!
   TBranch        *b_phoscphiwid;   //!
   TBranch        *b_phojurECAL03;   //!
   TBranch        *b_photwrHCAL03;   //!
   TBranch        *b_phohlwTrack03;   //!
   TBranch        *b_phopfCandPt;   //!
   TBranch        *b_phopfCandEta;   //!
   TBranch        *b_phopfCandPhi;   //!
   TBranch        *b_phopfCandVtx;   //!
   TBranch        *b_phopfCandType;   //!
   TBranch        *b_phoptiso004;   //!
   TBranch        *b_phontrkiso004;   //!
   TBranch        *b_phoptiso035;   //!
   TBranch        *b_phontrkiso035;   //!
   TBranch        *b_phoptiso04;   //!
   TBranch        *b_phontrkiso04;   //!
   TBranch        *b_phoPfSumChargedHadronPt;   //!
   TBranch        *b_phoPfSumNeutralHadronEt;   //!
   TBranch        *b_phoPfSumPhotonEt;   //!
   TBranch        *b_pfSCn;   //!
   TBranch        *b_pfSCeta;   //!
   TBranch        *b_pfSCphi;   //!
   TBranch        *b_pfSCe;   //!
   TBranch        *b_pfSCnBC;   //!
   TBranch        *b_pfSCnXtals;   //!
   TBranch        *b_pfSCbcEta;   //!
   TBranch        *b_pfSCbcPhi;   //!
   TBranch        *b_pfSCbcE;   //!
   TBranch        *b_multi5x5SCn;   //!
   TBranch        *b_multi5x5SCeta;   //!
   TBranch        *b_multi5x5SCphi;   //!
   TBranch        *b_multi5x5SCe;   //!
   TBranch        *b_multi5x5SCnBC;   //!
   TBranch        *b_multi5x5SCnXtals;   //!
   TBranch        *b_hybridSCn;   //!
   TBranch        *b_hybridSCeta;   //!
   TBranch        *b_hybridSCphi;   //!
   TBranch        *b_hybridSCe;   //!
   TBranch        *b_hybridSCnBC;   //!
   TBranch        *b_hybridSCnXtals;   //!
   TBranch        *b_elen;   //!
   TBranch        *b_elepx;   //!
   TBranch        *b_elepy;   //!
   TBranch        *b_elepz;   //!
   TBranch        *b_elevx;   //!
   TBranch        *b_elevy;   //!
   TBranch        *b_elevz;   //!
   TBranch        *b_elept;   //!
   TBranch        *b_eleeta;   //!
   TBranch        *b_elephi;   //!
   TBranch        *b_elee;   //!
   TBranch        *b_eleecalEnergy;   //!
   TBranch        *b_eletrackPatVtx;   //!
   TBranch        *b_eletrackAtVtxPt;   //!
   TBranch        *b_eletrackAtVtxEta;   //!
   TBranch        *b_eletrackAtVtxPhi;   //!
   TBranch        *b_eletrackAtCaloPt;   //!
   TBranch        *b_eletrackAtCaloEta;   //!
   TBranch        *b_eletrackAtCaloPhi;   //!
   TBranch        *b_eleesc;   //!
   TBranch        *b_eleetasc;   //!
   TBranch        *b_elephisc;   //!
   TBranch        *b_elexsc;   //!
   TBranch        *b_eleysc;   //!
   TBranch        *b_elezsc;   //!
   TBranch        *b_elexcalo;   //!
   TBranch        *b_eleycalo;   //!
   TBranch        *b_elezcalo;   //!
   TBranch        *b_eleisEB;   //!
   TBranch        *b_eleisEE;   //!
   TBranch        *b_eleisEBEEGap;   //!
   TBranch        *b_eleE9;   //!
   TBranch        *b_eleE25;   //!
   TBranch        *b_elecharge;   //!
   TBranch        *b_eleFbrem;   //!
   TBranch        *b_eleScFbrem;   //!
   TBranch        *b_elePfScFbrem;   //!
   TBranch        *b_eleESeedClusterOverPout;   //!
   TBranch        *b_eledist;   //!
   TBranch        *b_eledcot;   //!
   TBranch        *b_elemisHits;   //!
   TBranch        *b_elematchedConv;   //!
   TBranch        *b_eleseedType;   //!
   TBranch        *b_eleEoP;   //!
   TBranch        *b_eleOneOverEMinusOneOverP;   //!
   TBranch        *b_eler9;   //!
   TBranch        *b_elenSubClusters;   //!
   TBranch        *b_eletrkIso;   //!
   TBranch        *b_eleecalIso;   //!
   TBranch        *b_elehcalIso;   //!
   TBranch        *b_eletrkIso03;   //!
   TBranch        *b_eleecalIso03;   //!
   TBranch        *b_elehcalIso03;   //!
   TBranch        *b_elesiEtaiEtaZS;   //!
   TBranch        *b_elesiEtaiEtaNoZS;   //!
   TBranch        *b_elesiEtaiEtaWrong;   //!
   TBranch        *b_elesiPhiiPhiZS;   //!
   TBranch        *b_elesiPhiiPhiNoZS;   //!
   TBranch        *b_elesiPhiiPhiWrong;   //!
   TBranch        *b_elesMajZS;   //!
   TBranch        *b_elesMajNoZS;   //!
   TBranch        *b_elesMinZS;   //!
   TBranch        *b_elesMinNoZS;   //!
   TBranch        *b_elealphaZS;   //!
   TBranch        *b_elealphaNoZS;   //!
   TBranch        *b_elepfCandPt;   //!
   TBranch        *b_elepfCandEta;   //!
   TBranch        *b_elepfCandPhi;   //!
   TBranch        *b_elepfCandVtx;   //!
   TBranch        *b_elepfCandType;   //!
   TBranch        *b_eledEtaIn;   //!
   TBranch        *b_eledPhiIn;   //!
   TBranch        *b_eleHoE;   //!
   TBranch        *b_elepFlowMVA;   //!
   TBranch        *b_eleScEnergy;   //!
   TBranch        *b_eleScEta;   //!
   TBranch        *b_eleScPhi;   //!
   TBranch        *b_elePfSumChargedHadronPt;   //!
   TBranch        *b_elePfSumNeutralHadronEt;   //!
   TBranch        *b_elePfSumPhotonEt;   //!
   TBranch        *b_gpn;   //!
   TBranch        *b_gppt;   //!
   TBranch        *b_gpeta;   //!
   TBranch        *b_gpphi;   //!
   TBranch        *b_gpidMC;   //!
   TBranch        *b_gpstatusMC;   //!
   TBranch        *b_gpmotherIdMC;   //!
   TBranch        *b_gphon;   //!
   TBranch        *b_gphopt;   //!
   TBranch        *b_gphoeta;   //!
   TBranch        *b_gphophi;   //!
   TBranch        *b_gphoindex;   //!
   TBranch        *b_gelen;   //!
   TBranch        *b_gelept;   //!
   TBranch        *b_geleeta;   //!
   TBranch        *b_gelephi;   //!
   TBranch        *b_gelefbrem80;   //!
   TBranch        *b_gelefbrem120;   //!
   TBranch        *b_geleindex;   //!
   TBranch        *b_truePU;   //!
   TBranch        *b_bxPU;   //!

   createHistos(TChain* chain);
   virtual ~createHistos();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   void bookHisto(TString name, int nbins, float xLow, float xUp);
   void bookHistos();
   void writeHistos();
   //   void setInputFile(TString name);
   void setOutputFile(TString nameFile);

};



#endif
