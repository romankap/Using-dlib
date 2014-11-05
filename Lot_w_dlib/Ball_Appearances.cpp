#include "stdafx.h"
#include "Ball_Appearances.h"

template<int N>
Ball_Appearances<N>::Ball_Appearances(const int array_ball):
	Ball_num(array_ball),
	array_len(N)
{
}

template<int N>
Ball_Appearances<N>::Ball_Appearances(const int array_ball, vector<Result_Balls>& raffles_vec):
	Ball_num(array_ball),
	array_len(N)
{
	int raffle_num=0;
	vector<Result_Balls>::iterator raffles_iter = raffles_vec.begin();
	for ( ; (raffles_iter != raffles_vec.end()) && (raffles_num < N) ; ++raffles_iter, ++raffle_num) 
	{
		Appearances_array[raffle_num] = raffles_iter->is_ball_in_result(Ball_num);
	}
}

template<int N>
Ball_Appearances<N>::~Ball_Appearances(void)
{
}
