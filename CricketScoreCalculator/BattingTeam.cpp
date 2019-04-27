#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <conio.h>

#include "BattingTeam.h"

void run_by_ball()
{
s:
	int bp;
	system("CLS");
	std::cout << "Enter the position of ball : ";
	std::cin >> bp;
	if (bp <= over * 6 && bp >= 1)
	{
		if (ball[bp] == -1)
			b_count++;
		else if (ball[bp] == -2)
			wicket--;
		std::cout << "\n\nEnter the score : ";
		std::cin >> run;
		char b[] = "wicket", c[] = "WICKET", d[] = "Wicket", e[] = "W", f[] = "w";
		char bb[] = "r", bc[] = "run out";
		if (strcmp(run, b) == 0 || strcmp(run, c) == 0 || strcmp(run, d) == 0 || strcmp(run, e) == 0 || strcmp(run, f) == 0)
		{
			wicket += 1;
			ball[bp] = -2;
		}
		else if (strcmp(run, bb) == 0 || strcmp(run, bc) == 0)
		{
			wicket += 1;
			std::cout << "\n\nNon striker is out press 1 : ";
			int h;
			std::cin >> h;
			if (h == 1)
				ball[bp] = -3;
			else
				ball[bp] = -2;
		}
		else if (wicket >= 10)
			std::cout << "\n\nGame is over";
		else
			ball[bp] = atoi(run);
	}
	else
		std::cout << "\n\nYou can not insert score in this position";
	std::cout << "\n\nIf continue press 1\n\nPress any key to main menu";
	int j;
	std::cin >> j;
	if (j == 1)
		goto s;
}
void run_by_over()
{
s:
	int op, i;
	system("CLS");
	std::cout << "Enter the position of over : ";
	std::cin >> op;
	const int v = op * 6 - 5;
	if (op <= over && op >= 1)
	{
		for (i = 0; i < 6; i++)
		{
			if (ball[v + i] == -1)
				b_count++;
			else if (ball[v + i] == -2 || ball[v + i] == -3)
				wicket--;
			char b[] = "wicket", c[] = "WICKET", d[] = "Wicket", e[] = "W", f[] = "w";
			std::cout << "\n\nEnter the score for " << std::setw(3) << i + v << " ball : ";
			std::cin >> run;
			if (strcmp(run, b) == 0 || strcmp(run, c) == 0 || strcmp(run, d) == 0 || strcmp(run, e) == 0 || strcmp(run, f) == 0)
			{
				wicket += 1;
				ball[v + i] = -2;
			}
			char bb[] = "r", bc[] = "run out";
			if (strcmp(run, bb) == 0 || strcmp(run, bc) == 0)
			{
				wicket += 1;
				std::cout << "\n\nEnter 1 for non striker is out : ";
				int h;
				std::cin >> h;
				if (h == 1)
					ball[v + i] = -3;
				else
					ball[v + i] = -2;
			}
			else
				ball[v + i] = atoi(run);
		}
	}
	else
		std::cout << "\n\nYou can not insert the score this position";
	std::cout << "\n\nIf you try again press 1\n\nPress any key to main menu";
	std::cin >> i;
	if (i == 1)
		goto s;
}
void display_ball()
{
s:
	int bp;
	system("CLS");
	std::cout << "Enter the position of ball : ";
	std::cin >> bp;
	if (bp <= over * 6 && bp >= 1)
	{
		if (ball[bp] == -2 || ball[bp] == -3)
			std::cout << "\n\nScore for " << bp << " is : "
			<< "Wicket";
		else if (ball[bp] == -1)
			std::cout << "\n\nScore for " << bp << " is : "
			<< "0";
		else if (ball[bp] >= 0)
			std::cout << "\n\nScore for " << bp << " is : " << ball[bp];
	}
	else
		std::cout << "\n\nYou can not view score in this position";
	std::cout << "\n\nIf continue this press 1\n\nPress any key to main menu";
	int i;
	std::cin >> i;
	if (i == 1)
		goto s;
}

void display_over()
{
s:
	int run = 0;
	system("CLS");
	int op;
	std::cout << "Enter the position of over : ";
	std::cin >> op;
	const int v = op * 6 - 5;
	if (op <= over && op >= 1)
	{
		for (int i = 0; i < 6; i++)
		{
			if (ball[v + i] == -1)
				std::cout << "\n\nThe score for " << std::setw(3) << v + i << " is : " << "Wicket";
			else if (ball[v + i] == -1)
				std::cout << "\n\nThe score for " << std::setw(3) << v + i << " is : " << "0";
			else if (ball[v + i] >= 0)
			{
				run += ball[v + i];
				std::cout << "\n\nThe score for " << std::setw(3) << v + i << " is : " << ball[v + i];
			}
		}
		std::cout << "\n\nThe total run for this over : " << run;
	}
	else
		std::cout << "\n\nYou can not view score in this position";
	std::cout << "\n\nIf you continue press 1\n\nPress any key to main menu";
	int i;
	std::cin >> i;
	if (i == 1)
		goto s;
}

