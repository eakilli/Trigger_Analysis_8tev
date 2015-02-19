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


using namespace std;
void all_xe_turn_on_comb(){


	TString dirname_1 = "/atlas/data2/userdata/eakilli/razor_output/New_grid";
	TString dirname_2 = "/atlas/data2/userdata/eakilli/razor_output/New_grid_axial";

//	Int_t ece_counter = 0;

	xe_pt_h_eff_tr_only = (TEfficiency*) new TEfficiency("xe_pt_h_eff_tr_only","Eff xe_pt_only",40, 50, 250);



       	xe_pt_h_eff_tr_only->SetStatisticOption(1);


	xe_pt_h_eff_tr_only->SetUseWeightedEvents();

       static const int n_t=3;
        static const int n_t_noprodr=2;



	// Define weights and number of events for the seperate trees and the trees loop
	Float_t weight_1 = 0;
	Float_t weight_2 = 0;
	Float_t weight = 0;

        Float_t number_of_events_1 = 0;
        Float_t number_of_events_2 = 0;
	Float_t number_of_events_cur = 0;

        Float_t number_of_events = 0; // total, weighted after the combination

	Float_t value = 0; // calculated value for hyperbolic cut


	vector<Float_t> efficiencies(0);
	Float_t value = 0;

	Float_t n_razor = 0;

	Float_t shatR=0; Long64_t n_shatR=0;
	Float_t cosptR=0; Long64_t n_cosptR=0;
	Float_t mdeltaR=0; Long64_t n_mdeltaR=0;
	Float_t gaminvR=0; Long64_t n_gaminvR=0;
	Float_t dphivbR=0; Long64_t n_dphivbR=0;
	Float_t ptcm=0; Long64_t n_ptcm=0;
	Float_t Prod=0;

	Float_t LeadPt = 0;

	Float_t xe_pt = 0;


	int flag_prodr_t[n_t]={0};


	// Razor and L1

	Bool_t b_xe100_XE70=0; //t2


	//No razor
	Float_t n_o_e_xe100_XE70 = 0;


	vector<Float_t> vect_met(0);
	vector<Float_t> vect_n_met(0);
	vector<Float_t> vect_n_met_passtrigger(0);
	vector<Float_t> eff_met(0);

//begin parsedir


	TString dirname;
	TString output_directory = "/atlas/data2/userdata/eakilli/razor_output/Output_efficiency_directory" ;

	vector<Float_t> efficiency_170(0);

	Float_t cross_sect1 = 0;
	Float_t cross_sect2 = 0;

	Int_t flag_comb = 0;

	int ece = 0;

	TString output_file_name_efficiency;
	TString input_file_name;
	TString output_file_name;



for(Int_t mul_dir= 0; mul_dir<2;mul_dir++){



	if(mul_dir==0) dirname = dirname_1;
	if(mul_dir==1) dirname = dirname_2;

	cout << "Operating in " << dirname << endl;

	TString file_directory = dirname;

	TSystemDirectory dir(dirname, dirname);
	TList *files = dir.GetListOfFiles();



	if (files) {

		cout << "Found files." << endl;

		TSystemFile *file ;

		TString input_file_name_1; //qcut80
		TString input_file_name_2; //qcut300


		TIter next(files);

		while ((file=(TSystemFile*)next())) {

			input_file_name = file->GetName();

			flag_comb = 0;
			cross_sect1 = 0;
			cross_sect2 = 0;


				if ( (input_file_name.EndsWith("dmv_dm50_mm50_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
					cross_sect1 = 9.7111E-02;
					cross_sect2 = 1.5375E-03;
					flag_comb++;
				}
				if ( (input_file_name.EndsWith("dmv_dm50_mm100_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
					cross_sect1 = 2.9907E-01;
					cross_sect2 = 3.8267E-03;
					flag_comb++;
				}
				if ( (input_file_name.EndsWith("dmv_dm50_mm300_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
					cross_sect1 = 7.1889E-02;
					cross_sect2 = 2.2939E-03;
					flag_comb++;
				}

				if ( (input_file_name.EndsWith("dmv_dm50_mm600_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
					cross_sect1 = 9.4679E-03;
					cross_sect2 = 5.5195E-04;
					flag_comb++;
				}
				if ( (input_file_name.EndsWith("dmv_dm50_mm1000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
					cross_sect1 = 1.4869E-03;
					cross_sect2 = 1.1363E-04;
					flag_comb++;
				}
				if ( (input_file_name.EndsWith("dmv_dm50_mm3000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
					cross_sect1 = 8.7935E-06;
					cross_sect2 = 6.9580E-07;
					flag_comb++;
				}
				if ( (input_file_name.EndsWith("dmv_dm50_mm6000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
					cross_sect1 = 4.3139E-07;
					cross_sect2 = 3.0427E-08;
					flag_comb++;
				}
				if ( (input_file_name.EndsWith("dmv_dm50_mm10000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
					cross_sect1 = 5.3874E-08;
					cross_sect2 = 3.7327E-09;
					flag_comb++;
				}
				if ( (input_file_name.EndsWith("dmv_dm50_mm30000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
					cross_sect1 = 6.5714E-10;
					cross_sect2 = 4.5056E-11;
					flag_comb++;
				}
				if ( (input_file_name.EndsWith("dmv_dm400_mm50_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
					cross_sect1 = 1.2034E-04;
					cross_sect2 = 1.0759E-05;
					flag_comb++;
				}
				if ( (input_file_name.EndsWith("dmv_dm400_mm100_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
					cross_sect1 = 1.2350E-04;
					cross_sect2 = 1.0920E-05;
					flag_comb++;
				}
				if ( (input_file_name.EndsWith("dmv_dm400_mm300_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
					cross_sect1 = 1.4860E-04;
					cross_sect2 = 1.2936E-05;
					flag_comb++;
				}
				if ( (input_file_name.EndsWith("dmv_dm400_mm600_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
					cross_sect1 = 3.0935E-04;
					cross_sect2 = 2.6166E-05;
					flag_comb++;
				}
				if ( (input_file_name.EndsWith("dmv_dm400_mm1000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
					cross_sect1 = 7.0620E-04;
					cross_sect2 = 6.3103E-05;
					flag_comb++;
				}
				if ( (input_file_name.EndsWith("dmv_dm400_mm3000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
					cross_sect1 = 4.4852E-06;
					cross_sect2 = 4.6517E-07;
					flag_comb++;
				}
				if ( (input_file_name.EndsWith("dmv_dm400_mm6000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
					cross_sect1 = 1.7366E-07;
					cross_sect2 = 1.6857E-08;
					flag_comb++;
				}
				if ( (input_file_name.EndsWith("dmv_dm400_mm10000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
					cross_sect1 = 2.0742E-08;
					cross_sect2 = 2.0086E-09;
					flag_comb++;
				}
				if ( (input_file_name.EndsWith("dmv_dm400_mm30000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
					cross_sect1 = 2.4684E-10;
					cross_sect2 = 2.3864E-11;
					flag_comb++;
				}





			if ( (input_file_name.EndsWith("dmv_dm50_mm50_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 9.6144E-02;
				cross_sect2 = 1.5224E-03;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dmv_dm50_mm100_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 1.2398E+00;
				cross_sect2 = 1.2518E-02;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dmv_dm50_mm300_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 7.1245E-01;
				cross_sect2 = 2.2210E-02;
				flag_comb++;
			}

			if ( (input_file_name.EndsWith("dmv_dm50_mm600_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 8.8637E-02;
				cross_sect2 = 5.5275E-03;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dmv_dm50_mm1000_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 1.2609E-02;
				cross_sect2 = 1.0859E-03;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dmv_dm50_mm3000_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 1.8145E-05;
				cross_sect2 = 1.7378E-06;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dmv_dm50_mm6000_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 4.7073E-07;
				cross_sect2 = 3.3860E-08;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dmv_dm50_mm10000_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 5.8283E-08;
				cross_sect2 = 4.1306E-09;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dmv_dm50_mm30000_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 7.0477E-10;
				cross_sect2 = 4.9768E-11;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dmv_dm400_mm50_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 1.2042E-04;
				cross_sect2 = 1.0754E-05;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dmv_dm400_mm100_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 1.2201E-04;
				cross_sect2 = 1.0929E-05;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dmv_dm400_mm300_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 1.4537E-04;
				cross_sect2 = 1.2850E-05;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dmv_dm400_mm600_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 3.1843E-04;
				cross_sect2 = 2.7656E-05;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dmv_dm400_mm1000_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 9.2579E-03;
				cross_sect2 = 8.1472E-04;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dmv_dm400_mm3000_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 1.3376E-05;
				cross_sect2 = 1.4767E-06;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dmv_dm400_mm6000_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 1.8881E-07;
				cross_sect2 = 1.8932E-08;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dmv_dm400_mm10000_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 2.2234E-08;
				cross_sect2 = 2.2245E-09;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dmv_dm400_mm30000_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 2.6534E-10;
				cross_sect2 = 2.6414E-11;
				flag_comb++;
			}




			if ( (input_file_name.EndsWith("dma_dm50_mm50_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 4.2185E-02;
				cross_sect2 = 8.5520E-04;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dma_dm50_mm100_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 9.3229E-02;
				cross_sect2 = 1.5222E-03;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dma_dm50_mm300_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 5.9043E-02;
				cross_sect2 = 1.9425E-03;
				flag_comb++;
			}

			if ( (input_file_name.EndsWith("dma_dm50_mm600_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 8.8116E-03;
				cross_sect2 = 5.2282E-04;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dma_dm400_mm50_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 3.5215E-05;
				cross_sect2 = 3.3535E-06;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dma_dm400_mm100_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 3.5220E-05;
				cross_sect2 = 3.3552E-06;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dma_dm400_mm300_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 4.2157E-05;
				cross_sect2 = 3.8423E-06;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dma_dm400_mm600_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 7.2973E-05;
				cross_sect2 = 6.5962E-06;
				flag_comb++;
			}




			if ( (input_file_name.EndsWith("dma_dm50_mm50_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 4.1717E-02;
				cross_sect2 = 8.4859E-04;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dma_dm50_mm100_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 1.4820E-01;
				cross_sect2 = 2.0674E-03;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dma_dm50_mm300_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 5.9839E-01;
				cross_sect2 = 1.8850E-02;
				flag_comb++;
			}

			if ( (input_file_name.EndsWith("dma_dm50_mm600_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 8.4463E-02;
				cross_sect2 = 5.3156E-03;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dma_dm400_mm50_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 3.5488E-05;
				cross_sect2 = 3.3520E-06;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dma_dm400_mm100_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 3.5351E-05;
				cross_sect2 = 3.3685E-06;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dma_dm400_mm300_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 4.0287E-05;
				cross_sect2 = 3.8236E-06;
				flag_comb++;
			}
			if ( (input_file_name.EndsWith("dma_dm400_mm600_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 7.3279E-05;
				cross_sect2 = 6.7523E-06;
				flag_comb++;
			}




			if( flag_comb == 1 ) {

				cout << "Attempting to tamper with file " << input_file_name << endl;

				// Input file names (to be combined)
				TString temp_input_file_name_0 = input_file_name;
				input_file_name_1 = temp_input_file_name_0;
				Ssiz_t pos_0 = temp_input_file_name_0.Index("qcut80_razor.root");
				input_file_name_2 = temp_input_file_name_0.Remove(pos_0)+"qcut300_razor.root";

				cout << "Attempting to tamper with files " << input_file_name_1 << "," <<  input_file_name_2  << endl ;

				// EFFICIENCY

				//Output file efficiency
	                	TString temp_input_file_name_efficiency = input_file_name;
	                	Ssiz_t pos_efficiency = temp_input_file_name_efficiency.Index("qcut80_razor.root");
		            	output_file_name_efficiency = temp_input_file_name_efficiency.Remove(pos_efficiency)+"efficiency_output_";
	                	output_file_name_efficiency = temp_input_file_name_efficiency.Remove(0,12);


				weight_1 = cross_sect1;
				weight_2 = cross_sect2;



				// Open file1 QCUT80
				TFile *razor_file_1 = TFile::Open(file_directory+"/"+input_file_name_1);
			    	if(razor_file_1==0) {
			                cout << "Couldn't open the root file" << endl;
			                return;
			        }


				// Get the tree 1

				TTree* mytree_1 = (TTree*)razor_file_1->Get("physics");
				number_of_events_1 = mytree_1->GetEntries();

				// Open file 2 QCUT300

			     	TFile *razor_file_2 = TFile::Open(file_directory+"/"+input_file_name_2);
			       	if(razor_file_2==0) {
			        	cout << "Couldn't open the root file" << endl;
			                return;
			        }


				// Get the tree 2

			        TTree* mytree_2 = (TTree*)razor_file_2->Get("physics");
			        number_of_events_2 = mytree_2->GetEntries();


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

							currenttree->SetBranchAddress("xe100_XE70",&b_xe100_XE70);

							//Tree event loop
							for (Long64_t i=0; i<number_of_events_cur; i++) {

								//Clear flags
								for (int j = 0; j<n_t; j++) {
									flag_prodr_t[j] = 0;
								}
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




								//Fill the values, flags

								if(shatR>0 && gaminvR>0) {
									n_razor = n_razor + weight;
								}


								//t2 (only met, no jet,no razor)
								if(b_xe100_XE70==1){
									flag_prodr_t[1]=1; //actually it is not a flag_prodr_t, only met
									n_o_e_xe100_XE70 = n_o_e_xe100_XE70 + weight;
					//                             	if (flag_xe_off == 1 ) { flag_prodr_t_off[1]=1; n_o_e_xe100_XE70_off = n_o_e_xe100_XE70_off  + weight; }
								}



								// Turn on : MET

								// Turn-on : without trigger

								if(shatR<=0 && gaminvR <= 0  ){
								xe_pt_h_eff_tr_only->FillWeighted(flag_prodr_t[1]==1 , weight, xe_pt/1000);
								}


								number_of_events = number_of_events + weight;

							} //end event loop


							if(tr == 0) {razor_file_1->Close();}

							if(tr == 1) {razor_file_2->Close();}

							delete newfile;
							cout << "end event loop : "<< tr << endl;


						} // end the 2 trees loop



				}
			}

		}

		else cout << "No files in " <<   <<endl;


}
// end parsedir


		Float_t eff_xe = n_o_e_xe100_XE70/number_of_events;


		efficiencies.push_back(eff_xe) ;

		setstyle();


		TCanvas *c3 = new TCanvas ("c3","Efficiency ET miss");
		c3->Clear();
		gPad->SetGrid();

	        xe_pt_h_eff_tr_only->SetMarkerColor(kBlue);
	        xe_pt_h_eff_tr_only->SetLineColor(kBlue);
	        xe_pt_h_eff_tr_only->SetTitle("Efficiency ; E_{T}^{miss} [GeV] ; Efficiency");
		xe_pt_h_eff_tr_only->Draw();



	        c3->SaveAs(output_directory+"/all_w3_xe_pt_eff_OR1_only.pdf");
	        c3->Close();


}




