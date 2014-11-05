#pragma once

#include "iostream"
#include <dlib/mlp.h>
#include "globals.h"

// This typedef declares a matrix with 2 rows and 1 column.  It will be the
// object that contains each of our 2 dimensional samples.   (Note that if you wanted 
// more than 2 features in this vector you can simply change the 2 to something else)
typedef dlib::matrix<double, 2, 1> sample_type;
typedef dlib::matrix<double, MAXIMAL_BALL_NUMBER, 1> raffle_result;

class ANN {
public:
	void classify();

private:
	int input_nodes_num;
	int first_hidden_nodes_num;
	int second_hidden_nodes_num;
	int ouput_nodes_num;

};