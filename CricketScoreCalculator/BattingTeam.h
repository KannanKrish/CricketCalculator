#pragma once

class team
{
public:
	char name[25];
	float strike_rate;
	int run;
	int ball_facing;
	int fours;
	int sixes;
	int status;
};

__declspec(selectany) team bat[12];
__declspec(selectany) char bowling_team_name[25];
__declspec(selectany) char batting_team_name[25];
__declspec(selectany) int bo_count;
__declspec(selectany) int nb;
__declspec(selectany) int over; // Maximum Overs Going To Play
__declspec(selectany) int wicket;
__declspec(selectany) int b_count;
__declspec(selectany) int* ball;
__declspec(selectany) char run[5];

void team_details();
void color(int, int);
void run_by_ball();
void run_by_over();
void display_ball();
void display_over();
void display_wicket();
void bat_statistics();