void display_wicket()
{
	int six = 0, four = 0, run = 0;
	system("CLS");
	for (int i = 1; i <= over * 6; i++)
	{
		if (ball[i] > 0)
		{
			run += ball[i];
			if (ball[i] == 4)
				four++;
			else if (ball[i] == 6)
				six++;
		}
	}
	std::cout << "Total run for this innings : " << run;
	std::cout << "\n\nTotal sixes for this innings : " << six;
	std::cout << "\n\nTotal fours for this innings : " << four;
	if (b_count >= 1)
	{
		const float t = float(run) / float(b_count) * float(6);
		std::cout << "\n\nRun rate of this innings : " << std::setprecision(2) << t;
	}
	std::cout << "\n\nThe wicket for that innings : " << wicket << "\n\nPress any key to main menu";
	_getch();
}

void color(int x, int y)
{
	// lowvideo();
	// system("CLS");
	// if (x > 15 || y > 15 || x == y)
	// {
	// 	textcolor(0);
	// 	textbackground(15);
	// }
	// else if (x != y)
	// {
	// 	textcolor(x);
	// 	textbackground(y);
	// }
}

void team_details()
{
	int striker = 1, non_striker = 2;
	for (int i = 1; i <= 11; i++)
	{
		bat[i].ball_facing = 0;
		bat[i].strike_rate = 0.0;
		bat[i].run = 0;
		bat[i].fours = 0;
		bat[i].sixes = 0;
	}
	for (int i = 1; i <= b_count; i++)
	{
		if (ball[i] == -2)
		{
			bat[striker].status = 1;
			bat[striker].ball_facing += 1;
			striker = striker > non_striker ? 1 + striker : 1 + non_striker;
		}
		else if (ball[i] == -3)
		{
			bat[striker].status = 1;
			striker = striker > non_striker ? 1 + striker : 1 + non_striker;
		}
		else if (ball[i] != -2 || ball[i] == -3)
		{
			const int run = ball[i] <= 0 ? 0 : ball[i];
			if (run == 4)
				bat[striker].fours += 1;
			if (run == 6)
				bat[striker].sixes += 1;
			bat[striker].run += run;
			if (ball[i] != -1)
				bat[striker].ball_facing += 1;
			if (i % 6 == 0)
			{
				if (run % 2 == 0)
				{
					const int temp = striker;
					striker = non_striker;
					non_striker = temp;
				}
				/*else
				{
					striker = striker;
					non_striker = non_striker;
				}*/
			}
			else if (run % 2 != 0)
			{
				const int temp = striker;
				striker = non_striker;
				non_striker = temp;
			}
			/*else if (run % 2 == 0)
			{
				striker = striker;
				non_striker = non_striker;
			}
			else
			{
				int temp = striker;
				striker = non_striker;
				non_striker = temp;
			}*/
		}
	}
	for (int i = 1; i <= 10; i++)
		if (bat[i].ball_facing != 0)
			bat[i].strike_rate = (float(bat[i].run) / float(bat[i].ball_facing)) * float(100);
}
void bat_statistics()
{
	team_details();
	system("CLS");
	std::cout << "BATTING STATISTICS : " << batting_team_name;
	std::cout << "\n\nNAME\t\t\tBALLS\tFOURS\tSIXES\tRUNS\tSTRIKE_RATE\n";
	for (int i = 1; i <= 11; i++)
	{
		std::cout << "\n"
			<< std::setw(20) << bat[i].name;
		if (bat[i].status == 0 && bat[i].ball_facing != 0)
			std::cout << "*";
		std::cout << "\t" << bat[i].ball_facing << "\t" << bat[i].fours << "\t" << bat[i].sixes << "\t" << bat[i].run << "\t" << std::setprecision(2) << bat[i].strike_rate;
	}
	std::cout << "\n\nPress any key to main menu";
	_getch();
}

/*
class bowler
{
	char name[25];
	int over;
	int *deliver;
	int ovcount;//over counting
	int maiden;
	int run;
	int wicket;
}*bow;

void input_bowler()
{
	std::cout<<"Enter the no.of bowlers : ");
	std::cin>>nb;
	bow=new class bowler[nb];
	for(int i=0;i<nb;i++)
	{
		system("CLS");
		Console.WriteLine<<"Enter the team name : ");
		std::cin>>bowling_team_name;
		Console.WriteLine<<"Enter the bowler name in bowling order : ");
		std::cin>>bow[i].name;
	}
}

void over_input(int x)
{
	static int i;
	x-=1;
	if(i==0){
		for(int j=0;j<nb;j++)
			bow[j].over=bow[j].maiden=bow[j].run=bow[j].wicket=bow[j].ovcount=0;
		bow[x].deliver=new int[1];
		std::cin>>bow[x].deliver[i];
		bow[x].ovcount++;
	}
	else{
		bow[x].deliver=(int *)realloc(bow[x].deliver,sizeof(int));
		std::cin>>bow[x].deliver[i];
	}
}

void ca_bowler()
{
	for(int i=0;i<nb;i++)
	{ //i is point no.of bowlers
		for(int j=0;j<bow[i].ovcount;j++)
		{//j is point no.of overs
			int v=(bow[i].deliver[j]*6)-5;
			int run=0;
			for(int k=0;k<6;k++)
			{
				if(ball[v+k]==-2)
					bow[i].wicket++;
				else if(ball[v+k]>=0)
				{
					bow[i].run+=ball[v+k];
					run+=ball[v+k];
				}
			}
			if(run==0)
				bow[i].maiden++;
		}
	}
}*/
