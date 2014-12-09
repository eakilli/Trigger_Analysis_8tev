#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLatex.h>
#include <TTree.h>
#include "common_plotting_functions.hh"

//#include <TString.h>
//#include <iostream>
//#include <iomanip>


//JETs : not trigger but only pt cuts
//JET : L1


void razor_trigger_comb(TString c_prodr, Float_t prodr, Float_t c_1, Float_t c_2, TString file_directory , TString input_file_name_1,TString input_file_name_2 , TString output_directory , TString output_file_name,Float_t cross_sect1, Float_t cross_sect2){

	// Define weights and number of events for the seperate trees and the trees loop
	Float_t weight_1 = cross_sect1;
	Float_t weight_2 = cross_sect2;
	Float_t weight = 0;

        Float_t number_of_events_1 = 0;
        Float_t number_of_events_2 = 0;
	Float_t number_of_events_cur = 0;

        Float_t number_of_events = 0; // total, weighted after the combination

	Float_t value = 0; // calculated value for hyperbolic cut

	ofstream outputfile(output_directory+"/"+output_file_name+c_prodr+"_outputfile.txt");
	outputfile<< " *** output messages file for : " << file_directory << "/" << input_file_name_1  << "," << input_file_name_2 <<" *** \n"<<
	"\n prodr : " << prodr <<
	"\n c_1 : " << c_1 <<
	"\n c_2 : " << c_2 <<
	endl;


	// Float because they will be weighted with the cross section
//	Float_t n_razor = 0;
	Float_t jet_n_o_e_plus2 = 0;
	Float_t JETs_n_o_e_plus2 = 0;

	Float_t shatR=0; Long64_t n_shatR=0;
	Float_t cosptR=0; Long64_t n_cosptR=0;
	Float_t mdeltaR=0; Long64_t n_mdeltaR=0;
	Float_t gaminvR=0; Long64_t n_gaminvR=0;
	Float_t dphivbR=0; Long64_t n_dphivbR=0;
	Float_t ptcm=0; Long64_t n_ptcm=0;
	Float_t Prod=0;

	Float_t LeadPt = 0;

	static const int n_t=11;
	static const int n_t_noprodr=6;

	if(prodr == 200) { TString triggernames[n_t] = { "ProdR200_4J20" , "ProdR200_2J30_XE40", "ProdR200_HT200", "ProdR200_XE70", "ProdR200_2J10_XE60", "ProdR200_2J15_XE55","5j85_4J20",
					"j150_xe90_J75_XE40","xe100_XE70","ht1000_HT200","All jet + MET triggers"};
	}

	if(prodr == 170){ TString triggernames[n_t] = { "ProdR170_4J20" , "ProdR170_2J30_XE40", "ProdR170_HT200", "ProdR170_XE70", "ProdR170_2J10_XE60", "ProdR170_2J15_XE55","5j85_4J20",
                                        "j150_xe90_J75_XE40","xe100_XE70","ht1000_HT200","All jet + MET triggers"};
	}


	TString triggernames_norazor[n_t_noprodr] = { "4J20" , "2J30_XE40", "HT200", "XE70", "2J10_XE60", "2J15_XE55"};

	int flag_prodr_t[n_t]={0};
	Float_t n_trigger_overlap[n_t][n_t] = {0};

	Float_t per_overlap[n_t][n_t]={0};



	// Razor and L1 branches, number of events

	// Trigger branch variables, booleans
	Bool_t b_4J20=0;
	Bool_t b_2J30_XE40=0;
	Bool_t b_HT200=0;
	Bool_t b_XE70=0;
	Bool_t b_2J10_XE60=0;
	Bool_t b_2J15_XE55=0;
	// L2 included
	Bool_t b_5j85_4J20=0;
	Bool_t b_j150_xe90_J75_XE40=0;
	Bool_t b_xe100_XE70=0;
	Bool_t b_ht1000_HT200=0;


	Float_t n_o_e_prodr = 0;
        Float_t n_o_e_prodr_4J20 = 0; 		flag_prodr_t[0] = 0; //t1
        Float_t n_o_e_prodr_2J30_XE40 = 0; 	flag_prodr_t[1] = 0; //t2
	Float_t n_o_e_prodr_HT200 = 0; 	flag_prodr_t[2] = 0; //t3
	Float_t n_o_e_prodr_XE70 = 0; 		flag_prodr_t[3] = 0; //t4
	Float_t n_o_e_prodr_2J10_XE60 = 0;	flag_prodr_t[4] = 0; //t5
	Float_t n_o_e_prodr_2J15_XE55 =0; 	flag_prodr_t[5] = 0; //t6

	Float_t n_t1_noprodr = 0;
	Float_t n_t2_noprodr = 0;
	Float_t n_t3_noprodr = 0;
	Float_t n_t4_noprodr = 0;
	Float_t n_t5_noprodr = 0;
	Float_t n_t6_noprodr = 0;

	//No razor
	Float_t n_o_e_5j85_4J20 = 0; 		//t7 , flag_prodr_t[6] = 0 ...
	Float_t n_o_e_j150_xe90_J75_XE40 = 0; 	//t8
	Float_t n_o_e_xe100_XE70 = 0; 		//t9
	Float_t n_o_e_b_ht1000_HT200 = 0; 	//t10
	Float_t n_o_e_all_jet_met = 0; 	//t11, flag_prodr_t[10]


	// Jets
 	static const int Njet_max = 20;
  	Int_t jet_n=0;
	Int_t JETs_n=0;
  	Float_t jet_pt[Njet_max]={0};
	Float_t JETs_pt[Njet_max]={0};
//	Float_t jet_eta[Njet_max];


	// xe
	Float_t xe_pt;

	// Razor defined XE and JET(L1) histogram variables
	Float_t XE_pt = 0;
	Int_t JET_n = 0;
	Float_t JET_pt[Njet_max]={0};


	//Razor variables
	TH1F * gaminvR_h = new TH1F("gaminvR_h", "1/#gamma_{R+1}", 100, 0, 1 ); //c3
	TH1F * shatR_h = new TH1F("shatR_h", "#sqrt{\hat{s}_R}", 72, 0, 3000); //c4
	TH2F * raz_var_h = new TH2F("raz_var_h", "Razor Variables ProdR = 200", 72, 0, 3000, 50, 0, 1); // c5


	// Histograms where the razor variables are defined

	//XE

        TH1F * xe_pt_h = new TH1F("xe_pt_h" , "xe_pt" , 100,0,700); //c8

	// XE_pt
	TH1F * XE_pt_1_h = new TH1F("XE_pt_1_h" , "XE_pt" , 100,0,700); //c6

	// JET_pt
	TH1F * JET_pt_h = new TH1F("JET_pt", "JET_pt", 100, 0 , 700); //c7

	TH2I *overlap_h = new TH2I("overlap_h", "Trigger Overlap", n_t,0,n_t, n_t,0,n_t); //c10


	// Open the file 1
	TFile *razor_file_1 = TFile::Open(file_directory+"/"+input_file_name_1);
    	if(razor_file_1==0) {
                cout << "Couldn't open the root file 1" << endl;
                return;
        }

	// Get the tree 1, number of events, QCUT80

	TTree* mytree_1 = (TTree*)razor_file_1->Get("physics");
	number_of_events_1 = mytree_1->GetEntries();
	outputfile << " number of events 1 : " << number_of_events_1 << endl;


       // Open the file 2
        TFile *razor_file_2 = TFile::Open(file_directory+"/"+input_file_name_2);
        if(razor_file_2==0) {
                cout << "Couldn't open the root file 2" << endl;
                return;
        }

        // Get tree 2, number of events, QCUT 300

        TTree* mytree_2 = (TTree*)razor_file_2->Get("physics");
        number_of_events_2 = mytree_2->GetEntries();
        outputfile << " number of events 2 : " << number_of_events_2 << endl;


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
		currenttree->SetBranchAddress("jet_n",&jet_n);
		currenttree->SetBranchAddress("jet_pt",jet_pt);
		currenttree->SetBranchAddress("Prod" , &Prod);
		currenttree->SetBranchAddress("cosptR",&cosptR);
		currenttree->SetBranchAddress("mdeltaR",&mdeltaR);
		currenttree->SetBranchAddress("dphivbR",&dphivbR);
		currenttree->SetBranchAddress("ptcm",&ptcm);
		currenttree->SetBranchAddress("LeadPt",&LeadPt);

		//xe

		currenttree->SetBranchAddress("xe_pt", &xe_pt);


		// XE, JET(L1) Histogram branches where the razor variables are defined

		currenttree->SetBranchAddress("XE_pt",&XE_pt);
		currenttree->SetBranchAddress("JET_n",&JET_n); // L1
		currenttree->SetBranchAddress("JET_pt",JET_pt); // L1


		// Trigger information bool branches

		currenttree->SetBranchAddress("4J20",&b_4J20);
		currenttree->SetBranchAddress("2J30_XE40",&b_2J30_XE40);
		currenttree->SetBranchAddress("HT200",&b_HT200);
		currenttree->SetBranchAddress("XE70",&b_XE70);
		currenttree->SetBranchAddress("2J10_XE60",&b_2J10_XE60);
		currenttree->SetBranchAddress("2J15_XE55",&b_2J15_XE55);
		currenttree->SetBranchAddress("5j85_4J20",&b_5j85_4J20);
		currenttree->SetBranchAddress("j150_xe90_J75_XE40",&b_j150_xe90_J75_XE40);
		currenttree->SetBranchAddress("xe100_XE70",&b_xe100_XE70);
		currenttree->SetBranchAddress("ht1000_HT200",&b_ht1000_HT200);

		cout << "Branch address : done " << endl;

		//currenttree->SetBRanchAddress("HT",&HT) ;

		//Tree event loop, tree 1, QCUT80
		for (Long64_t i=0; i<number_of_events_cur; i++) {

			//Clear flags, jets
			for (int j = 0; j<n_t; j++) {
				flag_prodr_t[j] = 0;
			}

			for (int j=0; j<Njet_max; j++){
				JETs_pt[j] = 0;
				jet_pt[j] = 0;
			}


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
			//value = Prod;

			if (value >= prodr) {n_o_e_prodr = n_o_e_prodr + weight;}

			//Check the number of events with more than 1 jet
			if(jet_n>=2) {
				jet_n_o_e_plus2 = jet_n_o_e_plus2 + weight;
			}


			//Fill the histograms

			//Start to count the number of jets that satisfies the pt>=30GeV condition
			JETs_n = 0;

			for(int k = 0; k < jet_n ; k++){
				//JETs
				if(jet_pt[k]>=30000){
					JETs_pt[JETs_n] = jet_pt[k];
					JETs_n++ ;
				}
			}


			//New loop for the events where 2 hemispheres might be defined by JETs
			if(JETs_n < 2) continue;
			else {
				JETs_n_o_e_plus2 =JETs_n_o_e_plus2  + weight;

				// 2 Jets with pt > 30 GeV condition applied, continue to razor variables and L1 JET
		              	raz_var_h->Fill(shatR/1000,gaminvR/1000, weight);
				gaminvR_h->Fill(gaminvR/1000, weight);
				shatR_h->Fill(shatR/1000,weight);

		//            	n_razor++;
				xe_pt_h->Fill(xe_pt/1000, weight);
		              	XE_pt_1_h->Fill(XE_pt/1000, weight);

				for(int l=0; l<JET_n; l++){
					JET_pt_h->Fill(JET_pt[l]/1000, weight); // Look at the pt distribution of L1 JET
				}


				if(value<prodr) {
					if(b_4J20==1) n_t1_noprodr = n_t1_noprodr + weight;
					if(b_2J30_XE40==1) n_t2_noprodr = n_t2_noprodr + weight;
					if(b_HT200==1) n_t3_noprodr = n_t3_noprodr + weight;
					if(b_XE70==1) n_t4_noprodr = n_t4_noprodr + weight;
					if(b_2J10_XE60==1) n_t5_noprodr = n_t5_noprodr + weight;
					if(b_2J15_XE55==1) n_t6_noprodr = n_t6_noprodr + weight;
				}


				if(value>=prodr) {
					// t1
					if(b_4J20==1){
						flag_prodr_t[0]=1;
						n_o_e_prodr_4J20 = n_o_e_prodr_4J20 + weight;
					}
					// t2
					if(b_2J30_XE40==1){
						flag_prodr_t[1]=1;
						n_o_e_prodr_2J30_XE40 = n_o_e_prodr_2J30_XE40 + weight;
					}
					//t3
					if(b_HT200==1){
						flag_prodr_t[2]=1;
						n_o_e_prodr_HT200 = n_o_e_prodr_HT200 + weight ;
					}
					//t4
		        	       	if(b_XE70==1){
		                	       	flag_prodr_t[3]=1;
		                       		n_o_e_prodr_XE70 = n_o_e_prodr_XE70 + weight;
		                      	}
					//t5
					if(b_2J10_XE60==1){
						flag_prodr_t[4]=1;
						n_o_e_prodr_2J10_XE60 =n_o_e_prodr_2J10_XE60  + weight;
					}
					//t6
					if(b_2J15_XE55==1){
						flag_prodr_t[5]=1;
						n_o_e_prodr_2J15_XE55 = n_o_e_prodr_2J15_XE55 + weight;
					}

				}


				// (Not razor) L2 included

				//t7
				if(b_5j85_4J20==1) {
					flag_prodr_t[6]=1;
					n_o_e_5j85_4J20 = n_o_e_5j85_4J20+weight;
				}


				//t8
				if(b_j150_xe90_J75_XE40==1){
					flag_prodr_t[7]=1;
					n_o_e_j150_xe90_J75_XE40 = n_o_e_j150_xe90_J75_XE40+weight;
				}

				//t9
				if(b_xe100_XE70==1){
					flag_prodr_t[8]=1;
					n_o_e_xe100_XE70 = n_o_e_xe100_XE70 + weight;
				}

				//t10
				if(b_ht1000_HT200==1){
					flag_prodr_t[9]=1;
					n_o_e_b_ht1000_HT200 = n_o_e_b_ht1000_HT200 + weight ;
				}


				if(flag_prodr_t[6]==1 || flag_prodr_t[7] == 1 || flag_prodr_t[8] ==1 || flag_prodr_t[9]== 1){
					flag_prodr_t[10]=1;
					n_o_e_all_jet_met = n_o_e_all_jet_met + weight;
				}



			} // end the else


			// Use vectors of flags for trigger overlap


			for (int x = 0; x<n_t ; x++) {

				for(int y=0; y<n_t; y++){

					if(flag_prodr_t[x] == 0 && flag_prodr_t[y] == 1){
						n_trigger_overlap[x][y] = n_trigger_overlap[x][y] + weight ;

					}

				}

			}


			number_of_events = number_of_events + weight;



		} //end event loop 1


		if(tr == 0) {razor_file_1->Close();}

		if(tr == 1) {razor_file_2->Close();}


		delete newfile;
		cout << "end event loop" << endl;


	} // end the 2 trees loop





	// Start to analyse and plot

	for (int x = 0 ; x< n_t ; x++){

		for(int y=0; y < n_t ; y++){

		per_overlap[x][y] = 100 *  n_trigger_overlap[x][y] / JETs_n_o_e_plus2 ;

		overlap_h->Fill( x, y, per_overlap[x][y]);

//		cout << x << y << ":" <<per_overlap[x][y] << endl;

		}
	}


	Float_t per_n_t1_noprodr = 100*  n_t1_noprodr /  JETs_n_o_e_plus2 ;
        Float_t per_n_t2_noprodr = 100*  n_t2_noprodr /  JETs_n_o_e_plus2 ;
        Float_t per_n_t3_noprodr = 100*  n_t3_noprodr /  JETs_n_o_e_plus2 ;
        Float_t per_n_t4_noprodr = 100*  n_t4_noprodr /  JETs_n_o_e_plus2 ;
        Float_t per_n_t5_noprodr = 100*  n_t5_noprodr /  JETs_n_o_e_plus2 ;
        Float_t per_n_t6_noprodr = 100*  n_t6_noprodr /  JETs_n_o_e_plus2 ;


	// Output text and root files

	// Writing text

	outputfile << "number of total events , (weighted,combined) : " << number_of_events <<
	"\n not weighted : " <<
	"\n n_shatR : " << n_shatR <<
	"\n n_cosptR : " << n_cosptR <<
	"\n n_mdeltaR : " << n_mdeltaR <<
	"\n n_gaminvR : " << n_gaminvR <<
	"\n n_dphivbR : " << n_dphivbR <<
	"\n n_ptcm : " << n_ptcm << "\n" <<
