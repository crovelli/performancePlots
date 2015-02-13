#include <iostream>
#include <string>
#include <stdlib.h>
#include "createHistos.h"


void createHistos::bookHistos(){

  bookHisto("phoErecoOverETrueFirstEtaBin",200,0,2);
  bookHisto("phoErecoOverETrueSecondEtaBin",200,0,2);
  bookHisto("phoErecoOverETrueThirdEtaBin",200,0,2);
  
  bookHisto("eleErecoOverETrueFirstEtaBin",200,0,2);
  bookHisto("eleErecoOverETrueSecondEtaBin",200,0,2);
  bookHisto("eleErecoOverETrueThirdEtaBin",200,0,2);

  bookHisto("eleErecoOverETrueFirstEtaBinFbrem02",200,0,2);
  bookHisto("eleErecoOverETrueSecondEtaBinFbrem02",200,0,2);
  bookHisto("eleErecoOverETrueThirdEtaBinFbrem02",200,0,2);

  bookHisto2D("sieieVsPhi",100,-3.,3.,100,0.,0.1);
  bookHisto2D("sieieVsPhiFirstEtaBin",100,-3.,3.,100,0.,0.1);
  bookHisto2D("sieieVsPhiSecondEtaBin",100,-3.,3.,100,0.,0.1);
  bookHisto2D("sieieVsPhiThirdEtaBin",100,-3.,3.,100,0.,0.1);
}


void createHistos::bookHisto(TString name, int nbins, float xLow, float xUp){
  histos_[name]=new TH1F(name, name, nbins,xLow,xUp);

}

void createHistos::bookHisto2D(TString name, int nbins, float xLow, float xUp,int nbinsY, float yLow, float yUp){
  histos2D_[name]=new TH2F(name, name, nbins,xLow,xUp,nbins, yLow,yUp);

}


void createHistos::writeHistos(){
  for(std::map<TString,TH1F*>::const_iterator out=histos_.begin();out!=histos_.end();++out){
    out->second->Write(out->first,TObject::kOverwrite);
  }

  for(std::map<TString,TH2F*>::const_iterator out=histos2D_.begin();out!=histos2D_.end();++out){
    out->second->Write(out->first,TObject::kOverwrite);
  }

 
}


