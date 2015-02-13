#include "razor_trigger_comb.cxx"
#include "trigger_turn_on_comb.cxx"
#include "trigger_turn_on_comb_off.cxx"

using namespace std;
void vector_w3_run_over_samples_qcut_comb(){

parseDir("/atlas/data2/userdata/eakilli/razor_output/New_grid");

}


void parseDir(TString dirname){

	Float_t off_prodr = 115;
	Float_t off_c1 = -252;
	Float_t off_c2 = -0.08;
	TString off_prodr_string = "115";

	cout << "Operating in " << dirname << endl;

	TString file_directory = dirname;
	TString output_directory = "/atlas/data2/userdata/eakilli/razor_output/New_grid/Output_w3" ;

	TSystemDirectory dir(dirname, dirname);
	TList *files = dir.GetListOfFiles();

	vector<Float_t> efficiency_170_off(0);
	vector<Float_t> efficiency_all(0);

	Float_t cross_sect1 = 0;
	Float_t cross_sect2 = 0;

	Int_t flag_comb = 0;

	int ece = 0;


	// Text files for efficiency comparison later
	TString choose_txt_directory = "/afs/cern.ch/user/e/eakilli/razor_8tev/ece_code_8tev/Output_text";

	ofstream  				            dm_file(choose_txt_directory+"/dm_vector_w3_file.txt");
	ofstream  							   mm_file(choose_txt_directory+"/mm_vector_w3_file.txt");
	ofstream  	    file_efficiencies_eff_xe(choose_txt_directory+"/vector_w3_file_efficiencies_eff_xe.txt");
	ofstream  	  file_efficiencies_eff_or_1(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_1.txt");
	ofstream  	  file_efficiencies_eff_or_2(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_2.txt");
	ofstream  	  file_efficiencies_eff_or_3(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_3.txt");
	ofstream  	  file_efficiencies_eff_or_4(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_4.txt");
	ofstream  	file_efficiencies_eff_xe_off(choose_txt_directory+"/vector_w3_file_efficiencies_eff_xe_off.txt");
	ofstream  file_efficiencies_eff_or_1_off(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_1_off.txt");
	ofstream  file_efficiencies_eff_or_2_off(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_2_off.txt");
	ofstream  file_efficiencies_eff_or_3_off(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_3_off.txt");
	ofstream  file_efficiencies_eff_or_4_off(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_4_off.txt");
	ofstream  file_efficiencies_eff_or_5_off(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_5_off.txt");
	ofstream  file_efficiencies_eff_or_6_off(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_6_off.txt");


	ofstream  	    file_efficiencies_eff_xe_2j(choose_txt_directory+"/vector_w3_file_efficiencies_eff_xe_2j.txt");
	ofstream  	  file_efficiencies_eff_or_1_2j(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_1_2j.txt");
	ofstream  	  file_efficiencies_eff_or_2_2j(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_2_2j.txt");
	ofstream  	  file_efficiencies_eff_or_3_2j(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_3_2j.txt");
	ofstream  	  file_efficiencies_eff_or_4_2j(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_4_2j.txt");
	ofstream  	file_efficiencies_eff_xe_off_2j(choose_txt_directory+"/vector_w3_file_efficiencies_eff_xe_off_2j.txt");
	ofstream  file_efficiencies_eff_or_1_off_2j(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_1_off_2j.txt");
	ofstream  file_efficiencies_eff_or_2_off_2j(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_2_off_2j.txt");
	ofstream  file_efficiencies_eff_or_3_off_2j(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_3_off_2j.txt");
	ofstream  file_efficiencies_eff_or_4_off_2j(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_4_off_2j.txt");
	ofstream  file_efficiencies_eff_or_5_off_2j(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_5_off_2j.txt");
	ofstream  file_efficiencies_eff_or_6_off_2j(choose_txt_directory+"/vector_w3_file_efficiencies_eff_or_6_off_2j.txt");


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


			if ( (input_file_name.EndsWith("dmv_dm50_mm50_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 9.7111E-02;
				cross_sect2 = 1.5375E-03;
				flag_comb++;
				dm_file << 50 << endl;
				mm_file << 50 << endl;
			}

			if ( (input_file_name.EndsWith("dmv_dm50_mm100_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 2.9907E-01;
				cross_sect2 = 3.8267E-03;
				flag_comb++;
				dm_file << 50  << endl;
				mm_file << 100 << endl;
			}

			if ( (input_file_name.EndsWith("dmv_dm50_mm300_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 7.1889E-02;
				cross_sect2 = 2.2939E-03;
				flag_comb++;
				dm_file << 50 << endl;
				mm_file << 300 << endl;

			}

			if ( (input_file_name.EndsWith("dmv_dm50_mm600_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 9.4679E-03;
				cross_sect2 = 5.5195E-04;
				flag_comb++;
				dm_file << 50  << endl;
				mm_file << 600 << endl;
			}

			if ( (input_file_name.EndsWith("dmv_dm50_mm1000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 1.4869E-03;
				cross_sect2 = 1.1363E-04;
				flag_comb++;
				dm_file << 50 << endl;
				mm_file << 1000 << endl;
			}

			if ( (input_file_name.EndsWith("dmv_dm50_mm3000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 8.7935E-06;
				cross_sect2 = 6.9580E-07;
				flag_comb++;
				dm_file << 50 << endl;
				mm_file << 3000 << endl;

			}

			if ( (input_file_name.EndsWith("dmv_dm50_mm6000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 4.3139E-07;
				cross_sect2 = 3.0427E-08;
				flag_comb++;
				dm_file <<  50 << endl;
				mm_file <<  6000 << endl;
			}

			if ( (input_file_name.EndsWith("dmv_dm50_mm10000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 5.3874E-08;
				cross_sect2 = 3.7327E-09;
				flag_comb++;
				dm_file << 50 << endl;
				mm_file << 10000 << endl;
			}

			if ( (input_file_name.EndsWith("dmv_dm50_mm30000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 6.5714E-10;
				cross_sect2 = 4.5056E-11;
				flag_comb++;
				dm_file << 50 << endl;
				mm_file << 30000 << endl;
			}

			if ( (input_file_name.EndsWith("dmv_dm400_mm50_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 1.2034E-04;
				cross_sect2 = 1.0759E-05;
				flag_comb++;
				dm_file << 400 << endl;
				mm_file <<  50 << endl;
			}

			if ( (input_file_name.EndsWith("dmv_dm400_mm100_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 1.2350E-04;
				cross_sect2 = 1.0920E-05;
				flag_comb++;
				dm_file << 400 << endl;
				mm_file <<  100 << endl;
			}

			if ( (input_file_name.EndsWith("dmv_dm400_mm300_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 1.4860E-04;
				cross_sect2 = 1.2936E-05;
				flag_comb++;
				dm_file << 400 << endl;
				mm_file << 300 << endl;
			}

			if ( (input_file_name.EndsWith("dmv_dm400_mm600_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 3.0935E-04;
				cross_sect2 = 2.6166E-05;
				flag_comb++;
				dm_file << 400 << endl;
				mm_file <<  600 << endl;
			}

			if ( (input_file_name.EndsWith("dmv_dm400_mm1000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 7.0620E-04;
				cross_sect2 = 6.3103E-05;
				flag_comb++;
				dm_file << 400 << endl;
				mm_file <<  1000 << endl;
			}

			if ( (input_file_name.EndsWith("dmv_dm400_mm3000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 4.4852E-06;
				cross_sect2 = 4.6517E-07;
				flag_comb++;
				dm_file << 400  << endl;
				mm_file << 3000 << endl;
			}

			if ( (input_file_name.EndsWith("dmv_dm400_mm6000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 1.7366E-07;
				cross_sect2 = 1.6857E-08;
				flag_comb++;
				dm_file <<  400 << endl;
				mm_file <<  6000 << endl;
			}

			if ( (input_file_name.EndsWith("dmv_dm400_mm10000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 2.0742E-08;
				cross_sect2 = 2.0086E-09;
				flag_comb++;
				dm_file << 400 << endl;
				mm_file <<  10000 << endl;
			}

			if ( (input_file_name.EndsWith("dmv_dm400_mm30000_w3_qcut80_razor.root"))  && input_file_name(0,12)=="triggerInfo_"){
				cross_sect1 = 2.4684E-10;
				cross_sect2 = 2.3864E-11;
				flag_comb++;
				dm_file << 400 << endl;
				mm_file << 30000 << endl;
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


				efficiency_170_off.resize(0);
				efficiency_all.resize(0);

				trigger_turn_on_comb("170",170,200,0.0,off_prodr_string ,off_prodr,off_c1, off_c2, file_directory , input_file_name_1, input_file_name_2 ,output_directory, output_file_name_efficiency,cross_sect1,cross_sect2);

				efficiency_170_off = trigger_turn_on_comb_off("170",170,200,0.0, off_prodr,off_c1, off_c2, file_directory , input_file_name_1, input_file_name_2 ,output_directory, output_file_name_efficiency,cross_sect1,cross_sect2);


				for(Int_t k = 0 ; k < efficiency_170_off.size() ; k++) {

					efficiency_all.push_back(efficiency_170_off[k]);

				}



/*                                for(Int_t l = 0 ; l<efficiency_all.size() ; l++){

                                        cout << efficiency_all[l] << endl ;

                                }
*/


				 	    file_efficiencies_eff_xe << efficiency_all[0] << endl;
				 	  file_efficiencies_eff_or_1 << efficiency_all[1] << endl;
				 	  file_efficiencies_eff_or_2 << efficiency_all[2] << endl;
				 	  file_efficiencies_eff_or_3 << efficiency_all[3] << endl;
				 	  file_efficiencies_eff_or_4 << efficiency_all[4] << endl;
				 	file_efficiencies_eff_xe_off << efficiency_all[5] << endl;
				 file_efficiencies_eff_or_1_off << efficiency_all[6] << endl;
				 file_efficiencies_eff_or_2_off << efficiency_all[7] << endl;
				 file_efficiencies_eff_or_3_off << efficiency_all[8] << endl;
				 file_efficiencies_eff_or_4_off << efficiency_all[9] << endl;
				 file_efficiencies_eff_or_5_off << efficiency_all[10] << endl;
				 file_efficiencies_eff_or_6_off << efficiency_all[11] << endl;
				
				
				 	    file_efficiencies_eff_xe_2j << efficiency_all[12] << endl;
				 	  file_efficiencies_eff_or_1_2j << efficiency_all[13] << endl;
				 	  file_efficiencies_eff_or_2_2j << efficiency_all[14] << endl;
				 	  file_efficiencies_eff_or_3_2j << efficiency_all[15] << endl;
				 	  file_efficiencies_eff_or_4_2j << efficiency_all[16] << endl;
				 	file_efficiencies_eff_xe_off_2j << efficiency_all[17] << endl;
				 file_efficiencies_eff_or_1_off_2j << efficiency_all[18] << endl;
				 file_efficiencies_eff_or_2_off_2j << efficiency_all[19] << endl;
				 file_efficiencies_eff_or_3_off_2j << efficiency_all[20] << endl;
				 file_efficiencies_eff_or_4_off_2j << efficiency_all[21] << endl;
				 file_efficiencies_eff_or_5_off_2j << efficiency_all[22] << endl;
				 file_efficiencies_eff_or_6_off_2j << efficiency_all[23] << endl;







			}
		}

	}


	else cout << "No files in " <<   <<endl;


	 				            dm_file.close();
	 							   mm_file.close();
	 	    file_efficiencies_eff_xe.close();
	 	  file_efficiencies_eff_or_1.close();
	 	  file_efficiencies_eff_or_2.close();
	 	  file_efficiencies_eff_or_3.close();
	 	  file_efficiencies_eff_or_4.close();
	 	file_efficiencies_eff_xe_off.close();
	 file_efficiencies_eff_or_1_off.close();
	 file_efficiencies_eff_or_2_off.close();
	 file_efficiencies_eff_or_3_off.close();
	 file_efficiencies_eff_or_4_off.close();
	 file_efficiencies_eff_or_5_off.close();
	 file_efficiencies_eff_or_6_off.close();

	 	    file_efficiencies_eff_xe_2j.close();
	 	  file_efficiencies_eff_or_1_2j.close();
	 	  file_efficiencies_eff_or_2_2j.close();
	 	  file_efficiencies_eff_or_3_2j.close();
	 	  file_efficiencies_eff_or_4_2j.close();
	 	file_efficiencies_eff_xe_off_2j.close();
	 file_efficiencies_eff_or_1_off_2j.close();
	 file_efficiencies_eff_or_2_off_2j.close();
	 file_efficiencies_eff_or_3_off_2j.close();
	 file_efficiencies_eff_or_4_off_2j.close();
	 file_efficiencies_eff_or_5_off_2j.close();
	 file_efficiencies_eff_or_6_off_2j.close();


}

