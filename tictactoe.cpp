#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

char blocks[] = { '0','1','2','3','4','5','6','7','8','9' };

void draw()
{
	system("Color 4B");
	cout << "				PLAYER 1: X" << "        " << "PLAYER 2: O" << endl;
	cout << endl;
	cout << "			###########################################" << endl;
	cout << "			##         ######         ######         ##" << endl;
	cout << "			##    " << blocks[1] << "    ######    " << blocks[2] << "    ######    " << blocks[3] << "    ##" << endl;
	cout << "			##         ######         ######         ##" << endl;
	cout << "			###########################################" << endl;
	cout << "			##         ######         ######         ##" << endl;
	cout << "			##    " << blocks[4] << "    ######    " << blocks[5] << "    ######    " << blocks[6] << "    ##" << endl;
	cout << "			##         ######         ######         ##" << endl;
	cout << "			###########################################" << endl;
	cout << "			##         ######         ######         ##" << endl;
	cout << "			##    " << blocks[7] << "    ######    " << blocks[8] << "    ######    " << blocks[9] << "    ##" << endl;
	cout << "			##         ######         ######         ##" << endl;
	cout << "			###########################################" << endl;
}
bool check_win()
{
	if (blocks[1] == blocks[2] && blocks[1] == blocks[3])
	{
		return 1;
	}
	else if (blocks[4] == blocks[5] && blocks[4] == blocks[6])
	{
		return 1;
	}
	else if (blocks[7] == blocks[8] && blocks[7] == blocks[9])
	{
		return 1;
	}
	else if (blocks[1] == blocks[4] && blocks[1] == blocks[7])
	{
		return 1;
	}
	else if (blocks[2] == blocks[5] && blocks[2] == blocks[8])
	{
		return 1;
	}
	else if (blocks[3] == blocks[6] && blocks[3] == blocks[9])
	{
		return 1;
	}
	else if (blocks[1] == blocks[5] && blocks[1] == blocks[9])
	{
		return 1;
	}
	else if (blocks[3] == blocks[5] && blocks[3] == blocks[7])
	{
		return 1;
	}
}

void gameplay()
{
	int counter = 1;
	while (check_win() != 1)
	{
		int temp = 0;

		if (counter % 2 == 1)
		{
			cout << endl;
			cout << "			Player one's turn: ";
			cin >> temp;
			if (blocks[temp] == 'X' || blocks[temp] == 'O')
			{
				cout << "			Player one try again! ";
				cin >> temp;
			}
			blocks[temp] = 'X';
			//clear();
			system("CLS");
			draw();
			if (counter == 10)
			{
				cout << "Draw!" << endl;
				return;
			}
			counter++;
		}
		else if(counter % 2 == 0)
		{
			cout << endl;
			cout << "			Player two's turn: ";
			cin >> temp;
			if (blocks[temp] == 'X' || blocks[temp] == 'O')
			{
				cout << "			Player two try again!";
				cin >> temp;
			}
			blocks[temp] = 'O';
			//clear();
			system("CLS");
			draw();
			if (counter == 10)
			{
				cout << "Draw!" << endl;
				return;
			}
			counter++;
		}
	}
	counter -= 1;
	if (counter % 2 == 1 && counter < 10)
	{
		cout << "Player 1 has won the game!" << endl;
		return;
	}
	else if (counter % 2 == 0 && counter < 10)
	{
		cout << "Player 2 has won the game!" << endl;
		return;
	}
}

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 700, 500, TRUE); // 700 width, 500 height
	draw();
	gameplay();
	system("Pause");
}


//Draw condition
/*
2
1
5
3
7
4
6
8
9
*/
