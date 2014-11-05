#include "globals.h"

//-----------------------------------------------------------
const int RAFFLES_TO_LOOK_BACK_FOR_APPEARANCES = 50;
const int MAX_WINDOW_LENGTH = 300;
int VALIDATION_VECTOR_LENGTH = 2;

const int GENETIC_ALGORITHM_OFFSPRINGS_NUMBER = 1000;
const int GENETIC_ALGORITHM_ITERATIONS_NUMBER = 200;

const int BALLS_IN_RAFFLE = 6;
//const int MAXIMAL_BALL_NUMBER = 37;
const int MAXIMAL_STRONG_BALL_NUMBER = 7;

const int RAFFLES_NUMBER_ARRAY_LENGTH = 8;
const int RAFFLES_NUMBER_ARRAY[RAFFLES_NUMBER_ARRAY_LENGTH] = {3, 5, 10, 15, 20, 30, 50, 100}; 
//-----------------------------------------------------------

const string outputs_path = "C:\\The_Game\\dlib_Lot_Outputs\\";
const string input_filename_date = ".18.10.14";
string output_filename_date = input_filename_date ;
string output_filename_postfix = "-";
//-----------------------------------------------------------

fstream entire_program_output;
fstream final_predictor_output;
fstream final_predictor_full_output;
stringstream global_output;
//-----------------------------------------------------------

void open_global_outputs()
{
	string entire_program_output_filename = outputs_path + "entire_program_output" + output_filename_date + output_filename_postfix + ".txt";
	string final_predictor_output_filename = outputs_path + "final_predictor_output" + output_filename_date + output_filename_postfix + ".txt";
	string final_predictor_full_output_filename = outputs_path + "final_predictor_full_output" + output_filename_date + output_filename_postfix + ".txt";

	entire_program_output.open(entire_program_output_filename.c_str(), ios::out | ios::trunc);
	final_predictor_output.open(final_predictor_output_filename.c_str(), ios::out | ios::app);
	final_predictor_full_output.open(final_predictor_full_output_filename.c_str(), ios::out | ios::app);
}

void close_global_outputs()
{
	global_output << "----------------- END -----------------" << endl;
	global_output << "---------------------------------------" << endl;

	global_output.seekg (0, global_output.end);
    int length = global_output.tellg();
    global_output.seekg (0, global_output.beg);

    char * buffer = new char [length+1];
	buffer[length] = '\0';

    // read data as a block:
    global_output.read (buffer,length);

	//std::cout << buffer;
	entire_program_output << buffer;

	entire_program_output.close();
	final_predictor_output.close();
	final_predictor_full_output.close();

	//Emptying all strings and buffers
	global_output.str(string()); 
	delete[] buffer;
	entire_program_output.clear();
	final_predictor_output.clear();
	final_predictor_full_output.clear();
}

void add_postfixes_to_filenames(int last_ignored_raffles, int final_validation_vector_length)
{
	/*
	char output_filename_date_postfix[10];	
	sprintf(output_filename_date_postfix, "-%d", last_ignored_raffles);
	output_filename_date = input_filename_date + output_filename_date_postfix;*/

	char filename_postfix_number[20];
	sprintf(filename_postfix_number, "-%d_ValLen=%d", last_ignored_raffles, final_validation_vector_length);
	output_filename_postfix = filename_postfix_number;
}

