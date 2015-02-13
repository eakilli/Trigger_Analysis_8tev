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
vector<Float_t> all_trigger_turn_on_comb(TString c_prodr, Float_t prodr, Float_t c_1, Float_t c_2){


	TString dirname_1 = "/atlas/data2/userdata/eakilli/razor_output/New_grid";
	TString dirname_2 = "/atlas/data2/userdata/eakilli/razor_output/New_grid_axial";

//	Int_t ece_counter = 0;

	xe_pt_h_eff_tr = (TEfficiency*) new TEfficiency("xe_pt_h_eff_tr","Eff xe_pt",40, 50, 250);
	shatR_h_eff_tr =  (TEfficiency*) new TEfficiency ("shatR_h_eff_tr", "Eff shatr", 60, 0, 3000);
	gaminvR_h_eff_tr = (TEfficiency*) new TEfficiency ("gaminvR_h_eff_tr", "Eff gaminvr", 50, 0,1);
	raz_var_h_eff_tr =  (TEfficiency*) new TEfficiency("raz_var_h_eff_tr", "Eff 2d", 60, 0, 3000, 50, 0, 1);

	shatR_h_eff_tr_c1 = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c1","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c2 = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c2","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c3 = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c3","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c4 = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c4","Eff shatr , gaminvr", 60,0,3000);
    	shatR_h_eff_tr_c5 = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c5","Eff shatr , gaminvr", 60,0,3000);
    	shatR_h_eff_tr_c6 = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c6","Eff shatr , gaminvr", 60,0,3000);
        shatR_h_eff_tr_c7 = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c7","Eff shatr , gaminvr", 60,0,3000);
        shatR_h_eff_tr_c8 = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c8","Eff shatr , gaminvr", 60,0,3000);
        shatR_h_eff_tr_c9 = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c9","Eff shatr , gaminvr", 60,0,3000);
        shatR_h_eff_tr_c10 = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c10","Eff shatr , gaminvr", 60,0,3000);


	// 1 - Eff

	shatR_h_eff_tr_no =  (TEfficiency*) new TEfficiency ("shatR_h_eff_tr_no", "Eff shatr", 60, 0, 3000);
	gaminvR_h_eff_tr_no = (TEfficiency*) new TEfficiency ("gaminvR_h_eff_tr_no", "Eff gaminvr", 50, 0,1);
	raz_var_h_eff_tr_no =  (TEfficiency*) new TEfficiency("raz_var_h_eff_tr_no", "Eff 2d", 60, 0, 3000, 50 , 0, 1);


	shatR_h_eff_tr_c1_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c1_no","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c2_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c2_no","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c3_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c3_no","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c4_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c4_no","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c5_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c5_no","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c6_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c6_no","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c7_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c7_no","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c8_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c8_no","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c9_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c9_no","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c10_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c10_no","Eff shatr , gaminvr", 60,0,3000);


	shatR_h_eff_tr_c11_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c11_no","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c12_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c12_no","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c13_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c13_no","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c14_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c14_no","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c15_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c15_no","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c16_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c16_no","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c17_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c17_no","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c18_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c18_no","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c19_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c19_no","Eff shatr , gaminvr", 60,0,3000);
	shatR_h_eff_tr_c20_no = (TEfficiency*) new TEfficiency("shatR_h_eff_tr_c20_no","Eff shatr , gaminvr", 60,0,3000);


       	xe_pt_h_eff_tr->SetStatisticOption(1);
       	shatR_h_eff_tr     ->SetStatisticOption(1);
       	shatR_h_eff_tr_c1  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c2  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c3  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c4  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c5  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c6  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c7  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c8  ->SetStatisticOption(1);
       	gaminvR_h_eff_tr   ->SetStatisticOption(1);
       	raz_var_h_eff_tr   ->SetStatisticOption(1);
       	shatR_h_eff_tr_no     ->SetStatisticOption(1);
       	shatR_h_eff_tr_c1_no  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c2_no  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c3_no  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c4_no  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c5_no  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c6_no  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c7_no  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c8_no  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c9_no  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c10_no  ->SetStatisticOption(1);


       	shatR_h_eff_tr_c11_no  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c12_no  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c13_no  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c14_no  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c15_no  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c16_no  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c17_no  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c18_no  ->SetStatisticOption(1);
       	shatR_h_eff_tr_c19_no  ->SetStatisticOption(1);
      	shatR_h_eff_tr_c20_no  ->SetStatisticOption(1);



       	gaminvR_h_eff_tr_no ->SetStatisticOption(1);
      	raz_var_h_eff_tr_no ->SetStatisticOption(1);


	xe_pt_h_eff_tr->SetUseWeightedEvents();
        shatR_h_eff_tr->SetUseWeightedEvents();
        gaminvR_h_eff_tr->SetUseWeightedEvents();
        raz_var_h_eff_tr->SetUseWeightedEvents();

        shatR_h_eff_tr_c1->SetUseWeightedEvents();
        shatR_h_eff_tr_c2->SetUseWeightedEvents();
        shatR_h_eff_tr_c3->SetUseWeightedEvents();
        shatR_h_eff_tr_c4->SetUseWeightedEvents();
        shatR_h_eff_tr_c5->SetUseWeightedEvents();
        shatR_h_eff_tr_c6->SetUseWeightedEvents();
        shatR_h_eff_tr_c7->SetUseWeightedEvents();
        shatR_h_eff_tr_c8->SetUseWeightedEvents();
        shatR_h_eff_tr_c9->SetUseWeightedEvents();
        shatR_h_eff_tr_c10->SetUseWeightedEvents();


        shatR_h_eff_tr_no->SetUseWeightedEvents();
        gaminvR_h_eff_tr_no->SetUseWeightedEvents();
        raz_var_h_eff_tr_no->SetUseWeightedEvents();

        shatR_h_eff_tr_c1_no->SetUseWeightedEvents();
        shatR_h_eff_tr_c2_no->SetUseWeightedEvents();
        shatR_h_eff_tr_c3_no->SetUseWeightedEvents();
        shatR_h_eff_tr_c4_no->SetUseWeightedEvents();
        shatR_h_eff_tr_c5_no->SetUseWeightedEvents();
        shatR_h_eff_tr_c6_no->SetUseWeightedEvents();
        shatR_h_eff_tr_c7_no->SetUseWeightedEvents();
        shatR_h_eff_tr_c8_no->SetUseWeightedEvents();
        shatR_h_eff_tr_c9_no->SetUseWeightedEvents();
        shatR_h_eff_tr_c10_no->SetUseWeightedEvents();


        shatR_h_eff_tr_c11_no->SetUseWeightedEvents();
        shatR_h_eff_tr_c12_no->SetUseWeightedEvents();
        shatR_h_eff_tr_c13_no->SetUseWeightedEvents();
        shatR_h_eff_tr_c14_no->SetUseWeightedEvents();
        shatR_h_eff_tr_c15_no->SetUseWeightedEvents();
        shatR_h_eff_tr_c16_no->SetUseWeightedEvents();
        shatR_h_eff_tr_c17_no->SetUseWeightedEvents();
        shatR_h_eff_tr_c18_no->SetUseWeightedEvents();
        shatR_h_eff_tr_c19_no->SetUseWeightedEvents();
        shatR_h_eff_tr_c20_no->SetUseWeightedEvents();



	Float_t shatR_gaminvR_c1 = 800;
	Float_t shatR_gaminvR_c2 = 720;
	Float_t shatR_gaminvR_c3 = 640;
	Float_t shatR_gaminvR_c4 = 560;
	Float_t shatR_gaminvR_c5 = 480;
	Float_t shatR_gaminvR_c6 = 400;
	Float_t shatR_gaminvR_c7 = 320;
        Float_t shatR_gaminvR_c8 = 240;
        Float_t shatR_gaminvR_c9 = 160;
        Float_t shatR_gaminvR_c10 = 80;


	Float_t shatR_gaminvR_c11 = 760;
	Float_t shatR_gaminvR_c12 = 680;
	Float_t shatR_gaminvR_c13 = 600;
	Float_t shatR_gaminvR_c14 = 520;
	Float_t shatR_gaminvR_c15 = 440;
	Float_t shatR_gaminvR_c16 = 360;
	Float_t shatR_gaminvR_c17 = 280;
        Float_t shatR_gaminvR_c18 = 200;
        Float_t shatR_gaminvR_c19 = 120;
        Float_t shatR_gaminvR_c20 = 40;



	TString gaminvR_c1 = "0.8";
	TString gaminvR_c2 = "0.72";
 	TString gaminvR_c3 = "0.64";
	TString gaminvR_c4 = "0.56";
	TString gaminvR_c5 = "0.48";
	TString gaminvR_c6 = "0.40";
	TString gaminvR_c7 = "0.32";
        TString gaminvR_c8 = "0.24";
        TString gaminvR_c9 = "0.16";
        TString gaminvR_c10 = "0.88";

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

	static const int n_t=3;
	static const int n_t_noprodr=2;

	int flag_prodr_t[n_t]={0};
	//int flag_prodr_t_off[n_t]={0};


	// Razor and L1

	// Trigger branch variables, booleans
	Bool_t b_2J15_XE55=0; //t1
	Bool_t b_XE70 = 0; //t3
	// L2 included
	Bool_t b_xe100_XE70=0; //t2

	Float_t n_o_e_prodr = 0;
	Float_t n_o_e_prodr_2J15_XE55 =0;
	Float_t n_o_e_prodr_XE70 = 0;
//      Float_t n_o_e_prodr_2J15_XE55_off =0;
//      Float_t n_o_e_prodr_XE70_off = 0;


	Float_t n_t1_noprodr = 0;
	Float_t n_t3_noprodr = 0;

	//No razor
	Float_t n_o_e_xe100_XE70 = 0;
//     	Float_t n_o_e_xe100_XE70_off = 0;


	// OR combination of the triggers

	Float_t n_o_e_xe100_XE70_or_prodr_2J15_XE55=0;
	Float_t n_o_e_xe100_XE70_or_prodr_XE70=0;
       	Float_t n_o_e_prodr_2J15_XE55_or_prodr_XE70 = 0;
     	Float_t n_o_e_xe100_XE70_or_prodr_or3 = 0;

//	Float_t n_o_e_xe100_XE70_or_prodr_2J15_XE55_off=0;
//	Float_t n_o_e_xe100_XE70_or_prodr_XE70_off=0;
//     	Float_t n_o_e_prodr_2J15_XE55_or_prodr_XE70_off = 0;
//     	Float_t n_o_e_xe100_XE70_or_prodr_or3_off = 0;


	int flag_OR_1 = 0;
	int flag_OR_2 = 0;
	int flag_OR_3 = 0;
       	int flag_OR_4 = 0;


	int eff_off_criteria = 0;

//	int flag_OR_1_off = 0;
//	int flag_OR_2_off = 0;
//	int flag_OR_3_off = 0;
//     	int flag_OR_4_off = 0;


//      int flag_xe_off = 0;
//      int flag_prod_off = 0;


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




//	parseDir("/atlas/data2/userdata/eakilli/razor_output/New_grid*");

//begin parsedir


	TString dirname;
	TString output_directory = "/atlas/data2/userdata/eakilli/razor_output/Output_efficiency_directory" ;
	ofstream outputfile(output_directory+"/"+c_prodr+"_efficiency_outputfile_OR1.txt");

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


	outputfile<< " *** output messages file for : " << file_directory <<  " *** \n"<<
	"\n prodr : " << prodr <<
	"\n c_1 : " << c_1 <<
	"\n c_2 : " << c_2 <<
	endl;




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

//				trigger_turn_on_comb("170",170,200,0.0,  file_directory , input_file_name_1, input_file_name_2 ,cross_sect1,cross_sect2);


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
					//			for (int j = 0; j<n_t; j++) {
					//				flag_prodr_t_off[j] = 0;
					//			}

								flag_OR_1 = 0;
								flag_OR_2 = 0;
								flag_OR_3 = 0;
								flag_OR_4 = 0;


					/*			flag_OR_1_off = 0;
								flag_OR_2_off = 0;
								flag_OR_3_off = 0;
								flag_OR_4_off = 0;

					                     	flag_xe_off = 0;
					                     	flag_prod_off = 0;
					*/
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



					//                      	if( xe_pt/1000 >= off_xe) { flag_xe_off = 1;  }

					                    	value = (shatR/1000 + c_1) * (gaminvR/1000+c_2);
					                    	//      value = Prod;
					                    	if (value >= prodr) {n_o_e_prodr = n_o_e_prodr + weight;}
					//                   	off_value = (shatR/1000 + off_c_1 ) * (gaminvR/1000 + off_c_2);
					//                  	if(off_value >= off_prodr && shatR/1000 <= 3000 ) { flag_prod_off = 1; }



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
					//                              		if (flag_prod_off == 1 ) { flag_prodr_t_off[0]=1;  n_o_e_prodr_2J15_XE55_off =  n_o_e_prodr_2J15_XE55_off  + weight; }
									}


									//t3
									if(b_XE70==1){
										flag_prodr_t[2]=1;
										n_o_e_prodr_XE70 = n_o_e_prodr_XE70 + weight;
					 //                                    	if (flag_prod_off == 1 ) { flag_prodr_t_off[2]=1;  n_o_e_prodr_XE70_off = n_o_e_prodr_XE70_off  + weight; }

									}
								}


								//t2 (only met, no jet,no razor)
								if(b_xe100_XE70==1){
									flag_prodr_t[1]=1; //actually it is not a flag_prodr_t, only met
									n_o_e_xe100_XE70 = n_o_e_xe100_XE70 + weight;
					//                             	if (flag_xe_off == 1 ) { flag_prodr_t_off[1]=1; n_o_e_xe100_XE70_off = n_o_e_xe100_XE70_off  + weight; }

								}

