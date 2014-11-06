#pragma once
#include "Result_Balls.h"
#include "dlib\mlp.h"

typedef dlib::matrix<bool, RAFFLES_FOR_PREDICTION, 1> appearances_matrix;

using namespace std;

template<int N>
class Ball_Appearances
{
public:
	Ball_Appearances<N>(const int Ball_num);
	Ball_Appearances<N>(const int Ball_num, std::vector<Result_Balls>&, std::vector<Result_Balls>::iterator);

	bool get_appearance_result() {return Array_result; }
	dlib::matrix<bool, N, 1>& get_appearances_array() { return  Appearances_array; }
	
	void print(ostream& output_file = cout);

protected:
	bool Array_result;
	dlib::matrix<bool, N, 1> Appearances_array;
	int array_len;
	const int Ball_num;
};

/*		Implementation		*/

template<int N>
Ball_Appearances<N>::Ball_Appearances(const int array_ball):
	Ball_num(array_ball),
	array_len(N)
{
}

template<int N>
Ball_Appearances<N>::Ball_Appearances(const int array_ball, std::vector<Result_Balls>& raffles_vec, std::vector<Result_Balls>::iterator raffles_vec_start):
	Ball_num(array_ball),
	array_len(N)
{
	int raffle_num=0;
	std::vector<Result_Balls>::iterator raffles_iter = raffles_vec_start;

	Array_result = (raffles_iter++)->is_ball_in_result(Ball_num);

	for ( ; (raffles_iter != raffles_vec.end()) && (raffle_num < N) ; ++raffles_iter, ++raffle_num) 
	{
		Appearances_array(raffle_num) = raffles_iter->is_ball_in_result(Ball_num);
	}
}

template<int N>
void Ball_Appearances<N>::print(ostream& output_file) 
{
	output_file << "Ball number: " << Ball_num << endl;
	output_file << "Result: ";
	if (Array_result)
		output_file << "++ IN ++";
	else
		output_file << "- out -";
	output_file << endl;

	output_file << "[";
	for (int i=0; i<N; i++)
	{
		output_file << Appearances_array(i);
		if (i < N-1) 
			output_file << ", ";
	}
	output_file << "]" << endl << endl;
}