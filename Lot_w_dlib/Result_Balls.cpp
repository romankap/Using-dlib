#include "Result_Balls.h"
#include <stdio.h>
#include <iostream>

const int MAX_BALLS = 6;

Result_Balls::Result_Balls(void) :
	strong_ball(0),
	balls_inserted(0),
	raffle_number(0)
{
}

void Result_Balls::insert_ball(int new_ball)
{
	if (balls_inserted < MAX_BALLS)
	{
		balls.push_back(new_ball);
		balls_inserted++;
	}
	else
		cout << "TOO MANY BALLS" << endl;
}

void Result_Balls::insert_strong_ball(int new_strong_ball)
{
	if (balls_inserted == MAX_BALLS)
		strong_ball = new_strong_ball;
	else
		cout << "Not enough balls to insert the strong ball" << endl;
}

void Result_Balls::print()
{
	cout << raffle_number << ": ";
	for (int i=0; i<MAX_BALLS; i++)
	{
		cout << balls[i];
		if (i != MAX_BALLS-1)
			cout << ", ";
		else
			cout << " & ";
	}
	cout << strong_ball << "." << endl;
}

bool Result_Balls::is_ball_in_result(int ball_number)
{
	for (int i=0; i<MAX_BALLS; i++)
	{
		if(balls[i] == ball_number)
			return true;
	}
	return false;
}

void insert_results_from_file(ifstream& results_file, vector<Result_Balls>& results_vec)
{
	while (!results_file.eof())
	{
		Result_Balls result;
		string tmp_str;

		//raffle number
		getline(results_file, tmp_str, '\t');
		result.insert_raffle_number( atoi(tmp_str.c_str()) );

		//date - not used
		getline(results_file, tmp_str, '\t');

		//balls in order of appearance
		for (int i=0; i<MAX_BALLS; i++)
		{
			getline(results_file, tmp_str, '\t');
			result.insert_ball(tmp_str);
		}

		//strong ball
		getline(results_file, tmp_str, '\t');
		result.insert_strong_ball(tmp_str);

		//Winners number - not used
		getline(results_file, tmp_str, '\n');
		//getline(results_file, tmp_str, '\t');

		results_vec.push_back(result);
	}
}