//								cout << ece_counter++ << endl;


								// Triggers OR

								// t1 OR t2
								if(flag_prodr_t[0]==1 || flag_prodr_t[1]==1){
									flag_OR_1 = 1;
									n_o_e_xe100_XE70_or_prodr_2J15_XE55  = n_o_e_xe100_XE70_or_prodr_2J15_XE55 + weight;
								}


					/*                        if(flag_prodr_t_off[0] == 1 || flag_prodr_t_off[1]==1) {

					                                flag_OR_1_off = 1;
					                                n_o_e_xe100_XE70_or_prodr_2J15_XE55_off = n_o_e_xe100_XE70_or_prodr_2J15_XE55_off  + weight;


					                        }

					*/
								//t3 OR t2
								if(flag_prodr_t[2]==1 || flag_prodr_t[1]==1){
									flag_OR_2 = 1;
									n_o_e_xe100_XE70_or_prodr_XE70 = n_o_e_xe100_XE70_or_prodr_XE70 + weight;
								}



					/*                        if(flag_prodr_t_off[2]== 1 || flag_prodr_t_off[1]==1){
					                                flag_OR_2_off = 1;
					                                n_o_e_xe100_XE70_or_prodr_XE70_off = n_o_e_xe100_XE70_or_prodr_XE70_off  + weight;

					                        }

					*/


								// ProdR or : t1 or t3 : OR 3
								if( flag_prodr_t[0]==1 || flag_prodr_t[2]==1){
									flag_OR_3 = 1;
									n_o_e_prodr_2J15_XE55_or_prodr_XE70 = n_o_e_prodr_2J15_XE55_or_prodr_XE70 + weight;
								}


					/*                        if(flag_prodr_t_off[0] == 1 || flag_prodr_t_off[2] == 1){
					                                flag_OR_3_off =1;
					                                n_o_e_prodr_2J15_XE55_or_prodr_XE70_off  = n_o_e_prodr_2J15_XE55_or_prodr_XE70_off + weight;
					                        }

					*/

								// ProdR_or(flag_OR_3) OR met(t2) : OR 4
								if( flag_OR_3 ==1 || flag_prodr_t[1]==1){
									flag_OR_4 = 1;
									n_o_e_xe100_XE70_or_prodr_or3 = n_o_e_xe100_XE70_or_prodr_or3 + weight;
								}


					/*
					                        if(flag_OR_3_off == 1 || flag_prodr_t_off[1]==1){

					                                n_o_e_xe100_XE70_or_prodr_or3_off = n_o_e_xe100_XE70_or_prodr_or3_off  + weight;

					                        }

					*/
								// Turn on : MET

								// Turn-on : without trigger

								xe_pt_h_eff_tr->FillWeighted(flag_prodr_t[1]==1 , weight, xe_pt/1000);


								eff_off_criteria = flag_OR_1;

								// Turn on : RAZOR

								if(shatR>0 && gaminvR>0){

									// FILLING INTERVALS

									// Turn-on

									shatR_h_eff_tr->FillWeighted(eff_off_criteria, weight,shatR/1000 );
									gaminvR_h_eff_tr->FillWeighted(eff_off_criteria, weight,gaminvR/1000);
					                		raz_var_h_eff_tr->FillWeighted(eff_off_criteria, weight,shatR/1000, gaminvR/1000);

									if(gaminvR>=shatR_gaminvR_c1) shatR_h_eff_tr_c1->FillWeighted(eff_off_criteria, weight, shatR/1000);
									if(gaminvR>=shatR_gaminvR_c2) shatR_h_eff_tr_c2->FillWeighted(eff_off_criteria, weight, shatR/1000);
									if(gaminvR>=shatR_gaminvR_c3) shatR_h_eff_tr_c3->FillWeighted(eff_off_criteria, weight, shatR/1000);
									if(gaminvR>=shatR_gaminvR_c4) shatR_h_eff_tr_c4->FillWeighted(eff_off_criteria, weight, shatR/1000);
									if(gaminvR>=shatR_gaminvR_c5) shatR_h_eff_tr_c5->FillWeighted(eff_off_criteria, weight, shatR/1000);
									if(gaminvR>=shatR_gaminvR_c6) shatR_h_eff_tr_c6->FillWeighted(eff_off_criteria, weight, shatR/1000);
									if(gaminvR>=shatR_gaminvR_c7) shatR_h_eff_tr_c7->FillWeighted(eff_off_criteria, weight, shatR/1000);
									if(gaminvR>=shatR_gaminvR_c8) shatR_h_eff_tr_c8->FillWeighted(eff_off_criteria, weight, shatR/1000);
									if(gaminvR>=shatR_gaminvR_c9) shatR_h_eff_tr_c9->FillWeighted(eff_off_criteria, weight, shatR/1000);
									if(gaminvR>=shatR_gaminvR_c10) shatR_h_eff_tr_c10->FillWeighted(eff_off_criteria, weight, shatR/1000);


									// 1-Eff

									shatR_h_eff_tr_no->FillWeighted(eff_off_criteria==0, weight,shatR/1000 );
									gaminvR_h_eff_tr_no->FillWeighted(eff_off_criteria==0, weight,gaminvR/1000);
					                		raz_var_h_eff_tr_no->FillWeighted(eff_off_criteria==0, weight,shatR/1000, gaminvR/1000);

									if(gaminvR >= shatR_gaminvR_c1) shatR_h_eff_tr_c1_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);
									if(gaminvR >= shatR_gaminvR_c2) shatR_h_eff_tr_c2_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);
									if(gaminvR >= shatR_gaminvR_c3) shatR_h_eff_tr_c3_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);
									if(gaminvR >= shatR_gaminvR_c4) shatR_h_eff_tr_c4_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);
									if(gaminvR >= shatR_gaminvR_c5) shatR_h_eff_tr_c5_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);
									if(gaminvR >= shatR_gaminvR_c6) shatR_h_eff_tr_c6_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);
									if(gaminvR >= shatR_gaminvR_c7) shatR_h_eff_tr_c7_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);
									if(gaminvR >= shatR_gaminvR_c8) shatR_h_eff_tr_c8_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);
									if(gaminvR >= shatR_gaminvR_c9) shatR_h_eff_tr_c9_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);
									if(gaminvR >= shatR_gaminvR_c10) shatR_h_eff_tr_c10_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);


									if(gaminvR >= shatR_gaminvR_c11) shatR_h_eff_tr_c11_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);
									if(gaminvR >= shatR_gaminvR_c12) shatR_h_eff_tr_c12_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);
									if(gaminvR >= shatR_gaminvR_c13) shatR_h_eff_tr_c13_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);
									if(gaminvR >= shatR_gaminvR_c14) shatR_h_eff_tr_c14_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);
									if(gaminvR >= shatR_gaminvR_c15) shatR_h_eff_tr_c15_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);
									if(gaminvR >= shatR_gaminvR_c16) shatR_h_eff_tr_c16_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);
									if(gaminvR >= shatR_gaminvR_c17) shatR_h_eff_tr_c17_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);
									if(gaminvR >= shatR_gaminvR_c18) shatR_h_eff_tr_c18_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);
									if(gaminvR >= shatR_gaminvR_c19) shatR_h_eff_tr_c19_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);
									if(gaminvR >= shatR_gaminvR_c20) shatR_h_eff_tr_c20_no->FillWeighted(eff_off_criteria==0, weight, shatR/1000);


								} // end the RAZOR turn-on


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

		Float_t per_n_t1_noprodr = 100 * n_t1_noprodr / n_razor ;
		Float_t eff_or_1 = n_o_e_xe100_XE70_or_prodr_2J15_XE55/number_of_events ;

		Float_t per_n_t3_noprodr = 100*  n_t3_noprodr / n_razor ;
		Float_t eff_or_2 =  n_o_e_xe100_XE70_or_prodr_XE70/number_of_events;

		Float_t eff_or_3 =n_o_e_prodr_2J15_XE55_or_prodr_XE70/number_of_events;
		Float_t eff_or_4 =n_o_e_xe100_XE70_or_prodr_or3/number_of_events;


	/*
	        // Eff plateau
	        Float_t eff_xe_off = n_o_e_xe100_XE70_off/number_of_events;
	        Float_t eff_or_1_off = n_o_e_xe100_XE70_or_prodr_2J15_XE55_off/number_of_events ;
	        Float_t eff_or_2_off =  n_o_e_xe100_XE70_or_prodr_XE70_off/number_of_events;
	        Float_t eff_or_3_off =n_o_e_prodr_2J15_XE55_or_prodr_XE70_off/number_of_events;
	        Float_t eff_or_4_off =n_o_e_xe100_XE70_or_prodr_or3_off/number_of_events;
	*/

		efficiencies.push_back(eff_xe) ;
		efficiencies.push_back(eff_or_1);
		efficiencies.push_back(eff_or_2);
		efficiencies.push_back(eff_or_3);
		efficiencies.push_back(eff_or_4);
	/*       //Plateau
	        efficiencies.push_back(eff_xe_off) ;
	        efficiencies.push_back(eff_or_1_off);
	        efficiencies.push_back(eff_or_2_off);
	        efficiencies.push_back(eff_or_3_off);
	        efficiencies.push_back(eff_or_4_off);
	*/

		setstyle();


		// Efficiency turn-on plots

		TCanvas *c3 = new TCanvas ("c3","Efficiency ET miss");
		c3->Clear();
		gPad->SetGrid();

	        xe_pt_h_eff_tr->SetMarkerColor(kBlue);
	        xe_pt_h_eff_tr->SetLineColor(kBlue);
	        xe_pt_h_eff_tr->SetTitle("Efficiency ; E_{T}^{miss} [GeV] ; Efficiency");
		xe_pt_h_eff_tr->Draw();


		TCanvas *c4 = new TCanvas("c4","Efficiency shatR");
		c4->Clear();
		gPad->SetGrid();
		shatR_h_eff_tr->SetTitle("Efficiency ; #sqrt{#hat{s}_{R}}[GeV] ; Efficiency");
		shatR_h_eff_tr->Draw();



		shatR_h_eff_tr_c1->SetLineColor(2);
		shatR_h_eff_tr_c1->SetMarkerColor(2);
		shatR_h_eff_tr_c1->SetMarkerStyle(21);
		shatR_h_eff_tr_c1->Draw("same");

		shatR_h_eff_tr_c2->SetLineColor(3);
		shatR_h_eff_tr_c2->SetMarkerColor(3);
		shatR_h_eff_tr_c2->SetMarkerStyle(22);
		shatR_h_eff_tr_c2->Draw("same");

		shatR_h_eff_tr_c3->SetLineColor(4);
		shatR_h_eff_tr_c3->SetMarkerColor(4);
		shatR_h_eff_tr_c3->SetMarkerStyle(23);
		shatR_h_eff_tr_c3->Draw("same");

		shatR_h_eff_tr_c4->SetLineColor(6);
		shatR_h_eff_tr_c4->SetMarkerColor(6);
		shatR_h_eff_tr_c4->SetMarkerStyle(33);
		shatR_h_eff_tr_c4->Draw("same");

		shatR_h_eff_tr_c5->SetLineColor(7);
		shatR_h_eff_tr_c5->SetMarkerColor(7);
		shatR_h_eff_tr_c5->SetMarkerStyle(34);
		shatR_h_eff_tr_c5->Draw("same");


		shatR_h_eff_tr_c6->SetLineColor(8);
		shatR_h_eff_tr_c6->SetMarkerColor(8);
		shatR_h_eff_tr_c6->SetMarkerStyle(29);
		shatR_h_eff_tr_c6->Draw("same");



		shatR_h_eff_tr_c7->SetLineColor(9);
		shatR_h_eff_tr_c7->SetMarkerColor(9);
		shatR_h_eff_tr_c7->SetMarkerStyle(20);
		shatR_h_eff_tr_c7->Draw("same");

	/*
		shatR_h_eff_tr_c8->SetLineColor(11);
		shatR_h_eff_tr_c8->SetMarkerColor(11);
		shatR_h_eff_tr_c8->SetMarkerStyle(3);
		shatR_h_eff_tr_c8->Draw("same");

	*/

	    	leg = new TLegend(0.65,0.45,0.85,0.95);
	        leg->SetTextSize(0.02);
	        leg->AddEntry(shatR_h_eff_tr,"All 1/#gamma_{R+1}", "p");
	//	leg->AddEntry(shatR_h_eff_tr_c8,"1/#gamma_{R+1} #geq"+gaminvR_c8, "p");
		leg->AddEntry(shatR_h_eff_tr_c7,"1/#gamma_{R+1} #geq"+gaminvR_c7, "p");
		leg->AddEntry(shatR_h_eff_tr_c6,"1/#gamma_{R+1} #geq"+gaminvR_c6, "p");
		leg->AddEntry(shatR_h_eff_tr_c5,"1/#gamma_{R+1} #geq"+gaminvR_c5, "p");
		leg->AddEntry(shatR_h_eff_tr_c4,"1/#gamma_{R+1} #geq"+gaminvR_c4, "p");
		leg->AddEntry(shatR_h_eff_tr_c3,"1/#gamma_{R+1} #geq"+gaminvR_c3, "p");
		leg->AddEntry(shatR_h_eff_tr_c2,"1/#gamma_{R+1} #geq"+gaminvR_c2, "p");
		leg->AddEntry(shatR_h_eff_tr_c1,"1/#gamma_{R+1} #geq"+gaminvR_c1, "p");
	        leg->Draw();


		TCanvas *c5 = new TCanvas("c5","Efficiency gaminvR");
		c5->Clear();
		gPad->SetGrid();
		gaminvR_h_eff_tr->SetLineColor(kBlue);
		gaminvR_h_eff_tr->SetMarkerColor(kBlue);
	        gaminvR_h_eff_tr->SetTitle("Efficiency; 1/#gamma_{R+1}; Efficiency");
		gaminvR_h_eff_tr->Draw();



		// 1-Eff
		TCanvas *c7 = new TCanvas("c7","Efficiency shatR");
		c7->Clear();
		c7->SetLogy();
		gPad->SetGrid();
		shatR_h_eff_tr_no->SetTitle("1 - Efficiency ; #sqrt{#hat{s}_{R}}[GeV] ; 1 - Efficiency");
		shatR_h_eff_tr_no->Draw();



		shatR_h_eff_tr_c1_no->SetLineColor(2);
		shatR_h_eff_tr_c1_no->SetMarkerColor(2);
		shatR_h_eff_tr_c1_no->SetMarkerStyle(21);
		shatR_h_eff_tr_c1_no->Draw("same");

		shatR_h_eff_tr_c2_no->SetLineColor(3);
		shatR_h_eff_tr_c2_no->SetMarkerColor(3);
		shatR_h_eff_tr_c2_no->SetMarkerStyle(22);
		shatR_h_eff_tr_c2_no->Draw("same");

		shatR_h_eff_tr_c3_no->SetLineColor(4);
		shatR_h_eff_tr_c3_no->SetMarkerColor(4);
		shatR_h_eff_tr_c3_no->SetMarkerStyle(23);
		shatR_h_eff_tr_c3_no->Draw("same");

		shatR_h_eff_tr_c4_no->SetLineColor(6);
		shatR_h_eff_tr_c4_no->SetMarkerColor(6);
		shatR_h_eff_tr_c4_no->SetMarkerStyle(33);
		shatR_h_eff_tr_c4_no->Draw("same");



		shatR_h_eff_tr_c5_no->SetLineColor(7);
		shatR_h_eff_tr_c5_no->SetMarkerColor(7);
		shatR_h_eff_tr_c5_no->SetMarkerStyle(34);
		shatR_h_eff_tr_c5_no->Draw("same");


		shatR_h_eff_tr_c6_no->SetLineColor(8);
		shatR_h_eff_tr_c6_no->SetMarkerColor(8);
		shatR_h_eff_tr_c6_no->SetMarkerStyle(29);
		shatR_h_eff_tr_c6_no->Draw("same");

		shatR_h_eff_tr_c7_no->SetLineColor(9);
		shatR_h_eff_tr_c7_no->SetMarkerColor(9);
		shatR_h_eff_tr_c7_no->SetMarkerStyle(20);
		shatR_h_eff_tr_c7_no->Draw("same");

	/*	shatR_h_eff_tr_c8_no->SetLineColor(11);
		shatR_h_eff_tr_c8_no->SetMarkerColor(11);
		shatR_h_eff_tr_c8_no->SetMarkerStyle(3);
		shatR_h_eff_tr_c8_no->Draw("same");

	*/
	     	leg = new TLegend(0.63,0.41,0.83,0.90);
	        leg->SetTextSize(0.04);
	        leg->AddEntry(shatR_h_eff_tr,"All 1/#gamma_{R+1}", "p");
	//	leg->AddEntry(shatR_h_eff_tr_c8_no,"1/#gamma_{R+1} #geq"+gaminvR_c8, "p");
		leg->AddEntry(shatR_h_eff_tr_c7_no,"1/#gamma_{R+1} #geq"+gaminvR_c7, "p");
		leg->AddEntry(shatR_h_eff_tr_c6_no,"1/#gamma_{R+1} #geq"+gaminvR_c6, "p");
		leg->AddEntry(shatR_h_eff_tr_c5_no,"1/#gamma_{R+1} #geq"+gaminvR_c5, "p");
		leg->AddEntry(shatR_h_eff_tr_c4_no,"1/#gamma_{R+1} #geq"+gaminvR_c4, "p");
		leg->AddEntry(shatR_h_eff_tr_c3_no,"1/#gamma_{R+1} #geq"+gaminvR_c3, "p");
		leg->AddEntry(shatR_h_eff_tr_c2_no,"1/#gamma_{R+1} #geq"+gaminvR_c2, "p");
		leg->AddEntry(shatR_h_eff_tr_c1_no,"1/#gamma_{R+1} #geq"+gaminvR_c1, "p");
	        leg->Draw();



		TCanvas *canvas_1 = new TCanvas("canvas_1","parametrize");
		canvas_1->Clear();

		Double_t eff_bin = 0;
		Double_t eff_err_low = 0;
		vector<Float_t> x_axis_vect(0);
		vector<Float_t> y_axis_vect(0);
		Float_t x_ax = 0;
		Float_t hit_no_eff = 0.07;


	/*

	        for(Int_t x = 0; x < 60 ; x++){

			eff_bin = shatR_h_eff_tr_c20_no->GetEfficiency(x);
			eff_err_low = shatR_h_eff_tr_c20_no->GetEfficiencyErrorLow(x);

	            	if(eff_bin-eff_err_low <= hit_no_eff && eff_bin != 0) {
				x_ax = x * 50 + 25 ;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c20);
				break;
			}
	        }


	        for(Int_t x = 0; x < 60 ; x++){

			eff_bin = shatR_h_eff_tr_c19_no->GetEfficiency(x);
			eff_err_low = shatR_h_eff_tr_c19_no->GetEfficiencyErrorLow(x);

	            	if(eff_bin-eff_err_low <= hit_no_eff && eff_bin != 0) {
				x_ax = x * 50 + 25 ;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c19);
				break;
			}
	        }



	        for(Int_t x = 0; x < 60 ; x++){

			eff_bin = shatR_h_eff_tr_c18_no->GetEfficiency(x);
			eff_err_low = shatR_h_eff_tr_c18_no->GetEfficiencyErrorLow(x);

	            	if(eff_bin-eff_err_low <= hit_no_eff && eff_bin != 0) {
				x_ax = x * 50 + 25 ;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c18);
				break;
			}
	        }


	*/
	        for(Int_t x = 0; x < 60 ; x++){

			eff_bin = shatR_h_eff_tr_c17_no->GetEfficiency(x);
			eff_err_low = shatR_h_eff_tr_c17_no->GetEfficiencyErrorLow(x);

	//eff_err_low = 0;

	            	if(eff_bin-eff_err_low <= hit_no_eff && eff_bin != 0) {
				x_ax = x * 50 + 25 ;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c17);
				break;
			}
	        }



	        for(Int_t x = 0; x < 60 ; x++){

			eff_bin = shatR_h_eff_tr_c16_no->GetEfficiency(x);
			eff_err_low = shatR_h_eff_tr_c16_no->GetEfficiencyErrorLow(x);
	//eff_err_low = 0;
	            	if(eff_bin-eff_err_low <= hit_no_eff && eff_bin != 0) {
				x_ax = x * 50 + 25 ;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c16);
				break;
			}
	        }


	        for(Int_t x = 0; x < 60 ; x++){

			eff_bin = shatR_h_eff_tr_c15_no->GetEfficiency(x);
			eff_err_low = shatR_h_eff_tr_c15_no->GetEfficiencyErrorLow(x);
	//eff_err_low = 0;
	            	if(eff_bin-eff_err_low <= hit_no_eff && eff_bin != 0) {
				x_ax = x * 50 + 25 ;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c15);
				break;
			}
	        }



	        for(Int_t x = 0; x < 60 ; x++){

			eff_bin = shatR_h_eff_tr_c14_no->GetEfficiency(x);
			eff_err_low = shatR_h_eff_tr_c14_no->GetEfficiencyErrorLow(x);
	//eff_err_low = 0;
	            	if(eff_bin-eff_err_low <= hit_no_eff && eff_bin != 0) {
				x_ax = x * 50 + 25 ;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c14);
				break;
			}
	        }



	        for(Int_t x = 0; x < 60 ; x++){

			eff_bin = shatR_h_eff_tr_c13_no->GetEfficiency(x);
			eff_err_low = shatR_h_eff_tr_c13_no->GetEfficiencyErrorLow(x);
	//eff_err_low = 0;
	            	if(eff_bin-eff_err_low <= hit_no_eff && eff_bin != 0) {
				x_ax = x * 50 + 25 ;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c13);
				break;
			}
	        }


	        for(Int_t x = 0; x < 60 ; x++){

			eff_bin = shatR_h_eff_tr_c12_no->GetEfficiency(x);
			eff_err_low = shatR_h_eff_tr_c12_no->GetEfficiencyErrorLow(x);
	//eff_err_low = 0;
	            	if(eff_bin-eff_err_low <= hit_no_eff && eff_bin != 0) {
				x_ax = x * 50 + 25 ;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c12);
				break;
			}
	        }




	        for(Int_t x = 0; x < 60 ; x++){

			eff_bin = shatR_h_eff_tr_c11_no->GetEfficiency(x);
			eff_err_low = shatR_h_eff_tr_c11_no->GetEfficiencyErrorLow(x);
	//eff_err_low = 0;
	            	if(eff_bin-eff_err_low <= hit_no_eff && eff_bin != 0) {
				x_ax = x * 50 + 25 ;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c11);
				break;
			}
	        }



	/*

	        for(Int_t x = 0; x < 60 ; x++){

			eff_bin = shatR_h_eff_tr_c10_no->GetEfficiency(x);
			eff_err_low = shatR_h_eff_tr_c10_no->GetEfficiencyErrorLow(x);

	            	if(eff_bin-eff_err_low <= hit_no_eff && eff_bin != 0) {
				x_ax = x * 50 + 25 ;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c10);
				break;
			}
	        }


	        for(Int_t x = 0; x < 60 ; x++){

			eff_bin = shatR_h_eff_tr_c9_no->GetEfficiency(x);
			eff_err_low = shatR_h_eff_tr_c9_no->GetEfficiencyErrorLow(x);

	            	if(eff_bin-eff_err_low <= hit_no_eff && eff_bin != 0) {
				x_ax = x * 50 + 25 ;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c9);
				break;
			}
	        }



	        for(Int_t x = 0; x < 60 ; x++){

			eff_bin = shatR_h_eff_tr_c8_no->GetEfficiency(x);
			eff_err_low = shatR_h_eff_tr_c8_no->GetEfficiencyErrorLow(x);

	            	if(eff_bin-eff_err_low <= hit_no_eff && eff_bin != 0) {
				x_ax = x * 50 + 25;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c8);
				break;
			}
	        }

	*/
	        for(Int_t x = 0; x < 60 ; x++){

			eff_bin = shatR_h_eff_tr_c7_no->GetEfficiency(x);
			eff_err_low = shatR_h_eff_tr_c7_no->GetEfficiencyErrorLow(x);
	//eff_err_low = 0;
	            	if(eff_bin-eff_err_low <= hit_no_eff && eff_bin != 0) {
				x_ax = x * 50 + 25;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c7);
				break;
			}
	        }


	        for(Int_t x = 0; x < 60 ; x++){

			eff_bin = shatR_h_eff_tr_c6_no->GetEfficiency(x);
			eff_err_low = shatR_h_eff_tr_c6_no->GetEfficiencyErrorLow(x);
	//eff_err_low = 0;
	            	if(eff_bin-eff_err_low <= hit_no_eff && eff_bin != 0) {
				x_ax = x * 50 + 25;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c6);
				break;
			}
	        }


	        for(Int_t x = 0; x < 60 ; x++){

			eff_bin = shatR_h_eff_tr_c5_no->GetEfficiency(x);
			eff_err_low = shatR_h_eff_tr_c5_no->GetEfficiencyErrorLow(x);
	//eff_err_low = 0;
		      	if(eff_bin-eff_err_low  <= hit_no_eff && eff_bin!=0) {
				x_ax = x * 50 + 25;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c5);

				break;
			}
	        }


	        for(Int_t x = 0; x < 60 ; x++){

			eff_bin = shatR_h_eff_tr_c4_no->GetEfficiency(x);
	        	eff_err_low = shatR_h_eff_tr_c4_no->GetEfficiencyErrorLow(x);
	//eff_err_low = 0;

	    		if(eff_bin-eff_err_low <= hit_no_eff && eff_bin != 0) {
				x_ax = x * 50 + 25;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c4);

				break;
			}
	        }


	        for(Int_t x = 0; x < 60 ; x++){

			Double_t eff_bin = shatR_h_eff_tr_c3_no->GetEfficiency(x);
	        	eff_err_low = shatR_h_eff_tr_c3_no->GetEfficiencyErrorLow(x);
	//eff_err_low = 0;
	        	if(eff_bin-eff_err_low <= hit_no_eff && eff_bin != 0) {
				x_ax = x * 50 + 25;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c3);

				break;
			}
	        }


	        for(Int_t x = 0; x < 60 ; x++){

			Double_t eff_bin = shatR_h_eff_tr_c2_no->GetEfficiency(x);
	                eff_err_low = shatR_h_eff_tr_c2_no->GetEfficiencyErrorLow(x);
	//eff_err_low = 0;
		 	if(eff_bin-eff_err_low <= hit_no_eff && eff_bin != 0) {
				x_ax = x * 50 + 25;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c2);

				break;
			}
	        }



	        for(Int_t x = 0; x < 60 ; x++){

			Double_t eff_bin = shatR_h_eff_tr_c1_no->GetEfficiency(x);
	        	eff_err_low = shatR_h_eff_tr_c1_no->GetEfficiencyErrorLow(x);
	//eff_err_low = 0;
	            	if(eff_bin-eff_err_low <= hit_no_eff && eff_bin != 0) {
				x_ax = x * 50 + 25;
				x_axis_vect.push_back(x_ax);
				y_axis_vect.push_back(shatR_gaminvR_c1);

				break;
			}
	        }



		const Int_t gr_size = x_axis_vect.size();


		Float_t x_axis_arr[gr_size];
		Float_t y_axis_arr[gr_size];
		Float_t x_axis_err[gr_size];
		Float_t y_axis_err[gr_size];


		for (Int_t g = 0 ; g< gr_size; g++ ){

			x_axis_arr[g] = x_axis_vect[g];
			y_axis_arr[g] = y_axis_vect[g]/1000;
			x_axis_err[g] = 25;
			y_axis_err[g] = 0.01;

		}


		graph_1 = new  TGraphErrors( gr_size , x_axis_arr , y_axis_arr,x_axis_err , y_axis_err );
	      	gStyle->SetOptFit(0000);
		graph_1->Draw("A*");


		TF1 *off_f1 =new TF1("off_f1", "[0]/(x+[1])-[2]",0,3000 );
	       // off_f1->SetParameters(off_prodr,off_c_1,off_c_2);
	//	off_f1->SetParLimits(0,0,400);
		off_f1->SetParLimits(0,0,300);
