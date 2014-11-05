#pragma once

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////
////	GLOBAL DEFINES
////////////////////////////////////////////////////
#define PRINT_EVERY_ALGORITHM_SEPARATELY
#define PRINT_BEST_PREDICTION
//#define IS_PPMC_HAS_FULL_COVER
#define PRINT_PREDICTIONS_OF_EVERY_ALGORITHM
#define EVEN_ODD_PRINT_EVERY_RAFFLE_RATIO
//#define PPMC_DEBUG_PRINTS

//----- RANDOMNESS LEVEL: MODERATE/CRAZY/DEFAULT + "_RANDOMNESS"
#define DEFAULT_RANDOMNESS

//#define CLUSTERS_ALG_DEBUG_PRINTS

////////////////////////////////////////////////////
////	GLOBAL CONSTANTS
////////////////////////////////////////////////////
extern const int RAFFLES_TO_LOOK_BACK_FOR_APPEARANCES;
extern const int MAX_WINDOW_LENGTH;
extern int VALIDATION_VECTOR_LENGTH;

extern const int GENETIC_ALGORITHM_OFFSPRINGS_NUMBER;
extern const int GENETIC_ALGORITHM_ITERATIONS_NUMBER;

extern const int BALLS_IN_RAFFLE;
#define MAXIMAL_BALL_NUMBER 37
extern const int MAXIMAL_STRONG_BALL_NUMBER;

extern const int RAFFLES_NUMBER_ARRAY_LENGTH;
extern const int RAFFLES_NUMBER_ARRAY[]; 

#define RAFFLES_FOR_PREDICTION = 50;

extern const string input_filename_date;
extern string output_filename_date;
extern string output_filename_postfix;
////////////////////////////////////////////////////
////	GLOBAL VARIABLES
////////////////////////////////////////////////////
extern fstream final_predictor_output;
extern fstream final_predictor_full_output;
extern fstream entire_program_output;
extern stringstream global_output;

////////////////////////////////////////////////////
////	GLOBAL FUNCTIONS
////////////////////////////////////////////////////
void open_global_outputs();
void close_global_outputs();
void add_postfixes_to_filenames(int last_ignored_raffles, int final_validation_vector_length);