#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLatex.h>
#include <TTree.h>
#include <vector>
#include "common_plotting_functions.hh"


//#include <TString.h>
//#include <iostream>
//#include <iomanip>


//JETs : not trigger but only pt cuts
//JET : L1


// mytree_1 : QCUT80
// mytree_2 : QCUT300

vector<Float_t> trigger_efficiency_comb(TString c_prodr, Float_t prodr, Float_t c_1, Float_t c_2, TString file_directory , TString input_file_name_1, TString input_file_name_2, TString output_directory , TString output_file_name, Float_t cross_sect1, Float_t cross_sect2){



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

	static const int n_t=3;
	static const int n_t_noprodr=2;

	if(prodr == 200) { TString triggernames[n_t] = { "ProdR200_2J15_XE55","xe100_XE70","ProdR200_XE70"};
	}

	if(prodr == 170){ TString triggernames[n_t] = { "ProdR170_2J15_XE55","xe100_XE70","ProdR170_XE70"};
	}


	TString triggernames_norazor[n_t_noprodr] = { "2J15_XE55","XE70"};

	int flag_prodr_t[n_t]={0};

	// Razor and L1

	// Trigger branch variables, booleans
	Bool_t b_2J15_XE55=0; //t1
	Bool_t b_XE70 = 0; //t3
	// L2 included
	Bool_t b_xe100_XE70=0; //t2


	Float_t n_o_e_prodr = 0;
	Float_t n_o_e_prodr_2J15_XE55 =0;
	Float_t n_o_e_prodr_XE70 = 0;

	Float_t n_t1_noprodr = 0;
	Float_t n_t3_noprodr = 0;

	//No razor
	Float_t n_o_e_xe100_XE70 = 0;

	// OR combination of the triggers

	Float_t n_o_e_xe100_XE70_or_prodr_2J15_XE55=0;
	Float_t n_o_e_xe100_XE70_or_prodr_XE70=0;
	int flag_OR_1 = 0;
	int flag_OR_2 = 0;


	// Open file1 QCUT80
	TFile *razor_file_1 = TFile::Open(file_directory+"/"+input_file_name_1);
    	if(razor_file_1==0) {
                cout << "Couldn't open the root file" << endl;
                return;
        }


	// Get the tree 1 branches
	TTree* mytree_1 = (TTree*)razor_file_1->Get("physics");
	number_of_events_1 = mytree_1->GetEntries();
	outputfile << " number of events tree 1 : " << number_of_events_1 << endl;


	// Open file 2 QCUT300
      	TFile *razor_file_2 = TFile::Open(file_directory+"/"+input_file_name_2);
       	if(razor_file_2==0) {
        	cout << "Couldn't open the root file" << endl;
                return;
        }

        // Get the tree 2 branches
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

			weight = weight_1;
			number_of_events_cur = number_of_events_1;

		}

		if(tr == 1) {

                	mytree_2->SetBranchStatus("*",1);

			currenttree = mytree_2->CloneTree();
			if(currenttree!=0) cout << "Cloned second tree" << endl;

			weight = weight_2;
			number_of_events_cur = number_of_events_2;

		}


		currenttree->SetBranchAddress("shatR",&shatR);
		currenttree->SetBranchAddress("gaminvR",&gaminvR);
	//	currenttree->SetBranchAddress("Prod" , &Prod);
		currenttree->SetBranchAddress("LeadPt",&LeadPt);

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
			flag_OR_1 = 0;
			flag_OR_2 = 0;

			currenttree->GetEntry(i); // the object event has been filled at this point

			if(tr == 0)  {if(LeadPt>350000) continue;}
			if(tr == 1)  {if(LeadPt<=350000) continue;}


			//Check the number of events with each razor variable defined
			if(shatR>0) {n_shatR++;}
			if(cosptR>0) {n_cosptR++;}
			if(mdeltaR>0) {n_mdeltaR++;}
			if(gaminvR>0) {n_gaminvR++;}
			if(dphivbR>0) {n_dphivbR++;}
			if(ptcm>0) {n_ptcm++;}

			value = (shatR/1000 + c_1) * (gaminvR/1000+c_2);
		//	value = Prod;

			if (value >= prodr) {n_o_e_prodr = n_o_e_prodr + weight;}


			//Fill the values, flags

			if(shatR>0 && gaminvR>0) {
				n_razor = n_razor + weight;
			}

			if(shatR>0 && gaminvR>0 && value<prodr) {

				if(b_2J15_XE55==1) n_t1_noprodr = n_t1_noprodr + weight;
				if(b_XE70==1) n_t3_noprodr = n_t3_noprodr + weight;

			}


			if(value>=prodr) {
				// t1
				if(b_2J15_XE55==1){
					flag_prodr_t[0]=1;
					n_o_e_prodr_2J15_XE55 = n_o_e_prodr_2J15_XE55 + weight;
				}

				//t3
				if(b_XE70==1){
					flag_prodr_t[2]=1;
					n_o_e_prodr_XE70 = n_o_e_prodr_XE70 + weight;
				}

			}


			//t2
			if(b_xe100_XE70==1){
				flag_prodr_t[1]=1;
				n_o_e_xe100_XE70 = n_o_e_xe100_XE70 + weight;
			}



			// t1 OR t2

			if(flag_prodr_t[0]==1 || flag_prodr_t[1]==1){

				flag_OR_1 = 1;
				n_o_e_xe100_XE70_or_prodr_2J15_XE55 = n_o_e_xe100_XE70_or_prodr_2J15_XE55 + weight;

			}


			//t3 OR t2

			if(flag_prodr_t[2]==1 || flag_prodr_t[1]==1){

				flag_OR_2 = 1;
				n_o_e_xe100_XE70_or_prodr_XE70 =  n_o_e_xe100_XE70_or_prodr_XE70 + weight;

			}


		number_of_events = number_of_events + weight;

		} //end event loop

		if(tr == 0) {razor_file_1->Close();}

		if(tr == 1) {razor_file_2->Close();}

		delete newfile;
		cout << "end event loop" << endl;


	} // end the 2 trees loop


	Float_t per_n_t1_noprodr = 100 * n_t1_noprodr / n_razor ;
	Float_t eff_or_1 = n_o_e_xe100_XE70_or_prodr_2J15_XE55/number_of_events ;

	Float_t per_n_t3_noprodr = 100*  n_t3_noprodr / n_razor ;
	Float_t eff_or_2 =  n_o_e_xe100_XE70_or_prodr_XE70/number_of_events;

	Float_t eff_xe = n_o_e_xe100_XE70/number_of_events;


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
	"\n number of events (combined,weighted)" <<number_of_events <<
	"\n number of events for triggers : " <<
	"\n number of events that passes the hyperbolic cut : " << n_o_e_prodr <<
	"\n t1 : n_o_e_prodr_2J15_XE55 : " << n_o_e_prodr_2J15_XE55 <<
        "\n t1 : n_noprodr_2J15_XE55 : " << n_t1_noprodr << ", %" << per_n_t1_noprodr <<
	"\n" <<
	"\n t2 : n_o_e_xe100_XE70 : " << n_o_e_xe100_XE70 <<
        "\n t3 : n_o_e_prodr_XE70 : " << n_o_e_prodr_XE70 <<
        "\n t3 : n_noprodr_XE70 : " << n_t3_noprodr << ", %" << per_n_t3_noprodr <<
	"\n t4 : n_o_e_xe100_XE70_or_prodr_2J15_XE55 : " << n_o_e_xe100_XE70_or_prodr_2J15_XE55 <<
	"\n t5 : n_o_e_xe100_XE70_or_prodr_XE70 : " << n_o_e_xe100_XE70_or_prodr_XE70 <<
	"\n efficiency  (xe100_XE70 OR ProdR_2J15_XE55) : " << eff_or_1 <<
	"\n efficiency (xe100_XE70 OR ProdR_XE70) : " << eff_or_2 <<
	"\n efficiency (xe100_XE70) : " << eff_xe <<
	endl;


	efficiencies.push_back(eff_xe) ;
	efficiencies.push_back(eff_or_1);
	efficiencies.push_back(eff_or_2);

	return efficiencies;
}