//		off_f1->SetParLimits(1,-350,350);
//		off_f1->SetParLimits(2,-1,1);


			off_f1->SetParLimits(1,-500,500);
			off_f1->SetParLimits(2,-2,2);

		graph_1->Fit("off_f1");


		Float_t new_off_prodr = off_f1->GetParameter(0);
		Float_t new_off_c_1 = off_f1->GetParameter(1);
		Float_t new_off_c_2 = off_f1->GetParameter(2);


		efficiencies.push_back(new_off_prodr);
		efficiencies.push_back(new_off_c_1);
		efficiencies.push_back(new_off_c_2);


		TCanvas *c8 = new TCanvas("c8","1-Efficiency gaminvR");
		c8->Clear();
		c8->SetLogy();
		gPad->SetGrid();
		gaminvR_h_eff_tr_no->SetMarkerColor(kBlue);
		gaminvR_h_eff_tr_no->SetMarkerColor(kBlue);
	        gaminvR_h_eff_tr_no->SetTitle("1 - Efficiency; 1/#gamma_{R+1}; 1 - Efficiency");
		gaminvR_h_eff_tr_no->Draw();





		// Raz var!

		TCanvas *c6 = new TCanvas("c6","Efficiency Raz Var");
	       	c6->Clear();
		gPad->SetGrid();
		raz_var_h_eff_tr->SetTitle("Efficiency; #sqrt{#hat{s}_{R}}[GeV]; 1/#gamma_{R+1}; Efficiency");
	      	raz_var_h_eff_tr->Draw("colz");


		TF2 *f2 = new TF2("f2",prodr_funct,0,3000,0,1,2);
	//	f2->SetParameters(off_c_1,off_c_2);
		f2->SetParameters(new_off_c_1,new_off_c_2);
		f2->SetLineColor(kBlack);
		f2->SetLineWidth(4);
		f2->SetContour(1);
		f2->SetContourLevel(0,new_off_prodr);
		f2->Draw("same");
