//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Feb 22 14:34:41 2017 by ROOT version 6.04/16
// from TTree Nominal/Nominal
// found on file: /export/scratch2/amontalb/Janv26_mj/fetch/data-MVATree/data16-11.root
//////////////////////////////////////////////////////////

#ifndef Nominal_h
#define Nominal_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "string"

class Nominal {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           nFats;
   Int_t           nJets;
   Int_t           nTags;
   Int_t           nTaus;
   Int_t           j1Flav;
   Int_t           j2Flav;
   Int_t           nMuons;
   Int_t           passTrig;
   Int_t           nElectrons;
   Int_t           EventNumber;
   Int_t           EventRegime;
   Float_t         WM;
   Float_t         lM;
   Float_t         mu;
   Float_t         WMt;
   Float_t         WPt;
   Float_t         j1M;
   Float_t         j2M;
   Float_t         jjM;
   Float_t         lPt;
   Float_t         met;
   Float_t         WPhi;
   Float_t         WjjM;
   Float_t         j1Pt;
   Float_t         j2Pt;
   Float_t         jjPt;
   Float_t         jjdR;
   Float_t         lEta;
   Float_t         lPhi;
   Float_t         j1Eta;
   Float_t         j1Phi;
   Float_t         j2Eta;
   Float_t         j2Phi;
   Float_t         jjEta;
   Float_t         jjPhi;
   Float_t         BTagSF;
   Float_t         jjdEta;
   Float_t         jjdPhi;
   Float_t         jldPhi;
   Float_t         WjjdPhi;
   Float_t         LeptonSF;
   Float_t         PUWeight;
   Float_t         j1MV2c20;
   Float_t         j2MV2c20;
   Float_t         jmetdPhi;
   Float_t         lmetdPhi;
   Float_t         TriggerSF;
   Float_t         ljmindPhi;
   Float_t         EventWeight;
   Float_t         ptvarcone20;
   Float_t         ptvarcone30;
   Float_t         topoetcone20;
   Float_t         topoetcone30;
   Float_t         topoetcone40;
   Double_t        jjmindPhi;
   string          *Sample;
   string          *Description;
   string          *EventFlavor;
   Float_t         j3M;
   Float_t         j3Pt;
   Float_t         jjjM;
   Float_t         j3Eta;
   Float_t         j3Phi;
   Int_t           J1nTags;
   Float_t         J1M;
   Float_t         WJM;
   Float_t         J1Pt;
   Float_t         J1Eta;
   Float_t         J1Phi;
   Float_t         WJdPhi;

   // List of branches
   TBranch        *b_nFats;   //!
   TBranch        *b_nJets;   //!
   TBranch        *b_nTags;   //!
   TBranch        *b_nTaus;   //!
   TBranch        *b_j1Flav;   //!
   TBranch        *b_j2Flav;   //!
   TBranch        *b_nMuons;   //!
   TBranch        *b_passTrig;   //!
   TBranch        *b_nElectrons;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_EventRegime;   //!
   TBranch        *b_WM;   //!
   TBranch        *b_lM;   //!
   TBranch        *b_mu;   //!
   TBranch        *b_WMt;   //!
   TBranch        *b_WPt;   //!
   TBranch        *b_j1M;   //!
   TBranch        *b_j2M;   //!
   TBranch        *b_jjM;   //!
   TBranch        *b_lPt;   //!
   TBranch        *b_met;   //!
   TBranch        *b_WPhi;   //!
   TBranch        *b_WjjM;   //!
   TBranch        *b_j1Pt;   //!
   TBranch        *b_j2Pt;   //!
   TBranch        *b_jjPt;   //!
   TBranch        *b_jjdR;   //!
   TBranch        *b_lEta;   //!
   TBranch        *b_lPhi;   //!
   TBranch        *b_j1Eta;   //!
   TBranch        *b_j1Phi;   //!
   TBranch        *b_j2Eta;   //!
   TBranch        *b_j2Phi;   //!
   TBranch        *b_jjEta;   //!
   TBranch        *b_jjPhi;   //!
   TBranch        *b_BTagSF;   //!
   TBranch        *b_jjdEta;   //!
   TBranch        *b_jjdPhi;   //!
   TBranch        *b_jldPhi;   //!
   TBranch        *b_WjjdPhi;   //!
   TBranch        *b_LeptonSF;   //!
   TBranch        *b_PUWeight;   //!
   TBranch        *b_j1MV2c20;   //!
   TBranch        *b_j2MV2c20;   //!
   TBranch        *b_jmetdPhi;   //!
   TBranch        *b_lmetdPhi;   //!
   TBranch        *b_TriggerSF;   //!
   TBranch        *b_ljmindPhi;   //!
   TBranch        *b_EventWeight;   //!
   TBranch        *b_ptvarcone20;   //!
   TBranch        *b_ptvarcone30;   //!
   TBranch        *b_topoetcone20;   //!
   TBranch        *b_topoetcone30;   //!
   TBranch        *b_topoetcone40;   //!
   TBranch        *b_jjmindPhi;   //!
   TBranch        *b_Sample;   //!
   TBranch        *b_Description;   //!
   TBranch        *b_EventFlavor;   //!
   TBranch        *b_j3M;   //!
   TBranch        *b_j3Pt;   //!
   TBranch        *b_jjjM;   //!
   TBranch        *b_j3Eta;   //!
   TBranch        *b_j3Phi;   //!
   TBranch        *b_J1nTags;   //!
   TBranch        *b_J1M;   //!
   TBranch        *b_WJM;   //!
   TBranch        *b_J1Pt;   //!
   TBranch        *b_J1Eta;   //!
   TBranch        *b_J1Phi;   //!
   TBranch        *b_WJdPhi;   //!

