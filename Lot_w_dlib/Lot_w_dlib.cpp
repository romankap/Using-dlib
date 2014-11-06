// Lot_w_dlib.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "globals.h"
#include "dlib\any.h"
#include "ANN.h"
#include "Result_Balls.h"
#include "Ball_Appearances.h"
#include "Ball_ANN.h"

using namespace std;


int main(int argc, char* argv[])
{

	string string_file_name = "C:\\The_Game\\Lot_Inputs\\Lotto" + input_filename_date + ".txt";
	cout << "Starting to work on input file: " << string_file_name << endl;

	for (int VALIDATION_VECTOR_LENGTH=5; VALIDATION_VECTOR_LENGTH<=5; ++VALIDATION_VECTOR_LENGTH) // Controls Valida
	{
		add_postfixes_to_filenames(0, VALIDATION_VECTOR_LENGTH);
		open_global_outputs();
		srand(time(NULL));
				
		std::vector<Result_Balls> all_raffles_vec;
		ifstream all_raffles_file(string_file_name.c_str());
		if (all_raffles_file.fail())
		{
			cout << "!!! BAD INPUT FILENAME !!!" << endl;
			exit(1);
		}

		insert_results_from_file(all_raffles_file, all_raffles_vec);

		//PredictionValidation predictionValidator;
		//GeneticAlgorithm geneticAlgorithm(all_raffles_vec, predictionValidator);
		//geneticAlgorithm.find_best_algorithm();
		
		//Statistics
		//find_all_balls_last_appearances(results_vec, RAFFLES_TO_LOOK_BACK_FOR_APPEARANCES);
		//count_even_odd_ratio(all_raffles_vec.begin(), all_raffles_vec, global_output);
		//count_range_ratios(all_raffles_vec.begin(), all_raffles_vec, global_output);
		//close_global_outputs();

		for (int ball_num=1; ball_num <= MAXIMAL_BALL_NUMBER; ++ball_num) {
			Ball_Appearances<RAFFLES_FOR_PREDICTION> raffle_to_predict(ball_num, all_raffles_vec, all_raffles_vec.begin());
			
			std::vector<Result_Balls>::iterator begin_of_training_set = all_raffles_vec.begin();
			++begin_of_training_set;

			Ball_ANN<RAFFLES_FOR_PREDICTION> ball_ann(ball_num);
			ball_ann.train(all_raffles_vec, begin_of_training_set);
			
			raffle_to_predict.print();
			cout << "Predcition val: " << ball_ann.classify(raffle_to_predict) << endl;
		}
		
		cout << "Done with "<< output_filename_date + output_filename_postfix; 
		cout << " (Validation Len: " << VALIDATION_VECTOR_LENGTH << ")" << endl;
	}

	//Close outputs 
	cout << "Done!" << endl;
	return 0;

}