/*
	        leg = new TLegend(0.68,0.80,0.84,0.9);
	        leg->SetTextSize(0.03);
	//        leg->AddEntry(f2,"#bar{#Pi}="+off_prodr_s+"GeV","l");
	        leg->AddEntry(f2,"#bar{#Pi}","l");
	        leg->Draw();

*/


		TCanvas *c9 = new TCanvas("c9","1-Efficiency Raz Var");
	       	c9->Clear();
		c9->SetLogz();
		gPad->SetGrid();
		raz_var_h_eff_tr_no->SetTitle("1 - Efficiency; #sqrt{#hat{s}_{R}}[GeV]; 1/#gamma_{R+1}; 1 - Efficiency");
	      	raz_var_h_eff_tr_no->Draw("colz");

	/*
		TF2 *f2 = new TF2("f2",prodr_funct,0,3000,0,1,2);
		f2->SetParameters(off_c_1,off_c_2);
		f2->SetLineColor(kBlack);
		f2->SetLineWidth(4);
		f2->SetContour(1);
		f2->SetContourLevel(0,off_prodr); */
		f2->Draw("same");

	        leg = new TLegend(0.68,0.80,0.84,0.9);
	        leg->SetTextSize(0.03);
	//    	leg->AddEntry(f2,"#bar{#Pi}="+off_prodr_s+"GeV","l");
		leg->AddEntry(f2,"#bar{#Pi}","l");
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
	/*        //Plateau
	        "\n PLATEAU" <<
	        "\n efficiency (xe100_XE70) : " << eff_xe_off <<
	        "\n efficiency  (xe100_XE70 OR ProdR_2J15_XE55) : " << eff_or_1_off <<
	        "\n efficiency (xe100_XE70 OR ProdR_XE70) : " << eff_or_2_off <<
	        "\n efficiency (ProdR_2J15_XE55 OR ProdR_XE70) : " << eff_or_3_off <<
	        "\n efficiency (xe100_XE70 OR ProdR_2J15_XE55 OR ProdR_XE70) : " << eff_or_4_off <<
		"\n" <<
		"\n New c_1 offline : " << new_off_c_1 << endl <<
		"\n New c_2 offline : " << new_off_c_2 << endl <<
		"\n New ProdR offline : " << new_off_prodr << endl << */
	        endl;