//	"\n n_razor : " << n_razor <<
	"\n weighted : " <<
	"\n number of events with more than one jet : " << jet_n_o_e_plus2  <<
	"\n number of events with more than one jet with pt>=30GeV : " << JETs_n_o_e_plus2 <<
	" \n " <<
	"\n number of events for triggers : " <<
	"\n number of events that passes the hyperbolic cut : " << n_o_e_prodr <<
	"\n t1 : n_o_e_prodr_4J20 : " << n_o_e_prodr_4J20 <<
	"\n t1 : n_noprodr_4J20 : " << n_t1_noprodr << ", %" << per_n_t1_noprodr <<
	"\n t2 : n_o_e_prodr_2J30_XE40 : " << n_o_e_prodr_2J30_XE40  <<
	"\n t2 : n_noprodr_2J30_XE40 : " << n_t2_noprodr << ", %" << per_n_t2_noprodr <<
	"\n t3 : n_o_e_prodr_HT200 : " << n_o_e_prodr_HT200 <<
        "\n t3 : n_noprodr_HT200 : " << n_t3_noprodr << ", %" << per_n_t3_noprodr <<
	"\n t4 : n_o_e_prodr_XE70 : " << n_o_e_prodr_XE70  <<
        "\n t4 : n_noprodr_XE70 : " << n_t4_noprodr << ", %" << per_n_t4_noprodr <<
	"\n t5 : n_o_e_prodr_2J10_XE60 : " << n_o_e_prodr_2J10_XE60 <<
        "\n t5 : n_noprodr_2J10_XE60 : " << n_t5_noprodr << ", %" << per_n_t5_noprodr <<
	"\n t6 : n_o_e_prodr_2J15_XE55 : " << n_o_e_prodr_2J15_XE55 <<
        "\n t6 : n_noprodr_2J15_XE55 : " << n_t6_noprodr << ", %" << per_n_t6_noprodr <<
	"\n" <<
	"\n t7 : n_o_e_5j85_4J20 : " << n_o_e_5j85_4J20 <<
	"\n t8 : n_o_e_j150_xe90_J75_XE40 : " << n_o_e_j150_xe90_J75_XE40 <<
	"\n t9 : n_o_e_xe100_XE70 : " << n_o_e_xe100_XE70 <<
	"\n t10 : n_o_e_b_ht1000_HT200 : " << n_o_e_b_ht1000_HT200 <<
	"\n t11 : n_o_e_all_jet_met : " << n_o_e_all_jet_met ;
	endl;


	// Drawing, writing histograms

	setstyle();  // Emma's style with minor changes

	// Razor Variables

	TCanvas *c3 = new TCanvas("c3", "shatR",150,10,990,600);
	c3->Clear();
