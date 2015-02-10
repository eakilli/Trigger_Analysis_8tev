#include "razor_trigger.cxx"
#include "trigger_efficiency.cxx"

void run_over_samples(){

parseDir("/atlas/data2/userdata/eakilli/razor_output/");


}


void parseDir(TString dirname){

	cout << "Operating in " << dirname << endl;

	TString file_directory = dirname;
	TString output_directory = "/afs/cern.ch/user/e/eakilli/razor/ece_code_8tev/Output_eff";

	TSystemDirectory dir(dirname, dirname);
	TList *files = dir.GetListOfFiles();


	vector<Float_t> efficiency_200(0);
	vector<Float_t> efficiency_170(0);
	vector<Float_t> efficiency_all(0);

	if (files){

		cout << "Found files." << endl;

		TSystemFile *file;

		TString input_file_name;
		TString output_file_name;

		TIter next(files);

		while ((file=(TSystemFile*)next())) {
			input_file_name = file->GetName();
//			cout << input_file_name << endl;

			if ((input_file_name.EndsWith("trigger_dm50_mm1000_w3_qcut300_susy_razor.root") ||  input_file_name.EndsWith("trigger_dm400_mm1000_w3_qcut80_susy_razor.root")  || input_file_name.EndsWith("trigger_dm1300_mm100_w3_qcut80_susy_razor.root")     ) && input_file_name(0,12)=="triggerInfo_"){
//			if (input_file_name.EndsWith("susy_razor.root")  && input_file_name(0,12)=="triggerInfo_"){

				cout << "Attempting to tamper with file " << input_file_name << endl;
				TString temp_input_file_name = input_file_name;
				Ssiz_t pos = temp_input_file_name.Index(".root");
//		      		output_file_name = temp_input_file_name.Remove(pos)+"_output_";
                                output_file_name = temp_input_file_name.Remove(pos)+"efficiency_output_";
				output_file_name = temp_input_file_name.Remove(0,12);
//				razor_trigger("200",200,85,0.048,  file_directory , input_file_name, output_directory, output_file_name);
//                            	razor_trigger("170",170,200,0.0,  file_directory , input_file_name, output_directory, output_file_name);

				efficiency_200.resize(0); efficiency_170.resize(0); efficiency_all.resize(0);
				efficiency_200 = trigger_efficiency("200",200,85,0.048,  file_directory , input_file_name, output_directory, output_file_name);
				efficiency_170 = trigger_efficiency("170",170,200,0.0,  file_directory , input_file_name, output_directory, output_file_name);

					efficiency_all.push_back(efficiency_200[0]);
					efficiency_all.push_back(efficiency_200[1]);
					efficiency_all.push_back(efficiency_200[2]);
					efficiency_all.push_back(efficiency_170[1]);
					efficiency_all.push_back(efficiency_170[2]);

				for(int l = 0 ; l<5 ; l++){

					cout << efficiency_all[l] << endl ;

				}


			}
		}

	}
	else cout << "No files in " <<   <<endl;
}


//    	TString file_directory = "/atlas/data2/userdata/eakilli/razor_output";
//   	TString output_directory = "/afs/cern.ch/user/e/eakilli/razor/HarvardTriggerCode/D3PDtoTrigger/ece_code/Output";
//   	TString input_file_name = "triggerInfo_8tev_trigger_dm400_mm1000_w8pi_qcut80_susy_razor.root";
// 	TString output_file_name = input_file_name.Remove(input_file_name.Index(".root"))+"_output_";

