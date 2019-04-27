#include <iostream>
#include <iomanip>
#include <conio.h>

#include "BattingTeam.h"

int main()
{
s:
	color(7, 1);
	system("CLS");
	std::cout << "Enter the total overs for you play : ";
	std::cin >> over;
	if (over <= 0)
	{
		int i;
		std::cout << "\n\nYou can not play for this over\n\nPress 1 for try again";
		std::cin >> i;
		if (i == 1)
			goto s;
		exit(1);
	}

	ball = new int[over * 6 + 1];
	memset(ball, 0, sizeof(int) * (over * 6 + 1));

	for (int i = 1; i <= over * 6; i++)
		ball[i] = -1;
	while (true)
	{
	top:
		system("CLS");
		int ch;
		std::cout << "1.Insert by ball\n\n2.Insert by over\n\n3.View by ball\n\n4.View by over\n\n5.View run & Wicket\n\n6.Color change\n\n7.Input name\n\n8.Batsman details\n\n9.Exit";
		std::cout << "\n\nEnter Your choice : ";
		std::cin >> ch;
		switch (ch)
		{
		case 1:
			system("CLS");
			run_by_ball();
			break;
		case 2:
			system("CLS");
			run_by_over();
			break;
		case 3:
			system("CLS");
			display_ball();
			break;
		case 4:
			system("CLS");
			display_over();
			break;
		case 5:
			system("CLS");
			display_wicket();
			break;
		case 6:
			system("CLS");
			int x, y;
			std::cout << "Enter 0-15 to change the text color : ";
			std::cin >> x;
			std::cout << "\n\nEnter 0-15 to change the text background : ";
			std::cin >> y;
			color(x, y);
			break;
		case 7:
			system("CLS");
			std::cout << "Enter the team name : ";
			std::cin >> batting_team_name;
			std::cout << "\n\nEnter the player name in batting order .....";
			for (int i = 1; i <= 11; i++)
			{
				std::cout << "\n\nThe name of batsman " << i << " is : ";
				std::cin >> bat[i].name;
			}
			break;
		case 8:
			system("CLS");
			bat_statistics();
			break;
		case 9:
			delete[] ball;
			exit(1);
		default:
			system("CLS");
			std::cout << "Invalid choice\n\nPress any key to main menu";
			_getch();
			goto top;
		}
	}
	return 0;
}