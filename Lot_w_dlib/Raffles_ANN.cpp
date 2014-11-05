#include "Raffles_ANN.h"

using namespace std;
using namespace dlib;

Raffles_ANN::Raffles_ANN(int _input_nodes_num, 
						int _first_hidden_nodes_num, int _second_hidden_nodes_num, 
						int _output_nodes_num,
						double _alpha, double _momentum):
input_nodes_num(_input_nodes_num),
	first_hidden_nodes_num(_input_nodes_num),
	second_hidden_nodes_num(_second_hidden_nodes_num),
	output_nodes_num(_output_nodes_num),
	alpha(_alpha),
	momentum(_momentum),
	net(input_nodes_num, first_hidden_nodes_num, second_hidden_nodes_num, output_nodes_num, alpha, momentum)
{
}

void Raffles_ANN::train() {
	// input: vector of fixed length binary result for each ball
	// for raffle in all_raffles:
	//		net.train(raffle, raffle_result)
}

void Raffles_ANN::classify() {
	sample_type sample;

	for (int i = 0; i < 1000; ++i)
    {
        for (int r = -20; r <= 20; ++r)
        {
            for (int c = -20; c <= 20; ++c)
            {
                sample(0) = r;
                sample(1) = c;

                // if this point is less than 10 from the origin
                if (sqrt((double)r*r + c*c) <= 10)
                    net.train(sample,1);
                else
                    net.train(sample,0);
            }
        }
    }
}