//	gStyle->SetOptStat(1101);
	shatR_h->SetLineColor(kBlue);
	shatR_h->SetStats(1);
	shatR_h->Draw();
	shatR_h->GetXaxis()->SetTitle("#sqrt{#hat{s}_{R}}[GeV]");
	shatR_h->GetYaxis()->SetTitle("N");


	TCanvas *c4 = new TCanvas("c4", "gaminvR", 150,10,990,600);
	c4->Clear();
//	gStyle->SetOptStat("m");
	gaminvR_h->SetLineColor(kBlue);
	gaminvR_h->SetStats(1);
	gaminvR_h->Draw();
	gaminvR_h->GetXaxis()->SetTitle("1/#gamma_{R+1}");
	gaminvR_h->GetYaxis()->SetTitle("N");


/*
    	TF1 *f1 = new TF1("f1","[0]/(x+[1])-[2]",0,3000);
	f1->SetParameters(prodr,c_1,c_2);
       	TF1 *f2 = new TF1("f2","[0]/(x+[1])-[2]",0,3000);
        f2->SetParameters(170,200,0);
*/
	double norm_param = 1/(raz_var_h->Integral());

        TCanvas * c5= new TCanvas("c5", "Razor Variables",150,10,990,660);
        c5->Clear();
//	gStyle->SetOptStat(0);
	raz_var_h->Scale(norm_param);
      	raz_var_h->SetStats(0);
        raz_var_h->Draw("colz");
        raz_var_h->GetXaxis()->SetTitle("#sqrt{#hat{s}_{R}}[GeV]");
        raz_var_h->GetYaxis()->SetTitle("1/#gamma_{R+1}");
	c5->SetRightMargin(0.18);


        TF2 *f2 = new TF2("f2",prodr_funct,0,3000,0,1,2);
        f2->SetParameters(c_1,c_2);
        f2->SetLineColor(kBlack);
        f2->SetLineWidth(4);
        f2->SetContour(1);
        f2->SetContourLevel(0,prodr);
        f2->Draw("same");

	TF2 *f2_2 = new TF2("f2_2",prodr_funct,0,3000,0,1,2);
        f2_2->SetParameters(200,0);
        f2_2->SetLineColor(kRed);
        f2_2->SetLineWidth(4);
        f2_2->SetContour(1);
        f2_2->SetContourLevel(0,170);
        f2_2->Draw("same");


        leg = new TLegend(0.66,0.80,0.82,0.9);
        leg->SetTextSize(0.03);
        leg->AddEntry(f2,"#bar{#Pi}="+c_prodr+"GeV","l");
        leg->AddEntry(f2_2,"#bar{#Pi}=170GeV","l");
        leg->Draw();



       	TCanvas * c6= new TCanvas("c6", "XE_pt_1",150,10,990,660);
        c6->Clear();
