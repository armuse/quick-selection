#include <vector>
#include <iostream>
#include <algorithm>
#include <sys/stat.h>
#include "TLeaf.h"
#include "TROOT.h"
#include "TFile.h"
#include "TChain.h"
#include "TLorentzVector.h"
#include "TH1.h"
#include "TH2.h"
#include "TEnv.h"
#include "TString.h"
#include "TVector.h"
#include "TSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
//#include <chrono>

using namespace std;
#include "./Nominal.C"

//// bi variable enum
enum varList{
 
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void fillFileList( string sampleName, string fullPath, vector<string> &filelist) {
  void *dirp = gSystem->OpenDirectory( fullPath.c_str() );
  if (!dirp) {
    cout << "The directory< " << fullPath << " >does not exist! .... bye \n";
    exit(0);
  }
  char *direntry;
  while ((direntry = (char*) gSystem->GetDirEntry(dirp))) {
    string thePath=string(direntry);
    if (thePath.find(".root")==string::npos) continue;
    if (thePath.find(sampleName)==string::npos) continue; 
    filelist.push_back(  fullPath+"/"+thePath);
  }
  return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool doesFolderExist(string pathString){
  pathString.append("test.test");
  ofstream outf(pathString.c_str());
  bool existFlag = outf;
  if(outf){
    outf.close();
    remove(pathString.c_str());
  }
  return existFlag;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void makeNewFolder(string pathString){
  if ( doesFolderExist(pathString) ) return;
  cout<<"Making new directory: "<<pathString.c_str()<<endl;
  string commandString = "mkdir -p -m 755 ";
  commandString.append(pathString.c_str());
  system(commandString.c_str());
  return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TObject * fetchObject(TFile * file, const string &name){
  TObject * result = 0;
  result = file->Get(name.c_str());
  if (result == 0) cout << " ERROR: COULDN'T FIND OBJECT NAMED " << name << endl;
  return result;
}


class varInfo{
public:
  varInfo(string name, int nbins, float xmin, float xmax) {
    p_name =name;
    p_nbins=nbins;
    p_xmin =xmin;
    p_xmax =xmax;
    p_h=NULL;
    p_val=0;
    p_dofabs=false;
  }
  public:
  string p_name;
  int    p_nbins;
  float  p_xmin;
  float  p_xmax;
  TH1F*  p_h;
  float  p_val;
  bool   p_dofabs; //to be implemented
};

string myVar(int var){
  if (var==9) return("jjdR");
  if (var==10) return("jjdEta");
  if (var==11) return("jjdPhi");
  return "BLAH";
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]){

  TH1::SetDefaultSumw2(kTRUE);
  cout << "Setup trees and Branches"<< endl;
  
  TChain *chain = 0;
  Nominal *nom = 0;

  vector<string> filelist;
  vector<string> samplelist;

  samplelist.clear();
  filelist.clear();
  gStyle->SetOptStat(111111);

  string sample = "";
  sample = argv[1];
  samplelist.push_back(sample);
  string Region = "";
  Region = argv[2];

  string dataFolder="/export/scratch2/amontalb/Janv26_data/fetch/data-MVATree/";
  string mcFolder  ="/export/scratch2/amontalb/Janv26_mc/fetch/data-MVATree/";
  string mjFolder  ="/export/scratch2/amontalb/Janv26_mj/fetch/data-MVATree/";

  //Read in files based on sample given
  for (int i = 0; i < samplelist.size(); i++){
    cout << "size of sample list " << samplelist.size() << endl;
    cout << "sample: " << samplelist[i] << endl;
    stringstream ss;
    int j = 0;
    if (samplelist[i] == "Zjets"){       
      fillFileList( "ZeeB", mcFolder, filelist);
      fillFileList( "ZeeC", mcFolder, filelist);
      fillFileList( "ZeeL", mcFolder, filelist);
      fillFileList( "ZmumuB", mcFolder, filelist);
      fillFileList( "ZmumuC", mcFolder, filelist);
      fillFileList( "ZmumuL", mcFolder, filelist);
      fillFileList( "ZtautauB", mcFolder, filelist);
      fillFileList( "ZtautauC", mcFolder, filelist);
      fillFileList( "ZtautauL", mcFolder, filelist);
      fillFileList( "ZnunuB", mcFolder, filelist);
      fillFileList( "ZnunuC", mcFolder, filelist);
      fillFileList( "ZnunuL", mcFolder, filelist);
    } else if (samplelist[i] == "MJ_Zjets"){ 
      fillFileList( "ZeeB", mjFolder, filelist);
      fillFileList( "ZeeC", mjFolder, filelist);
      fillFileList( "ZeeL", mjFolder, filelist);
      fillFileList( "ZmumuB", mjFolder, filelist);
      fillFileList( "ZmumuC", mjFolder, filelist);
      fillFileList( "ZmumuL", mjFolder, filelist);
      fillFileList( "ZtautauB", mjFolder, filelist);
      fillFileList( "ZtautauC", mjFolder, filelist);
      fillFileList( "ZtautauL", mjFolder, filelist);
      fillFileList( "ZnunuB", mjFolder, filelist);
      fillFileList( "ZnunuC", mjFolder, filelist);
      fillFileList( "ZnunuL", mjFolder, filelist);
    } else if (samplelist[i] == "data15"){
      fillFileList( "data-15", dataFolder, filelist);
    
    } else if (samplelist[i] == "data16"){
      fillFileList( "data-16", dataFolder, filelist);
    
    } else if (samplelist[i] == "dataCombined"){
      fillFileList( "data15-", dataFolder, filelist);
      fillFileList( "data16-", dataFolder, filelist);
    
    } else if (samplelist[i] == "data"){
      fillFileList( "data-", dataFolder, filelist);
    } else if (samplelist[i] == "MJ_data"){
      fillFileList( "data15-", mjFolder, filelist);
      fillFileList( "data16-", mjFolder, filelist);
    } else if (samplelist[i] == "ttbar"){
      fillFileList( samplelist[i], mcFolder, filelist);
    } else if (samplelist[i] == "MJ_ttbar"){
      fillFileList( "ttbar", mjFolder, filelist);
    } else if (samplelist[i] == "singletop"){
      fillFileList( "singletop_s",  mcFolder, filelist);
      fillFileList( "singletop_t",  mcFolder, filelist);
      fillFileList( "singletop_Wt", mcFolder, filelist);
    } else if (samplelist[i] == "MJ_singletop"){
      fillFileList( "singletop_s", mjFolder, filelist);
      fillFileList( "singletop_t", mjFolder, filelist);
      fillFileList( "singletop_Wt", mjFolder, filelist);
    } else if (samplelist[i] == "signal"){
      fillFileList( "ZHll125",  mcFolder, filelist);
      fillFileList( "WH125",  mcFolder, filelist);
      fillFileList( "ZHvv125", mcFolder, filelist);      
    } else if (samplelist[i] == "WH125"){
      fillFileList( samplelist[i], mcFolder, filelist);

    } else if (samplelist[i] == "Wjets"){
      fillFileList( "WenuB", mcFolder, filelist);
      fillFileList( "WenuC", mcFolder, filelist);
      fillFileList( "WenuL", mcFolder, filelist);
      fillFileList( "WmunuB", mcFolder, filelist);
      fillFileList( "WmunuC", mcFolder, filelist);
      fillFileList( "WmunuL", mcFolder, filelist);
      fillFileList( "WtaunuB", mcFolder, filelist);
      fillFileList( "WtaunuC", mcFolder, filelist);
      fillFileList( "WtaunuL", mcFolder, filelist);
    } else if (samplelist[i] == "MJ_Wjets"){
      fillFileList( "WenuB", mjFolder, filelist);
      fillFileList( "WenuC", mjFolder, filelist);
      fillFileList( "WenuL", mjFolder, filelist);
      fillFileList( "WmunuB", mjFolder, filelist);
      fillFileList( "WmunuC", mjFolder, filelist);
      fillFileList( "WmunuL", mjFolder, filelist);
      fillFileList( "WtaunuB", mjFolder, filelist);
      fillFileList( "WtaunuC", mjFolder, filelist);
      fillFileList( "WtaunuL", mjFolder, filelist);   
    }
  }
  
  UInt_t nentries = 0;
  chain = new TChain("Nominal");
  for (int i = 0; i < filelist.size(); i++){
    chain->Add(filelist.at(i).c_str());
    cout << "file " << filelist.at(i) << endl;
  }
  if (filelist.size() < 1) cout << "No files!" << endl;
  nom = new Nominal(chain); 
  nentries = nom->fChain->GetEntries();
  
  //////////////////////////////////////////////////////////////////////////////////////////////
  /// THIS IS FOR VARIABLES
  vector<varInfo*> varList;
  // met-related
  varList.push_back( new varInfo("met",200,0,400) );
  varList.push_back( new varInfo("WMt",200,0,400) );
  varList.push_back( new varInfo("WPt",300,0,600) );
  // lepton related
  varList.push_back( new varInfo("lPt" ,200,0,400) );
  varList.push_back( new varInfo("lEta",60,-2.5,2.5) );
  // jet related
  varList.push_back( new varInfo("j1Pt" ,300,0,600) );
  varList.push_back( new varInfo("j1Eta",60,-2.5,2.5) );
  varList.push_back( new varInfo("j2Pt" ,200,0,400) );
  varList.push_back( new varInfo("j2Eta",60,-2.5,2.5) );
  // di-jets
  varList.push_back( new varInfo("jjdR"  ,120,0,5) );
  varList.push_back( new varInfo("jjdEta",120,0,5) );
  varList.push_back( new varInfo("jjdPhi",120,0,3.2) );
  // counters
  varList.push_back( new varInfo("nJets" ,6,-0.5, 5.5) );
  varList.push_back( new varInfo("nTags" ,5,-0.5, 4.5) );
  varList.push_back( new varInfo("mu"    ,50,-0.51, 49.49) );

  for (int V = 0; V < varList.size(); V++) {
    varInfo* theVar=varList[V];
    string temp_histName = sample+"_"+Region+"_"+theVar->p_name;
    theVar->p_h=new TH1F(temp_histName.c_str(), temp_histName.c_str(), theVar->p_nbins, theVar->p_xmin, theVar->p_xmax);
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //Identify Region from string
  int btag = -1;
  bool isInclusiveTag=false;
  if ( Region.find("0tag")!=string::npos) {
    btag = 0;
  } else if ( Region.find("0ptag")!=string::npos) {
    btag = 0; 
    isInclusiveTag=true;
  } else if ( Region.find("1tag")!=string::npos) {
    btag = 1;
  } else if ( Region.find("1ptag")!=string::npos) {
    btag = 1;
    isInclusiveTag=true;
  } else if ( Region.find("2tag")!=string::npos) {
    btag = 2;
  } else if ( Region.find("2ptag")!=string::npos) {
    btag = 2;
    isInclusiveTag=true;
  } else if ( Region.find("3tag")!=string::npos) {
    btag = 3;
  } else if ( Region.find("3ptag")!=string::npos) {
    btag = 3;
    isInclusiveTag=true;
  } else {
    cout << "Couldn't find btag" << endl; return 0;
  }

  int jtag = -1;
  bool isInclusiveJet=false;
  if ( Region.find("2jet")!=string::npos) {
    jtag = 2;
  } else if (Region.find("2pjet")!=string::npos) {
    jtag = 2;
    isInclusiveJet=true;
  } else if ( Region.find("3jet")!=string::npos) {
    jtag = 3;
  } else if (Region.find("3pjet")!=string::npos) {
    jtag = 3;
    isInclusiveJet=true;
  } else if ( Region.find("4jet")!=string::npos) {
    jtag = 4;
  } else if (Region.find("4pjet")!=string::npos) {
    jtag = 4;
    isInclusiveJet=true;
  } else {
    cout << "Couldn't find jtag" << endl; return 0;
  }
  
  float ptVhi=100000e3;
  float ptVlo= 0e3;
  if (Region.find("0_150")!=string::npos) {
    ptVhi = 150;
  } else if (Region.find("150")!=string::npos) {
    ptVlo = 150;
  } 

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //Loop over events
  for (int i = 0; i <nentries; i++){
//    if (i % 10000 == 0) cout << "Loop: " << i << endl;
    nom->fChain->GetEntry(i);
    
    if (isInclusiveTag) {
      if (nom->nTags<btag) continue;
    } else {
      if (nom->nTags!=btag) continue;
    }

    if (isInclusiveJet) {
      if (nom->nJets<jtag) continue;
    } else {
      if (nom->nJets!=jtag) continue;
    }
    
    if (nom->WPt<ptVlo) continue;
    if (nom->WPt>ptVhi) continue;
    
    // EXTRA cuts here (like blinding)
    //  blinding
    //   if (nom->jjM > 110 && nom->jjM < 140) continue;
    //  signal region
    //if (nom->jjM <110 || nom->jjM >140) continue;
    //  muons
    if (nom->nMuons == 0) continue;
    float trackIso = nom->ptvarcone30;
    if (trackIso <= 0.06) continue;
    //  electrons
 /*   if (nom->nMuons == 1) continue;
    if (nom->met<30) continue;
    if (nom->lPt<27) continue;
    float trackIso = nom->ptvarcone20;
    if (trackIso <= 0.06) continue;
*/
    for (int V = 0; V < varList.size(); V++) {
      varInfo* theVar=varList[V];
      string varName=theVar->p_name;
      TBranch* myB=nom->fChain->GetBranch(varName.c_str());
      if (myB==NULL) {
	cout << " variable: " << varName << " was not found in the nutples!!!!!" << endl;
      } else {
	theVar->p_val=myB->GetLeaf(varName.c_str())->GetValue();
	if (theVar->p_dofabs) {
	  theVar->p_val=fabs(theVar->p_val);
	}
      }
    }
    float evtWeight = nom->EventWeight;    

    //Filling Histograms
    for (int V = 0; V < varList.size(); V++) {
      varInfo* theVar=varList[V];
      float Hmin=theVar->p_h->GetXaxis()->GetXmin();
      float Hmax=theVar->p_h->GetXaxis()->GetXmax();
      float theValue=theVar->p_val;
      if ( theValue<Hmin ) {
	if ( Hmin<0 )      theValue=Hmin*0.9999;
	else if ( Hmin>0 ) theValue=Hmin*1.0001;
	else               theValue=0.00001;
      }
      if ( theValue>Hmax ) {
	if ( Hmax<0 )      theValue=Hmax*1.00001;
	else if ( Hmax>0 ) theValue=Hmax*0.99999;
	else               theValue=-0.00001;
      }
      theVar->p_h->Fill(theValue,evtWeight);
    }  
  } 

  ///////////////////////////////////////////////////////////////////////////////////////
  // outfolder creation
  string outFolderName="outputHistoFolder/";//+Region+"/";
  makeNewFolder(outFolderName);
  

  //Writing out histograms - rebin possible
  for (int i = 0; i < 1; i++){
    string name = outFolderName+"output-"+samplelist[i]+"_"+Region+".root";
    TFile *plot_file = new TFile(name.c_str(), "RECREATE");
    plot_file->cd();
    for (int V = 0; V < varList.size(); V++) {
      varInfo* theVar=varList[V];
      theVar->p_h->Write();
    }
    plot_file->Close();
  }
}
