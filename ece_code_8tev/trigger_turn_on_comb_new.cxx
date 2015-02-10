#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLatex.h>
#include <TTree.h>
#include "common_plotting_functions.hh"
#include <TGraph.h>
#include <TEfficiency.h>
#include <vector>

//#include <TString.h>
//#include <iostream>
//#include <iomanip>


//JETs : not trigger but only pt cuts
//JET : L1


// mytree_1 : QCUT80
// mytree_2 : QCUT300




vector<Float_t> trigger_turn_on_comb_new(TString c_prodr, Float_t prodr, Float_t c_1, Float_t c_2, TString file_directory , TString input_file_name_1, TString input_file_name_2, TString output_directory , TString output_file_name, Float_t cross_sect1, Float_t cross_sect2){


	TH1F *xe_pt_h_den_tr1 = new TH1F("xe_pt_h_den_tr1", "xe pt den", 40, 50, 250);
	TH1F *xe_pt_h_num_tr1 = new TH1F("xe_pt_h_num_tr1", "xe pt num", 40, 50, 250);

	TH1F * shatR_h_den_tr1 = new TH1F("shatR_h_den_tr1","shatR den",60,0,3000);
        TH1F * shatR_h_num_tr1 = new TH1F("shatR_h_num_tr1","shatR num",60,0,3000);
	TH1F * shatR_h_den_tr2 = new TH1F("shatR_h_den_tr2","shatR den",60,0,3000);
        TH1F * shatR_h_num_tr2 = new TH1F("shatR_h_num_tr2","shatR num",60,0,3000);

	TH1F * gaminvR_h_den_tr1 = new TH1F("gaminvR_h_den_tr1","gaminvR den",50,0,1);
        TH1F * gaminvR_h_num_tr1 = new TH1F("gaminvR_h_num_tr1","gaminvR num",50,0,1);
	TH1F * gaminvR_h_den_tr2 = new TH1F("gaminvR_h_den_tr2","gaminvR den",50,0,1);
        TH1F * gaminvR_h_num_tr2 = new TH1F("gaminvR_h_num_tr2","gaminvR num",50,0,1);

        TH2F * raz_var_h_tr1_total = new TH2F("raz_var_h_tr1_total", "Raz Var Tr1 (total)", 60, 0, 3000, 50, 0, 1);
        TH2F * raz_var_h_tr1_passed = new TH2F("raz_var_h_tr1_passed", "Raz Var Tr1 (passed)", 60, 0, 3000, 50, 0, 1);
        TH2F * raz_var_h_tr2_total = new TH2F("raz_var_h_tr2_total", "Raz Var Tr2 (total)", 60, 0, 3000, 50, 0, 1);
        TH2F * raz_var_h_tr2_passed = new TH2F("raz_var_h_tr2_passed", "Raz Var Tr2 (passed)", 60, 0, 3000, 50, 0, 1);

        TH2F * raz_var_efficiency_h = new TH2F("raz_var_efficiency_h", "Efficiency", 30, 0, 3000, 50, 0, 1);

	TH1F * shatR_h_den_tr1_c1 = new TH1F("shatR_h_den_tr1_c1","shatR den",60,0,3000);
        TH1F * shatR_h_num_tr1_c1 = new TH1F("shatR_h_num_tr1_c1","shatR num",60,0,3000);
	TH1F * shatR_h_den_tr2_c1 = new TH1F("shatR_h_den_tr2_c1","shatR den",60,0,3000);
        TH1F * shatR_h_num_tr2_c1 = new TH1F("shatR_h_num_tr2_c1","shatR num",60,0,3000);

	TH1F * shatR_h_den_tr1_c2 = new TH1F("shatR_h_den_tr1_c2","shatR den",60,0,3000);
        TH1F * shatR_h_num_tr1_c2 = new TH1F("shatR_h_num_tr1_c2","shatR num",60,0,3000);
	TH1F * shatR_h_den_tr2_c2 = new TH1F("shatR_h_den_tr2_c2","shatR den",60,0,3000);
        TH1F * shatR_h_num_tr2_c2 = new TH1F("shatR_h_num_tr2_c2","shatR num",60,0,3000);

	TH1F * shatR_h_den_tr1_c3 = new TH1F("shatR_h_den_tr1_c3","shatR den",60,0,3000);
        TH1F * shatR_h_num_tr1_c3 = new TH1F("shatR_h_num_tr1_c3","shatR num",60,0,3000);
	TH1F * shatR_h_den_tr2_c3 = new TH1F("shatR_h_den_tr2_c3","shatR den",60,0,3000);
        TH1F * shatR_h_num_tr2_c3 = new TH1F("shatR_h_num_tr2_c3","shatR num",60,0,3000);

	TH1F * shatR_h_den_tr1_c4 = new TH1F("shatR_h_den_tr1_c4","shatR den",60,0,3000);
        TH1F * shatR_h_num_tr1_c4 = new TH1F("shatR_h_num_tr1_c4","shatR num",60,0,3000);
	TH1F * shatR_h_den_tr2_c4 = new TH1F("shatR_h_den_tr2_c4","shatR den",60,0,3000);
        TH1F * shatR_h_num_tr2_c4 = new TH1F("shatR_h_num_tr2_c4","shatR num",60,0,3000);

	Float_t shatR_gaminvR_c1 = 800;
	Float_t shatR_gaminvR_c2 = 600;
	Float_t shatR_gaminvR_c3 = 400;
	Float_t shatR_gaminvR_c4 = 200;

	TString gaminvR_c1 = "0.8";
	TString gaminvR_c2 = "0.6";
 	TString gaminvR_c3 = "0.4";
	TString gaminvR_c4 = "0.2";

	Float_t off_c_1 = 200;
	Float_t off_c_2 = 0;
	Float_t off_prodr = 260;
	Float_t off_value = 0;
	TString off_prodr_s = "260";

      	Float_t off_xe = 200;

	// Define weights and number of events for the seperate trees and the trees loop
	Float_t weight_1 = cross_sect1;
	Float_t weight_2 = cross_sect2;
	Float_t weight = 0;

        Float_t number_of_events_1 = 0;
        Float_t number_of_events_2 = 0;
	Float_t number_of_events_cur = 0;

        Float_t number_of_events = 0; // total, weighted after the combination

	Float_t value = 0; // calculated value for hyperbolic cut


	vector<Float_t> efficiencies(0);
	Float_t value = 0;

	ofstream outputfile(output_directory+"/"+output_file_name+c_prodr+"_efficiency_outputfile.txt");
	outputfile<< " *** output messages file for : " << file_directory << "/" << input_file_name_1 << "," << input_file_name_2  << " *** \n"<<
	"\n prodr : " << prodr <<
	"\n c_1 : " << c_1 <<
	"\n c_2 : " << c_2 <<
	endl;

	Float_t n_razor = 0;

	Float_t shatR=0; Long64_t n_shatR=0;
	Float_t cosptR=0; Long64_t n_cosptR=0;
	Float_t mdeltaR=0; Long64_t n_mdeltaR=0;
	Float_t gaminvR=0; Long64_t n_gaminvR=0;
	Float_t dphivbR=0; Long64_t n_dphivbR=0;
	Float_t ptcm=0; Long64_t n_ptcm=0;
	Float_t Prod=0;

	Float_t LeadPt = 0;

	Float_t xe_pt;

	static const int n_t=3;
	static const int n_t_noprodr=2;

	int flag_prodr_t[n_t]={0};
        int flag_prodr_t_off[n_t]={0};


	// Razor and L1

	// Trigger branch variables, booleans
	Bool_t b_2J15_XE55=0; //t1
	Bool_t b_XE70 = 0; //t3
	// L2 included
	Bool_t b_xe100_XE70=0; //t2

	Float_t n_o_e_prodr = 0;
	Float_t n_o_e_prodr_2J15_XE55 =0;
	Float_t n_o_e_prodr_XE70 = 0;
      	Float_t n_o_e_prodr_2J15_XE55_off =0;
      	Float_t n_o_e_prodr_XE70_off = 0;


	Float_t n_t1_noprodr = 0;
	Float_t n_t3_noprodr = 0;

	//No razor
	Float_t n_o_e_xe100_XE70 = 0;
      	Float_t n_o_e_xe100_XE70_off = 0;


	// OR combination of the triggers

	Float_t n_o_e_xe100_XE70_or_prodr_2J15_XE55=0;
	Float_t n_o_e_xe100_XE70_or_prodr_XE70=0;
       	Float_t n_o_e_prodr_2J15_XE55_or_prodr_XE70 = 0;
     	Float_t n_o_e_xe100_XE70_or_prodr_or3 = 0;

	Float_t n_o_e_xe100_XE70_or_prodr_2J15_XE55_off=0;
	Float_t n_o_e_xe100_XE70_or_prodr_XE70_off=0;
       	Float_t n_o_e_prodr_2J15_XE55_or_prodr_XE70_off = 0;
     	Float_t n_o_e_xe100_XE70_or_prodr_or3_off = 0;


	int flag_OR_1 = 0;
	int flag_OR_2 = 0;
	int flag_OR_3 = 0;
       	int flag_OR_4 = 0;

	int flag_OR_1_off = 0;
	int flag_OR_2_off = 0;
	int flag_OR_3_off = 0;
       	int flag_OR_4_off = 0;


      	int flag_xe_off = 0;
      	int flag_prod_off = 0;


	// Efficiency turn-on curves
	vector<Float_t> vect_shatR(0);
	vector<Float_t> vect_n_shatR(0);
	vector<Float_t> vect_n_shatR_passtrigger(0);
	vector<Float_t> eff_shatR(0);
	vect_shatR.push_back(0);
	vect_n_shatR.push_back(0);
	vect_n_shatR_passtrigger.push_back(0);
	Float_t shatR_bin = 100000;

	vector<Float_t> vect_gaminvR(0);
	vector<Float_t> vect_n_gaminvR(0);
	vector<Float_t> vect_n_gaminvR_passtrigger(0);
	vector<Float_t> eff_gaminvR(0);
	vect_gaminvR.push_back(0);
	vect_n_gaminvR.push_back(0);
	vect_n_gaminvR_passtrigger.push_back(0);
	Float_t gaminvR_bin = 20;

	vector<Float_t> vect_met(0);
	vector<Float_t> vect_n_met(0);
	vector<Float_t> vect_n_met_passtrigger(0);
	vector<Float_t> eff_met(0);


//	Float_t all_events_passtrigger = 0;


	for(Int_t vect = 0; vect < 29 ; vect++){

		vect_shatR.push_back(vect_shatR[vect]+shatR_bin);
		vect_n_shatR.push_back(0);
		vect_n_shatR_passtrigger.push_back(0);
	}


	for(Int_t vect = 0; vect<49; vect++){
		vect_gaminvR.push_back( vect_gaminvR[vect] + gaminvR_bin);
		vect_n_gaminvR.push_back(0);
		vect_n_gaminvR_passtrigger.push_back(0);
	}


	Int_t n_shatR_eff = vect_shatR.size();
	Int_t n_gaminvR_eff = vect_gaminvR.size();

//	cout << n_shatR_eff << endl;
//	cout << n_gaminvR_eff << endl;


	// Open file1 QCUT80
	TFile *razor_file_1 = TFile::Open(file_directory+"/"+input_file_name_1);
    	if(razor_file_1==0) {
                cout << "Couldn't open the root file" << endl;
                return;
        }

	// Get the tree 1

	TTree* mytree_1 = (TTree*)razor_file_1->Get("physics");
	number_of_events_1 = mytree_1->GetEntries();
	outputfile << " number of events tree 1 : " << number_of_events_1 << endl;

	// Open file 2 QCUT300

      	TFile *razor_file_2 = TFile::Open(file_directory+"/"+input_file_name_2);
       	if(razor_file_2==0) {
        	cout << "Couldn't open the root file" << endl;
                return;
        }


	// Get the tree 2

        TTree* mytree_2 = (TTree*)razor_file_2->Get("physics");
        number_of_events_2 = mytree_2->GetEntries();
        outputfile << " number of events tree 2 : " << number_of_events_2 << endl;


	efficiencies.resize(0);

 	// The tree loop, 2 trees
	for(int tr = 0; tr<2; tr++){

		TFile *newfile = new TFile("small.root","recreate");
		TTree *currenttree = new TTree("current tree", "current tree");

		if(tr == 0) {

			mytree_1->SetBranchStatus("*",1);

	   		currenttree = mytree_1->CloneTree();
			if(currenttree!=0)cout << "Cloned first tree" << endl;


                        weight = weight_1/number_of_events_1;
			number_of_events_cur = number_of_events_1;

		}

		if(tr == 1) {

                	mytree_2->SetBranchStatus("*",1);

			currenttree = mytree_2->CloneTree();
			if(currenttree!=0) cout << "Cloned second tree" << endl;

                        weight = weight_2/number_of_events_2;
			number_of_events_cur = number_of_events_2;

		}


		currenttree->SetBranchAddress("shatR",&shatR);
		currenttree->SetBranchAddress("gaminvR",&gaminvR);
	//	currenttree->SetBranchAddress("Prod" , &Prod);
		currenttree->SetBranchAddress("LeadPt",&LeadPt);
		currenttree->SetBranchAddress("xe_pt",&xe_pt);

		// Trigger information bool branches

 		currenttree->SetBranchAddress("2J15_XE55",&b_2J15_XE55);
		currenttree->SetBranchAddress("xe100_XE70",&b_xe100_XE70);
		currenttree->SetBranchAddress("XE70",&b_XE70);

		//Tree event loop
		for (Long64_t i=0; i<number_of_events_cur; i++) {

			//Clear flags
			for (int j = 0; j<n_t; j++) {
				flag_prodr_t[j] = 0;
			}
			for (int j = 0; j<n_t; j++) {
				flag_prodr_t_off[j] = 0;
			}

			flag_OR_1 = 0;
			flag_OR_2 = 0;
			flag_OR_3 = 0;
			flag_OR_4 = 0;


			flag_OR_1_off = 0;
			flag_OR_2_off = 0;
			flag_OR_3_off = 0;
			flag_OR_4_off = 0;

                     	flag_xe_off = 0;
                     	flag_prod_off = 0;

			currenttree->GetEntry(i); // the object event has been filled at this point

			if(tr==0) {if(LeadPt>350000) continue;}
			if(tr==1) {if(LeadPt<=350000) continue;}

			//Check the number of events with each razor variable defined
			if(shatR>0) {n_shatR++;}
			if(cosptR>0) {n_cosptR++;}
			if(mdeltaR>0) {n_mdeltaR++;}
			if(gaminvR>0) {n_gaminvR++;}
			if(dphivbR>0) {n_dphivbR++;}
			if(ptcm>0) {n_ptcm++;}



                      	if( xe_pt/1000 >= off_xe) { flag_xe_off = 1;  }

                    	value = (shatR/1000 + c_1) * (gaminvR/1000+c_2);
                    	//      value = Prod;
                    	if (value >= prodr) {n_o_e_prodr = n_o_e_prodr + weight;}
                     	off_value = (shatR/1000 + off_c_1 ) * (gaminvR/1000 + off_c_2);
                    	if(off_value >= off_prodr && shatR/1000 <= 3000 ) { flag_prod_off = 1; }



			//Fill the values, flags

			if(shatR>0 && gaminvR>0) {
				n_razor = n_razor + weight;
			}

			if(shatR>0 && gaminvR>0 && value<prodr) {

				if(b_2J15_XE55==1) n_t1_noprodr = n_t1_noprodr +weight;
				if(b_XE70==1) n_t3_noprodr = n_t3_noprodr + weight ;

			}


			// ProdR
			if(shatR>0 && gaminvR>0 && value>=prodr) {
				// t1
				if(b_2J15_XE55==1){
					flag_prodr_t[0]=1;
					n_o_e_prodr_2J15_XE55 = n_o_e_prodr_2J15_XE55 + weight;
                              		if (flag_prod_off == 1 ) { flag_prodr_t_off[0]=1;  n_o_e_prodr_2J15_XE55_off =  n_o_e_prodr_2J15_XE55_off  + weight; }
				}


				//t3
				if(b_XE70==1){
					flag_prodr_t[2]=1;
					n_o_e_prodr_XE70 = n_o_e_prodr_XE70 + weight;
                                     	if (flag_prod_off == 1 ) { flag_prodr_t_off[2]=1;  n_o_e_prodr_XE70_off = n_o_e_prodr_XE70_off  + weight; }

				}
			}


			//t2 (only met, no jet,no razor)
			if(b_xe100_XE70==1){
				flag_prodr_t[1]=1; //actually it is not a flag_prodr_t, only met
				n_o_e_xe100_XE70 = n_o_e_xe100_XE70 + weight;
                             	if (flag_xe_off == 1 ) { flag_prodr_t_off[1]=1; n_o_e_xe100_XE70_off = n_o_e_xe100_XE70_off  + weight; }

			}



			// Triggers OR

			// t1 OR t2
			if(flag_prodr_t[0]==1 || flag_prodr_t[1]==1){
				flag_OR_1 = 1;
				n_o_e_xe100_XE70_or_prodr_2J15_XE55  = n_o_e_xe100_XE70_or_prodr_2J15_XE55 + weight;
			}


                        if(flag_prodr_t_off[0] == 1 || flag_prodr_t_off[1]==1) {

                                flag_OR_1_off = 1;
                                n_o_e_xe100_XE70_or_prodr_2J15_XE55_off = n_o_e_xe100_XE70_or_prodr_2J15_XE55_off  + weight;


                        }


			//t3 OR t2
			if(flag_prodr_t[2]==1 || flag_prodr_t[1]==1){
				flag_OR_2 = 1;
				n_o_e_xe100_XE70_or_prodr_XE70 = n_o_e_xe100_XE70_or_prodr_XE70 + weight;
			}



                        if(flag_prodr_t_off[2]== 1 || flag_prodr_t_off[1]==1){
                                flag_OR_2_off = 1;
                                n_o_e_xe100_XE70_or_prodr_XE70_off = n_o_e_xe100_XE70_or_prodr_XE70_off  + weight;

                        }




			// ProdR or : t1 or t3 : OR 3
			if( flag_prodr_t[0]==1 || flag_prodr_t[2]==1){
				flag_OR_3 = 1;
				n_o_e_prodr_2J15_XE55_or_prodr_XE70 = n_o_e_prodr_2J15_XE55_or_prodr_XE70 + weight;
			}


                        if(flag_prodr_t_off[0] == 1 || flag_prodr_t_off[2] == 1){
                                flag_OR_3_off =1;
                                n_o_e_prodr_2J15_XE55_or_prodr_XE70_off  = n_o_e_prodr_2J15_XE55_or_prodr_XE70_off + weight;
                        }



			// ProdR_or(flag_OR_3) OR met(t2) : OR 4
			if( flag_OR_3 ==1 || flag_prodr_t[1]==1){
				flag_OR_4 = 1;
				n_o_e_xe100_XE70_or_prodr_or3 = n_o_e_xe100_XE70_or_prodr_or3 + weight;
			}



                        if(flag_OR_3_off == 1 || flag_prodr_t_off[1]==1){

                                n_o_e_xe100_XE70_or_prodr_or3_off = n_o_e_xe100_XE70_or_prodr_or3_off  + weight;

                        }




			// Turn on : MET

			// Turn-on : without trigger

			xe_pt_h_den_tr1->Fill(xe_pt/1000,weight);



			// Turn-on : passed trigger MET
			if(flag_prodr_t[1]==1){
				xe_pt_h_num_tr1->Fill(xe_pt/1000,weight);
			}



			// Turn on : RAZOR

			if(shatR>0 && gaminvR>0){


				// Turn-on : without trigger


				// FILLING INTERVALS

				// Turn-on : no trigger
				if(tr == 0) {
					shatR_h_den_tr1->Fill( shatR/1000,weight);
					gaminvR_h_den_tr1->Fill( gaminvR/1000,weight);
                      			raz_var_h_tr1_total->Fill(shatR/1000, gaminvR/1000,weight);

					if(gaminvR >= shatR_gaminvR_c1) shatR_h_den_tr1_c1->Fill(shatR/1000,weight);
					if(gaminvR >= shatR_gaminvR_c2) shatR_h_den_tr1_c2->Fill(shatR/1000,weight);
					if(gaminvR >= shatR_gaminvR_c3) shatR_h_den_tr1_c3->Fill(shatR/1000,weight);
					if(gaminvR >= shatR_gaminvR_c4) shatR_h_den_tr1_c4->Fill(shatR/1000,weight);
				}


				if(tr == 1) {
					shatR_h_den_tr2->Fill( shatR/1000, weight);
					gaminvR_h_den_tr2->Fill( gaminvR/1000,weight);
                      			raz_var_h_tr2_total->Fill(shatR/1000, gaminvR/1000,weight);

					if(gaminvR >= shatR_gaminvR_c1) shatR_h_den_tr2_c1->Fill(shatR/1000,weight);
					if(gaminvR >= shatR_gaminvR_c2) shatR_h_den_tr2_c2->Fill(shatR/1000,weight);
					if(gaminvR >= shatR_gaminvR_c3) shatR_h_den_tr2_c3->Fill(shatR/1000,weight);
					if(gaminvR >= shatR_gaminvR_c4) shatR_h_den_tr2_c4->Fill(shatR/1000,weight);

				}


				// Turn-on : passed trigger
                        	       	if(flag_OR_3 == 1) {
					if(tr == 0){
						shatR_h_num_tr1->Fill(shatR/1000,weight);
						gaminvR_h_num_tr1->Fill(gaminvR/1000,weight);
                               			raz_var_h_tr1_passed->Fill(shatR/1000, gaminvR/1000,weight);

						if(gaminvR >= shatR_gaminvR_c1) shatR_h_num_tr1_c1->Fill(shatR/1000,weight);
						if(gaminvR >= shatR_gaminvR_c2) shatR_h_num_tr1_c2->Fill(shatR/1000,weight);
						if(gaminvR >= shatR_gaminvR_c3) shatR_h_num_tr1_c3->Fill(shatR/1000,weight);
						if(gaminvR >= shatR_gaminvR_c4) shatR_h_num_tr1_c4->Fill(shatR/1000,weight);
					}

					if(tr == 1){
						shatR_h_num_tr2->Fill(shatR/1000,weight);
						gaminvR_h_num_tr2->Fill(gaminvR/1000,weight);
                                       		raz_var_h_tr2_passed->Fill(shatR/1000, gaminvR/1000,weight);

						if(gaminvR >= shatR_gaminvR_c1) shatR_h_num_tr2_c1->Fill(shatR/1000,weight);
						if(gaminvR >= shatR_gaminvR_c2) shatR_h_num_tr2_c2->Fill(shatR/1000,weight);
						if(gaminvR >= shatR_gaminvR_c3) shatR_h_num_tr2_c3->Fill(shatR/1000,weight);
						if(gaminvR >= shatR_gaminvR_c4) shatR_h_num_tr2_c4->Fill(shatR/1000,weight);

					}

                              	}
			
/* FILLING ALL EVENTS THAT PASS THE THRESHOLD, NOT INTERVALS


				for(Int_t vect2 = 0; vect2 < n_shatR_eff; vect2++){

					if( shatR >= vect_shatR[vect2] ){
						if(tr == 0) shatR_h_den_tr1->Fill( vect_shatR[vect2]/1000);
						if(tr == 1) shatR_h_den_tr2->Fill( vect_shatR[vect2]/1000);

						// Turn-on : passed trigger
						if(flag_prodr_t[0]==1){
                                             		if(tr == 0)shatR_h_num_tr1->Fill( vect_shatR[vect2]/1000);
							if(tr == 1)shatR_h_num_tr2->Fill( vect_shatR[vect2]/1000);
						}


					}
				}



				for(Int_t vect2 = 0; vect2 < n_gaminvR_eff; vect2++){

					if(gaminvR < vect_gaminvR[vect2] ){
						if(tr == 0) gaminvR_h_den_tr1->Fill(vect_gaminvR[vect2]/1000);
						if(tr == 1) gaminvR_h_den_tr2->Fill(vect_gaminvR[vect2]/1000);
						//Turn-on : passed trigger
						if(flag_prodr_t[0]==1){
							if(tr == 0) gaminvR_h_num_tr1->Fill(vect_gaminvR[vect2]/1000);
							if(tr == 1) gaminvR_h_num_tr2->Fill(vect_gaminvR[vect2]/1000);
						}

					}
				}


*/

/* TOTAL
				for(Int_t x_2 = 0; x_2 < n_shatR_eff; x_2++){

					for(Int_t y_2 = 0 ; y_2 <n_gaminvR_eff; y_2++){


						if( shatR >= vect_shatR[x_2] &&  gaminvR < vect_gaminvR[y_2]) {

							if(tr == 0) raz_var_h_tr1_total->Fill(vect_shatR[x_2]/1000, vect_gaminvR[y_2]/1000);
							if(tr == 1) raz_var_h_tr2_total->Fill(vect_shatR[x_2]/1000, vect_gaminvR[y_2]/1000);

							if(flag_OR_3 == 1) {

								if(tr == 0) raz_var_h_tr1_passed->Fill(vect_shatR[x_2]/1000, vect_gaminvR[y_2]/1000);
								if(tr == 1) raz_var_h_tr2_passed->Fill(vect_shatR[x_2]/1000, vect_gaminvR[y_2]/1000);

							}
						}
					}

				}
*/



			} // end the RAZOR turn-on
			

			number_of_events = number_of_events + weight;

		} //end event loop


		if(tr == 0) {razor_file_1->Close();}

		if(tr == 1) {razor_file_2->Close();}

		delete newfile;
		cout << "end event loop : "<< tr << endl;


	} // end the 2 trees loop


	Float_t eff_xe = n_o_e_xe100_XE70/number_of_events;

	Float_t per_n_t1_noprodr = 100 * n_t1_noprodr / n_razor ;
	Float_t eff_or_1 = n_o_e_xe100_XE70_or_prodr_2J15_XE55/number_of_events ;

	Float_t per_n_t3_noprodr = 100*  n_t3_noprodr / n_razor ;
	Float_t eff_or_2 =  n_o_e_xe100_XE70_or_prodr_XE70/number_of_events;

	Float_t eff_or_3 =n_o_e_prodr_2J15_XE55_or_prodr_XE70/number_of_events;
	Float_t eff_or_4 =n_o_e_xe100_XE70_or_prodr_or3/number_of_events;


        // Eff plateau
        Float_t eff_xe_off = n_o_e_xe100_XE70_off/number_of_events;
        Float_t eff_or_1_off = n_o_e_xe100_XE70_or_prodr_2J15_XE55_off/number_of_events ;
        Float_t eff_or_2_off =  n_o_e_xe100_XE70_or_prodr_XE70_off/number_of_events;
        Float_t eff_or_3_off =n_o_e_prodr_2J15_XE55_or_prodr_XE70_off/number_of_events;
        Float_t eff_or_4_off =n_o_e_xe100_XE70_or_prodr_or3_off/number_of_events;


	efficiencies.push_back(eff_xe) ;
	efficiencies.push_back(eff_or_1);
	efficiencies.push_back(eff_or_2);
	efficiencies.push_back(eff_or_3);
	efficiencies.push_back(eff_or_4);
       //Plateau
        efficiencies.push_back(eff_xe_off) ;
        efficiencies.push_back(eff_or_1_off);
        efficiencies.push_back(eff_or_2_off);
        efficiencies.push_back(eff_or_3_off);
        efficiencies.push_back(eff_or_4_off);


	setstyle();

      	weight_1 = weight_1/number_of_events_1;
      	weight_2 = weight_2/number_of_events_2;



	// Efficiency turn-on plots

	TCanvas *c3 = new TCanvas ("c3","Efficiency ET miss");
	c3->Clear();


	xe_pt_h_eff_tr1 =(TEfficiency*) new TEfficiency(*xe_pt_h_num_tr1, *xe_pt_h_den_tr1);
	xe_pt_h_eff_tr1->SetMarkerColor(kBlue);
	xe_pt_h_eff_tr1->SetLineColor(kBlue);
	xe_pt_h_eff_tr1->SetTitle("Efficiency ; E_{T}^{miss} [GeV] ; Efficiency");

	xe_pt_h_eff_tr1->Draw();






	TCanvas *c4 = new TCanvas("c4","Efficiency shatR");
	c4->Clear();
	shatR_h_eff_tr1 = (TEfficiency*) new TEfficiency(*shatR_h_num_tr1,*shatR_h_den_tr1);
	shatR_h_eff_tr1->SetWeight(weight_1);
	shatR_h_eff_tr2 = (TEfficiency*) new TEfficiency(*shatR_h_num_tr2,*shatR_h_den_tr2);
	shatR_h_eff_tr2->SetWeight(weight_2);
	shatR_h_eff_tr1->Add(*shatR_h_eff_tr2);
	shatR_h_eff_tr1->SetTitle("Efficiency ; #sqrt{#hat{s}_{R}}[GeV] ; Efficiency");
	shatR_h_eff_tr1->Draw();


	shatR_h_eff_tr1_c1 = (TEfficiency*) new TEfficiency(*shatR_h_num_tr1_c1,*shatR_h_den_tr1_c1);
	shatR_h_eff_tr1_c2 = (TEfficiency*) new TEfficiency(*shatR_h_num_tr1_c2,*shatR_h_den_tr1_c2);
	shatR_h_eff_tr1_c3 = (TEfficiency*) new TEfficiency(*shatR_h_num_tr1_c3,*shatR_h_den_tr1_c3);
	shatR_h_eff_tr1_c4 = (TEfficiency*) new TEfficiency(*shatR_h_num_tr1_c4,*shatR_h_den_tr1_c4);

	shatR_h_eff_tr1_c1->SetWeight(weight_1);
	shatR_h_eff_tr1_c2->SetWeight(weight_1);
	shatR_h_eff_tr1_c3->SetWeight(weight_1);
	shatR_h_eff_tr1_c4->SetWeight(weight_1);

	shatR_h_eff_tr2_c1 = (TEfficiency*) new TEfficiency(*shatR_h_num_tr2_c1,*shatR_h_den_tr2_c1);
	shatR_h_eff_tr2_c2 = (TEfficiency*) new TEfficiency(*shatR_h_num_tr2_c2,*shatR_h_den_tr2_c2);
	shatR_h_eff_tr2_c3 = (TEfficiency*) new TEfficiency(*shatR_h_num_tr2_c3,*shatR_h_den_tr2_c3);
	shatR_h_eff_tr2_c4 = (TEfficiency*) new TEfficiency(*shatR_h_num_tr2_c4,*shatR_h_den_tr2_c4);

	shatR_h_eff_tr2_c1->SetWeight(weight_2);
	shatR_h_eff_tr2_c2->SetWeight(weight_2);
	shatR_h_eff_tr2_c3->SetWeight(weight_2);
	shatR_h_eff_tr2_c4->SetWeight(weight_2);
	shatR_h_eff_tr1_c1->Add(*shatR_h_eff_tr2_c1);
	shatR_h_eff_tr1_c2->Add(*shatR_h_eff_tr2_c2);
	shatR_h_eff_tr1_c3->Add(*shatR_h_eff_tr2_c3);
	shatR_h_eff_tr1_c4->Add(*shatR_h_eff_tr2_c4);

	shatR_h_eff_tr1_c1->SetLineColor(2);
	shatR_h_eff_tr1_c1->SetMarkerColor(2);
	shatR_h_eff_tr1_c1->SetMarkerStyle(21);
	shatR_h_eff_tr1_c1->Draw("same");

	shatR_h_eff_tr1_c2->SetLineColor(3);
	shatR_h_eff_tr1_c2->SetMarkerColor(3);
	shatR_h_eff_tr1_c2->SetMarkerStyle(22);
	shatR_h_eff_tr1_c2->Draw("same");

	shatR_h_eff_tr1_c3->SetLineColor(4);
	shatR_h_eff_tr1_c3->SetMarkerColor(4);
	shatR_h_eff_tr1_c3->SetMarkerStyle(23);
	shatR_h_eff_tr1_c3->Draw("same");

	shatR_h_eff_tr1_c4->SetLineColor(6);
	shatR_h_eff_tr1_c4->SetMarkerColor(6);
	shatR_h_eff_tr1_c4->SetMarkerStyle(33);
	shatR_h_eff_tr1_c4->Draw("same");


        leg = new TLegend(0.65,0.35,0.85,0.75);
        leg->SetTextSize(0.04);
        leg->AddEntry(shatR_h_eff_tr1,"All 1/#gamma_{R+1}", "p");
	leg->AddEntry(shatR_h_eff_tr1_c4,"1/#gamma_{R+1} #geq"+gaminvR_c4, "p");
	leg->AddEntry(shatR_h_eff_tr1_c3,"1/#gamma_{R+1} #geq"+gaminvR_c3, "p");
	leg->AddEntry(shatR_h_eff_tr1_c2,"1/#gamma_{R+1} #geq"+gaminvR_c2, "p");
	leg->AddEntry(shatR_h_eff_tr1_c1,"1/#gamma_{R+1} #geq"+gaminvR_c1, "p");
        leg->Draw();


	TCanvas *c5 = new TCanvas("c5","Efficiency gaminvR");
	c5->Clear();
	gaminvR_h_eff_tr1 = (TEfficiency*) new TEfficiency(*gaminvR_h_num_tr1,*gaminvR_h_den_tr1);
//	gaminvR_h_eff_tr1->SetWeight(weight_1);
	gaminvR_h_eff_tr2 = (TEfficiency*) new TEfficiency(*gaminvR_h_num_tr2,*gaminvR_h_den_tr2);
//	gaminvR_h_eff_tr2->SetWeight(weight_2);
	gaminvR_h_eff_tr1->Add(*gaminvR_h_eff_tr2);
        gaminvR_h_eff_tr1->SetTitle("Efficiency; 1/#gamma_{R+1}; Efficiency");
	gaminvR_h_eff_tr1->Draw();






	raz_var_h_eff_tr1 = (TEfficiency*) new TEfficiency(*raz_var_h_tr1_passed, *raz_var_h_tr1_total);

/*	TCanvas *c7 = new TCanvas("c7","tree 1");
	c7->Clear();
	raz_var_h_eff_tr1->Draw("colz");
*/

//	raz_var_h_eff_tr1->SetWeight(weight_1);


	raz_var_h_eff_tr2 = (TEfficiency*) new TEfficiency(*raz_var_h_tr2_passed, *raz_var_h_tr2_total);

/*	TCanvas *c8 = new TCanvas("c8", "tree2");
	c8->Clear();
	raz_var_h_eff_tr2->Draw("colz");
*/
//	raz_var_h_eff_tr2->SetWeight(weight_2);

	TCanvas *c6 = new TCanvas("c6","Efficiency Raz Var");
       	c6->Clear();

	raz_var_h_eff_tr1->Add(*raz_var_h_eff_tr2);
      	raz_var_h_eff_tr1->Draw("colz");
	raz_var_h_eff_tr1->SetTitle("Efficiency; #sqrt{#hat{s}_{R}}[GeV]; 1/#gamma_{R+1}; Efficiency");


/*
	TH2D *eff_fit_h = new TH2D ("eff_fit_h","eff", 60, 0, 30, 50, 0, 50);

	for(Int_t x = 0; x < 60 ; x++){

		for(Int_t y = 0; y < 50 ; y++){
			Int_t global_bin = raz_var_h_eff_tr1->GetGlobalBin(x,y);
			Double_t eff_bin = raz_var_h_eff_tr1->GetEfficiency(global_bin);
			eff_fit_h->Fill(x,y,eff_bin);
		}
	}

*/



	TF2 *f2 = new TF2("f2",prodr_funct,0,3000,0,1,2);
	f2->SetParameters(off_c_1,off_c_2);
	f2->SetLineColor(kBlack);
	f2->SetLineWidth(4);
	f2->SetContour(1);
	f2->SetContourLevel(0,off_prodr);

//	eff_fit_h->Fit("f2");

	f2->Draw("same");

        leg = new TLegend(0.68,0.80,0.84,0.9);
        leg->SetTextSize(0.03);
        leg->AddEntry(f2,"#bar{#Pi}="+off_prodr_s+"GeV","l");
        leg->Draw();


	// Output text file
	// Writing text

	outputfile << " n_shatR : " << n_shatR <<
	"\n n_cosptR : " << n_cosptR <<
	"\n n_mdeltaR : " << n_mdeltaR <<
	"\n n_gaminvR : " << n_gaminvR <<
	"\n n_dphivbR : " << n_dphivbR <<
	"\n n_ptcm : " << n_ptcm << "\n" <<
	"\n n_razor : " << n_razor <<
	" \n " <<
	"\n number of events for triggers : " <<
	"\n number of events that passes the hyperbolic cut : " << n_o_e_prodr << ", percentage in all events(without the jet restriction) : " << n_o_e_prodr/number_of_events  <<
	"\n " <<
	"\n t1 : n_o_e_prodr_2J15_XE55 : " << n_o_e_prodr_2J15_XE55 <<
        "\n t1 : n_noprodr_2J15_XE55 : " << n_t1_noprodr << ", %" << per_n_t1_noprodr <<
	"\n" <<
	"\n t2 : n_o_e_xe100_XE70 : " << n_o_e_xe100_XE70 <<
        "\n t3 : n_o_e_prodr_XE70 : " << n_o_e_prodr_XE70 <<
        "\n t3 : n_noprodr_XE70 : " << n_t3_noprodr << ", %" << per_n_t3_noprodr <<
	"\n t4 : n_o_e_xe100_XE70_or_prodr_2J15_XE55 : " << n_o_e_xe100_XE70_or_prodr_2J15_XE55 <<
	"\n t5 : n_o_e_xe100_XE70_or_prodr_XE70 : " << n_o_e_xe100_XE70_or_prodr_XE70 <<
	"\n " <<
	"\n efficiency (xe100_XE70) : " << eff_xe <<
	"\n efficiency  (xe100_XE70 OR ProdR_2J15_XE55) : " << eff_or_1 <<
	"\n efficiency (xe100_XE70 OR ProdR_XE70) : " << eff_or_2 <<
	"\n efficiency (ProdR_2J15_XE55 OR ProdR_XE70) : " << eff_or_3 <<
	"\n efficiency (xe100_XE70 OR ProdR_2J15_XE55 OR ProdR_XE70) : " << eff_or_4 <<
        //Plateau
        "\n PLATEAU" <<
        "\n efficiency (xe100_XE70) : " << eff_xe_off <<
        "\n efficiency  (xe100_XE70 OR ProdR_2J15_XE55) : " << eff_or_1_off <<
        "\n efficiency (xe100_XE70 OR ProdR_XE70) : " << eff_or_2_off <<
        "\n efficiency (ProdR_2J15_XE55 OR ProdR_XE70) : " << eff_or_3_off <<
        "\n efficiency (xe100_XE70 OR ProdR_2J15_XE55 OR ProdR_XE70) : " << eff_or_4_off <<
        endl;





        TFile* efficiency_turnon_output= new TFile (output_directory+"/"+output_file_name+c_prodr+"eff_turnon.root" ,"recreate");

	xe_pt_h_eff_tr1->Write();
 	shatR_h_eff_tr1->Write();
	gaminvR_h_eff_tr1->Write();
	raz_var_h_eff_tr1->Write();


        c3->SaveAs(output_directory+"/"+output_file_name+c_prodr+"_xe_pt_eff_3.pdf");
        c3->Close();
        c4->SaveAs(output_directory+"/"+output_file_name+c_prodr+"_shatr_eff_2.pdf");
        c4->Close();
        c5->SaveAs(output_directory+"/"+output_file_name+c_prodr+"_gaminvr_eff_2.pdf");
        c5->Close();
        c6->SaveAs(output_directory+"/"+output_file_name+c_prodr+"_raz_var_2d_eff_2.pdf");
        c6->Close();

        efficiency_turnon_output->Close();

	xe_pt_h_den_tr1       ->Delete();
	xe_pt_h_num_tr1       ->Delete();
	xe_pt_h_den_tr2       ->Delete();
	xe_pt_h_num_tr2       ->Delete();

	shatR_h_den_tr1       ->Delete();
	shatR_h_num_tr1       ->Delete();
	shatR_h_den_tr2       ->Delete();
	shatR_h_num_tr2       ->Delete();
	gaminvR_h_den_tr1     ->Delete();
	gaminvR_h_num_tr1     ->Delete();
	gaminvR_h_den_tr2     ->Delete();
	gaminvR_h_num_tr2     ->Delete();
	raz_var_h_tr1_total   ->Delete();
	raz_var_h_tr1_passed  ->Delete();
	raz_var_h_tr2_total   ->Delete();
	raz_var_h_tr2_passed  ->Delete();
	raz_var_efficiency_h  ->Delete();
	shatR_h_den_tr1_c1    ->Delete();
	shatR_h_num_tr1_c1    ->Delete();
	shatR_h_den_tr2_c1    ->Delete();
	shatR_h_num_tr2_c1    ->Delete();
	shatR_h_den_tr1_c2    ->Delete();
	shatR_h_num_tr1_c2    ->Delete();
	shatR_h_den_tr2_c2    ->Delete();
	shatR_h_num_tr2_c2    ->Delete();
	shatR_h_den_tr1_c3    ->Delete();
	shatR_h_num_tr1_c3    ->Delete();
	shatR_h_den_tr2_c3    ->Delete();
	shatR_h_num_tr2_c3    ->Delete();
	shatR_h_den_tr1_c4    ->Delete();
	shatR_h_num_tr1_c4    ->Delete();
	shatR_h_den_tr2_c4    ->Delete();
	shatR_h_num_tr2_c4    ->Delete();

	xe_pt_h_eff_tr1     ->Delete();
	xe_pt_h_eff_tr2     ->Delete();
	shatR_h_eff_tr1     ->Delete();
	shatR_h_eff_tr2     ->Delete();
	shatR_h_eff_tr1_c1  ->Delete();
	shatR_h_eff_tr1_c2  ->Delete();
	shatR_h_eff_tr1_c3  ->Delete();
	shatR_h_eff_tr1_c4  ->Delete();
	shatR_h_eff_tr2_c1  ->Delete();
	shatR_h_eff_tr2_c2  ->Delete();
	shatR_h_eff_tr2_c3  ->Delete();
	shatR_h_eff_tr2_c4  ->Delete();
	gaminvR_h_eff_tr1   ->Delete();
	gaminvR_h_eff_tr2   ->Delete();
	raz_var_h_eff_tr1   ->Delete();
	raz_var_h_eff_tr2   ->Delete();


	return efficiencies;
}

Double_t prodr_funct(Double_t *x, Double_t *par){

	return (x[0] + par[0] )*( x[1] + par[1]);

}