void createHistos::Loop(){

  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntries();
  std::cout<<"nentries:"<<nentries<<std::endl;
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;           

    if(jentry%1000==0)std::cout<<"jentry:"<<jentry<<"/"<<nentries<<std::endl;

    float endcapBoundaryLow=1.5;
    float firstEtaBinUp=1.8;
    float secondEtaBinDown=1.8;
    float secondEtaBinUp=2.4;
    float thirdEtaBinDown=2.4;

    //loop on electrons
    for(int i=0;i<elen;i++){
      //matching with gen ele
      TLorentzVector elep4;
      elep4.SetPtEtaPhiM(elept[i],eleeta[i],elephi[i],0.);
      //      std::cout<<"etaele:"<<elep4.Eta();                                                                                                                                                                                           

      int geleindexMatch=-1;
      float drMatch=999;
      for(int j=0;j<gelen;j++){
	if(gelept[j]<5)continue;

	TLorentzVector gelep4;
	gelep4.SetPtEtaPhiM(gelept[j],geleeta[j],gelephi[j],0.);

	float dr=elep4.DeltaR(gelep4);

	if(dr<0.1 && dr<drMatch){
	  geleindexMatch=j;
	  drMatch=dr;
	}
      }
      //filling histos for electrons
      if(geleindexMatch!=-1 && TMath::Abs(eleeta[i])>endcapBoundaryLow){
	histos2D_["sieieVsPhi"]->Fill(elephi[i],elesiEtaiEtaZS[i]);
	//	std::cout<<elephi[i]<<" "<<elesiEtaiEtaZS[i]<<std::endl;
	if(TMath::Abs(eleeta[i])<firstEtaBinUp && TMath::Abs(eleeta[i])>endcapBoundaryLow){
	  histos_["eleErecoOverETrueFirstEtaBin"]->Fill(elee[i]/(gelept[geleindexMatch]*cosh(geleeta[geleindexMatch])));
	  if(gelefbrem80[geleindexMatch]<0.2)histos_["eleErecoOverETrueFirstEtaBinFbrem02"]->Fill(elee[i]/(gelept[geleindexMatch]*cosh(geleeta[geleindexMatch])));
	  histos2D_["sieieVsPhiThirdEtaBin"]->Fill(elephi[i],elesiEtaiEtaZS[i]);
	}
	else if(TMath::Abs(eleeta[i])>secondEtaBinDown && TMath::Abs(eleeta[i])<secondEtaBinUp){
	  histos_["eleErecoOverETrueSecondEtaBin"]->Fill(elee[i]/(gelept[geleindexMatch]*cosh(geleeta[geleindexMatch])));
	  if(gelefbrem80[geleindexMatch]<0.2)histos_["eleErecoOverETrueSecondEtaBinFbrem02"]->Fill(elee[i]/(gelept[geleindexMatch]*cosh(geleeta[geleindexMatch])));
	  histos2D_["sieieVsPhiSecondEtaBin"]->Fill(elephi[i],elesiEtaiEtaZS[i]);
	}
	else if(TMath::Abs(eleeta[i])>thirdEtaBinDown){
	  histos_["eleErecoOverETrueThirdEtaBin"]->Fill(elee[i]/(gelept[geleindexMatch]*cosh(geleeta[geleindexMatch])));
	  if(gelefbrem80[geleindexMatch]<0.2)histos_["eleErecoOverETrueThirdEtaBinFbrem02"]->Fill(elee[i]/(gelept[geleindexMatch]*cosh(geleeta[geleindexMatch])));
	  histos2D_["sieieVsPhiThirdEtaBin"]->Fill(elephi[i],elesiEtaiEtaZS[i]);
	}
      }
    }//elen


    //loop on photons
    for(int i=0;i<phon;i++){
      //matching with gen pho
      TLorentzVector phop4;
      phop4.SetPtEtaPhiM(phopt[i],phoeta[i],phophi[i],0.);
      //      std::cout<<"etapho:"<<phop4.Eta();                                                                                                                                                                                           

      int gphoindexMatch=-1;
      float drMatch=999;
      for(int j=0;j<gphon;j++){
	if(gphopt[j]<5)continue;

	TLorentzVector gphop4;
	gphop4.SetPtEtaPhiM(gphopt[j],gphoeta[j],gphophi[j],0.);

	float dr=phop4.DeltaR(gphop4);

	if(dr<0.1 && dr<drMatch){
	  gphoindexMatch=j;
	  drMatch=dr;
	}
      }
      //filling histos for phoctrons
      if(gphoindexMatch!=-1){
	if(TMath::Abs(phoeta[i])<firstEtaBinUp && TMath::Abs(phoeta[i])>endcapBoundaryLow){
	  histos_["phoErecoOverETrueFirstEtaBin"]->Fill(phoe[i]/(gphopt[gphoindexMatch]*cosh(gphoeta[gphoindexMatch])));
	}
	else if(TMath::Abs(phoeta[i])>secondEtaBinDown && TMath::Abs(phoeta[i])<secondEtaBinUp){
	  histos_["phoErecoOverETrueSecondEtaBin"]->Fill(phoe[i]/(gphopt[gphoindexMatch]*cosh(gphoeta[gphoindexMatch])));
	}
	else if(TMath::Abs(phoeta[i])>thirdEtaBinDown){
	  histos_["phoErecoOverETrueThirdEtaBin"]->Fill(phoe[i]/(gphopt[gphoindexMatch]*cosh(gphoeta[gphoindexMatch])));
	}
      }
    }//phon

	

  }

  
}

