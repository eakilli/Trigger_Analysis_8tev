#include <TH2.h>
#include <TH1.h>
#include <TF1>
#include <TF2>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLatex.h>
#include <TTree.h>
#include "common_plotting_functions.hh"
#include <TGraph.h>
#include <TEfficiency>
#include <vector>


using namespace std;


void the_graph_fit() {

	TString output_eff_dir = "/atlas/data2/userdata/eakilli/razor_output/Output_efficiency_directory/";
	TString output_eff_root_file = "all170_eff_turnon_OR1.root";

	// Open the output file
	TFile *output_root_file = TFile::Open(output_eff_dir+output_eff_root_file);
   	if(output_root_file==0) {
	      cout << "Couldn't open the root file" << endl;
              return;
        }

	// Get the graph

	setstyle();




	TGraphErrors graph_1 = (TGraphErrors)output_root_file->Get("Graph");
	TCanvas *fit_canvas = new TCanvas("fit_canvas","Parametrize");
	fit_canvas->Clear();
	graph_1.Draw("A*");
	gStyle->SetOptFit(1);


	TF1 *off_f1 =new TF1("off_f1", "[0]/(x+[1])-[2]",0,3000);
//	off_f1->SetParameters(off_prodr,off_c_1,off_c_2);
//	off_f1->SetParLimits(0,0,400);
	off_f1->SetParLimits(0,0,300);
//	off_f1->SetParLimits(1,-350,350);
//	off_f1->SetParLimits(2,-1,1);
	off_f1->SetParLimits(1,-500,500);
//	off_f1->SetParLimits(2,-2,2);

	off_f1->FixParameter(0,230);
	off_f1->FixParameter(1,-170);

	off_f1->FixParameter(2,0);

	graph_1.Fit("off_f1","R");
	fit_canvas->Update();


	fit_canvas->SaveAs(output_eff_dir+"parametrize_fit_canvas_OR1.pdf");


	Float_t new_off_prodr = off_f1->GetParameter(0);
	Float_t new_off_c_1 = off_f1->GetParameter(1);
	Float_t new_off_c_2 = off_f1->GetParameter(2);



	TF2 *f2 = new TF2("f2",prodr_funct,0,3000,0,1,2);
	f2->SetParameters(new_off_c_1,new_off_c_2);
	f2->SetLineColor(kBlack);
	f2->SetLineWidth(4);
	f2->SetContour(1);
	f2->SetContourLevel(0,new_off_prodr);
	f2->Draw("same");



	TEfficiency* raz_var_h_eff_tr_new = (TEfficiency*)output_root_file->Get("raz_var_h_eff_tr");
	TEfficiency* raz_var_h_eff_tr_no_new = (TEfficiency*)output_root_file->Get("raz_var_h_eff_tr_no");

	TCanvas *canvas_2d_eff = new TCanvas("canvas_2d_eff","Efficiency Raz Var");
	canvas_2d_eff->Clear();
	gPad->SetGrid();
	raz_var_h_eff_tr_new->Draw("colz");
	f2->Draw("same");
	canvas_2d_eff->SaveAs(output_eff_dir+"2d_eff_OR1.pdf");


	TCanvas *canvas_2d_no_eff = new TCanvas("canvas_2d_no_eff", "1-Efficiency Raz Var");
	canvas_2d_no_eff->Clear();
	canvas_2d_no_eff->SetLogz();
	gPad->SetGrid();
	raz_var_h_eff_tr_no_new->Draw("colz");
	f2->Draw("same");
	canvas_2d_no_eff->SaveAs(output_eff_dir+"2d_no_eff_OR1.pdf");



	//ShatR

	Float_t shatR_gaminvR_c1 = 0.80;
	Float_t shatR_gaminvR_c2 = 0.72;
	Float_t shatR_gaminvR_c3 = 0.64;
	Float_t shatR_gaminvR_c4 = 0.56;
	Float_t shatR_gaminvR_c5 = 0.48;
	Float_t shatR_gaminvR_c6 = 0.40;
	Float_t shatR_gaminvR_c7 = 0.32;


	Float_t shatR_c[7] = {0};

	shatR_c[0] = (new_off_prodr)/(shatR_gaminvR_c1+new_off_c_2) - new_off_c_1;
	shatR_c[1] = (new_off_prodr)/(shatR_gaminvR_c2+new_off_c_2) - new_off_c_1;
	shatR_c[2] = (new_off_prodr)/(shatR_gaminvR_c3+new_off_c_2) - new_off_c_1;
	shatR_c[3] = (new_off_prodr)/(shatR_gaminvR_c4+new_off_c_2) - new_off_c_1;
	shatR_c[4] = (new_off_prodr)/(shatR_gaminvR_c5+new_off_c_2) - new_off_c_1;
	shatR_c[5] = (new_off_prodr)/(shatR_gaminvR_c6+new_off_c_2) - new_off_c_1;
	shatR_c[6] = (new_off_prodr)/(shatR_gaminvR_c7+new_off_c_2) - new_off_c_1;




	TEfficiency* shatR_h_eff_tr_new_c1 = (TEfficiency*)output_root_file->Get("shatR_h_eff_tr_c1");
	TEfficiency* shatR_h_eff_tr_new_c2 = (TEfficiency*)output_root_file->Get("shatR_h_eff_tr_c2");
	TEfficiency* shatR_h_eff_tr_new_c3 = (TEfficiency*)output_root_file->Get("shatR_h_eff_tr_c3");
	TEfficiency* shatR_h_eff_tr_new_c4 = (TEfficiency*)output_root_file->Get("shatR_h_eff_tr_c4");
	TEfficiency* shatR_h_eff_tr_new_c5 = (TEfficiency*)output_root_file->Get("shatR_h_eff_tr_c5");
	TEfficiency* shatR_h_eff_tr_new_c6 = (TEfficiency*)output_root_file->Get("shatR_h_eff_tr_c6");
	TEfficiency* shatR_h_eff_tr_new_c7 = (TEfficiency*)output_root_file->Get("shatR_h_eff_tr_c7");


	TCanvas *canvas_shatR = new TCanvas("canvas_shatR","Efficiency shatR");
	canvas_shatR->Clear();
	gPad->SetGrid();
	shatR_h_eff_tr_new_c1->SetTitle("Efficiency ; #sqrt{#hat{s}_{R}}[GeV] ; Efficiency");

	shatR_h_eff_tr_new_c1->SetLineColor(2);
	shatR_h_eff_tr_new_c1->SetMarkerColor(2);
	shatR_h_eff_tr_new_c1->SetMarkerStyle(21);
	shatR_h_eff_tr_new_c1->Draw();

	shatR_h_eff_tr_new_c2->SetLineColor(3);
	shatR_h_eff_tr_new_c2->SetMarkerColor(3);
	shatR_h_eff_tr_new_c2->SetMarkerStyle(22);
	shatR_h_eff_tr_new_c2->Draw("same");

	shatR_h_eff_tr_new_c3->SetLineColor(4);
	shatR_h_eff_tr_new_c3->SetMarkerColor(4);
	shatR_h_eff_tr_new_c3->SetMarkerStyle(23);
	shatR_h_eff_tr_new_c3->Draw("same");

	shatR_h_eff_tr_new_c4->SetLineColor(6);
	shatR_h_eff_tr_new_c4->SetMarkerColor(6);
	shatR_h_eff_tr_new_c4->SetMarkerStyle(33);
	shatR_h_eff_tr_new_c4->Draw("same");
/*
	shatR_h_eff_tr_new_c5->SetLineColor(7);
	shatR_h_eff_tr_new_c5->SetMarkerColor(7);
	shatR_h_eff_tr_new_c5->SetMarkerStyle(34);
	shatR_h_eff_tr_new_c5->Draw("same");


	shatR_h_eff_tr_new_c6->SetLineColor(8);
	shatR_h_eff_tr_new_c6->SetMarkerColor(8);
	shatR_h_eff_tr_new_c6->SetMarkerStyle(29);
	shatR_h_eff_tr_new_c6->Draw("same");



	shatR_h_eff_tr_new_c7->SetLineColor(9);
	shatR_h_eff_tr_new_c7->SetMarkerColor(9);
	shatR_h_eff_tr_new_c7->SetMarkerStyle(20);
	shatR_h_eff_tr_new_c7->Draw("same");

*/


	TString gaminvR_c1 = "0.8";
	TString gaminvR_c2 = "0.72";
 	TString gaminvR_c3 = "0.64";
	TString gaminvR_c4 = "0.56";
	TString gaminvR_c5 = "0.48";
	TString gaminvR_c6 = "0.40";
	TString gaminvR_c7 = "0.32";
        TString gaminvR_c8 = "0.24";
        TString gaminvR_c9 = "0.16";
        TString gaminvR_c10 = "0.08";


	leg = new TLegend(0.63,0.41,0.83,0.90);
	leg->SetTextSize(0.04);
	leg->AddEntry(shatR_h_eff_tr_new_c7,"1/#gamma_{R+1} #geq"+gaminvR_c7, "p");
	leg->AddEntry(shatR_h_eff_tr_new_c6,"1/#gamma_{R+1} #geq"+gaminvR_c6, "p");
	leg->AddEntry(shatR_h_eff_tr_new_c5,"1/#gamma_{R+1} #geq"+gaminvR_c5, "p");
	leg->AddEntry(shatR_h_eff_tr_new_c4,"1/#gamma_{R+1} #geq"+gaminvR_c4, "p");
	leg->AddEntry(shatR_h_eff_tr_new_c3,"1/#gamma_{R+1} #geq"+gaminvR_c3, "p");
	leg->AddEntry(shatR_h_eff_tr_new_c2,"1/#gamma_{R+1} #geq"+gaminvR_c2, "p");
	leg->AddEntry(shatR_h_eff_tr_new_c1,"1/#gamma_{R+1} #geq"+gaminvR_c1, "p");
        leg->Draw();





// 1- Eff

TEfficiency* shatR_h_eff_tr_new_c1_no = (TEfficiency*)output_root_file->Get("shatR_h_eff_tr_c1_no");
TEfficiency* shatR_h_eff_tr_new_c2_no = (TEfficiency*)output_root_file->Get("shatR_h_eff_tr_c2_no");
TEfficiency* shatR_h_eff_tr_new_c3_no = (TEfficiency*)output_root_file->Get("shatR_h_eff_tr_c3_no");
TEfficiency* shatR_h_eff_tr_new_c4_no = (TEfficiency*)output_root_file->Get("shatR_h_eff_tr_c4_no");
TEfficiency* shatR_h_eff_tr_new_c5_no = (TEfficiency*)output_root_file->Get("shatR_h_eff_tr_c5_no");
TEfficiency* shatR_h_eff_tr_new_c6_no = (TEfficiency*)output_root_file->Get("shatR_h_eff_tr_c6_no");
TEfficiency* shatR_h_eff_tr_new_c7_no = (TEfficiency*)output_root_file->Get("shatR_h_eff_tr_c7_no");




	TCanvas *canvas_shatR_no = new TCanvas("canvas_shatR_no","1-Efficiency shatR");
	canvas_shatR_no->Clear();
	canvas_shatR_no->SetLogy();
	gPad->SetGrid();
	shatR_h_eff_tr_new_c1_no->SetTitle("1 - Efficiency ; #sqrt{#hat{s}_{R}}[GeV] ;1 - Efficiency");


	shatR_h_eff_tr_new_c1_no->SetLineColor(2);
	shatR_h_eff_tr_new_c1_no->SetMarkerColor(2);
	shatR_h_eff_tr_new_c1_no->SetMarkerStyle(21);
	shatR_h_eff_tr_new_c1_no->Draw();
	shatR_h_eff_tr_new_c2_no->SetLineColor(3);
	shatR_h_eff_tr_new_c2_no->SetMarkerColor(3);
	shatR_h_eff_tr_new_c2_no->SetMarkerStyle(22);
	shatR_h_eff_tr_new_c2_no->Draw("same");
	shatR_h_eff_tr_new_c3_no->SetLineColor(4);
	shatR_h_eff_tr_new_c3_no->SetMarkerColor(4);
	shatR_h_eff_tr_new_c3_no->SetMarkerStyle(23);
	shatR_h_eff_tr_new_c3_no->Draw("same");
	shatR_h_eff_tr_new_c4_no->SetLineColor(6);
	shatR_h_eff_tr_new_c4_no->SetMarkerColor(6);
	shatR_h_eff_tr_new_c4_no->SetMarkerStyle(33);
	shatR_h_eff_tr_new_c4_no->Draw("same");

/*	shatR_h_eff_tr_new_c5_no->SetLineColor(7);
	shatR_h_eff_tr_new_c5_no->SetMarkerColor(7);
	shatR_h_eff_tr_new_c5_no->SetMarkerStyle(34);
	shatR_h_eff_tr_new_c5_no->Draw("same");

	shatR_h_eff_tr_new_c6_no->SetLineColor(8);
	shatR_h_eff_tr_new_c6_no->SetMarkerColor(8);
	shatR_h_eff_tr_new_c6_no->SetMarkerStyle(29);
	shatR_h_eff_tr_new_c6_no->Draw("same");

	shatR_h_eff_tr_new_c7_no->SetLineColor(9);
	shatR_h_eff_tr_new_c7_no->SetMarkerColor(9);
	shatR_h_eff_tr_new_c7_no->SetMarkerStyle(20);
	shatR_h_eff_tr_new_c7_no->Draw("same");

*/

  	leg_no = new TLegend(0.63,0.41,0.83,0.90);
	leg_no->SetTextSize(0.04);

	leg_no->AddEntry(shatR_h_eff_tr_new_c7_no,"1/#gamma_{R+1} #geq"+gaminvR_c7, "p");
	leg_no->AddEntry(shatR_h_eff_tr_new_c6_no,"1/#gamma_{R+1} #geq"+gaminvR_c6, "p");
	leg_no->AddEntry(shatR_h_eff_tr_new_c5_no,"1/#gamma_{R+1} #geq"+gaminvR_c5, "p");
	leg_no->AddEntry(shatR_h_eff_tr_new_c4_no,"1/#gamma_{R+1} #geq"+gaminvR_c4, "p");
	leg_no->AddEntry(shatR_h_eff_tr_new_c3_no,"1/#gamma_{R+1} #geq"+gaminvR_c3, "p");
	leg_no->AddEntry(shatR_h_eff_tr_new_c2_no,"1/#gamma_{R+1} #geq"+gaminvR_c2, "p");
	leg_no->AddEntry(shatR_h_eff_tr_new_c1_no,"1/#gamma_{R+1} #geq"+gaminvR_c1, "p");
  	leg_no->Draw();





	for(Int_t i = 0 ; i<7; i++){


		cout << shatR_c[i]<< endl;


	}




}



Double_t prodr_funct(Double_t *x, Double_t *par){

	return (x[0] + par[0] )*( x[1] + par[1]);

}

