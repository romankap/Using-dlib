#pragma once

#include "iostream"
#include <dlib/mlp.h>
#include "globals.h"
#include "Result_Balls.h"

using namespace dlib;

// This typedef declares a matrix with 2 rows and 1 column.  It will be the
// object that contains each of our 2 dimensional samples.   (Note that if you wanted 
// more than 2 features in this vector you can simply change the 2 to something else)
typedef dlib::matrix<double, 2, 1> sample_type;
typedef dlib::matrix<double, MAXIMAL_BALL_NUMBER, 1> raffle_result;

class Raffles_ANN {
public:
	Raffles_ANN(int input_nodes_num, 
				int first_hidden_nodes_num, int second_hidden_nodes_num, 
				int output_nodes_num,
				double alpha, double momentum);
	
	void train();	//Train the ANN with a training set
	void classify();	// Get a classification after training
	void test(); //Check result for validation vector 

	int get_input_nodes_num() { return input_nodes_num; }
	int get_first_nodes_num() { return first_hidden_nodes_num; }
	int get_second_nodes_num() { return second_hidden_nodes_num; }
	int get_output_nodes_num() { return output_nodes_num; }
	double get_alpha() {return alpha; }
	double get_momentum() {return momentum; }

private:
	int input_nodes_num;
	int first_hidden_nodes_num;
	int second_hidden_nodes_num;
	int output_nodes_num;
	double alpha, momentum;

	mlp::kernel_1a_c net;
};