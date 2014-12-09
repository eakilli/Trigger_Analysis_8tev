#include "razor_trigger_comb.cxx"
#include "trigger_turn_on_comb.cxx"
#include "trigger_turn_on_comb_off.cxx"

using namespace std;
void run_over_samples_qcut_comb(){

parseDir("/atlas/data2/userdata/eakilli/razor_output/");

}


void parseDir(TString dirname){

	cout << "Operating in " << dirname << endl;

	TString file_directory = dirname;
	TString output_directory = "/afs/cern.ch/user/e/eakilli/razor_8tev/ece_code_8tev/Output_pr_unige_final" ;

	TSystemDirectory dir(dirname, dirname);
	TList *files = dir.GetListOfFiles();

	vector<Float_t> efficiency_200(0);
	vector<Float_t> efficiency_170(0);
	vector<Float_t> efficiency_all(0);

	vector<Float_t> efficiency_170_off(0);

	Float_t cross_sect1 = 0;
	Float_t cross_sect2 = 0;

	Int_t flag_1 = 0;
	Int_t flag_2 = 0;
	Int_t flag_3 = 0;
	Int_t flag_4 = 0;
	Int_t flag_5 = 0;
	int ece = 0;

	if (files) {

		cout << "Found files." << endl;

		TSystemFile *file ;

		TString input_file_name;
		TString output_file_name;

		TString input_file_name_1; //qcut80
		TString input_file_name_2; //qcut300

		TString output_file_name_razor;
		TString output_file_name_efficiency;

		TIter next(files);

		while ((file=(TSystemFile*)next())) {

			input_file_name = file->GetName();


			flag_1 = 0;
			flag_2 = 0;
			flag_3 = 0;
			flag_4 = 0;
			flag_5 = 0;

//			if ((input_file_name.EndsWith("trigger_dm50_mm1000_w3_qcut300_susy_razor.root") ||  input_file_name.EndsWith("trigger_dm400_mm1000_w3_qcut80_susy_razor.root")  || input_file_name.EndsWith("trigger_dm1300_mm100_w3_qcut80_susy_razor.root")     ) && input_file_name(0,12)=="triggerInfo_"){
//			if (input_file_name.EndsWith("susy_razor.root")  && input_file_name(0,12)=="triggerInfo_"){


//			if ( (input_file_name.EndsWith("dm50_mm1000_w3_qcut80_susy_razor.root")|| input_file_name.EndsWith("trigger_dm400_mm1000_w3_qcut80_susy_razor.root") ||  input_file_name.EndsWith("trigger_dm1300_mm100_w3_qcut80_susy_razor.root") )&& input_file_name(0,12)=="triggerInfo_"){



			if ( (input_file_name.EndsWith("dm50_mm1000_w3_qcut80_susy_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){ flag_1 = 1; cout << "file" << endl;}

			if ( (input_file_name.EndsWith("dm400_mm1000_w3_qcut80_susy_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){ flag_2 = 1; cout <<"file2" << endl;}

			if ( (input_file_name.EndsWith("dm1300_mm100_w3_qcut80_susy_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){ flag_3 = 1; cout << "file3"<< endl;}

			if ( (input_file_name.EndsWith("dm50_mm50_w3_qcut80_susy_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){flag_4 = 1; cout << "file4" << endl;}

			if ( (input_file_name.EndsWith("dm400_mm50_w3_qcut80_susy_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){flag_5 = 1; cout << "file5" << endl;}


			cross_sect1 = 0;
			cross_sect2 = 0;


			if(flag_1 == 1) {
				cross_sect1 = 1.4869E-03;
				cross_sect2 = 1.1363E-04; cout << " 1 " << endl;
			}

			if(flag_2 == 1) {
				cross_sect1 = 7.0620E-04;
				cross_sect2 = 6.3103E-05;
			}


			if(flag_3 == 1){
				cross_sect1 = 4.3761E-08;
				cross_sect2 = 5.0431E-09;

			}


			if(flag_4 ==1){

				cross_sect1 =  9.7111E-02;
				cross_sect2 = 1.5375E-03;

			}


			if(flag_5==1){

				cross_sect1 = 1.2034E-04;
				cross_sect2 = 1.0759E-05;

			}



			if( flag_1 == 1 || flag_2 ==1 || flag_3 == 1 || flag_4 == 1 || flag_5 == 1) {

				cout << "Attempting to tamper with file " << input_file_name << endl;

				// Input file names (to be combined)
				TString temp_input_file_name_0 = input_file_name;
				input_file_name_1 = temp_input_file_name_0;
				Ssiz_t pos_0 = temp_input_file_name_0.Index("qcut80_susy_razor.root");
				input_file_name_2 = temp_input_file_name_0.Remove(pos_0)+"qcut300_susy_razor.root";

				cout << "Attempting to tamper with files " << input_file_name_1 << "," <<  input_file_name_2  << endl ;

/*
				// RAZOR VARIABLES AND TRIGGER OVERLAPS

				// Output file razor variables, trigger overlap
				TString temp_input_file_name_razor = input_file_name;
				Ssiz_t pos_razor = temp_input_file_name_razor.Index("qcut80_susy_razor.root");
		      		output_file_name_razor = temp_input_file_name_razor.Remove(pos_razor)+"_output_";
				output_file_name_razor = temp_input_file_name_razor.Remove(0,12);
				razor_trigger_comb("200",200,85,0.048,  file_directory , input_file_name_1, input_file_name_2, output_directory, output_file_name_razor,cross_sect1,cross_sect2);
                            	razor_trigger_comb("170",170,200,0.0,  file_directory , input_file_name_1, input_file_name_2 , output_directory, output_file_name_razor,cross_sect1,cross_sect2);

*/

				// EFFICIENCY

				//Output file efficiency
                                TString temp_input_file_name_efficiency = input_file_name;
                                Ssiz_t pos_efficiency = temp_input_file_name_efficiency.Index("qcut80_susy_razor.root");
	                 	output_file_name_efficiency = temp_input_file_name_efficiency.Remove(pos_efficiency)+"efficiency_output_";
                                output_file_name_efficiency = temp_input_file_name_efficiency.Remove(0,12);


				efficiency_200.resize(0); efficiency_170.resize(0); efficiency_all.resize(0);
				efficiency_170_off.resize(0);

//				efficiency_200 = trigger_turn_on_comb("200",200,85,0.048,  file_directory , input_file_name_1, input_file_name_2, output_directory, output_file_name_efficiency,cross_sect1,cross_sect2);
				efficiency_170 = trigger_turn_on_comb("170",170,200,0.0,  file_directory , input_file_name_1, input_file_name_2 ,output_directory, output_file_name_efficiency,cross_sect1,cross_sect2);
				efficiency_170_off = trigger_turn_on_comb_off("170",170,200,0.0, efficiency_170[5],efficiency_170[6],efficiency_170[7],file_directory , input_file_name_1, input_file_name_2 ,output_directory, output_file_name_efficiency,cross_sect1,cross_sect2);


				for(int k = 0; k< efficiency_170.size(); k++){

					efficiency_all.push_back(efficiency_170[k]);

				}


				for(int k = 0 ; k < efficiency_170_off.size() ; k++) {

					efficiency_all.push_back(efficiency_170_off[k]);

				}


				for(int l = 0 ; l<efficiency_all.size() ; l++){

					cout << efficiency_all[l] << endl ;

				}


			}
		}

	}

	else cout << "No files in " <<   <<endl;
}

