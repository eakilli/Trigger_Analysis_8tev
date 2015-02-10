#include "razor_trigger_comb.cxx"
#include "trigger_turn_on_comb.cxx"
#include "trigger_turn_on_comb_off.cxx"

using namespace std;
void axial_w8pi_run_over_samples_qcut_comb(){

parseDir("/atlas/data2/userdata/eakilli/razor_output/New_grid_axial");

}


void parseDir(TString dirname){

	cout << "Operating in " << dirname << endl;

	TString file_directory = dirname;
	TString output_directory = "/atlas/data2/userdata/eakilli/razor_output/New_grid_axial/Output_w8pi" ;

	TSystemDirectory dir(dirname, dirname);
	TList *files = dir.GetListOfFiles();

//	vector<Float_t> efficiency_200(0);
	vector<Float_t> efficiency_170(0);
	vector<Float_t> efficiency_all(0);

	vector<Float_t> efficiency_170_off(0);

	Float_t cross_sect1 = 0;
	Float_t cross_sect2 = 0;

	Int_t flag_comb = 0;

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

			flag_comb = 0;
			cross_sect1 = 0;
			cross_sect2 = 0;


			if ( (input_file_name.EndsWith("dma_dm50_mm50_w8pi_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 8.4859E-04;
				cross_sect2 = 4.1717E-02;
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

/*
				// RAZOR VARIABLES AND TRIGGER OVERLAPS

				// Output file razor variables, trigger overlap
				TString temp_input_file_name_razor = input_file_name;
				Ssiz_t pos_razor = temp_input_file_name_razor.Index("qcut80_razor.root");
		      		output_file_name_razor = temp_input_file_name_razor.Remove(pos_razor)+"_output_";
				output_file_name_razor = temp_input_file_name_razor.Remove(0,12);
//				razor_trigger_comb("200",200,85,0.048,  file_directory , input_file_name_1, input_file_name_2, output_directory, output_file_name_razor,cross_sect1,cross_sect2);
                            	razor_trigger_comb("170",170,200,0.0,  file_directory , input_file_name_1, input_file_name_2 , output_directory, output_file_name_razor,cross_sect1,cross_sect2);
*/


				// EFFICIENCY

				//Output file efficiency
                                TString temp_input_file_name_efficiency = input_file_name;
                                Ssiz_t pos_efficiency = temp_input_file_name_efficiency.Index("qcut80_razor.root");
	                 	output_file_name_efficiency = temp_input_file_name_efficiency.Remove(pos_efficiency)+"efficiency_output_";
                                output_file_name_efficiency = temp_input_file_name_efficiency.Remove(0,12);


//				efficiency_200.resize(0);
				efficiency_170.resize(0); efficiency_all.resize(0);
				efficiency_170_off.resize(0);

//				efficiency_200 = trigger_turn_on_comb("200",200,85,0.048,  file_directory , input_file_name_1, input_file_name_2, output_directory, output_file_name_efficiency,cross_sect1,cross_sect2);
				efficiency_170 = trigger_turn_on_comb("170",170,200,0.0,  file_directory , input_file_name_1, input_file_name_2 ,output_directory, output_file_name_efficiency,cross_sect1,cross_sect2);
//				efficiency_170_off = trigger_turn_on_comb_off("170",170,200,0.0, efficiency_170[5],efficiency_170[6],efficiency_170[7],file_directory , input_file_name_1, input_file_name_2 ,output_directory, output_file_name_efficiency,cross_sect1,cross_sect2);


				for(Int_t k = 0; k< efficiency_170.size(); k++){

					efficiency_all.push_back(efficiency_170[k]);

				}


				for(Int_t k = 0 ; k < efficiency_170_off.size() ; k++) {

					efficiency_all.push_back(efficiency_170_off[k]);

				}


				for(Int_t l = 0 ; l<efficiency_all.size() ; l++){

					cout << efficiency_all[l] << endl ;

				}


			}
		}

	}

	else cout << "No files in " <<   <<endl;
}

