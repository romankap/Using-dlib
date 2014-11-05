#pragma once
#include "globals.h"
#include <string>
#include <vector>

//#define DEBUG_PRINTS

using namespace std;

class Result_Balls
{
public:
	Result_Balls(void);
	~Result_Balls(void) {}

	void insert_ball(int ball);
	void insert_ball(string ball) { insert_ball(atoi(ball.c_str())); }
	void insert_strong_ball(int ball);
	void insert_strong_ball(string ball) { insert_strong_ball(atoi(ball.c_str())); }
	void insert_raffle_number(int raf) { raffle_number = raf; }

	bool is_ball_in_result(int ball);

	class iterator
	{
		public:
			iterator(Result_Balls& result) { inner_iterator = result.begin_of_balls(); }
			void	set_start(Result_Balls& result) { inner_iterator = result.begin_of_balls(); }
			bool	is_end(Result_Balls& result) {return inner_iterator == result.end_of_balls(); }
			iterator&	operator++()  { ++inner_iterator; return (*this); }
			int		operator*() { return *inner_iterator; }
		private:
			vector<int>::iterator inner_iterator;
	};

	vector<int>::iterator begin_of_balls() {return balls.begin(); }
	vector<int>::iterator end_of_balls() {return balls.end(); }

	void print();
protected:
	//int balls[BALLS_IN_RAFFLE];
	vector<int> balls;
	int strong_ball;
	int raffle_number;

	int balls_inserted;
};

void insert_results_from_file(ifstream& results_file, vector<Result_Balls>& results_vec);