   Nominal(TTree *tree=0);
   virtual ~Nominal();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Nominal_cxx
Nominal::Nominal(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/export/scratch2/amontalb/Janv26_mj/fetch/data-MVATree/data16-11.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/export/scratch2/amontalb/Janv26_mj/fetch/data-MVATree/data16-11.root");
      }
      f->GetObject("Nominal",tree);

   }
   Init(tree);
}

Nominal::~Nominal()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Nominal::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Nominal::LoadTree(Long64_t entry)
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

void Nominal::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   Sample = 0;
   Description = 0;
   EventFlavor = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("nFats", &nFats, &b_nFats);
   fChain->SetBranchAddress("nJets", &nJets, &b_nJets);
   fChain->SetBranchAddress("nTags", &nTags, &b_nTags);
   fChain->SetBranchAddress("nTaus", &nTaus, &b_nTaus);
   fChain->SetBranchAddress("j1Flav", &j1Flav, &b_j1Flav);
   fChain->SetBranchAddress("j2Flav", &j2Flav, &b_j2Flav);
   fChain->SetBranchAddress("nMuons", &nMuons, &b_nMuons);
   fChain->SetBranchAddress("passTrig", &passTrig, &b_passTrig);
   fChain->SetBranchAddress("nElectrons", &nElectrons, &b_nElectrons);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("EventRegime", &EventRegime, &b_EventRegime);
   fChain->SetBranchAddress("WM", &WM, &b_WM);
   fChain->SetBranchAddress("lM", &lM, &b_lM);
   fChain->SetBranchAddress("mu", &mu, &b_mu);
   fChain->SetBranchAddress("WMt", &WMt, &b_WMt);
   fChain->SetBranchAddress("WPt", &WPt, &b_WPt);
   fChain->SetBranchAddress("j1M", &j1M, &b_j1M);
   fChain->SetBranchAddress("j2M", &j2M, &b_j2M);
   fChain->SetBranchAddress("jjM", &jjM, &b_jjM);
   fChain->SetBranchAddress("lPt", &lPt, &b_lPt);
   fChain->SetBranchAddress("met", &met, &b_met);
   fChain->SetBranchAddress("WPhi", &WPhi, &b_WPhi);
   fChain->SetBranchAddress("WjjM", &WjjM, &b_WjjM);
   fChain->SetBranchAddress("j1Pt", &j1Pt, &b_j1Pt);
   fChain->SetBranchAddress("j2Pt", &j2Pt, &b_j2Pt);
   fChain->SetBranchAddress("jjPt", &jjPt, &b_jjPt);
   fChain->SetBranchAddress("jjdR", &jjdR, &b_jjdR);
   fChain->SetBranchAddress("lEta", &lEta, &b_lEta);
   fChain->SetBranchAddress("lPhi", &lPhi, &b_lPhi);
   fChain->SetBranchAddress("j1Eta", &j1Eta, &b_j1Eta);
   fChain->SetBranchAddress("j1Phi", &j1Phi, &b_j1Phi);
   fChain->SetBranchAddress("j2Eta", &j2Eta, &b_j2Eta);
   fChain->SetBranchAddress("j2Phi", &j2Phi, &b_j2Phi);
   fChain->SetBranchAddress("jjEta", &jjEta, &b_jjEta);
   fChain->SetBranchAddress("jjPhi", &jjPhi, &b_jjPhi);
   fChain->SetBranchAddress("BTagSF", &BTagSF, &b_BTagSF);
   fChain->SetBranchAddress("jjdEta", &jjdEta, &b_jjdEta);
   fChain->SetBranchAddress("jjdPhi", &jjdPhi, &b_jjdPhi);
   fChain->SetBranchAddress("jldPhi", &jldPhi, &b_jldPhi);
   fChain->SetBranchAddress("WjjdPhi", &WjjdPhi, &b_WjjdPhi);
   fChain->SetBranchAddress("LeptonSF", &LeptonSF, &b_LeptonSF);
   fChain->SetBranchAddress("PUWeight", &PUWeight, &b_PUWeight);
   fChain->SetBranchAddress("j1MV2c20", &j1MV2c20, &b_j1MV2c20);
   fChain->SetBranchAddress("j2MV2c20", &j2MV2c20, &b_j2MV2c20);
   fChain->SetBranchAddress("jmetdPhi", &jmetdPhi, &b_jmetdPhi);
   fChain->SetBranchAddress("lmetdPhi", &lmetdPhi, &b_lmetdPhi);
   fChain->SetBranchAddress("TriggerSF", &TriggerSF, &b_TriggerSF);
   fChain->SetBranchAddress("ljmindPhi", &ljmindPhi, &b_ljmindPhi);
   fChain->SetBranchAddress("EventWeight", &EventWeight, &b_EventWeight);
   fChain->SetBranchAddress("ptvarcone20", &ptvarcone20, &b_ptvarcone20);
   fChain->SetBranchAddress("ptvarcone30", &ptvarcone30, &b_ptvarcone30);
   fChain->SetBranchAddress("topoetcone20", &topoetcone20, &b_topoetcone20);
   fChain->SetBranchAddress("topoetcone30", &topoetcone30, &b_topoetcone30);
   fChain->SetBranchAddress("topoetcone40", &topoetcone40, &b_topoetcone40);
   fChain->SetBranchAddress("jjmindPhi", &jjmindPhi, &b_jjmindPhi);
   fChain->SetBranchAddress("Sample", &Sample, &b_Sample);
   fChain->SetBranchAddress("Description", &Description, &b_Description);
   fChain->SetBranchAddress("EventFlavor", &EventFlavor, &b_EventFlavor);
   fChain->SetBranchAddress("j3M", &j3M, &b_j3M);
   fChain->SetBranchAddress("j3Pt", &j3Pt, &b_j3Pt);
   fChain->SetBranchAddress("jjjM", &jjjM, &b_jjjM);
   fChain->SetBranchAddress("j3Eta", &j3Eta, &b_j3Eta);
   fChain->SetBranchAddress("j3Phi", &j3Phi, &b_j3Phi);
   fChain->SetBranchAddress("J1nTags", &J1nTags, &b_J1nTags);
   fChain->SetBranchAddress("J1M", &J1M, &b_J1M);
   fChain->SetBranchAddress("WJM", &WJM, &b_WJM);
   fChain->SetBranchAddress("J1Pt", &J1Pt, &b_J1Pt);
   fChain->SetBranchAddress("J1Eta", &J1Eta, &b_J1Eta);
   fChain->SetBranchAddress("J1Phi", &J1Phi, &b_J1Phi);
   fChain->SetBranchAddress("WJdPhi", &WJdPhi, &b_WJdPhi);
   Notify();
}

Bool_t Nominal::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Nominal::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Nominal::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Nominal_cxx