//	gStyle->SetOptStat(1101);
	XE_pt_1_h->SetLineColor(kBlue);
	XE_pt_1_h->SetStats(1);
        XE_pt_1_h->Draw();
        XE_pt_1_h->GetXaxis()->SetTitle("XE_pt");
        XE_pt_1_h->GetYaxis()->SetTitle("N");

	TCanvas *c7 = new TCanvas("c7","JET_pt",150,10,990,660);
	c7->Clear();
	c7->SetLogy();
//	gStyle->SetOptStat(1101);
	JET_pt_h->SetLineColor(kBlue);
	JET_pt_h->SetStats(1);
	JET_pt_h->Draw();
	JET_pt_h->GetXaxis()->SetTitle("JET_pt");
	JET_pt_h->GetYaxis()->SetTitle("N");


	TCanvas *c8 = new TCanvas("c8","xe_pt",150,10,990,660);
	c8->Clear();
//	gStyle->SetOptStat(1101);
	xe_pt_h->SetLineColor(kBlue);
	xe_pt_h->SetStats(1);
	xe_pt_h->Draw();
        xe_pt_h->GetXaxis()->SetTitle("E_{T}^{miss}[GeV]");
        xe_pt_h->GetYaxis()->SetTitle("N");



	TCanvas *c10 = new TCanvas("c10", "Trigger Overlap",1200,800);
	c10->Clear();
