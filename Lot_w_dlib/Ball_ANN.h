#pragma once
#include "iostream"
#include <dlib/mlp.h>
#include "globals.h"
#include "Result_Balls.h"

using namespace std;

// This typedef declares a matrix with 2 rows and 1 column.  It will be the
// object that contains each of our 2 dimensional samples.   (Note that if you wanted 
// more than 2 features in this vector you can simply change the 2 to something else)
typedef dlib::matrix<bool, MAXIMAL_BALL_NUMBER, 1> sample_type;

template <int N>
class Ball_ANN {
public:
	Ball_ANN<N>(int Ball_num);
	Ball_ANN<N>(int input_nodes_num, 
				int first_hidden_nodes_num, int second_hidden_nodes_num, 
				int output_nodes_num,
				double alpha, double momentum,
				int Ball_num);
	
	void train(std::vector<Result_Balls>& raffles_vector, std::vector<Result_Balls>::iterator begin_of_training_set);	//Train the ANN with a training set
	double classify(Ball_Appearances<N>& ball_appearances);	// Get a classification after training
	void test(); //Check result for validation vector 

	int get_Ball_num() { return Ball_num; } ;
	
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

	int Ball_num;

	dlib::mlp::kernel_1a_c net;
};

template<int N>
Ball_ANN<N>::Ball_ANN(int _ball_num):
	Ball_num(_ball_num),
	net(RAFFLES_FOR_PREDICTION, RAFFLES_FOR_PREDICTION/2, RAFFLES_FOR_PREDICTION/5)
{
}

template<int N>
Ball_ANN<N>::Ball_ANN(int _input_nodes_num, 
						int _first_hidden_nodes_num, int _second_hidden_nodes_num, 
						int _output_nodes_num,
						double _alpha, double _momentum,
						int _ball_num):
input_nodes_num(_input_nodes_num),
	first_hidden_nodes_num(_input_nodes_num),
	second_hidden_nodes_num(_second_hidden_nodes_num),
	output_nodes_num(_output_nodes_num),
	alpha(_alpha),
	momentum(_momentum),
	Ball_num(_ball_num),
	net(input_nodes_num, first_hidden_nodes_num, second_hidden_nodes_num, output_nodes_num, alpha, momentum)
{
}

template<int N>
void Ball_ANN<N>::train(std::vector<Result_Balls>& raffles_vector, std::vector<Result_Balls>::iterator begin_of_training_set) {
	std::vector<Result_Balls>::iterator training_iterator = begin_of_training_set;

	for (int raffles_counter=0; raffles_counter < 1000; ++raffles_counter, ++training_iterator)
	{
		Ball_Appearances<RAFFLES_FOR_PREDICTION> training_raffle(Ball_num, raffles_vector, training_iterator);
		net.train(training_raffle.get_appearances_array(), training_raffle.get_appearance_result());
	}
}

template<int N>
double Ball_ANN<N>::classify(Ball_Appearances<N>& ball_appearances) {
	return net(ball_appearances.get_appearances_array());
}