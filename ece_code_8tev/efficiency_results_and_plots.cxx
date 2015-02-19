#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLatex.h>
#include <TTree.h>
#include "common_plotting_functions.hh"
#include <TGraph.h>
#include <TEfficiency>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Riostream.h"

using namespace std;


void efficiency_results_and_plots(){
	
	
	static const Int_t number_dm = 2;
	static const Int_t number_mm_vector = 9;
	static const Int_t number_mm_axial = 4;
	
	
	TString binnames_dm[number_dm] = {"50","400"};
	TString binnames_mm_vector[number_mm_vector] = {"50","100","300","600","1000","3000","6000","10000","30000"};
	TString binnames_mm_axial[number_mm_axial] = {"50","100","300","600"};
	
	
	TString choose_txt_directory = "/afs/cern.ch/user/e/eakilli/razor_8tev/ece_code_8tev/Output_text";
	TString output_dir = "/atlas/data2/userdata/eakilli/razor_output/Output_efficiency_directory";
	// Open the ROOT file
  	TFile *eff_results_plots = TFile::Open(choose_txt_directory+"/eff_results_plots.root");

	
	// Get the trees
	TTree*eff_results_plots_vector_w3 = (TTree*)eff_results_plots->Get("eff_results_plots_vector_w3");
	TTree*eff_results_plots_vector_w8pi  = (TTree*)eff_results_plots->Get("eff_results_plots_vector_w8pi");
	TTree*eff_results_plots_axial_w3 = (TTree*)eff_results_plots->Get("eff_results_plots_axial_w3");
	TTree*eff_results_plots_axial_w8pi = (TTree*)eff_results_plots->Get("eff_results_plots_axial_w8pi");
	// Check the number of events
	Int_t n_o_e_vector_w3 = eff_results_plots_vector_w3->GetEntries();
	cout << n_o_e_vector_w3 << endl;
	Int_t n_o_e_vector_w8pi = eff_results_plots_vector_w8pi->GetEntries();
	cout << n_o_e_vector_w8pi << endl;
	Int_t n_o_e_axial_w3 = eff_results_plots_axial_w3->GetEntries();
	cout << n_o_e_axial_w3 << endl;
	Int_t n_o_e_axial_w8pi = eff_results_plots_axial_w8pi->GetEntries();
	cout << n_o_e_axial_w8pi << endl;
	
	// Define the branch variables...
	Float_t dm_vector_w3,mm_vector_w3,efficiencies_eff_xe_vector_w3,efficiencies_eff_or_1_vector_w3,efficiencies_eff_or_2_vector_w3,efficiencies_eff_or_3_vector_w3,efficiencies_eff_or_4_vector_w3;
	Float_t efficiencies_eff_xe_off_vector_w3,efficiencies_eff_or_1_off_vector_w3,efficiencies_eff_or_2_off_vector_w3,efficiencies_eff_or_3_off_vector_w3;
	Float_t efficiencies_eff_or_4_off_vector_w3,efficiencies_eff_or_5_off_vector_w3,efficiencies_eff_or_6_off_vector_w3;
	Float_t efficiencies_eff_xe_2j_vector_w3,efficiencies_eff_or_1_2j_vector_w3,efficiencies_eff_or_2_2j_vector_w3,efficiencies_eff_or_3_2j_vector_w3,efficiencies_eff_or_4_2j_vector_w3;
	Float_t efficiencies_eff_xe_off_2j_vector_w3,efficiencies_eff_or_1_off_2j_vector_w3,efficiencies_eff_or_2_off_2j_vector_w3,efficiencies_eff_or_3_off_2j_vector_w3;
	Float_t efficiencies_eff_or_4_off_2j_vector_w3,efficiencies_eff_or_5_off_2j_vector_w3,efficiencies_eff_or_6_off_2j_vector_w3;
	
	Float_t dm_vector_w8pi,mm_vector_w8pi,efficiencies_eff_xe_vector_w8pi,efficiencies_eff_or_1_vector_w8pi,efficiencies_eff_or_2_vector_w8pi,efficiencies_eff_or_3_vector_w8pi,efficiencies_eff_or_4_vector_w8pi;
	Float_t efficiencies_eff_xe_off_vector_w8pi,efficiencies_eff_or_1_off_vector_w8pi,efficiencies_eff_or_2_off_vector_w8pi,efficiencies_eff_or_3_off_vector_w8pi;
	Float_t efficiencies_eff_or_4_off_vector_w8pi,efficiencies_eff_or_5_off_vector_w8pi,efficiencies_eff_or_6_off_vector_w8pi;
	Float_t efficiencies_eff_xe_2j_vector_w8pi,efficiencies_eff_or_1_2j_vector_w8pi,efficiencies_eff_or_2_2j_vector_w8pi,efficiencies_eff_or_3_2j_vector_w8pi,efficiencies_eff_or_4_2j_vector_w8pi;
	Float_t efficiencies_eff_xe_off_2j_vector_w8pi,efficiencies_eff_or_1_off_2j_vector_w8pi,efficiencies_eff_or_2_off_2j_vector_w8pi,efficiencies_eff_or_3_off_2j_vector_w8pi;
	Float_t efficiencies_eff_or_4_off_2j_vector_w8pi,efficiencies_eff_or_5_off_2j_vector_w8pi,efficiencies_eff_or_6_off_2j_vector_w8pi;
    
	Float_t dm_axial_w3,mm_axial_w3,efficiencies_eff_xe_axial_w3,efficiencies_eff_or_1_axial_w3,efficiencies_eff_or_2_axial_w3,efficiencies_eff_or_3_axial_w3,efficiencies_eff_or_4_axial_w3;
	Float_t efficiencies_eff_xe_off_axial_w3,efficiencies_eff_or_1_off_axial_w3,efficiencies_eff_or_2_off_axial_w3,efficiencies_eff_or_3_off_axial_w3;
	Float_t efficiencies_eff_or_4_off_axial_w3,efficiencies_eff_or_5_off_axial_w3,efficiencies_eff_or_6_off_axial_w3;
	Float_t efficiencies_eff_xe_2j_axial_w3,efficiencies_eff_or_1_2j_axial_w3,efficiencies_eff_or_2_2j_axial_w3,efficiencies_eff_or_3_2j_axial_w3,efficiencies_eff_or_4_2j_axial_w3;
	Float_t efficiencies_eff_xe_off_2j_axial_w3,efficiencies_eff_or_1_off_2j_axial_w3,efficiencies_eff_or_2_off_2j_axial_w3,efficiencies_eff_or_3_off_2j_axial_w3;
	Float_t efficiencies_eff_or_4_off_2j_axial_w3,efficiencies_eff_or_5_off_2j_axial_w3,efficiencies_eff_or_6_off_2j_axial_w3;
	
	Float_t dm_axial_w8pi,mm_axial_w8pi,efficiencies_eff_xe_axial_w8pi,efficiencies_eff_or_1_axial_w8pi,efficiencies_eff_or_2_axial_w8pi,efficiencies_eff_or_3_axial_w8pi,efficiencies_eff_or_4_axial_w8pi;
	Float_t efficiencies_eff_xe_off_axial_w8pi,efficiencies_eff_or_1_off_axial_w8pi,efficiencies_eff_or_2_off_axial_w8pi,efficiencies_eff_or_3_off_axial_w8pi;
	Float_t efficiencies_eff_or_4_off_axial_w8pi,efficiencies_eff_or_5_off_axial_w8pi,efficiencies_eff_or_6_off_axial_w8pi;
	Float_t efficiencies_eff_xe_2j_axial_w8pi,efficiencies_eff_or_1_2j_axial_w8pi,efficiencies_eff_or_2_2j_axial_w8pi,efficiencies_eff_or_3_2j_axial_w8pi,efficiencies_eff_or_4_2j_axial_w8pi;
	Float_t efficiencies_eff_xe_off_2j_axial_w8pi,efficiencies_eff_or_1_off_2j_axial_w8pi,efficiencies_eff_or_2_off_2j_axial_w8pi,efficiencies_eff_or_3_off_2j_axial_w8pi;
	Float_t efficiencies_eff_or_4_off_2j_axial_w8pi,efficiencies_eff_or_5_off_2j_axial_w8pi,efficiencies_eff_or_6_off_2j_axial_w8pi;
	
	// Set Branch addresses
	eff_results_plots_vector_w3->SetBranchAddress("dm_vector_w3",&dm_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("mm_vector_w3",&mm_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_xe_vector_w3",&efficiencies_eff_xe_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_1_vector_w3",&efficiencies_eff_or_1_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_2_vector_w3",&efficiencies_eff_or_2_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_3_vector_w3",&efficiencies_eff_or_3_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_4_vector_w3",&efficiencies_eff_or_4_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_xe_off_vector_w3",&efficiencies_eff_xe_off_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_1_off_vector_w3",&efficiencies_eff_or_1_off_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_2_off_vector_w3",&efficiencies_eff_or_2_off_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_3_off_vector_w3",&efficiencies_eff_or_3_off_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_4_off_vector_w3",&efficiencies_eff_or_4_off_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_5_off_vector_w3",&efficiencies_eff_or_5_off_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_6_off_vector_w3",&efficiencies_eff_or_6_off_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_xe_2j_vector_w3",&efficiencies_eff_xe_2j_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_1_2j_vector_w3",&efficiencies_eff_or_1_2j_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_2_2j_vector_w3",&efficiencies_eff_or_2_2j_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_3_2j_vector_w3",&efficiencies_eff_or_3_2j_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_4_2j_vector_w3",&efficiencies_eff_or_4_2j_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_xe_off_2j_vector_w3",&efficiencies_eff_xe_off_2j_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_1_off_2j_vector_w3",&efficiencies_eff_or_1_off_2j_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_2_off_2j_vector_w3",&efficiencies_eff_or_2_off_2j_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_3_off_2j_vector_w3",&efficiencies_eff_or_3_off_2j_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_4_off_2j_vector_w3",&efficiencies_eff_or_4_off_2j_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_5_off_2j_vector_w3",&efficiencies_eff_or_5_off_2j_vector_w3);
	eff_results_plots_vector_w3->SetBranchAddress("efficiencies_eff_or_6_off_2j_vector_w3",&efficiencies_eff_or_6_off_2j_vector_w3);

	eff_results_plots_vector_w8pi->SetBranchAddress("dm_vector_w8pi",&dm_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("mm_vector_w8pi",&mm_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_xe_vector_w8pi",&efficiencies_eff_xe_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_1_vector_w8pi",&efficiencies_eff_or_1_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_2_vector_w8pi",&efficiencies_eff_or_2_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_3_vector_w8pi",&efficiencies_eff_or_3_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_4_vector_w8pi",&efficiencies_eff_or_4_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_xe_off_vector_w8pi",&efficiencies_eff_xe_off_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_1_off_vector_w8pi",&efficiencies_eff_or_1_off_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_2_off_vector_w8pi",&efficiencies_eff_or_2_off_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_3_off_vector_w8pi",&efficiencies_eff_or_3_off_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_4_off_vector_w8pi",&efficiencies_eff_or_4_off_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_5_off_vector_w8pi",&efficiencies_eff_or_5_off_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_6_off_vector_w8pi",&efficiencies_eff_or_6_off_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_xe_2j_vector_w8pi",&efficiencies_eff_xe_2j_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_1_2j_vector_w8pi",&efficiencies_eff_or_1_2j_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_2_2j_vector_w8pi",&efficiencies_eff_or_2_2j_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_3_2j_vector_w8pi",&efficiencies_eff_or_3_2j_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_4_2j_vector_w8pi",&efficiencies_eff_or_4_2j_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_xe_off_2j_vector_w8pi",&efficiencies_eff_xe_off_2j_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_1_off_2j_vector_w8pi",&efficiencies_eff_or_1_off_2j_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_2_off_2j_vector_w8pi",&efficiencies_eff_or_2_off_2j_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_3_off_2j_vector_w8pi",&efficiencies_eff_or_3_off_2j_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_4_off_2j_vector_w8pi",&efficiencies_eff_or_4_off_2j_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_5_off_2j_vector_w8pi",&efficiencies_eff_or_5_off_2j_vector_w8pi);
	eff_results_plots_vector_w8pi->SetBranchAddress("efficiencies_eff_or_6_off_2j_vector_w8pi",&efficiencies_eff_or_6_off_2j_vector_w8pi);
	
	
	eff_results_plots_axial_w3->SetBranchAddress("dm_axial_w3",&dm_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("mm_axial_w3",&mm_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_xe_axial_w3",&efficiencies_eff_xe_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_1_axial_w3",&efficiencies_eff_or_1_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_2_axial_w3",&efficiencies_eff_or_2_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_3_axial_w3",&efficiencies_eff_or_3_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_4_axial_w3",&efficiencies_eff_or_4_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_xe_off_axial_w3",&efficiencies_eff_xe_off_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_1_off_axial_w3",&efficiencies_eff_or_1_off_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_2_off_axial_w3",&efficiencies_eff_or_2_off_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_3_off_axial_w3",&efficiencies_eff_or_3_off_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_4_off_axial_w3",&efficiencies_eff_or_4_off_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_5_off_axial_w3",&efficiencies_eff_or_5_off_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_6_off_axial_w3",&efficiencies_eff_or_6_off_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_xe_2j_axial_w3",&efficiencies_eff_xe_2j_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_1_2j_axial_w3",&efficiencies_eff_or_1_2j_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_2_2j_axial_w3",&efficiencies_eff_or_2_2j_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_3_2j_axial_w3",&efficiencies_eff_or_3_2j_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_4_2j_axial_w3",&efficiencies_eff_or_4_2j_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_xe_off_2j_axial_w3",&efficiencies_eff_xe_off_2j_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_1_off_2j_axial_w3",&efficiencies_eff_or_1_off_2j_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_2_off_2j_axial_w3",&efficiencies_eff_or_2_off_2j_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_3_off_2j_axial_w3",&efficiencies_eff_or_3_off_2j_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_4_off_2j_axial_w3",&efficiencies_eff_or_4_off_2j_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_5_off_2j_axial_w3",&efficiencies_eff_or_5_off_2j_axial_w3);
	eff_results_plots_axial_w3->SetBranchAddress("efficiencies_eff_or_6_off_2j_axial_w3",&efficiencies_eff_or_6_off_2j_axial_w3);
	
	

	eff_results_plots_axial_w8pi->SetBranchAddress("dm_axial_w8pi",&dm_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("mm_axial_w8pi",&mm_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_xe_axial_w8pi",&efficiencies_eff_xe_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_1_axial_w8pi",&efficiencies_eff_or_1_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_2_axial_w8pi",&efficiencies_eff_or_2_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_3_axial_w8pi",&efficiencies_eff_or_3_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_4_axial_w8pi",&efficiencies_eff_or_4_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_xe_off_axial_w8pi",&efficiencies_eff_xe_off_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_1_off_axial_w8pi",&efficiencies_eff_or_1_off_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_2_off_axial_w8pi",&efficiencies_eff_or_2_off_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_3_off_axial_w8pi",&efficiencies_eff_or_3_off_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_4_off_axial_w8pi",&efficiencies_eff_or_4_off_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_5_off_axial_w8pi",&efficiencies_eff_or_5_off_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_6_off_axial_w8pi",&efficiencies_eff_or_6_off_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_xe_2j_axial_w8pi",&efficiencies_eff_xe_2j_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_1_2j_axial_w8pi",&efficiencies_eff_or_1_2j_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_2_2j_axial_w8pi",&efficiencies_eff_or_2_2j_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_3_2j_axial_w8pi",&efficiencies_eff_or_3_2j_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_4_2j_axial_w8pi",&efficiencies_eff_or_4_2j_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_xe_off_2j_axial_w8pi",&efficiencies_eff_xe_off_2j_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_1_off_2j_axial_w8pi",&efficiencies_eff_or_1_off_2j_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_2_off_2j_axial_w8pi",&efficiencies_eff_or_2_off_2j_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_3_off_2j_axial_w8pi",&efficiencies_eff_or_3_off_2j_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_4_off_2j_axial_w8pi",&efficiencies_eff_or_4_off_2j_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_5_off_2j_axial_w8pi",&efficiencies_eff_or_5_off_2j_axial_w8pi);
	eff_results_plots_axial_w8pi->SetBranchAddress("efficiencies_eff_or_6_off_2j_axial_w8pi",&efficiencies_eff_or_6_off_2j_axial_w8pi);

	
	// NOW, we can begin :)
	
	// First, the efficiencies we are interested in, 2D histograms
	
		
	Float_t diff_eff_or_1;
	Float_t diff_eff_or_1_off;
	Float_t diff_eff_or_5_off;
	Float_t diff_eff_or_6_off;
	Float_t diff_eff_or_1_2j;
	Float_t diff_eff_or_1_off_2j; 
	Float_t diff_eff_or_5_off_2j;
	Float_t diff_eff_or_6_off_2j; 
	
	// x axis : MM, y axis : DM
	// Vector W3
	TH2F *v_w3_eff_xe_h = new TH2F("v_w3_eff_xe_h","MET" , number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *v_w3_eff_or_1_h = new TH2F("v_w3_eff_or_1_h","MET or ProdR170_2J15_XE50",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *diff_v_w3_eff_or_1_h = new TH2F("diff_v_w3_eff_or_1_h","Difference MET or ProdR170_2J15_XE50",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	  
	TH2F *v_w3_eff_xe_off_h = new TH2F("v_w3_eff_xe_off_h","Offline(xe100_XE70)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *v_w3_eff_or_1_off_h = new TH2F("v_w3_eff_or_1_off_h","Offline_raz_(xe100_XE70 or ProdR_2J15_XE55)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *v_w3_eff_or_5_off_h = new TH2F("v_w3_eff_or_5_off_h","Offline(xe100_XE70) or Offline_raz(ProdR_2J15_XE55)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *v_w3_eff_or_6_off_h = new TH2F("v_w3_eff_or_6_off_h","Combine two offline cuts",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *diff_v_w3_eff_or_1_off_h = new TH2F("diff_v_w3_eff_or_1_off_h","Difference wrt Offline_raz_(xe100_XE70 or ProdR_2J15_XE55)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *diff_v_w3_eff_or_5_off_h = new TH2F("diff_v_w3_eff_or_5_off_h","Difference wrt Offline(xe100_XE70) or Offline_raz(ProdR_2J15_XE55)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *diff_v_w3_eff_or_6_off_h = new TH2F("diff_v_w3_eff_or_6_off_h","Difference wrt Combined two offline cuts",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	
	TH2F *v_w3_eff_xe_h_2j = new TH2F("v_w3_eff_xe_h_2j","MET" , number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *v_w3_eff_or_1_h_2j = new TH2F("v_w3_eff_or_1_h_2j","MET or ProdR170_2J15_XE50",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *diff_v_w3_eff_or_1_h_2j = new TH2F("diff_v_w3_eff_or_1_h_2j","Difference MET or ProdR170_2J15_XE50",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	
	   
	TH2F *v_w3_eff_xe_off_h_2j = new TH2F("v_w3_eff_xe_off_h_2j","Offline(xe100_XE70)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *v_w3_eff_or_1_off_h_2j = new TH2F("v_w3_eff_or_1_off_h_2j","Offline_raz_(xe100_XE70 or ProdR_2J15_XE55)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *v_w3_eff_or_5_off_h_2j = new TH2F("v_w3_eff_or_5_off_h_2j","Offline(xe100_XE70) or Offline_raz(ProdR_2J15_XE55)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *v_w3_eff_or_6_off_h_2j = new TH2F("v_w3_eff_or_6_off_h_2j","Combine two offline cuts",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *diff_v_w3_eff_or_1_off_h_2j = new TH2F("diff_v_w3_eff_or_1_off_h_2j","Difference wrt Offline_raz_(xe100_XE70 or ProdR_2J15_XE55)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *diff_v_w3_eff_or_5_off_h_2j = new TH2F("diff_v_w3_eff_or_5_off_h_2j","Difference wrt Offline(xe100_XE70) or Offline_raz(ProdR_2J15_XE55)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *diff_v_w3_eff_or_6_off_h_2j = new TH2F("diff_v_w3_eff_or_6_off_h_2j","Difference wrt Combined two offline cuts",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	
	
	
	
	// Vector W8Pi
	
	TH2F *v_w8pi_eff_xe_h = new TH2F("v_w8pi_eff_xe_h","MET",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *v_w8pi_eff_or_1_h = new TH2F("v_w8pi_eff_or_1_h","MET or ProdR170_2J15_XE50",number_mm_vector,0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *diff_v_w8pi_eff_or_1_h = new TH2F("diff_v_w8pi_eff_or_1_h","Difference MET or ProdR170_2J15_XE50",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );

	   
	TH2F *v_w8pi_eff_xe_off_h = new TH2F("v_w8pi_eff_xe_off_h","Offline(xe100_XE70)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *v_w8pi_eff_or_1_off_h = new TH2F("v_w8pi_eff_or_1_off_h","Offline_raz_(xe100_XE70 or ProdR_2J15_XE55)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *v_w8pi_eff_or_5_off_h = new TH2F("v_w8pi_eff_or_5_off_h","Offline(xe100_XE70) or Offline_raz(ProdR_2J15_XE55)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *v_w8pi_eff_or_6_off_h = new TH2F("v_w8pi_eff_or_6_off_h","Combine two offline cuts",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *diff_v_w8pi_eff_or_1_off_h = new TH2F("diff_v_w8pi_eff_or_1_off_h","Difference wrt Offline_raz_(xe100_XE70 or ProdR_2J15_XE55)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *diff_v_w8pi_eff_or_5_off_h = new TH2F("diff_v_w8pi_eff_or_5_off_h","Difference wrt Offline(xe100_XE70) or Offline_raz(ProdR_2J15_XE55)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *diff_v_w8pi_eff_or_6_off_h = new TH2F("diff_v_w8pi_eff_or_6_off_h","Difference wrt Combined two offline cuts",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	
	TH2F *v_w8pi_eff_xe_h_2j = new TH2F("v_w8pi_eff_xe_h_2j","MET",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *v_w8pi_eff_or_1_h_2j = new TH2F("v_w8pi_eff_or_1_h_2j","MET or ProdR170_2J15_XE50",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *diff_v_w8pi_eff_or_1_h_2j = new TH2F("diff_v_w8pi_eff_or_1_h_2j","Difference MET or ProdR170_2J15_XE50",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );

	   
	TH2F *v_w8pi_eff_xe_off_h_2j = new TH2F("v_w8pi_eff_xe_off_h_2j","Offline(xe100_XE70)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *v_w8pi_eff_or_1_off_h_2j = new TH2F("v_w8pi_eff_or_1_off_h_2j","Offline_raz_(xe100_XE70 or ProdR_2J15_XE55)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *v_w8pi_eff_or_5_off_h_2j = new TH2F("v_w8pi_eff_or_5_off_h_2j","Offline(xe100_XE70) or Offline_raz(ProdR_2J15_XE55)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *v_w8pi_eff_or_6_off_h_2j = new TH2F("v_w8pi_eff_or_6_off_h_2j","Combine two offline cuts",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *diff_v_w8pi_eff_or_1_off_h_2j = new TH2F("diff_v_w8pi_eff_or_1_off_h_2j","Difference wrt Offline_raz_(xe100_XE70 or ProdR_2J15_XE55)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *diff_v_w8pi_eff_or_5_off_h_2j = new TH2F("diff_v_w8pi_eff_or_5_off_h_2j","Difference wrt Offline(xe100_XE70) or Offline_raz(ProdR_2J15_XE55)",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	TH2F *diff_v_w8pi_eff_or_6_off_h_2j = new TH2F("diff_v_w8pi_eff_or_6_off_h_2j","Difference wrt Combined two offline cuts",number_mm_vector, 0, number_mm_vector, number_dm, 0, number_dm );
	
	
	
	// Axial W3
	
	TH2F *a_w3_eff_xe_h = new TH2F("a_w3_eff_xe_h","MET",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *a_w3_eff_or_1_h = new TH2F("a_w3_eff_or_1_h","MET or ProdR170_2J15_XE50",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *diff_a_w3_eff_or_1_h = new TH2F("diff_a_w3_eff_or_1_h","Difference MET or ProdR170_2J15_XE50",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	
	   
	TH2F *a_w3_eff_xe_off_h = new TH2F("a_w3_eff_xe_off_h","Offline(xe100_XE70)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *a_w3_eff_or_1_off_h = new TH2F("a_w3_eff_or_1_off_h","Offline_raz_(xe100_XE70 or ProdR_2J15_XE55)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *a_w3_eff_or_5_off_h = new TH2F("a_w3_eff_or_5_off_h","Offline(xe100_XE70) or Offline_raz(ProdR_2J15_XE55)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *a_w3_eff_or_6_off_h = new TH2F("a_w3_eff_or_6_off_h","Combine two offline cuts",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *diff_a_w3_eff_or_1_off_h = new TH2F("diff_a_w3_eff_or_1_off_h","Difference wrt Offline_raz_(xe100_XE70 or ProdR_2J15_XE55)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *diff_a_w3_eff_or_5_off_h = new TH2F("diff_a_w3_eff_or_5_off_h","Difference wrt Offline(xe100_XE70) or Offline_raz(ProdR_2J15_XE55)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *diff_a_w3_eff_or_6_off_h = new TH2F("diff_a_w3_eff_or_6_off_h","Difference wrt Combined two offline cuts",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );


	TH2F *a_w3_eff_xe_h_2j = new TH2F("a_w3_eff_xe_h_2j","MET",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *a_w3_eff_or_1_h_2j = new TH2F("a_w3_eff_or_1_h_2j","MET or ProdR170_2J15_XE50",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *diff_a_w3_eff_or_1_h_2j = new TH2F("diff_a_w3_eff_or_1_h_2j","Difference MET or ProdR170_2J15_XE50",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );

	   
	TH2F *a_w3_eff_xe_off_h_2j = new TH2F("a_w3_eff_xe_off_h_2j","Offline(xe100_XE70)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *a_w3_eff_or_1_off_h_2j = new TH2F("a_w3_eff_or_1_off_h_2j","Offline_raz_(xe100_XE70 or ProdR_2J15_XE55)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *a_w3_eff_or_5_off_h_2j = new TH2F("a_w3_eff_or_5_off_h_2j","Offline(xe100_XE70) or Offline_raz(ProdR_2J15_XE55)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *a_w3_eff_or_6_off_h_2j = new TH2F("a_w3_eff_or_6_off_h_2j","Combine two offline cuts",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *diff_a_w3_eff_or_1_off_h_2j = new TH2F("diff_a_w3_eff_or_1_off_h_2j","Difference wrt Offline_raz_(xe100_XE70 or ProdR_2J15_XE55)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *diff_a_w3_eff_or_5_off_h_2j = new TH2F("diff_a_w3_eff_or_5_off_h_2j","Difference wrt Offline(xe100_XE70) or Offline_raz(ProdR_2J15_XE55)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *diff_a_w3_eff_or_6_off_h_2j = new TH2F("diff_a_w3_eff_or_6_off_h_2j","Difference wrt Combined two offline cuts",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	
	
	// Axial W8pi
	
	TH2F *a_w8pi_eff_xe_h = new TH2F("a_w8pi_eff_xe_h","MET",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *a_w8pi_eff_or_1_h = new TH2F("a_w8pi_eff_or_1_h","MET or ProdR170_2J15_XE50",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm);
	TH2F *diff_a_w8pi_eff_or_1_h = new TH2F("diff_a_w8pi_eff_or_1_h","Difference MET or ProdR170_2J15_XE50",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	
	   
	TH2F *a_w8pi_eff_xe_off_h = new TH2F("a_w8pi_eff_xe_off_h","Offline(xe100_XE70)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm);
	TH2F *a_w8pi_eff_or_1_off_h = new TH2F("a_w8pi_eff_or_1_off_h","Offline_raz_(xe100_XE70 or ProdR_2J15_XE55)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm);
	TH2F *a_w8pi_eff_or_5_off_h = new TH2F("a_w8pi_eff_or_5_off_h","Offline(xe100_XE70) or Offline_raz(ProdR_2J15_XE55)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm);
	TH2F *a_w8pi_eff_or_6_off_h = new TH2F("a_w8pi_eff_or_6_off_h","Combine two offline cuts",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm);
	TH2F *diff_a_w8pi_eff_or_1_off_h = new TH2F("diff_a_w8pi_eff_or_1_off_h","Difference wrt Offline_raz_(xe100_XE70 or ProdR_2J15_XE55)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm);
	TH2F *diff_a_w8pi_eff_or_5_off_h = new TH2F("diff_a_w8pi_eff_or_5_off_h","Difference wrt Offline(xe100_XE70) or Offline_raz(ProdR_2J15_XE55)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *diff_a_w8pi_eff_or_6_off_h = new TH2F("diff_a_w8pi_eff_or_6_off_h","Difference wrt Combined two offline cuts",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm);
	
	
	TH2F *a_w8pi_eff_xe_h_2j = new TH2F("a_w8pi_eff_xe_h_2j","MET",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *a_w8pi_eff_or_1_h_2j = new TH2F("a_w8pi_eff_or_1_h_2j","MET or ProdR170_2J15_XE50",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm);
	TH2F *diff_a_w8pi_eff_or_1_h_2j = new TH2F("diff_a_w8pi_eff_or_1_h_2j","Difference MET or ProdR170_2J15_XE50",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );

	   
	TH2F *a_w8pi_eff_xe_off_h_2j = new TH2F("a_w8pi_eff_xe_off_h_2j","Offline(xe100_XE70)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm);
	TH2F *a_w8pi_eff_or_1_off_h_2j = new TH2F("a_w8pi_eff_or_1_off_h_2j","Offline_raz_(xe100_XE70 or ProdR_2J15_XE55)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm);
	TH2F *a_w8pi_eff_or_5_off_h_2j = new TH2F("a_w8pi_eff_or_5_off_h_2j","Offline(xe100_XE70) or Offline_raz(ProdR_2J15_XE55)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm);
	TH2F *a_w8pi_eff_or_6_off_h_2j = new TH2F("a_w8pi_eff_or_6_off_h_2j","Combine two offline cuts",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm);
	TH2F *diff_a_w8pi_eff_or_1_off_h_2j = new TH2F("diff_a_w8pi_eff_or_1_off_h_2j","Difference wrt Offline_raz_(xe100_XE70 or ProdR_2J15_XE55)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm);
	TH2F *diff_a_w8pi_eff_or_5_off_h_2j = new TH2F("diff_a_w8pi_eff_or_5_off_h_2j","Difference wrt Offline(xe100_XE70) or Offline_raz(ProdR_2J15_XE55)",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm );
	TH2F *diff_a_w8pi_eff_or_6_off_h_2j = new TH2F("diff_a_w8pi_eff_or_6_off_h_2j","Difference wrt Combined two offline cuts",number_mm_axial, 0, number_mm_axial, number_dm, 0, number_dm);
	

/*
	// Not really necessary
	TH2D eff_or_3_h
	TH2D eff_or_4
*/	
	
	// File to write the resulting canvases
	TFile *eff_plots = new TFile(choose_txt_directory+"/eff_plots.root","RECREATE","Efficiency Plots",9);
		
	// Now, event loops

	Int_t bin_dm;	
	Int_t bin_mm;
	
	// Vector W3
	for(Int_t i = 0; i<n_o_e_vector_w3; i++){
		
		eff_results_plots_vector_w3 -> GetEntry(i);
		if (dm_vector_w3 == 50)  	bin_dm = 0;
		if (dm_vector_w3 == 400) 	bin_dm = 1;
		if (mm_vector_w3 == 50)  	bin_mm = 0;
		if (mm_vector_w3 == 100) 	bin_mm = 1;
		if (mm_vector_w3 == 300) 	bin_mm = 2;
		if (mm_vector_w3 == 600) 	bin_mm = 3;
		if (mm_vector_w3 == 1000) 	bin_mm = 4;
		if (mm_vector_w3 == 3000)	bin_mm = 5;
		if (mm_vector_w3 == 6000)	bin_mm = 6;
		if (mm_vector_w3 == 10000)	bin_mm = 7;
		if (mm_vector_w3 == 30000)	bin_mm = 8;
		
		
		diff_eff_or_1 = efficiencies_eff_or_1_vector_w3 - efficiencies_eff_xe_vector_w3 ;
		diff_eff_or_1_off = efficiencies_eff_or_1_off_vector_w3 - efficiencies_eff_xe_off_vector_w3;
		diff_eff_or_5_off = efficiencies_eff_or_5_off_vector_w3 - efficiencies_eff_xe_off_vector_w3;
		diff_eff_or_6_off =  efficiencies_eff_or_6_off_vector_w3 - efficiencies_eff_xe_off_vector_w3;
		
		diff_eff_or_1_2j = efficiencies_eff_or_1_2j_vector_w3 - efficiencies_eff_xe_2j_vector_w3;
		diff_eff_or_1_off_2j = efficiencies_eff_or_1_off_2j_vector_w3 - efficiencies_eff_xe_off_2j_vector_w3;
		diff_eff_or_5_off_2j = efficiencies_eff_or_5_off_2j_vector_w3 - efficiencies_eff_xe_off_2j_vector_w3;
		diff_eff_or_6_off_2j = efficiencies_eff_or_6_off_2j_vector_w3 - efficiencies_eff_xe_off_2j_vector_w3; 
		

		v_w3_eff_xe_h 			->Fill(bin_mm,bin_dm,efficiencies_eff_xe_vector_w3);
        v_w3_eff_or_1_h 		->Fill(bin_mm,bin_dm,efficiencies_eff_or_1_vector_w3);
		diff_v_w3_eff_or_1_h 	->Fill(bin_mm,bin_dm,diff_eff_or_1);
		
		v_w3_eff_xe_off_h 		->Fill(bin_mm,bin_dm,efficiencies_eff_xe_off_vector_w3);
		v_w3_eff_or_1_off_h 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_1_off_vector_w3);
		v_w3_eff_or_5_off_h		->Fill(bin_mm,bin_dm,efficiencies_eff_or_5_off_vector_w3);
		v_w3_eff_or_6_off_h 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_6_off_vector_w3);
		diff_v_w3_eff_or_1_off_h->Fill(bin_mm,bin_dm,diff_eff_or_1_off); 
		diff_v_w3_eff_or_5_off_h->Fill(bin_mm,bin_dm,diff_eff_or_5_off);  
		diff_v_w3_eff_or_6_off_h->Fill(bin_mm,bin_dm,diff_eff_or_6_off);  
		                         
		v_w3_eff_xe_h_2j 		->Fill(bin_mm,bin_dm,efficiencies_eff_xe_2j_vector_w3);
		v_w3_eff_or_1_h_2j 		->Fill(bin_mm,bin_dm,efficiencies_eff_or_1_2j_vector_w3);
		diff_v_w3_eff_or_1_h_2j ->Fill(bin_mm,bin_dm,diff_eff_or_1_2j);
		
		v_w3_eff_xe_off_h_2j 	->Fill(bin_mm,bin_dm,efficiencies_eff_xe_off_2j_vector_w3);
		v_w3_eff_or_1_off_h_2j 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_1_off_2j_vector_w3);
		v_w3_eff_or_5_off_h_2j 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_5_off_2j_vector_w3);
		v_w3_eff_or_6_off_h_2j 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_6_off_2j_vector_w3);
		
		diff_v_w3_eff_or_1_off_h_2j ->Fill(bin_mm,bin_dm,diff_eff_or_1_off_2j);
		diff_v_w3_eff_or_5_off_h_2j ->Fill(bin_mm,bin_dm,diff_eff_or_5_off_2j);
		diff_v_w3_eff_or_6_off_h_2j ->Fill(bin_mm,bin_dm,diff_eff_or_6_off_2j);
		
		           
	}                                       
	

	setstyle();
	gStyle->SetPaintTextFormat("4.2f");
	gStyle->SetOptStat("n");
   
                                                                                                                                
 	for (int bin=0;bin<number_mm_vector;bin++){v_w3_eff_xe_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}							  
 	for (int bin=0;bin<number_dm;bin++){v_w3_eff_xe_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                                  
                                                                                                                     	            
	for (int bin=0;bin<number_mm_vector;bin++){v_w3_eff_or_1_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}                                        
 	for (int bin=0;bin<number_dm;bin++){v_w3_eff_or_1_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                                
                                                                                                                     	 	       
 	for (int bin=0;bin<number_mm_vector;bin++){diff_v_w3_eff_or_1_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}                       
 	for (int bin=0;bin<number_dm;bin++){diff_v_w3_eff_or_1_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                           
                                                                                                                     	          
 	for (int bin=0;bin<number_mm_vector;bin++){v_w3_eff_xe_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}                       
 	for (int bin=0;bin<number_dm;bin++){v_w3_eff_xe_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                                                         
                                                                                                                     	           		
 	for (int bin=0;bin<number_mm_vector;bin++){v_w3_eff_or_1_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}                      		  
 	for (int bin=0;bin<number_dm;bin++){v_w3_eff_or_1_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                                 
                                                                                                                     	                                     
 	for (int bin=0;bin<number_mm_vector;bin++){v_w3_eff_or_5_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}                                     
 	for (int bin=0;bin<number_dm;bin++){v_w3_eff_or_5_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                              	 	
                                                                                                                     	 	      
 	for (int bin=0;bin<number_mm_vector;bin++){v_w3_eff_or_6_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}                       	 	
 	for (int bin=0;bin<number_dm;bin++){v_w3_eff_or_6_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                              	 	
                                                                                                                     	                       
 	for (int bin=0;bin<number_mm_vector;bin++){diff_v_w3_eff_or_1_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}                       	
 	for (int bin=0;bin<number_dm;bin++){diff_v_w3_eff_or_1_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                              	
                                                                                                                     	          
 	for (int bin=0;bin<number_mm_vector;bin++){diff_v_w3_eff_or_5_off_h->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_v_w3_eff_or_5_off_h->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

 	for (int bin=0;bin<number_mm_vector;bin++){diff_v_w3_eff_or_6_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_v_w3_eff_or_6_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}
 	
	for (int bin=0;bin<number_mm_vector;bin++){v_w3_eff_xe_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){v_w3_eff_xe_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

 	for (int bin=0;bin<number_mm_vector;bin++){v_w3_eff_or_1_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){v_w3_eff_or_1_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}
  	
  	for (int bin=0;bin<number_mm_vector;bin++){diff_v_w3_eff_or_1_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_v_w3_eff_or_1_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_vector;bin++){v_w3_eff_xe_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){v_w3_eff_xe_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_vector;bin++){v_w3_eff_or_1_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){v_w3_eff_or_1_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_vector;bin++){v_w3_eff_or_5_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){v_w3_eff_or_5_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_vector;bin++){v_w3_eff_or_6_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){v_w3_eff_or_6_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_vector;bin++){diff_v_w3_eff_or_1_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_v_w3_eff_or_1_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_vector;bin++){diff_v_w3_eff_or_5_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_v_w3_eff_or_5_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_vector;bin++){diff_v_w3_eff_or_6_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_v_w3_eff_or_6_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

 	
	
	// Draw the histograms
	TCanvas *c1_v_w3 = new TCanvas("c1_v_w3", "c1",150,10,990,600);
	c1_v_w3->Clear();
	v_w3_eff_xe_h 				->Draw("coltextz");
	
	TCanvas *c2_v_w3 = new TCanvas("c2_c_w3", "c2_v_w3",150,10,990,600);
	c2_v_w3->Clear();
	v_w3_eff_or_1_h 			->Draw("coltextz"); 
	
	TCanvas *c3_v_w3 = new TCanvas("c3_v_w3", "c3",150,10,990,600);
	c3_v_w3->Clear();  
	diff_v_w3_eff_or_1_h 		->Draw("coltextz");

	TCanvas *c4_v_w3 = new TCanvas("c4_v_w3", "c4",150,10,990,600);
	c4_v_w3->Clear();                                        
	v_w3_eff_xe_off_h 			->Draw("coltextz");
	
	TCanvas *c5_v_w3 = new TCanvas("c5_v_w3", "c5",150,10,990,600);
	c5_v_w3->Clear();
	v_w3_eff_or_1_off_h 		->Draw("coltextz");
	
	TCanvas *c6_v_w3 = new TCanvas("c6_v_w3", "c6",150,10,990,600);
	c6_v_w3->Clear();
	v_w3_eff_or_5_off_h			->Draw("coltextz");
	
	TCanvas *c7_v_w3 = new TCanvas("c7_v_w3", "c7",150,10,990,600);
	c7_v_w3->Clear();
	v_w3_eff_or_6_off_h 		->Draw("coltextz");
	
	TCanvas *c8_v_w3 = new TCanvas("c8_v_w3", "c8",150,10,990,600);
	c8_v_w3->Clear();
	diff_v_w3_eff_or_1_off_h	->Draw("coltextz");
	
	TCanvas *c9_v_w3 = new TCanvas("c9_v_w3", "c9",150,10,990,600);
	c9_v_w3->Clear();
	diff_v_w3_eff_or_5_off_h	->Draw("coltextz");
	
	TCanvas *c10_v_w3 = new TCanvas("c10_v_w3", "c10",150,10,990,600);
	c10_v_w3->Clear();
	diff_v_w3_eff_or_6_off_h	->Draw("coltextz");
	
	TCanvas *c11_v_w3 = new TCanvas("c11_v_w3", "c11",150,10,990,600);
	c11_v_w3->Clear();                                    
	v_w3_eff_xe_h_2j 			->Draw("coltextz");
	
	TCanvas *c12_v_w3 = new TCanvas("c12_v_w3", "c12",150,10,990,600);
	c12_v_w3->Clear();
	v_w3_eff_or_1_h_2j 			->Draw("coltextz");
	
	TCanvas *c13_v_w3 = new TCanvas("c13_v_w3", "c13",150,10,990,600);
	c13_v_w3->Clear();
	diff_v_w3_eff_or_1_h_2j 	->Draw("coltextz");
	
	TCanvas *c14_v_w3 = new TCanvas("c14_v_w3", "c14",150,10,990,600);
	c14_v_w3->Clear();                                    
	v_w3_eff_xe_off_h_2j 		->Draw("coltextz");
	
	TCanvas *c15_v_w3 = new TCanvas("c15_v_w3", "c15",150,10,990,600);
	c15_v_w3->Clear();
	v_w3_eff_or_1_off_h_2j 		->Draw("coltextz");
	
	TCanvas *c16_v_w3 = new TCanvas("c16_v_w3", "c16",150,10,990,600);
	c16_v_w3->Clear();
	v_w3_eff_or_5_off_h_2j 		->Draw("coltextz");
	
	TCanvas *c17_v_w3 = new TCanvas("c17_v_w3", "c17",150,10,990,600);
	c17_v_w3->Clear();
	v_w3_eff_or_6_off_h_2j 		->Draw("coltextz");
	
	TCanvas *c18_v_w3 = new TCanvas("c18_v_w3", "c18",150,10,990,600);
	c18_v_w3->Clear();                                   
	diff_v_w3_eff_or_1_off_h_2j	->Draw("coltextz");
	
	TCanvas *c19_v_w3 = new TCanvas("c19_v_w3", "c19",150,10,990,600);
	c19_v_w3->Clear();
	diff_v_w3_eff_or_5_off_h_2j	->Draw("coltextz");
	
	TCanvas *c20_v_w3 = new TCanvas("c20_v_w3", "c20",150,10,990,600);
	c20_v_w3->Clear();
	diff_v_w3_eff_or_6_off_h_2j	->Draw("coltextz");

	
	
	
	
	
	
	
	// Vector W8pi
	for(Int_t j = 0; j<n_o_e_vector_w8pi; j++){
		
		eff_results_plots_vector_w8pi -> GetEntry(j);
		if (dm_vector_w8pi == 50)  		bin_dm = 0;
		if (dm_vector_w8pi == 400) 		bin_dm = 1;
		if (mm_vector_w8pi == 50)  		bin_mm = 0;
		if (mm_vector_w8pi == 100) 		bin_mm = 1;
		if (mm_vector_w8pi == 300) 		bin_mm = 2;
		if (mm_vector_w8pi == 600) 		bin_mm = 3;
		if (mm_vector_w8pi == 1000) 	bin_mm = 4;
		if (mm_vector_w8pi == 3000)		bin_mm = 5;
		if (mm_vector_w8pi == 6000)	bin_mm = 6;
		if (mm_vector_w8pi == 10000)	bin_mm = 7;
		if (mm_vector_w8pi == 30000)	bin_mm = 8;
		
		diff_eff_or_1 = efficiencies_eff_or_1_vector_w8pi - efficiencies_eff_xe_vector_w8pi ;
		diff_eff_or_1_off = efficiencies_eff_or_1_off_vector_w8pi - efficiencies_eff_xe_off_vector_w8pi;
		diff_eff_or_5_off = efficiencies_eff_or_5_off_vector_w8pi - efficiencies_eff_xe_off_vector_w8pi;
		diff_eff_or_6_off =  efficiencies_eff_or_6_off_vector_w8pi - efficiencies_eff_xe_off_vector_w8pi;
		
		diff_eff_or_1_2j = efficiencies_eff_or_1_2j_vector_w8pi - efficiencies_eff_xe_2j_vector_w8pi;
		diff_eff_or_1_off_2j = efficiencies_eff_or_1_off_2j_vector_w8pi - efficiencies_eff_xe_off_2j_vector_w8pi;
		diff_eff_or_5_off_2j = efficiencies_eff_or_5_off_2j_vector_w8pi - efficiencies_eff_xe_off_2j_vector_w8pi;
		diff_eff_or_6_off_2j = efficiencies_eff_or_6_off_2j_vector_w8pi - efficiencies_eff_xe_off_2j_vector_w8pi; 
		

		v_w8pi_eff_xe_h 			->Fill(bin_mm,bin_dm,efficiencies_eff_xe_vector_w8pi);
        v_w8pi_eff_or_1_h 		->Fill(bin_mm,bin_dm,efficiencies_eff_or_1_vector_w8pi);
		diff_v_w8pi_eff_or_1_h 	->Fill(bin_mm,bin_dm,diff_eff_or_1);
		
		v_w8pi_eff_xe_off_h 		->Fill(bin_mm,bin_dm,efficiencies_eff_xe_off_vector_w8pi);
		v_w8pi_eff_or_1_off_h 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_1_off_vector_w8pi);
		v_w8pi_eff_or_5_off_h		->Fill(bin_mm,bin_dm,efficiencies_eff_or_5_off_vector_w8pi);
		v_w8pi_eff_or_6_off_h 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_6_off_vector_w8pi);
		diff_v_w8pi_eff_or_1_off_h->Fill(bin_mm,bin_dm,diff_eff_or_1_off); 
		diff_v_w8pi_eff_or_5_off_h->Fill(bin_mm,bin_dm,diff_eff_or_5_off);  
		diff_v_w8pi_eff_or_6_off_h->Fill(bin_mm,bin_dm,diff_eff_or_6_off);  
		                         
		v_w8pi_eff_xe_h_2j 		->Fill(bin_mm,bin_dm,efficiencies_eff_xe_2j_vector_w8pi);
		v_w8pi_eff_or_1_h_2j 		->Fill(bin_mm,bin_dm,efficiencies_eff_or_1_2j_vector_w8pi);
		diff_v_w8pi_eff_or_1_h_2j ->Fill(bin_mm,bin_dm,diff_eff_or_1_2j);
		
		v_w8pi_eff_xe_off_h_2j 	->Fill(bin_mm,bin_dm,efficiencies_eff_xe_off_2j_vector_w8pi);
		v_w8pi_eff_or_1_off_h_2j 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_1_off_2j_vector_w8pi);
		v_w8pi_eff_or_5_off_h_2j 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_5_off_2j_vector_w8pi);
		v_w8pi_eff_or_6_off_h_2j 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_6_off_2j_vector_w8pi);
		
		diff_v_w8pi_eff_or_1_off_h_2j ->Fill(bin_mm,bin_dm,diff_eff_or_1_off_2j);
		diff_v_w8pi_eff_or_5_off_h_2j ->Fill(bin_mm,bin_dm,diff_eff_or_5_off_2j);
		diff_v_w8pi_eff_or_6_off_h_2j ->Fill(bin_mm,bin_dm,diff_eff_or_6_off_2j);
		
		
	}
	
	
	
	setstyle();
	gStyle->SetPaintTextFormat("4.2f");
	gStyle->SetOptStat("n");
   
                                                                                                                                
 	for (int bin=0;bin<number_mm_vector;bin++){v_w8pi_eff_xe_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}							  
 	for (int bin=0;bin<number_dm;bin++){v_w8pi_eff_xe_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                                  
                                                                                                                     	            
	for (int bin=0;bin<number_mm_vector;bin++){v_w8pi_eff_or_1_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}                                        
 	for (int bin=0;bin<number_dm;bin++){v_w8pi_eff_or_1_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                                
                                                                                                                     	 	       
 	for (int bin=0;bin<number_mm_vector;bin++){diff_v_w8pi_eff_or_1_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}                       
 	for (int bin=0;bin<number_dm;bin++){diff_v_w8pi_eff_or_1_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                           
                                                                                                                     	          
 	for (int bin=0;bin<number_mm_vector;bin++){v_w8pi_eff_xe_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}                       
 	for (int bin=0;bin<number_dm;bin++){v_w8pi_eff_xe_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                                                         
                                                                                                                     	           		
 	for (int bin=0;bin<number_mm_vector;bin++){v_w8pi_eff_or_1_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}                      		  
 	for (int bin=0;bin<number_dm;bin++){v_w8pi_eff_or_1_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                                 
                                                                                                                     	                                     
 	for (int bin=0;bin<number_mm_vector;bin++){v_w8pi_eff_or_5_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}                                     
 	for (int bin=0;bin<number_dm;bin++){v_w8pi_eff_or_5_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                              	 	
                                                                                                                     	 	      
 	for (int bin=0;bin<number_mm_vector;bin++){v_w8pi_eff_or_6_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}                       	 	
 	for (int bin=0;bin<number_dm;bin++){v_w8pi_eff_or_6_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                              	 	
                                                                                                                     	                       
 	for (int bin=0;bin<number_mm_vector;bin++){diff_v_w8pi_eff_or_1_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}                       	
 	for (int bin=0;bin<number_dm;bin++){diff_v_w8pi_eff_or_1_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                              	
                                                                                                                     	          
 	for (int bin=0;bin<number_mm_vector;bin++){diff_v_w8pi_eff_or_5_off_h->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_v_w8pi_eff_or_5_off_h->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

 	for (int bin=0;bin<number_mm_vector;bin++){diff_v_w8pi_eff_or_6_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_v_w8pi_eff_or_6_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}
 	
	for (int bin=0;bin<number_mm_vector;bin++){v_w8pi_eff_xe_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){v_w8pi_eff_xe_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

 	for (int bin=0;bin<number_mm_vector;bin++){v_w8pi_eff_or_1_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){v_w8pi_eff_or_1_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}
  	
  	for (int bin=0;bin<number_mm_vector;bin++){diff_v_w8pi_eff_or_1_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_v_w8pi_eff_or_1_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_vector;bin++){v_w8pi_eff_xe_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){v_w8pi_eff_xe_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_vector;bin++){v_w8pi_eff_or_1_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){v_w8pi_eff_or_1_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_vector;bin++){v_w8pi_eff_or_5_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){v_w8pi_eff_or_5_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_vector;bin++){v_w8pi_eff_or_6_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){v_w8pi_eff_or_6_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_vector;bin++){diff_v_w8pi_eff_or_1_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_v_w8pi_eff_or_1_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_vector;bin++){diff_v_w8pi_eff_or_5_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_v_w8pi_eff_or_5_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_vector;bin++){diff_v_w8pi_eff_or_6_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_vector[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_v_w8pi_eff_or_6_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

 	
	
	// Draw the histograms
	TCanvas *c1_v_w8pi = new TCanvas("c1_v_w8pi", "c1",150,10,990,600);
	c1_v_w8pi->Clear();
	v_w8pi_eff_xe_h 				->Draw("coltextz");
	
	TCanvas *c2_v_w8pi = new TCanvas("c2_c_w8pi", "c2_v_w8pi",150,10,990,600);
	c2_v_w8pi->Clear();
	v_w8pi_eff_or_1_h 			->Draw("coltextz"); 
	
	TCanvas *c3_v_w8pi = new TCanvas("c3_v_w8pi", "c3",150,10,990,600);
	c3_v_w8pi->Clear();  
	diff_v_w8pi_eff_or_1_h 		->Draw("coltextz");

	TCanvas *c4_v_w8pi = new TCanvas("c4_v_w8pi", "c4",150,10,990,600);
	c4_v_w8pi->Clear();                                        
	v_w8pi_eff_xe_off_h 			->Draw("coltextz");
	
	TCanvas *c5_v_w8pi = new TCanvas("c5_v_w8pi", "c5",150,10,990,600);
	c5_v_w8pi->Clear();
	v_w8pi_eff_or_1_off_h 		->Draw("coltextz");
	
	TCanvas *c6_v_w8pi = new TCanvas("c6_v_w8pi", "c6",150,10,990,600);
	c6_v_w8pi->Clear();
	v_w8pi_eff_or_5_off_h			->Draw("coltextz");
	
	TCanvas *c7_v_w8pi = new TCanvas("c7_v_w8pi", "c7",150,10,990,600);
	c7_v_w8pi->Clear();
	v_w8pi_eff_or_6_off_h 		->Draw("coltextz");
	
	TCanvas *c8_v_w8pi = new TCanvas("c8_v_w8pi", "c8",150,10,990,600);
	c8_v_w8pi->Clear();
	diff_v_w8pi_eff_or_1_off_h	->Draw("coltextz");
	
	TCanvas *c9_v_w8pi = new TCanvas("c9_v_w8pi", "c9",150,10,990,600);
	c9_v_w8pi->Clear();
	diff_v_w8pi_eff_or_5_off_h	->Draw("coltextz");
	
	TCanvas *c10_v_w8pi = new TCanvas("c10_v_w8pi", "c10",150,10,990,600);
	c10_v_w8pi->Clear();
	diff_v_w8pi_eff_or_6_off_h	->Draw("coltextz");
	
	TCanvas *c11_v_w8pi = new TCanvas("c11_v_w8pi", "c11",150,10,990,600);
	c11_v_w8pi->Clear();                                    
	v_w8pi_eff_xe_h_2j 			->Draw("coltextz");
	
	TCanvas *c12_v_w8pi = new TCanvas("c12_v_w8pi", "c12",150,10,990,600);
	c12_v_w8pi->Clear();
	v_w8pi_eff_or_1_h_2j 			->Draw("coltextz");
	
	TCanvas *c13_v_w8pi = new TCanvas("c13_v_w8pi", "c13",150,10,990,600);
	c13_v_w8pi->Clear();
	diff_v_w8pi_eff_or_1_h_2j 	->Draw("coltextz");
	
	TCanvas *c14_v_w8pi = new TCanvas("c14_v_w8pi", "c14",150,10,990,600);
	c14_v_w8pi->Clear();                                    
	v_w8pi_eff_xe_off_h_2j 		->Draw("coltextz");
	
	TCanvas *c15_v_w8pi = new TCanvas("c15_v_w8pi", "c15",150,10,990,600);
	c15_v_w8pi->Clear();
	v_w8pi_eff_or_1_off_h_2j 		->Draw("coltextz");
	
	TCanvas *c16_v_w8pi = new TCanvas("c16_v_w8pi", "c16",150,10,990,600);
	c16_v_w8pi->Clear();
	v_w8pi_eff_or_5_off_h_2j 		->Draw("coltextz");
	
	TCanvas *c17_v_w8pi = new TCanvas("c17_v_w8pi", "c17",150,10,990,600);
	c17_v_w8pi->Clear();
	v_w8pi_eff_or_6_off_h_2j 		->Draw("coltextz");
	
	TCanvas *c18_v_w8pi = new TCanvas("c18_v_w8pi", "c18",150,10,990,600);
	c18_v_w8pi->Clear();                                   
	diff_v_w8pi_eff_or_1_off_h_2j	->Draw("coltextz");
	
	TCanvas *c19_v_w8pi = new TCanvas("c19_v_w8pi", "c19",150,10,990,600);
	c19_v_w8pi->Clear();
	diff_v_w8pi_eff_or_5_off_h_2j	->Draw("coltextz");
	
	TCanvas *c20_v_w8pi = new TCanvas("c20_v_w8pi", "c20",150,10,990,600);
	c20_v_w8pi->Clear();
	diff_v_w8pi_eff_or_6_off_h_2j	->Draw("coltextz");
	
	
	
		c1_v_w3->SaveAs(output_dir+"/c1_v_w3.pdf");
	c2_v_w3->SaveAs(output_dir+"/c2_v_w3.pdf");
	c3_v_w3->SaveAs(output_dir+"/c3_v_w3.pdf");
	c4_v_w3->SaveAs(output_dir+"/c4_v_w3.pdf");
	c5_v_w3->SaveAs(output_dir+"/c5_v_w3.pdf");
	c6_v_w3->SaveAs(output_dir+"/c6_v_w3.pdf");
	c7_v_w3->SaveAs(output_dir+"/c7_v_w3.pdf");
	c8_v_w3->SaveAs(output_dir+"/c8_v_w3.pdf");
	c9_v_w3->SaveAs(output_dir+"/c9_v_w3.pdf");
	c10_v_w3->SaveAs(output_dir+"/c10_v_w3.pdf");
	c11_v_w3->SaveAs(output_dir+"/c11_v_w3.pdf");
	c12_v_w3->SaveAs(output_dir+"/c12_v_w3.pdf");
	c13_v_w3->SaveAs(output_dir+"/c13_v_w3.pdf");
	c14_v_w3->SaveAs(output_dir+"/c14_v_w3.pdf");
	c15_v_w3->SaveAs(output_dir+"/c15_v_w3.pdf");
	c16_v_w3->SaveAs(output_dir+"/c16_v_w3.pdf");
	c17_v_w3->SaveAs(output_dir+"/c17_v_w3.pdf");
	c18_v_w3->SaveAs(output_dir+"/c18_v_w3.pdf");
	c19_v_w3->SaveAs(output_dir+"/c19_v_w3.pdf");
	c20_v_w3->SaveAs(output_dir+"/c20_v_w3.pdf");
	
	
	c1_v_w8pi->SaveAs(output_dir+"/c1_v_w8pi.pdf");
	c2_v_w8pi->SaveAs(output_dir+"/c2_v_w8pi.pdf");
	c3_v_w8pi->SaveAs(output_dir+"/c3_v_w8pi.pdf");
	c4_v_w8pi->SaveAs(output_dir+"/c4_v_w8pi.pdf");
	c5_v_w8pi->SaveAs(output_dir+"/c5_v_w8pi.pdf");
	c6_v_w8pi->SaveAs(output_dir+"/c6_v_w8pi.pdf");
	c7_v_w8pi->SaveAs(output_dir+"/c7_v_w8pi.pdf");
	c8_v_w8pi->SaveAs(output_dir+"/c8_v_w8pi.pdf");
	c9_v_w8pi->SaveAs(output_dir+"/c9_v_w8pi.pdf");
	c10_v_w8pi->SaveAs(output_dir+"/c10_v_w8pi.pdf");
	c11_v_w8pi->SaveAs(output_dir+"/c11_v_w8pi.pdf");
	c12_v_w8pi->SaveAs(output_dir+"/c12_v_w8pi.pdf");
	c13_v_w8pi->SaveAs(output_dir+"/c13_v_w8pi.pdf");
	c14_v_w8pi->SaveAs(output_dir+"/c14_v_w8pi.pdf");
	c15_v_w8pi->SaveAs(output_dir+"/c15_v_w8pi.pdf");
	c16_v_w8pi->SaveAs(output_dir+"/c16_v_w8pi.pdf");
	c17_v_w8pi->SaveAs(output_dir+"/c17_v_w8pi.pdf");
	c18_v_w8pi->SaveAs(output_dir+"/c18_v_w8pi.pdf");
	c19_v_w8pi->SaveAs(output_dir+"/c19_v_w8pi.pdf");
	c20_v_w8pi->SaveAs(output_dir+"/c20_v_w8pi.pdf");

	
	
	c1_v_w3->Write();              	c1_v_w3->Close();
	c2_v_w3->Write();              	c2_v_w3->Close();
	c3_v_w3->Write();              	c3_v_w3->Close();
	c4_v_w3->Write();              	c4_v_w3->Close();
	c5_v_w3->Write();              	c5_v_w3->Close();
	c6_v_w3->Write();              	c6_v_w3->Close();
	c7_v_w3->Write();              	c7_v_w3->Close();
	c8_v_w3->Write();              	c8_v_w3->Close();
	c9_v_w3->Write();              	c9_v_w3->Close();
	c10_v_w3->Write();             	c10_v_w3->Close();
	c11_v_w3->Write();             	c11_v_w3->Close();
	c12_v_w3->Write();             	c12_v_w3->Close();
	c13_v_w3->Write();             	c13_v_w3->Close();
	c14_v_w3->Write();             	c14_v_w3->Close();
	c15_v_w3->Write();             	c15_v_w3->Close();
	c16_v_w3->Write();             	c16_v_w3->Close();
	c17_v_w3->Write();             	c17_v_w3->Close();
	c18_v_w3->Write();             	c18_v_w3->Close();
	c19_v_w3->Write();             	c19_v_w3->Close();
	c20_v_w3->Write();             	c20_v_w3->Close();
	                               	
	c1_v_w8pi->Write();            	c1_v_w8pi->Close();
	c2_v_w8pi->Write();            	c2_v_w8pi->Close();
	c3_v_w8pi->Write();            	c3_v_w8pi->Close();
	c4_v_w8pi->Write();            	c4_v_w8pi->Close();
	c5_v_w8pi->Write();            	c5_v_w8pi->Close();
	c6_v_w8pi->Write();            	c6_v_w8pi->Close();
	c7_v_w8pi->Write();            	c7_v_w8pi->Close();
	c8_v_w8pi->Write();            	c8_v_w8pi->Close();
	c9_v_w8pi->Write();            	c9_v_w8pi->Close();
	c10_v_w8pi->Write();           	c10_v_w8pi->Close();
	c11_v_w8pi->Write();           	c11_v_w8pi->Close();
	c12_v_w8pi->Write();           	c12_v_w8pi->Close();
	c13_v_w8pi->Write();           	c13_v_w8pi->Close();
	c14_v_w8pi->Write();           	c14_v_w8pi->Close();
	c15_v_w8pi->Write();           	c15_v_w8pi->Close();
	c16_v_w8pi->Write();           	c16_v_w8pi->Close();
	c17_v_w8pi->Write();           	c17_v_w8pi->Close();
	c18_v_w8pi->Write();           	c18_v_w8pi->Close();
	c19_v_w8pi->Write();           	c19_v_w8pi->Close();
	c20_v_w8pi->Write();           	c20_v_w8pi->Close();
	
	
	
	
	

	// Axial W3
	for(Int_t k = 0; k<n_o_e_axial_w3; k++){
		
		eff_results_plots_axial_w3 -> GetEntry(k);
		if (dm_axial_w3 == 50)  	bin_dm = 0;
		if (dm_axial_w3 == 400) 	bin_dm = 1;
		if (mm_axial_w3 == 50)  	bin_mm = 0;
		if (mm_axial_w3 == 100) 	bin_mm = 1;
		if (mm_axial_w3 == 300) 	bin_mm = 2;
		if (mm_axial_w3 == 600) 	bin_mm = 3;	

		diff_eff_or_1 = efficiencies_eff_or_1_axial_w3 - efficiencies_eff_xe_axial_w3 ;
		diff_eff_or_1_off = efficiencies_eff_or_1_off_axial_w3 - efficiencies_eff_xe_off_axial_w3;
		diff_eff_or_5_off = efficiencies_eff_or_5_off_axial_w3 - efficiencies_eff_xe_off_axial_w3;
		diff_eff_or_6_off =  efficiencies_eff_or_6_off_axial_w3 - efficiencies_eff_xe_off_axial_w3;
		
		diff_eff_or_1_2j = efficiencies_eff_or_1_2j_axial_w3 - efficiencies_eff_xe_2j_axial_w3;
		diff_eff_or_1_off_2j = efficiencies_eff_or_1_off_2j_axial_w3 - efficiencies_eff_xe_off_2j_axial_w3;
		diff_eff_or_5_off_2j = efficiencies_eff_or_5_off_2j_axial_w3 - efficiencies_eff_xe_off_2j_axial_w3;
		diff_eff_or_6_off_2j = efficiencies_eff_or_6_off_2j_axial_w3 - efficiencies_eff_xe_off_2j_axial_w3; 
		

		a_w3_eff_xe_h 			->Fill(bin_mm,bin_dm,efficiencies_eff_xe_axial_w3);
        a_w3_eff_or_1_h 		->Fill(bin_mm,bin_dm,efficiencies_eff_or_1_axial_w3);
		diff_a_w3_eff_or_1_h 	->Fill(bin_mm,bin_dm,diff_eff_or_1);
		
		a_w3_eff_xe_off_h 		->Fill(bin_mm,bin_dm,efficiencies_eff_xe_off_axial_w3);
		a_w3_eff_or_1_off_h 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_1_off_axial_w3);
		a_w3_eff_or_5_off_h		->Fill(bin_mm,bin_dm,efficiencies_eff_or_5_off_axial_w3);
		a_w3_eff_or_6_off_h 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_6_off_axial_w3);
		diff_a_w3_eff_or_1_off_h->Fill(bin_mm,bin_dm,diff_eff_or_1_off); 
		diff_a_w3_eff_or_5_off_h->Fill(bin_mm,bin_dm,diff_eff_or_5_off);  
		diff_a_w3_eff_or_6_off_h->Fill(bin_mm,bin_dm,diff_eff_or_6_off);  
		                         
		a_w3_eff_xe_h_2j 		->Fill(bin_mm,bin_dm,efficiencies_eff_xe_2j_axial_w3);
		a_w3_eff_or_1_h_2j 		->Fill(bin_mm,bin_dm,efficiencies_eff_or_1_2j_axial_w3);
		diff_a_w3_eff_or_1_h_2j ->Fill(bin_mm,bin_dm,diff_eff_or_1_2j);
		
		a_w3_eff_xe_off_h_2j 	->Fill(bin_mm,bin_dm,efficiencies_eff_xe_off_2j_axial_w3);
		a_w3_eff_or_1_off_h_2j 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_1_off_2j_axial_w3);
		a_w3_eff_or_5_off_h_2j 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_5_off_2j_axial_w3);
		a_w3_eff_or_6_off_h_2j 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_6_off_2j_axial_w3);
		
		diff_a_w3_eff_or_1_off_h_2j ->Fill(bin_mm,bin_dm,diff_eff_or_1_off_2j);
		diff_a_w3_eff_or_5_off_h_2j ->Fill(bin_mm,bin_dm,diff_eff_or_5_off_2j);
		diff_a_w3_eff_or_6_off_h_2j ->Fill(bin_mm,bin_dm,diff_eff_or_6_off_2j);
		
	}
	
	
	setstyle();
	gStyle->SetPaintTextFormat("4.2f");
	gStyle->SetOptStat("n");
   
                                                                                                                                
 	for (int bin=0;bin<number_mm_axial;bin++){a_w3_eff_xe_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}							  
 	for (int bin=0;bin<number_dm;bin++){a_w3_eff_xe_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                                  
                                                                                                                     	            
	for (int bin=0;bin<number_mm_axial;bin++){a_w3_eff_or_1_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}                                        
 	for (int bin=0;bin<number_dm;bin++){a_w3_eff_or_1_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                                
                                                                                                                     	 	       
 	for (int bin=0;bin<number_mm_axial;bin++){diff_a_w3_eff_or_1_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}                       
 	for (int bin=0;bin<number_dm;bin++){diff_a_w3_eff_or_1_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                           
                                                                                                                     	          
 	for (int bin=0;bin<number_mm_axial;bin++){a_w3_eff_xe_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}                       
 	for (int bin=0;bin<number_dm;bin++){a_w3_eff_xe_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                                                         
                                                                                                                     	           		
 	for (int bin=0;bin<number_mm_axial;bin++){a_w3_eff_or_1_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}                      		  
 	for (int bin=0;bin<number_dm;bin++){a_w3_eff_or_1_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                                 
                                                                                                                     	                                     
 	for (int bin=0;bin<number_mm_axial;bin++){a_w3_eff_or_5_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}                                     
 	for (int bin=0;bin<number_dm;bin++){a_w3_eff_or_5_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                              	 	
                                                                                                                     	 	      
 	for (int bin=0;bin<number_mm_axial;bin++){a_w3_eff_or_6_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}                       	 	
 	for (int bin=0;bin<number_dm;bin++){a_w3_eff_or_6_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                              	 	
                                                                                                                     	                       
 	for (int bin=0;bin<number_mm_axial;bin++){diff_a_w3_eff_or_1_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}                       	
 	for (int bin=0;bin<number_dm;bin++){diff_a_w3_eff_or_1_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                              	
                                                                                                                     	          
 	for (int bin=0;bin<number_mm_axial;bin++){diff_a_w3_eff_or_5_off_h->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_a_w3_eff_or_5_off_h->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

 	for (int bin=0;bin<number_mm_axial;bin++){diff_a_w3_eff_or_6_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_a_w3_eff_or_6_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}
 	
	for (int bin=0;bin<number_mm_axial;bin++){a_w3_eff_xe_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){a_w3_eff_xe_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

 	for (int bin=0;bin<number_mm_axial;bin++){a_w3_eff_or_1_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){a_w3_eff_or_1_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}
  	
  	for (int bin=0;bin<number_mm_axial;bin++){diff_a_w3_eff_or_1_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_a_w3_eff_or_1_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_axial;bin++){a_w3_eff_xe_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){a_w3_eff_xe_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_axial;bin++){a_w3_eff_or_1_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){a_w3_eff_or_1_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_axial;bin++){a_w3_eff_or_5_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){a_w3_eff_or_5_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_axial;bin++){a_w3_eff_or_6_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){a_w3_eff_or_6_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_axial;bin++){diff_a_w3_eff_or_1_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_a_w3_eff_or_1_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_axial;bin++){diff_a_w3_eff_or_5_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_a_w3_eff_or_5_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_axial;bin++){diff_a_w3_eff_or_6_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_a_w3_eff_or_6_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

 	
	
	// Draw the histograms
	TCanvas *c1_a_w3 = new TCanvas("c1_a_w3", "c1",150,10,990,600);
	c1_a_w3->Clear();
	a_w3_eff_xe_h 				->Draw("coltextz");
	
	TCanvas *c2_a_w3 = new TCanvas("c2_c_w3", "c2_a_w3",150,10,990,600);
	c2_a_w3->Clear();
	a_w3_eff_or_1_h 			->Draw("coltextz"); 
	
	TCanvas *c3_a_w3 = new TCanvas("c3_a_w3", "c3",150,10,990,600);
	c3_a_w3->Clear();  
	diff_a_w3_eff_or_1_h 		->Draw("coltextz");

	TCanvas *c4_a_w3 = new TCanvas("c4_a_w3", "c4",150,10,990,600);
	c4_a_w3->Clear();                                        
	a_w3_eff_xe_off_h 			->Draw("coltextz");
	
	TCanvas *c5_a_w3 = new TCanvas("c5_a_w3", "c5",150,10,990,600);
	c5_a_w3->Clear();
	a_w3_eff_or_1_off_h 		->Draw("coltextz");
	
	TCanvas *c6_a_w3 = new TCanvas("c6_a_w3", "c6",150,10,990,600);
	c6_a_w3->Clear();
	a_w3_eff_or_5_off_h			->Draw("coltextz");
	
	TCanvas *c7_a_w3 = new TCanvas("c7_a_w3", "c7",150,10,990,600);
	c7_a_w3->Clear();
	a_w3_eff_or_6_off_h 		->Draw("coltextz");
	
	TCanvas *c8_a_w3 = new TCanvas("c8_a_w3", "c8",150,10,990,600);
	c8_a_w3->Clear();
	diff_a_w3_eff_or_1_off_h	->Draw("coltextz");
	
	TCanvas *c9_a_w3 = new TCanvas("c9_a_w3", "c9",150,10,990,600);
	c9_a_w3->Clear();
	diff_a_w3_eff_or_5_off_h	->Draw("coltextz");
	
	TCanvas *c10_a_w3 = new TCanvas("c10_a_w3", "c10",150,10,990,600);
	c10_a_w3->Clear();
	diff_a_w3_eff_or_6_off_h	->Draw("coltextz");
	
	TCanvas *c11_a_w3 = new TCanvas("c11_a_w3", "c11",150,10,990,600);
	c11_a_w3->Clear();                                    
	a_w3_eff_xe_h_2j 			->Draw("coltextz");
	
	TCanvas *c12_a_w3 = new TCanvas("c12_a_w3", "c12",150,10,990,600);
	c12_a_w3->Clear();
	a_w3_eff_or_1_h_2j 			->Draw("coltextz");
	
	TCanvas *c13_a_w3 = new TCanvas("c13_a_w3", "c13",150,10,990,600);
	c13_a_w3->Clear();
	diff_a_w3_eff_or_1_h_2j 	->Draw("coltextz");
	
	TCanvas *c14_a_w3 = new TCanvas("c14_a_w3", "c14",150,10,990,600);
	c14_a_w3->Clear();                                    
	a_w3_eff_xe_off_h_2j 		->Draw("coltextz");
	
	TCanvas *c15_a_w3 = new TCanvas("c15_a_w3", "c15",150,10,990,600);
	c15_a_w3->Clear();
	a_w3_eff_or_1_off_h_2j 		->Draw("coltextz");
	
	TCanvas *c16_a_w3 = new TCanvas("c16_a_w3", "c16",150,10,990,600);
	c16_a_w3->Clear();
	a_w3_eff_or_5_off_h_2j 		->Draw("coltextz");
	
	TCanvas *c17_a_w3 = new TCanvas("c17_a_w3", "c17",150,10,990,600);
	c17_a_w3->Clear();
	a_w3_eff_or_6_off_h_2j 		->Draw("coltextz");
	
	TCanvas *c18_a_w3 = new TCanvas("c18_a_w3", "c18",150,10,990,600);
	c18_a_w3->Clear();                                   
	diff_a_w3_eff_or_1_off_h_2j	->Draw("coltextz");
	
	TCanvas *c19_a_w3 = new TCanvas("c19_a_w3", "c19",150,10,990,600);
	c19_a_w3->Clear();
	diff_a_w3_eff_or_5_off_h_2j	->Draw("coltextz");
	
	TCanvas *c20_a_w3 = new TCanvas("c20_a_w3", "c20",150,10,990,600);
	c20_a_w3->Clear();
	diff_a_w3_eff_or_6_off_h_2j	->Draw("coltextz");

	
	
	
	// Axial W8pi
	for(Int_t l = 0; l<n_o_e_axial_w8pi; l++){
		
		eff_results_plots_axial_w8pi -> GetEntry(l);
		if (dm_axial_w8pi == 50)  	bin_dm = 0;
		if (dm_axial_w8pi == 400) 	bin_dm = 1;
		if (mm_axial_w8pi == 50)  	bin_mm = 0;
		if (mm_axial_w8pi == 100) 	bin_mm = 1;
		if (mm_axial_w8pi == 300) 	bin_mm = 2;
		if (mm_axial_w8pi == 600) 	bin_mm = 3;	
		
		diff_eff_or_1 = efficiencies_eff_or_1_axial_w8pi - efficiencies_eff_xe_axial_w8pi ;
		diff_eff_or_1_off = efficiencies_eff_or_1_off_axial_w8pi - efficiencies_eff_xe_off_axial_w8pi;
		diff_eff_or_5_off = efficiencies_eff_or_5_off_axial_w8pi - efficiencies_eff_xe_off_axial_w8pi;
		diff_eff_or_6_off =  efficiencies_eff_or_6_off_axial_w8pi - efficiencies_eff_xe_off_axial_w8pi;
		
		diff_eff_or_1_2j = efficiencies_eff_or_1_2j_axial_w8pi - efficiencies_eff_xe_2j_axial_w8pi;
		diff_eff_or_1_off_2j = efficiencies_eff_or_1_off_2j_axial_w8pi - efficiencies_eff_xe_off_2j_axial_w8pi;
		diff_eff_or_5_off_2j = efficiencies_eff_or_5_off_2j_axial_w8pi - efficiencies_eff_xe_off_2j_axial_w8pi;
		diff_eff_or_6_off_2j = efficiencies_eff_or_6_off_2j_axial_w8pi - efficiencies_eff_xe_off_2j_axial_w8pi; 
		

		a_w8pi_eff_xe_h 			->Fill(bin_mm,bin_dm,efficiencies_eff_xe_axial_w8pi);
        a_w8pi_eff_or_1_h 		->Fill(bin_mm,bin_dm,efficiencies_eff_or_1_axial_w8pi);
		diff_a_w8pi_eff_or_1_h 	->Fill(bin_mm,bin_dm,diff_eff_or_1);
		
		a_w8pi_eff_xe_off_h 		->Fill(bin_mm,bin_dm,efficiencies_eff_xe_off_axial_w8pi);
		a_w8pi_eff_or_1_off_h 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_1_off_axial_w8pi);
		a_w8pi_eff_or_5_off_h		->Fill(bin_mm,bin_dm,efficiencies_eff_or_5_off_axial_w8pi);
		a_w8pi_eff_or_6_off_h 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_6_off_axial_w8pi);
		diff_a_w8pi_eff_or_1_off_h->Fill(bin_mm,bin_dm,diff_eff_or_1_off); 
		diff_a_w8pi_eff_or_5_off_h->Fill(bin_mm,bin_dm,diff_eff_or_5_off);  
		diff_a_w8pi_eff_or_6_off_h->Fill(bin_mm,bin_dm,diff_eff_or_6_off);  
		                         
		a_w8pi_eff_xe_h_2j 		->Fill(bin_mm,bin_dm,efficiencies_eff_xe_2j_axial_w8pi);
		a_w8pi_eff_or_1_h_2j 		->Fill(bin_mm,bin_dm,efficiencies_eff_or_1_2j_axial_w8pi);
		diff_a_w8pi_eff_or_1_h_2j ->Fill(bin_mm,bin_dm,diff_eff_or_1_2j);
		
		a_w8pi_eff_xe_off_h_2j 	->Fill(bin_mm,bin_dm,efficiencies_eff_xe_off_2j_axial_w8pi);
		a_w8pi_eff_or_1_off_h_2j 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_1_off_2j_axial_w8pi);
		a_w8pi_eff_or_5_off_h_2j 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_5_off_2j_axial_w8pi);
		a_w8pi_eff_or_6_off_h_2j 	->Fill(bin_mm,bin_dm,efficiencies_eff_or_6_off_2j_axial_w8pi);
		
		diff_a_w8pi_eff_or_1_off_h_2j ->Fill(bin_mm,bin_dm,diff_eff_or_1_off_2j);
		diff_a_w8pi_eff_or_5_off_h_2j ->Fill(bin_mm,bin_dm,diff_eff_or_5_off_2j);
		diff_a_w8pi_eff_or_6_off_h_2j ->Fill(bin_mm,bin_dm,diff_eff_or_6_off_2j);
		
		
		
	}
	
	setstyle();
	gStyle->SetPaintTextFormat("4.2f");
	gStyle->SetOptStat("n");
   
                                                                                                                                
 	for (int bin=0;bin<number_mm_axial;bin++){a_w8pi_eff_xe_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}							  
 	for (int bin=0;bin<number_dm;bin++){a_w8pi_eff_xe_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                                  
                                                                                                                     	            
	for (int bin=0;bin<number_mm_axial;bin++){a_w8pi_eff_or_1_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}                                        
 	for (int bin=0;bin<number_dm;bin++){a_w8pi_eff_or_1_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                                
                                                                                                                     	 	       
 	for (int bin=0;bin<number_mm_axial;bin++){diff_a_w8pi_eff_or_1_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}                       
 	for (int bin=0;bin<number_dm;bin++){diff_a_w8pi_eff_or_1_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                           
                                                                                                                     	          
 	for (int bin=0;bin<number_mm_axial;bin++){a_w8pi_eff_xe_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}                       
 	for (int bin=0;bin<number_dm;bin++){a_w8pi_eff_xe_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                                                         
                                                                                                                     	           		
 	for (int bin=0;bin<number_mm_axial;bin++){a_w8pi_eff_or_1_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}                      		  
 	for (int bin=0;bin<number_dm;bin++){a_w8pi_eff_or_1_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                                 
                                                                                                                     	                                     
 	for (int bin=0;bin<number_mm_axial;bin++){a_w8pi_eff_or_5_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}                                     
 	for (int bin=0;bin<number_dm;bin++){a_w8pi_eff_or_5_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                              	 	
                                                                                                                     	 	      
 	for (int bin=0;bin<number_mm_axial;bin++){a_w8pi_eff_or_6_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}                       	 	
 	for (int bin=0;bin<number_dm;bin++){a_w8pi_eff_or_6_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                              	 	
                                                                                                                     	                       
 	for (int bin=0;bin<number_mm_axial;bin++){diff_a_w8pi_eff_or_1_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}                       	
 	for (int bin=0;bin<number_dm;bin++){diff_a_w8pi_eff_or_1_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}                              	
                                                                                                                     	          
 	for (int bin=0;bin<number_mm_axial;bin++){diff_a_w8pi_eff_or_5_off_h->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_a_w8pi_eff_or_5_off_h->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

 	for (int bin=0;bin<number_mm_axial;bin++){diff_a_w8pi_eff_or_6_off_h ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_a_w8pi_eff_or_6_off_h ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}
 	
	for (int bin=0;bin<number_mm_axial;bin++){a_w8pi_eff_xe_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){a_w8pi_eff_xe_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

 	for (int bin=0;bin<number_mm_axial;bin++){a_w8pi_eff_or_1_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){a_w8pi_eff_or_1_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}
  	
  	for (int bin=0;bin<number_mm_axial;bin++){diff_a_w8pi_eff_or_1_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_a_w8pi_eff_or_1_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_axial;bin++){a_w8pi_eff_xe_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){a_w8pi_eff_xe_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_axial;bin++){a_w8pi_eff_or_1_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){a_w8pi_eff_or_1_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_axial;bin++){a_w8pi_eff_or_5_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){a_w8pi_eff_or_5_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_axial;bin++){a_w8pi_eff_or_6_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){a_w8pi_eff_or_6_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_axial;bin++){diff_a_w8pi_eff_or_1_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_a_w8pi_eff_or_1_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_axial;bin++){diff_a_w8pi_eff_or_5_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_a_w8pi_eff_or_5_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

  	for (int bin=0;bin<number_mm_axial;bin++){diff_a_w8pi_eff_or_6_off_h_2j ->GetXaxis()->SetBinLabel(bin+1,binnames_mm_axial[bin]);}
 	for (int bin=0;bin<number_dm;bin++){diff_a_w8pi_eff_or_6_off_h_2j ->GetYaxis()->SetBinLabel(bin+1,binnames_dm[bin]);}

 	
	
	// Draw the histograms
	TCanvas *c1_a_w8pi = new TCanvas("c1_a_w8pi", "c1",150,10,990,600);
	c1_a_w8pi->Clear();
	a_w8pi_eff_xe_h 				->Draw("coltextz");
	
	TCanvas *c2_a_w8pi = new TCanvas("c2_c_w8pi", "c2_a_w8pi",150,10,990,600);
	c2_a_w8pi->Clear();
	a_w8pi_eff_or_1_h 			->Draw("coltextz"); 
	
	TCanvas *c3_a_w8pi = new TCanvas("c3_a_w8pi", "c3",150,10,990,600);
	c3_a_w8pi->Clear();  
	diff_a_w8pi_eff_or_1_h 		->Draw("coltextz");

	TCanvas *c4_a_w8pi = new TCanvas("c4_a_w8pi", "c4",150,10,990,600);
	c4_a_w8pi->Clear();                                        
	a_w8pi_eff_xe_off_h 			->Draw("coltextz");
	
	TCanvas *c5_a_w8pi = new TCanvas("c5_a_w8pi", "c5",150,10,990,600);
	c5_a_w8pi->Clear();
	a_w8pi_eff_or_1_off_h 		->Draw("coltextz");
	
	TCanvas *c6_a_w8pi = new TCanvas("c6_a_w8pi", "c6",150,10,990,600);
	c6_a_w8pi->Clear();
	a_w8pi_eff_or_5_off_h			->Draw("coltextz");
	
	TCanvas *c7_a_w8pi = new TCanvas("c7_a_w8pi", "c7",150,10,990,600);
	c7_a_w8pi->Clear();
	a_w8pi_eff_or_6_off_h 		->Draw("coltextz");
	
	TCanvas *c8_a_w8pi = new TCanvas("c8_a_w8pi", "c8",150,10,990,600);
	c8_a_w8pi->Clear();
	diff_a_w8pi_eff_or_1_off_h	->Draw("coltextz");
	
	TCanvas *c9_a_w8pi = new TCanvas("c9_a_w8pi", "c9",150,10,990,600);
	c9_a_w8pi->Clear();
	diff_a_w8pi_eff_or_5_off_h	->Draw("coltextz");
	
	TCanvas *c10_a_w8pi = new TCanvas("c10_a_w8pi", "c10",150,10,990,600);
	c10_a_w8pi->Clear();
	diff_a_w8pi_eff_or_6_off_h	->Draw("coltextz");
	
	TCanvas *c11_a_w8pi = new TCanvas("c11_a_w8pi", "c11",150,10,990,600);
	c11_a_w8pi->Clear();                                    
	a_w8pi_eff_xe_h_2j 			->Draw("coltextz");
	
	TCanvas *c12_a_w8pi = new TCanvas("c12_a_w8pi", "c12",150,10,990,600);
	c12_a_w8pi->Clear();
	a_w8pi_eff_or_1_h_2j 			->Draw("coltextz");
	
	TCanvas *c13_a_w8pi = new TCanvas("c13_a_w8pi", "c13",150,10,990,600);
	c13_a_w8pi->Clear();
	diff_a_w8pi_eff_or_1_h_2j 	->Draw("coltextz");
	
	TCanvas *c14_a_w8pi = new TCanvas("c14_a_w8pi", "c14",150,10,990,600);
	c14_a_w8pi->Clear();                                    
	a_w8pi_eff_xe_off_h_2j 		->Draw("coltextz");
	
	TCanvas *c15_a_w8pi = new TCanvas("c15_a_w8pi", "c15",150,10,990,600);
	c15_a_w8pi->Clear();
	a_w8pi_eff_or_1_off_h_2j 		->Draw("coltextz");
	
	TCanvas *c16_a_w8pi = new TCanvas("c16_a_w8pi", "c16",150,10,990,600);
	c16_a_w8pi->Clear();
	a_w8pi_eff_or_5_off_h_2j 		->Draw("coltextz");
	
	TCanvas *c17_a_w8pi = new TCanvas("c17_a_w8pi", "c17",150,10,990,600);
	c17_a_w8pi->Clear();
	a_w8pi_eff_or_6_off_h_2j 		->Draw("coltextz");
	
	TCanvas *c18_a_w8pi = new TCanvas("c18_a_w8pi", "c18",150,10,990,600);
	c18_a_w8pi->Clear();                                   
	diff_a_w8pi_eff_or_1_off_h_2j	->Draw("coltextz");
	
	TCanvas *c19_a_w8pi = new TCanvas("c19_a_w8pi", "c19",150,10,990,600);
	c19_a_w8pi->Clear();
	diff_a_w8pi_eff_or_5_off_h_2j	->Draw("coltextz");
	
	TCanvas *c20_a_w8pi = new TCanvas("c20_a_w8pi", "c20",150,10,990,600);
	c20_a_w8pi->Clear();
	diff_a_w8pi_eff_or_6_off_h_2j	->Draw("coltextz");
	
	
	
	
	// The END !


	c1_a_w3->SaveAs(output_dir+"/c1_a_w3.pdf");
	c2_a_w3->SaveAs(output_dir+"/c2_a_w3.pdf");
	c3_a_w3->SaveAs(output_dir+"/c3_a_w3.pdf");
	c4_a_w3->SaveAs(output_dir+"/c4_a_w3.pdf");
	c5_a_w3->SaveAs(output_dir+"/c5_a_w3.pdf");
	c6_a_w3->SaveAs(output_dir+"/c6_a_w3.pdf");
	c7_a_w3->SaveAs(output_dir+"/c7_a_w3.pdf");
	c8_a_w3->SaveAs(output_dir+"/c8_a_w3.pdf");
	c9_a_w3->SaveAs(output_dir+"/c9_a_w3.pdf");
	c10_a_w3->SaveAs(output_dir+"/c10_a_w3.pdf");
	c11_a_w3->SaveAs(output_dir+"/c11_a_w3.pdf");
	c12_a_w3->SaveAs(output_dir+"/c12_a_w3.pdf");
	c13_a_w3->SaveAs(output_dir+"/c13_a_w3.pdf");
	c14_a_w3->SaveAs(output_dir+"/c14_a_w3.pdf");
	c15_a_w3->SaveAs(output_dir+"/c15_a_w3.pdf");
	c16_a_w3->SaveAs(output_dir+"/c16_a_w3.pdf");
	c17_a_w3->SaveAs(output_dir+"/c17_a_w3.pdf");
	c18_a_w3->SaveAs(output_dir+"/c18_a_w3.pdf");
	c19_a_w3->SaveAs(output_dir+"/c19_a_w3.pdf");
	c20_a_w3->SaveAs(output_dir+"/c20_a_w3.pdf");
	
	
	c1_a_w8pi->SaveAs(output_dir+"/c1_a_w8pi.pdf");
	c2_a_w8pi->SaveAs(output_dir+"/c2_a_w8pi.pdf");
	c3_a_w8pi->SaveAs(output_dir+"/c3_a_w8pi.pdf");
	c4_a_w8pi->SaveAs(output_dir+"/c4_a_w8pi.pdf");
	c5_a_w8pi->SaveAs(output_dir+"/c5_a_w8pi.pdf");
	c6_a_w8pi->SaveAs(output_dir+"/c6_a_w8pi.pdf");
	c7_a_w8pi->SaveAs(output_dir+"/c7_a_w8pi.pdf");
	c8_a_w8pi->SaveAs(output_dir+"/c8_a_w8pi.pdf");
	c9_a_w8pi->SaveAs(output_dir+"/c9_a_w8pi.pdf");
	c10_a_w8pi->SaveAs(output_dir+"/c10_a_w8pi.pdf");
	c11_a_w8pi->SaveAs(output_dir+"/c11_a_w8pi.pdf");
	c12_a_w8pi->SaveAs(output_dir+"/c12_a_w8pi.pdf");
	c13_a_w8pi->SaveAs(output_dir+"/c13_a_w8pi.pdf");
	c14_a_w8pi->SaveAs(output_dir+"/c14_a_w8pi.pdf");
	c15_a_w8pi->SaveAs(output_dir+"/c15_a_w8pi.pdf");
	c16_a_w8pi->SaveAs(output_dir+"/c16_a_w8pi.pdf");
	c17_a_w8pi->SaveAs(output_dir+"/c17_a_w8pi.pdf");
	c18_a_w8pi->SaveAs(output_dir+"/c18_a_w8pi.pdf");
	c19_a_w8pi->SaveAs(output_dir+"/c19_a_w8pi.pdf");
	c20_a_w8pi->SaveAs(output_dir+"/c20_a_w8pi.pdf");




	c1_a_w3->Write();                 c1_a_w3->Close();
	c2_a_w3->Write();                 c2_a_w3->Close();
	c3_a_w3->Write();                 c3_a_w3->Close();
	c4_a_w3->Write();                 c4_a_w3->Close();
	c5_a_w3->Write();                 c5_a_w3->Close();
	c6_a_w3->Write();                 c6_a_w3->Close();
	c7_a_w3->Write();                 c7_a_w3->Close();
	c8_a_w3->Write();                 c8_a_w3->Close();
	c9_a_w3->Write();                 c9_a_w3->Close();
	c10_a_w3->Write();                c10_a_w3->Close();
	c11_a_w3->Write();                c11_a_w3->Close();
	c12_a_w3->Write();                c12_a_w3->Close();
	c13_a_w3->Write();                c13_a_w3->Close();
	c14_a_w3->Write();                c14_a_w3->Close();
	c15_a_w3->Write();                c15_a_w3->Close();
	c16_a_w3->Write();                c16_a_w3->Close();
	c17_a_w3->Write();                c17_a_w3->Close();
	c18_a_w3->Write();                c18_a_w3->Close();
	c19_a_w3->Write();                c19_a_w3->Close();
	c20_a_w3->Write();                c20_a_w3->Close();
	                                  
	c1_a_w8pi->Write();               c1_a_w8pi->Close();
	c2_a_w8pi->Write();               c2_a_w8pi->Close();
	c3_a_w8pi->Write();               c3_a_w8pi->Close();
	c4_a_w8pi->Write();               c4_a_w8pi->Close();
	c5_a_w8pi->Write();               c5_a_w8pi->Close();
	c6_a_w8pi->Write();               c6_a_w8pi->Close();
	c7_a_w8pi->Write();               c7_a_w8pi->Close();
	c8_a_w8pi->Write();               c8_a_w8pi->Close();
	c9_a_w8pi->Write();               c9_a_w8pi->Close();
	c10_a_w8pi->Write();              c10_a_w8pi->Close();
	c11_a_w8pi->Write();              c11_a_w8pi->Close();
	c12_a_w8pi->Write();              c12_a_w8pi->Close();
	c13_a_w8pi->Write();              c13_a_w8pi->Close();
	c14_a_w8pi->Write();              c14_a_w8pi->Close();
	c15_a_w8pi->Write();              c15_a_w8pi->Close();
	c16_a_w8pi->Write();              c16_a_w8pi->Close();
	c17_a_w8pi->Write();              c17_a_w8pi->Close();
	c18_a_w8pi->Write();              c18_a_w8pi->Close();
	c19_a_w8pi->Write();              c19_a_w8pi->Close();
	c20_a_w8pi->Write();              c20_a_w8pi->Close();

	
}
