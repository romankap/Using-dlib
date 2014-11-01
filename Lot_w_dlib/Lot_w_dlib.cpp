// Lot_w_dlib.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "globals.h"
#include "dlib\any.h"
#include "ANN.h"
#include "Result_Balls.h"

using namespace std;



int main(int argc, char* argv[])
{

	string string_file_name = "C:\\The_Game\\Lot_Inputs\\Lotto" + input_filename_date + ".txt";
	cout << "Starting to work on input file: " << string_file_name << endl;

	for (int last_ignored_raffles=0; last_ignored_raffles<1; ++last_ignored_raffles)
	{
		for (int VALIDATION_VECTOR_LENGTH=5; VALIDATION_VECTOR_LENGTH<=5; ++VALIDATION_VECTOR_LENGTH) // Controls Valida
		{
			add_postfixes_to_filenames(last_ignored_raffles, VALIDATION_VECTOR_LENGTH);
			open_global_outputs();
			srand(time(NULL));
				
			vector<Result_Balls> all_raffles_vec;
			ifstream all_raffles_file(string_file_name.c_str());
			if (all_raffles_file.fail())
			{
				cout << "!!! BAD INPUT FILENAME !!!" << endl;
				exit(1);
			}

			insert_results_from_file(all_raffles_file, all_raffles_vec);
			for (int k=0; k<last_ignored_raffles; ++k)
			{
				all_raffles_vec.erase(all_raffles_vec.begin());
			}

			//PredictionValidation predictionValidator;
			//GeneticAlgorithm geneticAlgorithm(all_raffles_vec, predictionValidator);
			//geneticAlgorithm.find_best_algorithm();
		
			//Statistics
			//find_all_balls_last_appearances(results_vec, RAFFLES_TO_LOOK_BACK_FOR_APPEARANCES);
			//count_even_odd_ratio(all_raffles_vec.begin(), all_raffles_vec, global_output);
			//count_range_ratios(all_raffles_vec.begin(), all_raffles_vec, global_output);
			close_global_outputs();

			cout << "Done with "<< output_filename_date + output_filename_postfix; 
			cout << "  (ignored_raffles: " << last_ignored_raffles << ", Validation Len: " << VALIDATION_VECTOR_LENGTH << ")" << endl;
		}
	}

	//Close outputs 
	cout << "Done!" << endl;
	return 0;

}