//void createHistos::setInputFile(TString inputFileString){
//  inputFile_=TFile::Open(inputFileString);
//  Init((TTree*)inputFile_->Get("tree"));
//
//}

void createHistos::setOutputFile(TString outputFileString){
  outputFile_=TFile::Open(outputFileString,"recreate");
}

createHistos::createHistos(TChain* chain){
  Init(chain);
}

createHistos::~createHistos()
{
  outputFile_->Write();
  outputFile_->Close();
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t createHistos::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t createHistos::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void createHistos::Init(TTree *tree)
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
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("nvtx", &nvtx, &b_nvtx);
   fChain->SetBranchAddress("vertexx", vertexx, &b_vertexx);
   fChain->SetBranchAddress("vertexy", vertexy, &b_vertexy);
   fChain->SetBranchAddress("vertexz", vertexz, &b_vertexz);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("phon", &phon, &b_phon);
   fChain->SetBranchAddress("phopt", phopt, &b_phopt);
   fChain->SetBranchAddress("phoeta", phoeta, &b_phoeta);
   fChain->SetBranchAddress("phophi", phophi, &b_phophi);
   fChain->SetBranchAddress("phoe", phoe, &b_phoe);
   fChain->SetBranchAddress("phoesc", phoesc, &b_phoesc);
   fChain->SetBranchAddress("phoetasc", phoetasc, &b_phoetasc);
   fChain->SetBranchAddress("phophisc", phophisc, &b_phophisc);
   fChain->SetBranchAddress("phoxsc", phoxsc, &b_phoxsc);
   fChain->SetBranchAddress("phoysc", phoysc, &b_phoysc);
   fChain->SetBranchAddress("phozsc", phozsc, &b_phozsc);
   fChain->SetBranchAddress("phoxcalo", phoxcalo, &b_phoxcalo);
   fChain->SetBranchAddress("phoycalo", phoycalo, &b_phoycalo);
   fChain->SetBranchAddress("phozcalo", phozcalo, &b_phozcalo);
   fChain->SetBranchAddress("phohasPixelSeed", phohasPixelSeed, &b_phohasPixelSeed);
   fChain->SetBranchAddress("phoisEB", phoisEB, &b_phoisEB);
   fChain->SetBranchAddress("phoisEE", phoisEE, &b_phoisEE);
   fChain->SetBranchAddress("phoisEBEEGap", phoisEBEEGap, &b_phoisEBEEGap);
   fChain->SetBranchAddress("phoE9", phoE9, &b_phoE9);
   fChain->SetBranchAddress("phoE25", phoE25, &b_phoE25);
   fChain->SetBranchAddress("phojurECAL", phojurECAL, &b_phojurECAL);
   fChain->SetBranchAddress("photwrHCAL", photwrHCAL, &b_photwrHCAL);
   fChain->SetBranchAddress("phoHoverE", phoHoverE, &b_phoHoverE);
   fChain->SetBranchAddress("phohlwTrack", phohlwTrack, &b_phohlwTrack);
   fChain->SetBranchAddress("phosiEtaiEtaZS", phosiEtaiEtaZS, &b_phosiEtaiEtaZS);
   fChain->SetBranchAddress("phosiEtaiEtaNoZS", phosiEtaiEtaNoZS, &b_phosiEtaiEtaNoZS);
   fChain->SetBranchAddress("phosiEtaiEtaWrong", phosiEtaiEtaWrong, &b_phosiEtaiEtaWrong);
   fChain->SetBranchAddress("phosiPhiiPhiZS", phosiPhiiPhiZS, &b_phosiPhiiPhiZS);
   fChain->SetBranchAddress("phosiPhiiPhiNoZS", phosiPhiiPhiNoZS, &b_phosiPhiiPhiNoZS);
   fChain->SetBranchAddress("phosiPhiiPhiWrong", phosiPhiiPhiWrong, &b_phosiPhiiPhiWrong);
   fChain->SetBranchAddress("phosMajZS", phosMajZS, &b_phosMajZS);
   fChain->SetBranchAddress("phosMajNoZS", phosMajNoZS, &b_phosMajNoZS);
   fChain->SetBranchAddress("phosMinZS", phosMinZS, &b_phosMinZS);
   fChain->SetBranchAddress("phosMinNoZS", phosMinNoZS, &b_phosMinNoZS);
   fChain->SetBranchAddress("phoalphaZS", phoalphaZS, &b_phoalphaZS);
   fChain->SetBranchAddress("phoalphaNoZS", phoalphaNoZS, &b_phoalphaNoZS);
   fChain->SetBranchAddress("phoscetawid", phoscetawid, &b_phoscetawid);
   fChain->SetBranchAddress("phoscphiwid", phoscphiwid, &b_phoscphiwid);
   fChain->SetBranchAddress("phojurECAL03", phojurECAL03, &b_phojurECAL03);
   fChain->SetBranchAddress("photwrHCAL03", photwrHCAL03, &b_photwrHCAL03);
   fChain->SetBranchAddress("phohlwTrack03", phohlwTrack03, &b_phohlwTrack03);
   fChain->SetBranchAddress("phopfCandPt", phopfCandPt, &b_phopfCandPt);
   fChain->SetBranchAddress("phopfCandEta", phopfCandEta, &b_phopfCandEta);
   fChain->SetBranchAddress("phopfCandPhi", phopfCandPhi, &b_phopfCandPhi);
   fChain->SetBranchAddress("phopfCandVtx", phopfCandVtx, &b_phopfCandVtx);
   fChain->SetBranchAddress("phopfCandType", phopfCandType, &b_phopfCandType);
   fChain->SetBranchAddress("phoptiso004", phoptiso004, &b_phoptiso004);
   fChain->SetBranchAddress("phontrkiso004", phontrkiso004, &b_phontrkiso004);
   fChain->SetBranchAddress("phoptiso035", phoptiso035, &b_phoptiso035);
   fChain->SetBranchAddress("phontrkiso035", phontrkiso035, &b_phontrkiso035);
   fChain->SetBranchAddress("phoptiso04", phoptiso04, &b_phoptiso04);
   fChain->SetBranchAddress("phontrkiso04", phontrkiso04, &b_phontrkiso04);
   fChain->SetBranchAddress("phoPfSumChargedHadronPt", phoPfSumChargedHadronPt, &b_phoPfSumChargedHadronPt);
   fChain->SetBranchAddress("phoPfSumNeutralHadronEt", phoPfSumNeutralHadronEt, &b_phoPfSumNeutralHadronEt);
   fChain->SetBranchAddress("phoPfSumPhotonEt", phoPfSumPhotonEt, &b_phoPfSumPhotonEt);
   fChain->SetBranchAddress("pfSCn", &pfSCn, &b_pfSCn);
   fChain->SetBranchAddress("pfSCeta", pfSCeta, &b_pfSCeta);
   fChain->SetBranchAddress("pfSCphi", pfSCphi, &b_pfSCphi);
   fChain->SetBranchAddress("pfSCe", pfSCe, &b_pfSCe);
   fChain->SetBranchAddress("pfSCnBC", pfSCnBC, &b_pfSCnBC);
   fChain->SetBranchAddress("pfSCnXtals", pfSCnXtals, &b_pfSCnXtals);
   fChain->SetBranchAddress("pfSCbcEta", pfSCbcEta, &b_pfSCbcEta);
   fChain->SetBranchAddress("pfSCbcPhi", pfSCbcPhi, &b_pfSCbcPhi);
   fChain->SetBranchAddress("pfSCbcE", pfSCbcE, &b_pfSCbcE);
   fChain->SetBranchAddress("multi5x5SCn", &multi5x5SCn, &b_multi5x5SCn);
   fChain->SetBranchAddress("multi5x5SCeta", &multi5x5SCeta, &b_multi5x5SCeta);
   fChain->SetBranchAddress("multi5x5SCphi", &multi5x5SCphi, &b_multi5x5SCphi);
   fChain->SetBranchAddress("multi5x5SCe", &multi5x5SCe, &b_multi5x5SCe);
   fChain->SetBranchAddress("multi5x5SCnBC", &multi5x5SCnBC, &b_multi5x5SCnBC);
   fChain->SetBranchAddress("multi5x5SCnXtals", &multi5x5SCnXtals, &b_multi5x5SCnXtals);
   fChain->SetBranchAddress("hybridSCn", &hybridSCn, &b_hybridSCn);
   fChain->SetBranchAddress("hybridSCeta", hybridSCeta, &b_hybridSCeta);
   fChain->SetBranchAddress("hybridSCphi", hybridSCphi, &b_hybridSCphi);
   fChain->SetBranchAddress("hybridSCe", hybridSCe, &b_hybridSCe);
   fChain->SetBranchAddress("hybridSCnBC", hybridSCnBC, &b_hybridSCnBC);
   fChain->SetBranchAddress("hybridSCnXtals", hybridSCnXtals, &b_hybridSCnXtals);
   fChain->SetBranchAddress("elen", &elen, &b_elen);
   fChain->SetBranchAddress("elepx", elepx, &b_elepx);
   fChain->SetBranchAddress("elepy", elepy, &b_elepy);
   fChain->SetBranchAddress("elepz", elepz, &b_elepz);
   fChain->SetBranchAddress("elevx", elevx, &b_elevx);
   fChain->SetBranchAddress("elevy", elevy, &b_elevy);
   fChain->SetBranchAddress("elevz", elevz, &b_elevz);
   fChain->SetBranchAddress("elept", elept, &b_elept);
   fChain->SetBranchAddress("eleeta", eleeta, &b_eleeta);
   fChain->SetBranchAddress("elephi", elephi, &b_elephi);
   fChain->SetBranchAddress("elee", elee, &b_elee);
   fChain->SetBranchAddress("eleecalEnergy", eleecalEnergy, &b_eleecalEnergy);
   fChain->SetBranchAddress("eletrackPatVtx", eletrackPatVtx, &b_eletrackPatVtx);
   fChain->SetBranchAddress("eletrackAtVtxPt", eletrackAtVtxPt, &b_eletrackAtVtxPt);
   fChain->SetBranchAddress("eletrackAtVtxEta", eletrackAtVtxEta, &b_eletrackAtVtxEta);
   fChain->SetBranchAddress("eletrackAtVtxPhi", eletrackAtVtxPhi, &b_eletrackAtVtxPhi);
   fChain->SetBranchAddress("eletrackAtCaloPt", eletrackAtCaloPt, &b_eletrackAtCaloPt);
   fChain->SetBranchAddress("eletrackAtCaloEta", eletrackAtCaloEta, &b_eletrackAtCaloEta);
   fChain->SetBranchAddress("eletrackAtCaloPhi", eletrackAtCaloPhi, &b_eletrackAtCaloPhi);
   fChain->SetBranchAddress("eleesc", eleesc, &b_eleesc);
   fChain->SetBranchAddress("eleetasc", eleetasc, &b_eleetasc);
   fChain->SetBranchAddress("elephisc", elephisc, &b_elephisc);
   fChain->SetBranchAddress("elexsc", elexsc, &b_elexsc);
   fChain->SetBranchAddress("eleysc", eleysc, &b_eleysc);
   fChain->SetBranchAddress("elezsc", elezsc, &b_elezsc);
   fChain->SetBranchAddress("elexcalo", elexcalo, &b_elexcalo);
   fChain->SetBranchAddress("eleycalo", eleycalo, &b_eleycalo);
   fChain->SetBranchAddress("elezcalo", elezcalo, &b_elezcalo);
   fChain->SetBranchAddress("eleisEB", eleisEB, &b_eleisEB);
   fChain->SetBranchAddress("eleisEE", eleisEE, &b_eleisEE);
   fChain->SetBranchAddress("eleisEBEEGap", eleisEBEEGap, &b_eleisEBEEGap);
   fChain->SetBranchAddress("eleE9", eleE9, &b_eleE9);
   fChain->SetBranchAddress("eleE25", eleE25, &b_eleE25);
   fChain->SetBranchAddress("elecharge", elecharge, &b_elecharge);
   fChain->SetBranchAddress("eleFbrem", eleFbrem, &b_eleFbrem);
   fChain->SetBranchAddress("eleScFbrem", eleScFbrem, &b_eleScFbrem);
   fChain->SetBranchAddress("elePfScFbrem", elePfScFbrem, &b_elePfScFbrem);
   fChain->SetBranchAddress("eleESeedClusterOverPout", eleESeedClusterOverPout, &b_eleESeedClusterOverPout);
   fChain->SetBranchAddress("eledist", eledist, &b_eledist);
   fChain->SetBranchAddress("eledcot", eledcot, &b_eledcot);
   fChain->SetBranchAddress("elemisHits", elemisHits, &b_elemisHits);
   fChain->SetBranchAddress("elematchedConv", elematchedConv, &b_elematchedConv);
   fChain->SetBranchAddress("eleseedType", eleseedType, &b_eleseedType);
   fChain->SetBranchAddress("eleEoP", eleEoP, &b_eleEoP);
   fChain->SetBranchAddress("eleOneOverEMinusOneOverP", eleOneOverEMinusOneOverP, &b_eleOneOverEMinusOneOverP);
   fChain->SetBranchAddress("eler9", eler9, &b_eler9);
   fChain->SetBranchAddress("elenSubClusters", elenSubClusters, &b_elenSubClusters);
   fChain->SetBranchAddress("eletrkIso", eletrkIso, &b_eletrkIso);
   fChain->SetBranchAddress("eleecalIso", eleecalIso, &b_eleecalIso);
   fChain->SetBranchAddress("elehcalIso", elehcalIso, &b_elehcalIso);
   fChain->SetBranchAddress("eletrkIso03", eletrkIso03, &b_eletrkIso03);
   fChain->SetBranchAddress("eleecalIso03", eleecalIso03, &b_eleecalIso03);
   fChain->SetBranchAddress("elehcalIso03", elehcalIso03, &b_elehcalIso03);
   fChain->SetBranchAddress("elesiEtaiEtaZS", elesiEtaiEtaZS, &b_elesiEtaiEtaZS);
   fChain->SetBranchAddress("elesiEtaiEtaNoZS", elesiEtaiEtaNoZS, &b_elesiEtaiEtaNoZS);
   fChain->SetBranchAddress("elesiEtaiEtaWrong", elesiEtaiEtaWrong, &b_elesiEtaiEtaWrong);
   fChain->SetBranchAddress("elesiPhiiPhiZS", elesiPhiiPhiZS, &b_elesiPhiiPhiZS);
   fChain->SetBranchAddress("elesiPhiiPhiNoZS", elesiPhiiPhiNoZS, &b_elesiPhiiPhiNoZS);
   fChain->SetBranchAddress("elesiPhiiPhiWrong", elesiPhiiPhiWrong, &b_elesiPhiiPhiWrong);
   fChain->SetBranchAddress("elesMajZS", elesMajZS, &b_elesMajZS);
   fChain->SetBranchAddress("elesMajNoZS", elesMajNoZS, &b_elesMajNoZS);
   fChain->SetBranchAddress("elesMinZS", elesMinZS, &b_elesMinZS);
   fChain->SetBranchAddress("elesMinNoZS", elesMinNoZS, &b_elesMinNoZS);
   fChain->SetBranchAddress("elealphaZS", elealphaZS, &b_elealphaZS);
   fChain->SetBranchAddress("elealphaNoZS", elealphaNoZS, &b_elealphaNoZS);
   fChain->SetBranchAddress("elepfCandPt", elepfCandPt, &b_elepfCandPt);
   fChain->SetBranchAddress("elepfCandEta", elepfCandEta, &b_elepfCandEta);
   fChain->SetBranchAddress("elepfCandPhi", elepfCandPhi, &b_elepfCandPhi);
   fChain->SetBranchAddress("elepfCandVtx", elepfCandVtx, &b_elepfCandVtx);
   fChain->SetBranchAddress("elepfCandType", elepfCandType, &b_elepfCandType);
   fChain->SetBranchAddress("eledEtaIn", eledEtaIn, &b_eledEtaIn);
   fChain->SetBranchAddress("eledPhiIn", eledPhiIn, &b_eledPhiIn);
   fChain->SetBranchAddress("eleHoE", eleHoE, &b_eleHoE);
   fChain->SetBranchAddress("elepFlowMVA", elepFlowMVA, &b_elepFlowMVA);
   fChain->SetBranchAddress("eleScEnergy", eleScEnergy, &b_eleScEnergy);
   fChain->SetBranchAddress("eleScEta", eleScEta, &b_eleScEta);
   fChain->SetBranchAddress("eleScPhi", eleScPhi, &b_eleScPhi);
   fChain->SetBranchAddress("elePfSumChargedHadronPt", elePfSumChargedHadronPt, &b_elePfSumChargedHadronPt);
   fChain->SetBranchAddress("elePfSumNeutralHadronEt", elePfSumNeutralHadronEt, &b_elePfSumNeutralHadronEt);
   fChain->SetBranchAddress("elePfSumPhotonEt", elePfSumPhotonEt, &b_elePfSumPhotonEt);
   fChain->SetBranchAddress("gpn", &gpn, &b_gpn);
   fChain->SetBranchAddress("gppt", gppt, &b_gppt);
   fChain->SetBranchAddress("gpeta", gpeta, &b_gpeta);
   fChain->SetBranchAddress("gpphi", gpphi, &b_gpphi);
   fChain->SetBranchAddress("gpidMC", gpidMC, &b_gpidMC);
   fChain->SetBranchAddress("gpstatusMC", gpstatusMC, &b_gpstatusMC);
   fChain->SetBranchAddress("gpmotherIdMC", gpmotherIdMC, &b_gpmotherIdMC);
   fChain->SetBranchAddress("gphon", &gphon, &b_gphon);
   fChain->SetBranchAddress("gphopt", gphopt, &b_gphopt);
   fChain->SetBranchAddress("gphoeta", gphoeta, &b_gphoeta);
   fChain->SetBranchAddress("gphophi", gphophi, &b_gphophi);
   fChain->SetBranchAddress("gphoindex", gphoindex, &b_gphoindex);
   fChain->SetBranchAddress("gelen", &gelen, &b_gelen);
   fChain->SetBranchAddress("gelept", gelept, &b_gelept);
   fChain->SetBranchAddress("geleeta", geleeta, &b_geleeta);
   fChain->SetBranchAddress("gelephi", gelephi, &b_gelephi);
   fChain->SetBranchAddress("gelefbrem80", gelefbrem80, &b_gelefbrem80);
   fChain->SetBranchAddress("gelefbrem120", gelefbrem120, &b_gelefbrem120);
   fChain->SetBranchAddress("geleindex", geleindex, &b_geleindex);
   fChain->SetBranchAddress("truePU", &truePU, &b_truePU);
   fChain->SetBranchAddress("bxPU", bxPU, &b_bxPU);
   Notify();
}

Bool_t createHistos::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void createHistos::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t createHistos::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
