#pragma once
#include "Result_Balls.h"

template<int N>
class Ball_Appearances
{
public:
	Ball_Appearances<N>(const int Ball_num);
	Ball_Appearances<N>(const int Ball_num, vector<Result_Balls>&);
	~Ball_Appearances<N>(void);

protected:
	bool Appearances_array[N];
	int array_len;
	const int Ball_num;
};