/*

		for(int a = 0; a< 40 ; a++){

			if (xe_pt_h_eff_tr->GetEfficiency(a) == 1){

				cout << a << endl;
				cout << xe_pt_h_eff_tr->GetEfficiencyErrorUp(a) << endl;
				cout << xe_pt_h_eff_tr->GetEfficiencyErrorLow(a) << endl;

			}


		}


*/




	        TFile* efficiency_turnon_output= new TFile (output_directory+"/all"+c_prodr+"_eff_turnon_OR1.root" ,"recreate");

		xe_pt_h_eff_tr->Write();
		shatR_h_eff_tr->Write();
		shatR_h_eff_tr_c1->Write();
		shatR_h_eff_tr_c2->Write();
		shatR_h_eff_tr_c3->Write();
		shatR_h_eff_tr_c4->Write();
		gaminvR_h_eff_tr->Write();
		raz_var_h_eff_tr->Write();
		shatR_h_eff_tr_no->Write();
		shatR_h_eff_tr_c1_no->Write();
		shatR_h_eff_tr_c2_no->Write();
		shatR_h_eff_tr_c3_no->Write();
		shatR_h_eff_tr_c4_no->Write();
		gaminvR_h_eff_tr_no->Write();
		raz_var_h_eff_tr_no->Write();
		graph_1->Write();


	        c3->SaveAs(output_directory+"/all_w3_"+c_prodr+"_xe_pt_eff_OR1.pdf");
	        c3->Close();
	//        c4->SaveAs(output_directory+"/"+output_file_name+c_prodr+"_shatr_eff.pdf");
	        c4->Close();
	//        c5->SaveAs(output_directory+"/"+output_file_name+c_prodr+"_gaminvr_eff.pdf");
	        c5->Close();
	        c6->SaveAs(output_directory+"/all_w3_"+c_prodr+"_raz_var_2d_eff_OR1.pdf");
	        c6->Close();


	        c7->SaveAs(output_directory+"/all_w3_"+c_prodr+"_shatr_noeff_OR1.pdf");
	        c7->Close();
	        c8->SaveAs(output_directory+"/all_w3_"+c_prodr+"_gaminvr_noeff_OR1.pdf");
	        c8->Close();
	//        c9->SaveAs(output_directory+"/"+output_file_name+c_prodr+"_raz_var_2d_noeff.pdf");
	        c9->Close();

		canvas_1->SaveAs(output_directory+"/all_w3_"+c_prodr+"_parametrize_OR1.pdf");
		canvas_1->Close();

	        efficiency_turnon_output->Close();


		xe_pt_h_eff_tr     ->Delete();
		shatR_h_eff_tr     ->Delete();
		shatR_h_eff_tr_c1  ->Delete();
		shatR_h_eff_tr_c2  ->Delete();
		shatR_h_eff_tr_c3  ->Delete();
		shatR_h_eff_tr_c4  ->Delete();
		shatR_h_eff_tr_c5  ->Delete();
		shatR_h_eff_tr_c6  ->Delete();
		shatR_h_eff_tr_c7  ->Delete();


		gaminvR_h_eff_tr   ->Delete();
		raz_var_h_eff_tr   ->Delete();
		shatR_h_eff_tr_no     ->Delete();
		shatR_h_eff_tr_c1_no  ->Delete();
		shatR_h_eff_tr_c2_no  ->Delete();
		shatR_h_eff_tr_c3_no  ->Delete();
		shatR_h_eff_tr_c4_no  ->Delete();
		shatR_h_eff_tr_c5_no  ->Delete();
		shatR_h_eff_tr_c6_no  ->Delete();
		shatR_h_eff_tr_c7_no  ->Delete();
		gaminvR_h_eff_tr_no ->Delete();
		raz_var_h_eff_tr_no ->Delete();
		graph_1->Delete();




		for(Int_t fin_res = 0; fin_res < efficiencies.size(); fin_res++){


			cout << efficiencies[fin_res] << endl;


		}




		return efficiencies;


}

Double_t prodr_funct(Double_t *x, Double_t *par){

	return (x[0] + par[0] )*( x[1] + par[1]);

}