//	gPad->SetGridx();
//	gPad->SetGridy();
//	gStyle->SetOptStat(0);
	gStyle->SetPaintTextFormat("5.0f");
	overlap_h->SetStats(0);
  	for (int bin=0;bin<n_t;bin++){ overlap_h->GetXaxis()->SetBinLabel(bin+1,triggernames[bin]);}
 	for (int bin=0;bin<n_t;bin++){ overlap_h->GetYaxis()->SetBinLabel(bin+1,triggernames[bin]);}
//	overlap_h->SetTitle("Trigger Overlap 8TeV, DM40, MM1000, W8pi, QCUT80");
	overlap_h->GetZaxis()->SetRangeUser(0.,100.);
	overlap_h->GetYaxis()->SetTitle("Trigger Y");
	overlap_h->GetYaxis()->SetTitleSize(0.03);
	overlap_h->GetYaxis()->SetLabelSize(0.025);
	overlap_h->GetYaxis()->SetTitleOffset(2.7);
	overlap_h->GetXaxis()->SetTitle("Trigger X");
	overlap_h->GetXaxis()->SetTitleSize(0.03);
	overlap_h->GetXaxis()->SetLabelSize(0.025);
	overlap_h->GetXaxis()->SetTitleOffset(1.7);
	overlap_h->GetZaxis()->SetTitle("% of events that pass Trigger Y and not Trigger X");
	overlap_h->GetZaxis()->SetTitleSize(0.03);
	overlap_h->GetZaxis()->SetTitleOffset(1.6);
	overlap_h->SetMarkerSize(1.0);
	c10->SetTopMargin(0.1);
	c10->SetLeftMargin(0.16);
        c10->SetRightMargin(0.2);

	overlap_h->Draw("coltextz");


	TFile* razor_variables_output= new TFile (output_directory+"/"+output_file_name+c_prodr+".root" ,"recreate");
	xe_pt_h->Write();
	XE_pt_1_h->Write();
	JET_pt_h->Write();
	raz_var_h->Write();
	gaminvR_h->Write();
	shatR_h->Write();
	overlap_h->Write();


	c3->SaveAs(output_directory+"/"+output_file_name+c_prodr+"_shatR.pdf");
	c3->Close();
	c4->SaveAs(output_directory+"/"+output_file_name+c_prodr+"_gaminvR.pdf");
	c4->Close();
	c5->SaveAs(output_directory+"/"+output_file_name+c_prodr+"_razor_variables.pdf");
	c5->Close();
	c6->SaveAs(output_directory+"/"+output_file_name+c_prodr+"_XE_pt_1.pdf");
	c6->Close();
	c7->SaveAs(output_directory+"/"+output_file_name+c_prodr+"_JET_pt.pdf");
	c7->Close();
	c8->SaveAs(output_directory+"/"+output_file_name+c_prodr+"_xe_pt.pdf");
	c8->Close();
	c10->SaveAs(output_directory+"/"+output_file_name+c_prodr+"_trigger_overlap.pdf");
	c10->Close();

	razor_variables_output->Close();

	xe_pt_h->Delete();
	XE_pt_1_h->Delete();
	JET_pt_h->Delete();
	raz_var_h->Delete();
	gaminvR_h->Delete();
	shatR_h->Delete();
	overlap_h->Delete();

	return;
}

Double_t prodr_funct(Double_t *x, Double_t *par){

        return (x[0] + par[0] )*( x[1] + par[1]);

}
