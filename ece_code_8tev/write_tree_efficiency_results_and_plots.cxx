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


void write_tree_efficiency_results_and_plots(){
	
	TString choose_txt_directory = "/afs/cern.ch/user/e/eakilli/razor_8tev/ece_code_8tev/Output_text";
	
	
	// Create a ROOT file
  	TFile *eff_results_plots = new TFile(choose_txt_directory+"/eff_results_plots.root","RECREATE","Efficiency Results",9);


  	// Create ROOT trees for vector 
  	TTree *eff_results_plots_vector_w3 = new TTree("eff_results_plots_vector_w3", "Efficiency Results Vector W3");
  	TTree *eff_results_plots_vector_w8pi = new TTree("eff_results_plots_vector_w8pi", "Efficiency Results Vector W8pi");


  	// Create ROOT trees for axial 
  	TTree *eff_results_plots_axial_w3 = new TTree("eff_results_plots_axial_w3", "Efficiency Results Vector W3");
	TTree *eff_results_plots_axial_w8pi = new TTree("eff_results_plots_axial_w8pi", "Efficiency Results Vector W8pi");
	
	
	
		
	// Vector W3
	
	Float_t dm_vector_w3,mm_vector_w3,efficiencies_eff_xe_vector_w3,efficiencies_eff_or_1_vector_w3,efficiencies_eff_or_2_vector_w3,efficiencies_eff_or_3_vector_w3,efficiencies_eff_or_4_vector_w3;
	Float_t efficiencies_eff_xe_off_vector_w3,efficiencies_eff_or_1_off_vector_w3,efficiencies_eff_or_2_off_vector_w3,efficiencies_eff_or_3_off_vector_w3;
	Float_t efficiencies_eff_or_4_off_vector_w3,efficiencies_eff_or_5_off_vector_w3,efficiencies_eff_or_6_off_vector_w3;
	Float_t efficiencies_eff_xe_2j_vector_w3,efficiencies_eff_or_1_2j_vector_w3,efficiencies_eff_or_2_2j_vector_w3,efficiencies_eff_or_3_2j_vector_w3,efficiencies_eff_or_4_2j_vector_w3;
	Float_t efficiencies_eff_xe_off_2j_vector_w3,efficiencies_eff_or_1_off_2j_vector_w3,efficiencies_eff_or_2_off_2j_vector_w3,efficiencies_eff_or_3_off_2j_vector_w3;
	Float_t efficiencies_eff_or_4_off_2j_vector_w3,efficiencies_eff_or_5_off_2j_vector_w3,efficiencies_eff_or_6_off_2j_vector_w3;
	
	
	
	eff_results_plots_vector_w3->Branch("dm_vector_w3",&dm_vector_w3,"dm_vector_w3/F");
	eff_results_plots_vector_w3->Branch("mm_vector_w3",&mm_vector_w3,"mm_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_xe_vector_w3",&efficiencies_eff_xe_vector_w3,"efficiencies_eff_xe_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_1_vector_w3",&efficiencies_eff_or_1_vector_w3,"efficiencies_eff_or_1_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_2_vector_w3",&efficiencies_eff_or_2_vector_w3,"efficiencies_eff_or_2_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_3_vector_w3",&efficiencies_eff_or_3_vector_w3,"efficiencies_eff_or_3_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_4_vector_w3",&efficiencies_eff_or_4_vector_w3,"efficiencies_eff_or_4_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_xe_off_vector_w3",&efficiencies_eff_xe_off_vector_w3,"efficiencies_eff_xe_off_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_1_off_vector_w3",&efficiencies_eff_or_1_off_vector_w3,"efficiencies_eff_or_1_off_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_2_off_vector_w3",&efficiencies_eff_or_2_off_vector_w3,"efficiencies_eff_or_2_off_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_3_off_vector_w3",&efficiencies_eff_or_3_off_vector_w3,"efficiencies_eff_or_3_off_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_4_off_vector_w3",&efficiencies_eff_or_4_off_vector_w3,"efficiencies_eff_or_4_off_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_5_off_vector_w3",&efficiencies_eff_or_5_off_vector_w3,"efficiencies_eff_or_5_off_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_6_off_vector_w3",&efficiencies_eff_or_6_off_vector_w3,"efficiencies_eff_or_6_off_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_xe_2j_vector_w3",&efficiencies_eff_xe_2j_vector_w3,"efficiencies_eff_xe_2j_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_1_2j_vector_w3",&efficiencies_eff_or_1_2j_vector_w3,"efficiencies_eff_or_1_2j_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_2_2j_vector_w3",&efficiencies_eff_or_2_2j_vector_w3,"efficiencies_eff_or_2_2j_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_3_2j_vector_w3",&efficiencies_eff_or_3_2j_vector_w3,"efficiencies_eff_or_3_2j_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_4_2j_vector_w3",&efficiencies_eff_or_4_2j_vector_w3,"efficiencies_eff_or_4_2j_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_xe_off_2j_vector_w3",&efficiencies_eff_xe_off_2j_vector_w3,"efficiencies_eff_xe_off_2j_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_1_off_2j_vector_w3",&efficiencies_eff_or_1_off_2j_vector_w3,"efficiencies_eff_or_1_off_2j_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_2_off_2j_vector_w3",&efficiencies_eff_or_2_off_2j_vector_w3,"efficiencies_eff_or_2_off_2j_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_3_off_2j_vector_w3",&efficiencies_eff_or_3_off_2j_vector_w3,"efficiencies_eff_or_3_off_2j_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_4_off_2j_vector_w3",&efficiencies_eff_or_4_off_2j_vector_w3,"efficiencies_eff_or_4_off_2j_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_5_off_2j_vector_w3",&efficiencies_eff_or_5_off_2j_vector_w3,"efficiencies_eff_or_5_off_2j_vector_w3/F");
	eff_results_plots_vector_w3->Branch("efficiencies_eff_or_6_off_2j_vector_w3",&efficiencies_eff_or_6_off_2j_vector_w3,"efficiencies_eff_or_6_off_2j_vector_w3/F");
	
	
	ifstream    				         dm_file_vector_w3(choose_txt_directory+"/dm_vector_w3_file.txt");
	ifstream    				         mm_file_vector_w3(choose_txt_directory+"/mm_vector_w3_file.txt");
	ifstream    	    file_efficiencies_eff_xe_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_xe.txt");            
	ifstream    	  file_efficiencies_eff_or_1_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_1.txt");
	ifstream    	  file_efficiencies_eff_or_2_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_2.txt");
	ifstream    	  file_efficiencies_eff_or_3_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_3.txt");
	ifstream    	  file_efficiencies_eff_or_4_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_4.txt");
	ifstream    	file_efficiencies_eff_xe_off_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_xe_off.txt");
	ifstream      file_efficiencies_eff_or_1_off_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_1_off.txt");
	ifstream      file_efficiencies_eff_or_2_off_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_2_off.txt");
	ifstream      file_efficiencies_eff_or_3_off_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_3_off.txt");
	ifstream      file_efficiencies_eff_or_4_off_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_4_off.txt");
	ifstream      file_efficiencies_eff_or_5_off_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_5_off.txt");
	ifstream      file_efficiencies_eff_or_6_off_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_6_off.txt");
    
	ifstream   	     file_efficiencies_eff_xe_2j_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_xe_2j.txt");
	ifstream   	   file_efficiencies_eff_or_1_2j_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_1_2j.txt");
	ifstream   	   file_efficiencies_eff_or_2_2j_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_2_2j.txt");
	ifstream   	   file_efficiencies_eff_or_3_2j_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_3_2j.txt");
	ifstream   	   file_efficiencies_eff_or_4_2j_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_4_2j.txt");
	ifstream   	 file_efficiencies_eff_xe_off_2j_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_xe_off_2j.txt");
	ifstream   file_efficiencies_eff_or_1_off_2j_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_1_off_2j.txt");
	ifstream   file_efficiencies_eff_or_2_off_2j_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_2_off_2j.txt");
	ifstream   file_efficiencies_eff_or_3_off_2j_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_3_off_2j.txt");
	ifstream   file_efficiencies_eff_or_4_off_2j_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_4_off_2j.txt");
	ifstream   file_efficiencies_eff_or_5_off_2j_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_5_off_2j.txt");
	ifstream   file_efficiencies_eff_or_6_off_2j_vector_w3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_6_off_2j.txt");
	

	Int_t n_vector_w3 = 0;
	while (1) {
    	
		dm_file_vector_w3 >> dm_vector_w3;
		mm_file_vector_w3 >> mm_vector_w3;
		file_efficiencies_eff_xe_vector_w3           >>         efficiencies_eff_xe_vector_w3;	      	
		file_efficiencies_eff_or_1_vector_w3       >>         efficiencies_eff_or_1_vector_w3;   		 
		file_efficiencies_eff_or_2_vector_w3       >>         efficiencies_eff_or_2_vector_w3;   		 
		file_efficiencies_eff_or_3_vector_w3       >>         efficiencies_eff_or_3_vector_w3;   		 
		file_efficiencies_eff_or_4_vector_w3       >>         efficiencies_eff_or_4_vector_w3;   		 
		file_efficiencies_eff_xe_off_vector_w3       >>         efficiencies_eff_xe_off_vector_w3;  	
		file_efficiencies_eff_or_1_off_vector_w3        >>         efficiencies_eff_or_1_off_vector_w3;  	
		file_efficiencies_eff_or_2_off_vector_w3        >>         efficiencies_eff_or_2_off_vector_w3;  	
		file_efficiencies_eff_or_3_off_vector_w3        >>         efficiencies_eff_or_3_off_vector_w3;  	
		file_efficiencies_eff_or_4_off_vector_w3        >>         efficiencies_eff_or_4_off_vector_w3;    
		file_efficiencies_eff_or_5_off_vector_w3        >>         efficiencies_eff_or_5_off_vector_w3;    
		file_efficiencies_eff_or_6_off_vector_w3        >>         efficiencies_eff_or_6_off_vector_w3;    
		file_efficiencies_eff_xe_2j_vector_w3    >>         efficiencies_eff_xe_2j_vector_w3;        
		file_efficiencies_eff_or_1_2j_vector_w3    >>         efficiencies_eff_or_1_2j_vector_w3;      
		file_efficiencies_eff_or_2_2j_vector_w3    >>         efficiencies_eff_or_2_2j_vector_w3;      
		file_efficiencies_eff_or_3_2j_vector_w3    >>         efficiencies_eff_or_3_2j_vector_w3;      
		file_efficiencies_eff_or_4_2j_vector_w3    >>         efficiencies_eff_or_4_2j_vector_w3;      
		file_efficiencies_eff_xe_off_2j_vector_w3    >>         efficiencies_eff_xe_off_2j_vector_w3;    
		file_efficiencies_eff_or_1_off_2j_vector_w3   >>         efficiencies_eff_or_1_off_2j_vector_w3;  
		file_efficiencies_eff_or_2_off_2j_vector_w3    >>         efficiencies_eff_or_2_off_2j_vector_w3;  
		file_efficiencies_eff_or_3_off_2j_vector_w3    >>         efficiencies_eff_or_3_off_2j_vector_w3;  
		file_efficiencies_eff_or_4_off_2j_vector_w3    >>         efficiencies_eff_or_4_off_2j_vector_w3;  
		file_efficiencies_eff_or_5_off_2j_vector_w3    >>         efficiencies_eff_or_5_off_2j_vector_w3;  
		file_efficiencies_eff_or_6_off_2j_vector_w3    >>         efficiencies_eff_or_6_off_2j_vector_w3;  
		
		if (!dm_file_vector_w3.good()) break;
		eff_results_plots_vector_w3->Fill();
		n_vector_w3++;

	}
	cout << n_vector_w3 << endl;
	
							 dm_file_vector_w3.close();
	   				         mm_file_vector_w3.close();
	   	    file_efficiencies_eff_xe_vector_w3.close();
	   	  file_efficiencies_eff_or_1_vector_w3.close();
	   	  file_efficiencies_eff_or_2_vector_w3.close();
	   	  file_efficiencies_eff_or_3_vector_w3.close();
	   	  file_efficiencies_eff_or_4_vector_w3.close();
	   	file_efficiencies_eff_xe_off_vector_w3.close();
	  file_efficiencies_eff_or_1_off_vector_w3.close();
	  file_efficiencies_eff_or_2_off_vector_w3.close();
	  file_efficiencies_eff_or_3_off_vector_w3.close();
	  file_efficiencies_eff_or_4_off_vector_w3.close();
	  file_efficiencies_eff_or_5_off_vector_w3.close();
	  file_efficiencies_eff_or_6_off_vector_w3.close();
	   	 file_efficiencies_eff_xe_2j_vector_w3.close();
       file_efficiencies_eff_or_1_2j_vector_w3.close();
       file_efficiencies_eff_or_2_2j_vector_w3.close();
       file_efficiencies_eff_or_3_2j_vector_w3.close();
       file_efficiencies_eff_or_4_2j_vector_w3.close();
     file_efficiencies_eff_xe_off_2j_vector_w3.close();
   file_efficiencies_eff_or_1_off_2j_vector_w3.close();
   file_efficiencies_eff_or_2_off_2j_vector_w3.close();
   file_efficiencies_eff_or_3_off_2j_vector_w3.close();
   file_efficiencies_eff_or_4_off_2j_vector_w3.close();
   file_efficiencies_eff_or_5_off_2j_vector_w3.close();
   file_efficiencies_eff_or_6_off_2j_vector_w3.close(); 



	// Vector W8pi
	
	ifstream  				            dm_file_vector_w8pi(choose_txt_directory+"/dm_vector_w8pi_file.txt");                          	
	ifstream  							   mm_file_vector_w8pi(choose_txt_directory+"/mm_vector_w8pi_file.txt");                       	
	ifstream  	    file_efficiencies_eff_xe_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_xe.txt");            	
	ifstream  	  file_efficiencies_eff_or_1_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_1.txt");          	
	ifstream  	  file_efficiencies_eff_or_2_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_2.txt");          	
	ifstream  	  file_efficiencies_eff_or_3_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_3.txt");          	
	ifstream  	  file_efficiencies_eff_or_4_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_4.txt");          	
	ifstream  	file_efficiencies_eff_xe_off_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_xe_off.txt");        	
	ifstream  file_efficiencies_eff_or_1_off_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_1_off.txt");      	
	ifstream  file_efficiencies_eff_or_2_off_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_2_off.txt");      	
	ifstream  file_efficiencies_eff_or_3_off_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_3_off.txt");      	
	ifstream  file_efficiencies_eff_or_4_off_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_4_off.txt");      	
	ifstream  file_efficiencies_eff_or_5_off_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_5_off.txt");      	
	ifstream  file_efficiencies_eff_or_6_off_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_6_off.txt");      	
	                                                                                                                      	                                                                                                                      	
	ifstream  	    file_efficiencies_eff_xe_2j_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_xe_2j.txt");      	
	ifstream  	  file_efficiencies_eff_or_1_2j_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_1_2j.txt");    	
	ifstream  	  file_efficiencies_eff_or_2_2j_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_2_2j.txt");    	
	ifstream  	  file_efficiencies_eff_or_3_2j_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_3_2j.txt");    	
	ifstream  	  file_efficiencies_eff_or_4_2j_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_4_2j.txt");    	
	ifstream  	file_efficiencies_eff_xe_off_2j_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_xe_off_2j.txt");  	
	ifstream  file_efficiencies_eff_or_1_off_2j_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_1_off_2j.txt");	
	ifstream  file_efficiencies_eff_or_2_off_2j_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_2_off_2j.txt");	
	ifstream  file_efficiencies_eff_or_3_off_2j_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_3_off_2j.txt");	
	ifstream  file_efficiencies_eff_or_4_off_2j_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_4_off_2j.txt");	
	ifstream  file_efficiencies_eff_or_5_off_2j_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_5_off_2j.txt");	
	ifstream  file_efficiencies_eff_or_6_off_2j_vector_w8pi(choose_txt_directory+"/vector_w8pi_file_efficiencies_eff_or_6_off_2j.txt");	
                                                                                                                           	
                                                                                                                           	
    Float_t dm_vector_w8pi,mm_vector_w8pi,efficiencies_eff_xe_vector_w8pi,efficiencies_eff_or_1_vector_w8pi,efficiencies_eff_or_2_vector_w8pi,efficiencies_eff_or_3_vector_w8pi,efficiencies_eff_or_4_vector_w8pi;
	Float_t efficiencies_eff_xe_off_vector_w8pi,efficiencies_eff_or_1_off_vector_w8pi,efficiencies_eff_or_2_off_vector_w8pi,efficiencies_eff_or_3_off_vector_w8pi;
	Float_t efficiencies_eff_or_4_off_vector_w8pi,efficiencies_eff_or_5_off_vector_w8pi,efficiencies_eff_or_6_off_vector_w8pi;
	Float_t efficiencies_eff_xe_2j_vector_w8pi,efficiencies_eff_or_1_2j_vector_w8pi,efficiencies_eff_or_2_2j_vector_w8pi,efficiencies_eff_or_3_2j_vector_w8pi,efficiencies_eff_or_4_2j_vector_w8pi;
	Float_t efficiencies_eff_xe_off_2j_vector_w8pi,efficiencies_eff_or_1_off_2j_vector_w8pi,efficiencies_eff_or_2_off_2j_vector_w8pi,efficiencies_eff_or_3_off_2j_vector_w8pi;
	Float_t efficiencies_eff_or_4_off_2j_vector_w8pi,efficiencies_eff_or_5_off_2j_vector_w8pi,efficiencies_eff_or_6_off_2j_vector_w8pi;
	                                                                                                              	
	
	eff_results_plots_vector_w8pi->Branch("dm_vector_w8pi",&dm_vector_w8pi,"dm_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("mm_vector_w8pi",&mm_vector_w8pi,"mm_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_xe_vector_w8pi",&efficiencies_eff_xe_vector_w8pi,"efficiencies_eff_xe_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_1_vector_w8pi",&efficiencies_eff_or_1_vector_w8pi,"efficiencies_eff_or_1_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_2_vector_w8pi",&efficiencies_eff_or_2_vector_w8pi,"efficiencies_eff_or_2_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_3_vector_w8pi",&efficiencies_eff_or_3_vector_w8pi,"efficiencies_eff_or_3_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_4_vector_w8pi",&efficiencies_eff_or_4_vector_w8pi,"efficiencies_eff_or_4_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_xe_off_vector_w8pi",&efficiencies_eff_xe_off_vector_w8pi,"efficiencies_eff_xe_off_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_1_off_vector_w8pi",&efficiencies_eff_or_1_off_vector_w8pi,"efficiencies_eff_or_1_off_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_2_off_vector_w8pi",&efficiencies_eff_or_2_off_vector_w8pi,"efficiencies_eff_or_2_off_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_3_off_vector_w8pi",&efficiencies_eff_or_3_off_vector_w8pi,"efficiencies_eff_or_3_off_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_4_off_vector_w8pi",&efficiencies_eff_or_4_off_vector_w8pi,"efficiencies_eff_or_4_off_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_5_off_vector_w8pi",&efficiencies_eff_or_5_off_vector_w8pi,"efficiencies_eff_or_5_off_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_6_off_vector_w8pi",&efficiencies_eff_or_6_off_vector_w8pi,"efficiencies_eff_or_6_off_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_xe_2j_vector_w8pi",&efficiencies_eff_xe_2j_vector_w8pi,"efficiencies_eff_xe_2j_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_1_2j_vector_w8pi",&efficiencies_eff_or_1_2j_vector_w8pi,"efficiencies_eff_or_1_2j_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_2_2j_vector_w8pi",&efficiencies_eff_or_2_2j_vector_w8pi,"efficiencies_eff_or_2_2j_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_3_2j_vector_w8pi",&efficiencies_eff_or_3_2j_vector_w8pi,"efficiencies_eff_or_3_2j_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_4_2j_vector_w8pi",&efficiencies_eff_or_4_2j_vector_w8pi,"efficiencies_eff_or_4_2j_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_xe_off_2j_vector_w8pi",&efficiencies_eff_xe_off_2j_vector_w8pi,"efficiencies_eff_xe_off_2j_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_1_off_2j_vector_w8pi",&efficiencies_eff_or_1_off_2j_vector_w8pi,"efficiencies_eff_or_1_off_2j_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_2_off_2j_vector_w8pi",&efficiencies_eff_or_2_off_2j_vector_w8pi,"efficiencies_eff_or_2_off_2j_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_3_off_2j_vector_w8pi",&efficiencies_eff_or_3_off_2j_vector_w8pi,"efficiencies_eff_or_3_off_2j_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_4_off_2j_vector_w8pi",&efficiencies_eff_or_4_off_2j_vector_w8pi,"efficiencies_eff_or_4_off_2j_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_5_off_2j_vector_w8pi",&efficiencies_eff_or_5_off_2j_vector_w8pi,"efficiencies_eff_or_5_off_2j_vector_w8pi/F");
	eff_results_plots_vector_w8pi->Branch("efficiencies_eff_or_6_off_2j_vector_w8pi",&efficiencies_eff_or_6_off_2j_vector_w8pi,"efficiencies_eff_or_6_off_2j_vector_w8pi/F");
	
	
	
	Int_t n_vector_w8pi = 0;
	while (1) {
    	
		dm_file_vector_w8pi >> dm_vector_w8pi;
		mm_file_vector_w8pi >> mm_vector_w8pi;
		file_efficiencies_eff_xe_vector_w8pi           >>         efficiencies_eff_xe_vector_w8pi;	      	
		file_efficiencies_eff_or_1_vector_w8pi       >>         efficiencies_eff_or_1_vector_w8pi;   		 
		file_efficiencies_eff_or_2_vector_w8pi       >>         efficiencies_eff_or_2_vector_w8pi;   		 
		file_efficiencies_eff_or_3_vector_w8pi       >>         efficiencies_eff_or_3_vector_w8pi;   		 
		file_efficiencies_eff_or_4_vector_w8pi       >>         efficiencies_eff_or_4_vector_w8pi;   		 
		file_efficiencies_eff_xe_off_vector_w8pi       >>         efficiencies_eff_xe_off_vector_w8pi;  	
		file_efficiencies_eff_or_1_off_vector_w8pi        >>         efficiencies_eff_or_1_off_vector_w8pi;  	
		file_efficiencies_eff_or_2_off_vector_w8pi        >>         efficiencies_eff_or_2_off_vector_w8pi;  	
		file_efficiencies_eff_or_3_off_vector_w8pi        >>         efficiencies_eff_or_3_off_vector_w8pi;  	
		file_efficiencies_eff_or_4_off_vector_w8pi        >>         efficiencies_eff_or_4_off_vector_w8pi;    
		file_efficiencies_eff_or_5_off_vector_w8pi        >>         efficiencies_eff_or_5_off_vector_w8pi;    
		file_efficiencies_eff_or_6_off_vector_w8pi        >>         efficiencies_eff_or_6_off_vector_w8pi;    
		file_efficiencies_eff_xe_2j_vector_w8pi    >>         efficiencies_eff_xe_2j_vector_w8pi;        
		file_efficiencies_eff_or_1_2j_vector_w8pi    >>         efficiencies_eff_or_1_2j_vector_w8pi;      
		file_efficiencies_eff_or_2_2j_vector_w8pi    >>         efficiencies_eff_or_2_2j_vector_w8pi;      
		file_efficiencies_eff_or_3_2j_vector_w8pi    >>         efficiencies_eff_or_3_2j_vector_w8pi;      
		file_efficiencies_eff_or_4_2j_vector_w8pi    >>         efficiencies_eff_or_4_2j_vector_w8pi;      
		file_efficiencies_eff_xe_off_2j_vector_w8pi    >>         efficiencies_eff_xe_off_2j_vector_w8pi;    
		file_efficiencies_eff_or_1_off_2j_vector_w8pi   >>         efficiencies_eff_or_1_off_2j_vector_w8pi;  
		file_efficiencies_eff_or_2_off_2j_vector_w8pi    >>         efficiencies_eff_or_2_off_2j_vector_w8pi;  
		file_efficiencies_eff_or_3_off_2j_vector_w8pi    >>         efficiencies_eff_or_3_off_2j_vector_w8pi;  
		file_efficiencies_eff_or_4_off_2j_vector_w8pi    >>         efficiencies_eff_or_4_off_2j_vector_w8pi;  
		file_efficiencies_eff_or_5_off_2j_vector_w8pi    >>         efficiencies_eff_or_5_off_2j_vector_w8pi;  
		file_efficiencies_eff_or_6_off_2j_vector_w8pi    >>         efficiencies_eff_or_6_off_2j_vector_w8pi;  
		
		if (!dm_file_vector_w8pi.good()) break;
		eff_results_plots_vector_w8pi->Fill();
		n_vector_w8pi++;

	}
	cout << n_vector_w8pi << endl;
	
	 
	dm_file_vector_w8pi.close();
    mm_file_vector_w8pi.close();
	file_efficiencies_eff_xe_vector_w8pi.close();
	file_efficiencies_eff_or_1_vector_w8pi.close();
	file_efficiencies_eff_or_2_vector_w8pi.close();
	file_efficiencies_eff_or_3_vector_w8pi.close();
	file_efficiencies_eff_or_4_vector_w8pi.close();
	file_efficiencies_eff_xe_off_vector_w8pi.close();
	file_efficiencies_eff_or_1_off_vector_w8pi.close();
	file_efficiencies_eff_or_2_off_vector_w8pi.close();
	file_efficiencies_eff_or_3_off_vector_w8pi.close();
	file_efficiencies_eff_or_4_off_vector_w8pi.close();
	file_efficiencies_eff_or_5_off_vector_w8pi.close();
	file_efficiencies_eff_or_6_off_vector_w8pi.close();
	file_efficiencies_eff_xe_2j_vector_w8pi.close();
	file_efficiencies_eff_or_1_2j_vector_w8pi.close();
	file_efficiencies_eff_or_2_2j_vector_w8pi.close();
	file_efficiencies_eff_or_3_2j_vector_w8pi.close();
	file_efficiencies_eff_or_4_2j_vector_w8pi.close();
	file_efficiencies_eff_xe_off_2j_vector_w8pi.close();
	file_efficiencies_eff_or_1_off_2j_vector_w8pi.close();
	file_efficiencies_eff_or_2_off_2j_vector_w8pi.close();
	file_efficiencies_eff_or_3_off_2j_vector_w8pi.close();
	file_efficiencies_eff_or_4_off_2j_vector_w8pi.close();
	file_efficiencies_eff_or_5_off_2j_vector_w8pi.close();
	file_efficiencies_eff_or_6_off_2j_vector_w8pi.close(); 
	
	
		
	
	// Axial W3
	
	ifstream  				            dm_file_axial_w3(choose_txt_directory+"/dm_axial_w3_file.txt");
	ifstream  							   mm_file_axial_w3(choose_txt_directory+"/mm_axial_w3_file.txt");
	ifstream  	    file_efficiencies_eff_xe_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_xe.txt");
	ifstream  	  file_efficiencies_eff_or_1_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_1.txt");
	ifstream  	  file_efficiencies_eff_or_2_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_2.txt");
	ifstream  	  file_efficiencies_eff_or_3_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_3.txt");
	ifstream  	  file_efficiencies_eff_or_4_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_4.txt");
	ifstream  	file_efficiencies_eff_xe_off_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_xe_off.txt");
	ifstream  file_efficiencies_eff_or_1_off_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_1_off.txt");
	ifstream  file_efficiencies_eff_or_2_off_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_2_off.txt");
	ifstream  file_efficiencies_eff_or_3_off_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_3_off.txt");
	ifstream  file_efficiencies_eff_or_4_off_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_4_off.txt");
	ifstream  file_efficiencies_eff_or_5_off_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_5_off.txt");
	ifstream  file_efficiencies_eff_or_6_off_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_6_off.txt");

	ifstream  	    file_efficiencies_eff_xe_2j_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_xe_2j.txt");
	ifstream  	  file_efficiencies_eff_or_1_2j_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_1_2j.txt");
	ifstream  	  file_efficiencies_eff_or_2_2j_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_2_2j.txt");
	ifstream  	  file_efficiencies_eff_or_3_2j_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_3_2j.txt");
	ifstream  	  file_efficiencies_eff_or_4_2j_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_4_2j.txt");
	ifstream  	file_efficiencies_eff_xe_off_2j_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_xe_off_2j.txt");
	ifstream  file_efficiencies_eff_or_1_off_2j_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_1_off_2j.txt");
	ifstream  file_efficiencies_eff_or_2_off_2j_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_2_off_2j.txt");
	ifstream  file_efficiencies_eff_or_3_off_2j_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_3_off_2j.txt");
	ifstream  file_efficiencies_eff_or_4_off_2j_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_4_off_2j.txt");
	ifstream  file_efficiencies_eff_or_5_off_2j_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_5_off_2j.txt");
	ifstream  file_efficiencies_eff_or_6_off_2j_axial_w3(choose_txt_directory+"/axial_w3_file_efficiencies_eff_or_6_off_2j.txt");
	
	
	Float_t dm_axial_w3,mm_axial_w3,efficiencies_eff_xe_axial_w3,efficiencies_eff_or_1_axial_w3,efficiencies_eff_or_2_axial_w3,efficiencies_eff_or_3_axial_w3,efficiencies_eff_or_4_axial_w3;
	Float_t efficiencies_eff_xe_off_axial_w3,efficiencies_eff_or_1_off_axial_w3,efficiencies_eff_or_2_off_axial_w3,efficiencies_eff_or_3_off_axial_w3;
	Float_t efficiencies_eff_or_4_off_axial_w3,efficiencies_eff_or_5_off_axial_w3,efficiencies_eff_or_6_off_axial_w3;
	Float_t efficiencies_eff_xe_2j_axial_w3,efficiencies_eff_or_1_2j_axial_w3,efficiencies_eff_or_2_2j_axial_w3,efficiencies_eff_or_3_2j_axial_w3,efficiencies_eff_or_4_2j_axial_w3;
	Float_t efficiencies_eff_xe_off_2j_axial_w3,efficiencies_eff_or_1_off_2j_axial_w3,efficiencies_eff_or_2_off_2j_axial_w3,efficiencies_eff_or_3_off_2j_axial_w3;
	Float_t efficiencies_eff_or_4_off_2j_axial_w3,efficiencies_eff_or_5_off_2j_axial_w3,efficiencies_eff_or_6_off_2j_axial_w3;
	
	
	
	eff_results_plots_axial_w3->Branch("dm_axial_w3",&dm_axial_w3,"dm_axial_w3/F");
	eff_results_plots_axial_w3->Branch("mm_axial_w3",&mm_axial_w3,"mm_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_xe_axial_w3",&efficiencies_eff_xe_axial_w3,"efficiencies_eff_xe_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_1_axial_w3",&efficiencies_eff_or_1_axial_w3,"efficiencies_eff_or_1_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_2_axial_w3",&efficiencies_eff_or_2_axial_w3,"efficiencies_eff_or_2_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_3_axial_w3",&efficiencies_eff_or_3_axial_w3,"efficiencies_eff_or_3_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_4_axial_w3",&efficiencies_eff_or_4_axial_w3,"efficiencies_eff_or_4_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_xe_off_axial_w3",&efficiencies_eff_xe_off_axial_w3,"efficiencies_eff_xe_off_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_1_off_axial_w3",&efficiencies_eff_or_1_off_axial_w3,"efficiencies_eff_or_1_off_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_2_off_axial_w3",&efficiencies_eff_or_2_off_axial_w3,"efficiencies_eff_or_2_off_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_3_off_axial_w3",&efficiencies_eff_or_3_off_axial_w3,"efficiencies_eff_or_3_off_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_4_off_axial_w3",&efficiencies_eff_or_4_off_axial_w3,"efficiencies_eff_or_4_off_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_5_off_axial_w3",&efficiencies_eff_or_5_off_axial_w3,"efficiencies_eff_or_5_off_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_6_off_axial_w3",&efficiencies_eff_or_6_off_axial_w3,"efficiencies_eff_or_6_off_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_xe_2j_axial_w3",&efficiencies_eff_xe_2j_axial_w3,"efficiencies_eff_xe_2j_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_1_2j_axial_w3",&efficiencies_eff_or_1_2j_axial_w3,"efficiencies_eff_or_1_2j_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_2_2j_axial_w3",&efficiencies_eff_or_2_2j_axial_w3,"efficiencies_eff_or_2_2j_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_3_2j_axial_w3",&efficiencies_eff_or_3_2j_axial_w3,"efficiencies_eff_or_3_2j_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_4_2j_axial_w3",&efficiencies_eff_or_4_2j_axial_w3,"efficiencies_eff_or_4_2j_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_xe_off_2j_axial_w3",&efficiencies_eff_xe_off_2j_axial_w3,"efficiencies_eff_xe_off_2j_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_1_off_2j_axial_w3",&efficiencies_eff_or_1_off_2j_axial_w3,"efficiencies_eff_or_1_off_2j_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_2_off_2j_axial_w3",&efficiencies_eff_or_2_off_2j_axial_w3,"efficiencies_eff_or_2_off_2j_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_3_off_2j_axial_w3",&efficiencies_eff_or_3_off_2j_axial_w3,"efficiencies_eff_or_3_off_2j_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_4_off_2j_axial_w3",&efficiencies_eff_or_4_off_2j_axial_w3,"efficiencies_eff_or_4_off_2j_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_5_off_2j_axial_w3",&efficiencies_eff_or_5_off_2j_axial_w3,"efficiencies_eff_or_5_off_2j_axial_w3/F");
	eff_results_plots_axial_w3->Branch("efficiencies_eff_or_6_off_2j_axial_w3",&efficiencies_eff_or_6_off_2j_axial_w3,"efficiencies_eff_or_6_off_2j_axial_w3/F");
	
	
	
	
	Int_t n_axial_w3 = 0;
	while (1) {
    	
		dm_file_axial_w3 >> dm_axial_w3;
		mm_file_axial_w3 >> mm_axial_w3;
		file_efficiencies_eff_xe_axial_w3           >>         efficiencies_eff_xe_axial_w3;	      	
		file_efficiencies_eff_or_1_axial_w3       >>         efficiencies_eff_or_1_axial_w3;   		 
		file_efficiencies_eff_or_2_axial_w3       >>         efficiencies_eff_or_2_axial_w3;   		 
		file_efficiencies_eff_or_3_axial_w3       >>         efficiencies_eff_or_3_axial_w3;   		 
		file_efficiencies_eff_or_4_axial_w3       >>         efficiencies_eff_or_4_axial_w3;   		 
		file_efficiencies_eff_xe_off_axial_w3       >>         efficiencies_eff_xe_off_axial_w3;  	
		file_efficiencies_eff_or_1_off_axial_w3        >>         efficiencies_eff_or_1_off_axial_w3;  	
		file_efficiencies_eff_or_2_off_axial_w3        >>         efficiencies_eff_or_2_off_axial_w3;  	
		file_efficiencies_eff_or_3_off_axial_w3        >>         efficiencies_eff_or_3_off_axial_w3;  	
		file_efficiencies_eff_or_4_off_axial_w3        >>         efficiencies_eff_or_4_off_axial_w3;    
		file_efficiencies_eff_or_5_off_axial_w3        >>         efficiencies_eff_or_5_off_axial_w3;    
		file_efficiencies_eff_or_6_off_axial_w3        >>         efficiencies_eff_or_6_off_axial_w3;    
		file_efficiencies_eff_xe_2j_axial_w3    >>         efficiencies_eff_xe_2j_axial_w3;        
		file_efficiencies_eff_or_1_2j_axial_w3    >>         efficiencies_eff_or_1_2j_axial_w3;      
		file_efficiencies_eff_or_2_2j_axial_w3    >>         efficiencies_eff_or_2_2j_axial_w3;      
		file_efficiencies_eff_or_3_2j_axial_w3    >>         efficiencies_eff_or_3_2j_axial_w3;      
		file_efficiencies_eff_or_4_2j_axial_w3    >>         efficiencies_eff_or_4_2j_axial_w3;      
		file_efficiencies_eff_xe_off_2j_axial_w3    >>         efficiencies_eff_xe_off_2j_axial_w3;    
		file_efficiencies_eff_or_1_off_2j_axial_w3   >>         efficiencies_eff_or_1_off_2j_axial_w3;  
		file_efficiencies_eff_or_2_off_2j_axial_w3    >>         efficiencies_eff_or_2_off_2j_axial_w3;  
		file_efficiencies_eff_or_3_off_2j_axial_w3    >>         efficiencies_eff_or_3_off_2j_axial_w3;  
		file_efficiencies_eff_or_4_off_2j_axial_w3    >>         efficiencies_eff_or_4_off_2j_axial_w3;  
		file_efficiencies_eff_or_5_off_2j_axial_w3    >>         efficiencies_eff_or_5_off_2j_axial_w3;  
		file_efficiencies_eff_or_6_off_2j_axial_w3    >>         efficiencies_eff_or_6_off_2j_axial_w3;  
		
		if (!dm_file_axial_w3.good()) break;
		eff_results_plots_axial_w3->Fill();
		n_axial_w3++;

	}
	cout << n_axial_w3 << endl;
	
	
	
	dm_file_axial_w3.close();
    mm_file_axial_w3.close();
	file_efficiencies_eff_xe_axial_w3.close();
	file_efficiencies_eff_or_1_axial_w3.close();
	file_efficiencies_eff_or_2_axial_w3.close();
	file_efficiencies_eff_or_3_axial_w3.close();
	file_efficiencies_eff_or_4_axial_w3.close();
	file_efficiencies_eff_xe_off_axial_w3.close();
	file_efficiencies_eff_or_1_off_axial_w3.close();
	file_efficiencies_eff_or_2_off_axial_w3.close();
	file_efficiencies_eff_or_3_off_axial_w3.close();
	file_efficiencies_eff_or_4_off_axial_w3.close();
	file_efficiencies_eff_or_5_off_axial_w3.close();
	file_efficiencies_eff_or_6_off_axial_w3.close();
	file_efficiencies_eff_xe_2j_axial_w3.close();
	file_efficiencies_eff_or_1_2j_axial_w3.close();
	file_efficiencies_eff_or_2_2j_axial_w3.close();
	file_efficiencies_eff_or_3_2j_axial_w3.close();
	file_efficiencies_eff_or_4_2j_axial_w3.close();
	file_efficiencies_eff_xe_off_2j_axial_w3.close();
	file_efficiencies_eff_or_1_off_2j_axial_w3.close();
	file_efficiencies_eff_or_2_off_2j_axial_w3.close();
	file_efficiencies_eff_or_3_off_2j_axial_w3.close();
	file_efficiencies_eff_or_4_off_2j_axial_w3.close();
	file_efficiencies_eff_or_5_off_2j_axial_w3.close();
	file_efficiencies_eff_or_6_off_2j_axial_w3.close(); 
	
	
	
	// Axial W8pi
	
	
	
	Float_t dm_axial_w8pi,mm_axial_w8pi,efficiencies_eff_xe_axial_w8pi,efficiencies_eff_or_1_axial_w8pi,efficiencies_eff_or_2_axial_w8pi,efficiencies_eff_or_3_axial_w8pi,efficiencies_eff_or_4_axial_w8pi;
	Float_t efficiencies_eff_xe_off_axial_w8pi,efficiencies_eff_or_1_off_axial_w8pi,efficiencies_eff_or_2_off_axial_w8pi,efficiencies_eff_or_3_off_axial_w8pi;
	Float_t efficiencies_eff_or_4_off_axial_w8pi,efficiencies_eff_or_5_off_axial_w8pi,efficiencies_eff_or_6_off_axial_w8pi;
	Float_t efficiencies_eff_xe_2j_axial_w8pi,efficiencies_eff_or_1_2j_axial_w8pi,efficiencies_eff_or_2_2j_axial_w8pi,efficiencies_eff_or_3_2j_axial_w8pi,efficiencies_eff_or_4_2j_axial_w8pi;
	Float_t efficiencies_eff_xe_off_2j_axial_w8pi,efficiencies_eff_or_1_off_2j_axial_w8pi,efficiencies_eff_or_2_off_2j_axial_w8pi,efficiencies_eff_or_3_off_2j_axial_w8pi;
	Float_t efficiencies_eff_or_4_off_2j_axial_w8pi,efficiencies_eff_or_5_off_2j_axial_w8pi,efficiencies_eff_or_6_off_2j_axial_w8pi;
	
	
	
	eff_results_plots_axial_w8pi->Branch("dm_axial_w8pi",&dm_axial_w8pi,"dm_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("mm_axial_w8pi",&mm_axial_w8pi,"mm_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_xe_axial_w8pi",&efficiencies_eff_xe_axial_w8pi,"efficiencies_eff_xe_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_1_axial_w8pi",&efficiencies_eff_or_1_axial_w8pi,"efficiencies_eff_or_1_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_2_axial_w8pi",&efficiencies_eff_or_2_axial_w8pi,"efficiencies_eff_or_2_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_3_axial_w8pi",&efficiencies_eff_or_3_axial_w8pi,"efficiencies_eff_or_3_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_4_axial_w8pi",&efficiencies_eff_or_4_axial_w8pi,"efficiencies_eff_or_4_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_xe_off_axial_w8pi",&efficiencies_eff_xe_off_axial_w8pi,"efficiencies_eff_xe_off_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_1_off_axial_w8pi",&efficiencies_eff_or_1_off_axial_w8pi,"efficiencies_eff_or_1_off_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_2_off_axial_w8pi",&efficiencies_eff_or_2_off_axial_w8pi,"efficiencies_eff_or_2_off_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_3_off_axial_w8pi",&efficiencies_eff_or_3_off_axial_w8pi,"efficiencies_eff_or_3_off_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_4_off_axial_w8pi",&efficiencies_eff_or_4_off_axial_w8pi,"efficiencies_eff_or_4_off_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_5_off_axial_w8pi",&efficiencies_eff_or_5_off_axial_w8pi,"efficiencies_eff_or_5_off_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_6_off_axial_w8pi",&efficiencies_eff_or_6_off_axial_w8pi,"efficiencies_eff_or_6_off_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_xe_2j_axial_w8pi",&efficiencies_eff_xe_2j_axial_w8pi,"efficiencies_eff_xe_2j_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_1_2j_axial_w8pi",&efficiencies_eff_or_1_2j_axial_w8pi,"efficiencies_eff_or_1_2j_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_2_2j_axial_w8pi",&efficiencies_eff_or_2_2j_axial_w8pi,"efficiencies_eff_or_2_2j_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_3_2j_axial_w8pi",&efficiencies_eff_or_3_2j_axial_w8pi,"efficiencies_eff_or_3_2j_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_4_2j_axial_w8pi",&efficiencies_eff_or_4_2j_axial_w8pi,"efficiencies_eff_or_4_2j_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_xe_off_2j_axial_w8pi",&efficiencies_eff_xe_off_2j_axial_w8pi,"efficiencies_eff_xe_off_2j_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_1_off_2j_axial_w8pi",&efficiencies_eff_or_1_off_2j_axial_w8pi,"efficiencies_eff_or_1_off_2j_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_2_off_2j_axial_w8pi",&efficiencies_eff_or_2_off_2j_axial_w8pi,"efficiencies_eff_or_2_off_2j_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_3_off_2j_axial_w8pi",&efficiencies_eff_or_3_off_2j_axial_w8pi,"efficiencies_eff_or_3_off_2j_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_4_off_2j_axial_w8pi",&efficiencies_eff_or_4_off_2j_axial_w8pi,"efficiencies_eff_or_4_off_2j_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_5_off_2j_axial_w8pi",&efficiencies_eff_or_5_off_2j_axial_w8pi,"efficiencies_eff_or_5_off_2j_axial_w8pi/F");
	eff_results_plots_axial_w8pi->Branch("efficiencies_eff_or_6_off_2j_axial_w8pi",&efficiencies_eff_or_6_off_2j_axial_w8pi,"efficiencies_eff_or_6_off_2j_axial_w8pi/F");
	
	
	
	
	ifstream  				            dm_file_axial_w8pi(choose_txt_directory+"/dm_axial_w8pi_file.txt");
	ifstream  							   mm_file_axial_w8pi(choose_txt_directory+"/mm_axial_w8pi_file.txt");
	ifstream  	    file_efficiencies_eff_xe_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_xe.txt");
	ifstream  	  file_efficiencies_eff_or_1_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_1.txt");
	ifstream  	  file_efficiencies_eff_or_2_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_2.txt");
	ifstream  	  file_efficiencies_eff_or_3_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_3.txt");
	ifstream  	  file_efficiencies_eff_or_4_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_4.txt");
	ifstream  	file_efficiencies_eff_xe_off_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_xe_off.txt");
	ifstream  file_efficiencies_eff_or_1_off_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_1_off.txt");
	ifstream  file_efficiencies_eff_or_2_off_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_2_off.txt");
	ifstream  file_efficiencies_eff_or_3_off_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_3_off.txt");
	ifstream  file_efficiencies_eff_or_4_off_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_4_off.txt");
	ifstream  file_efficiencies_eff_or_5_off_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_5_off.txt");
	ifstream  file_efficiencies_eff_or_6_off_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_6_off.txt");

	ifstream  	    file_efficiencies_eff_xe_2j_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_xe_2j.txt");
	ifstream  	  file_efficiencies_eff_or_1_2j_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_1_2j.txt");
	ifstream  	  file_efficiencies_eff_or_2_2j_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_2_2j.txt");
	ifstream  	  file_efficiencies_eff_or_3_2j_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_3_2j.txt");
	ifstream  	  file_efficiencies_eff_or_4_2j_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_4_2j.txt");
	ifstream  	file_efficiencies_eff_xe_off_2j_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_xe_off_2j.txt");
	ifstream  file_efficiencies_eff_or_1_off_2j_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_1_off_2j.txt");
	ifstream  file_efficiencies_eff_or_2_off_2j_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_2_off_2j.txt");
	ifstream  file_efficiencies_eff_or_3_off_2j_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_3_off_2j.txt");
	ifstream  file_efficiencies_eff_or_4_off_2j_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_4_off_2j.txt");
	ifstream  file_efficiencies_eff_or_5_off_2j_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_5_off_2j.txt");
	ifstream  file_efficiencies_eff_or_6_off_2j_axial_w8pi(choose_txt_directory+"/axial_w8pi_file_efficiencies_eff_or_6_off_2j.txt");

	
	
	Int_t n_axial_w8pi = 0;
	while (1) {
    	
		dm_file_axial_w8pi >> dm_axial_w8pi;
		mm_file_axial_w8pi >> mm_axial_w8pi;
		file_efficiencies_eff_xe_axial_w8pi           >>         efficiencies_eff_xe_axial_w8pi;	      	
		file_efficiencies_eff_or_1_axial_w8pi       >>         efficiencies_eff_or_1_axial_w8pi;   		 
		file_efficiencies_eff_or_2_axial_w8pi       >>         efficiencies_eff_or_2_axial_w8pi;   		 
		file_efficiencies_eff_or_3_axial_w8pi       >>         efficiencies_eff_or_3_axial_w8pi;   		 
		file_efficiencies_eff_or_4_axial_w8pi       >>         efficiencies_eff_or_4_axial_w8pi;   		 
		file_efficiencies_eff_xe_off_axial_w8pi       >>         efficiencies_eff_xe_off_axial_w8pi;  	
		file_efficiencies_eff_or_1_off_axial_w8pi        >>         efficiencies_eff_or_1_off_axial_w8pi;  	
		file_efficiencies_eff_or_2_off_axial_w8pi        >>         efficiencies_eff_or_2_off_axial_w8pi;  	
		file_efficiencies_eff_or_3_off_axial_w8pi        >>         efficiencies_eff_or_3_off_axial_w8pi;  	
		file_efficiencies_eff_or_4_off_axial_w8pi        >>         efficiencies_eff_or_4_off_axial_w8pi;    
		file_efficiencies_eff_or_5_off_axial_w8pi        >>         efficiencies_eff_or_5_off_axial_w8pi;    
		file_efficiencies_eff_or_6_off_axial_w8pi        >>         efficiencies_eff_or_6_off_axial_w8pi;    
		file_efficiencies_eff_xe_2j_axial_w8pi    >>         efficiencies_eff_xe_2j_axial_w8pi;        
		file_efficiencies_eff_or_1_2j_axial_w8pi    >>         efficiencies_eff_or_1_2j_axial_w8pi;      
		file_efficiencies_eff_or_2_2j_axial_w8pi    >>         efficiencies_eff_or_2_2j_axial_w8pi;      
		file_efficiencies_eff_or_3_2j_axial_w8pi    >>         efficiencies_eff_or_3_2j_axial_w8pi;      
		file_efficiencies_eff_or_4_2j_axial_w8pi    >>         efficiencies_eff_or_4_2j_axial_w8pi;      
		file_efficiencies_eff_xe_off_2j_axial_w8pi    >>         efficiencies_eff_xe_off_2j_axial_w8pi;    
		file_efficiencies_eff_or_1_off_2j_axial_w8pi   >>         efficiencies_eff_or_1_off_2j_axial_w8pi;  
		file_efficiencies_eff_or_2_off_2j_axial_w8pi    >>         efficiencies_eff_or_2_off_2j_axial_w8pi;  
		file_efficiencies_eff_or_3_off_2j_axial_w8pi    >>         efficiencies_eff_or_3_off_2j_axial_w8pi;  
		file_efficiencies_eff_or_4_off_2j_axial_w8pi    >>         efficiencies_eff_or_4_off_2j_axial_w8pi;  
		file_efficiencies_eff_or_5_off_2j_axial_w8pi    >>         efficiencies_eff_or_5_off_2j_axial_w8pi;  
		file_efficiencies_eff_or_6_off_2j_axial_w8pi    >>         efficiencies_eff_or_6_off_2j_axial_w8pi;  
		  
		if (!dm_file_axial_w8pi.good()) break;
		eff_results_plots_axial_w8pi->Fill();
		n_axial_w8pi++;

	}
	cout << n_axial_w8pi << endl;
	
	
	
	dm_file_axial_w8pi.close();
    mm_file_axial_w8pi.close();
	file_efficiencies_eff_xe_axial_w8pi.close();
	file_efficiencies_eff_or_1_axial_w8pi.close();
	file_efficiencies_eff_or_2_axial_w8pi.close();
	file_efficiencies_eff_or_3_axial_w8pi.close();
	file_efficiencies_eff_or_4_axial_w8pi.close();
	file_efficiencies_eff_xe_off_axial_w8pi.close();
	file_efficiencies_eff_or_1_off_axial_w8pi.close();
	file_efficiencies_eff_or_2_off_axial_w8pi.close();
	file_efficiencies_eff_or_3_off_axial_w8pi.close();
	file_efficiencies_eff_or_4_off_axial_w8pi.close();
	file_efficiencies_eff_or_5_off_axial_w8pi.close();
	file_efficiencies_eff_or_6_off_axial_w8pi.close();
	file_efficiencies_eff_xe_2j_axial_w8pi.close();
	file_efficiencies_eff_or_1_2j_axial_w8pi.close();
	file_efficiencies_eff_or_2_2j_axial_w8pi.close();
	file_efficiencies_eff_or_3_2j_axial_w8pi.close();
	file_efficiencies_eff_or_4_2j_axial_w8pi.close();
	file_efficiencies_eff_xe_off_2j_axial_w8pi.close();
	file_efficiencies_eff_or_1_off_2j_axial_w8pi.close();
	file_efficiencies_eff_or_2_off_2j_axial_w8pi.close();
	file_efficiencies_eff_or_3_off_2j_axial_w8pi.close();
	file_efficiencies_eff_or_4_off_2j_axial_w8pi.close();
	file_efficiencies_eff_or_5_off_2j_axial_w8pi.close();
	file_efficiencies_eff_or_6_off_2j_axial_w8pi.close(); 




	eff_results_plots_vector_w3->Write(); 
	eff_results_plots_vector_w8pi->Write();    
	eff_results_plots_axial_w3->Write(); 
	eff_results_plots_axial_w8pi->Write();
	eff_results_plots->Close();
	
	
}

