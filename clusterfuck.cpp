#include <iostream>
#include <cstdlib>
#include <string>
#include <termios.h>
#include <unistd.h>

using namespace std;

char square[] = {'o','1','2','3','4','5','6','7','8','9'};

int checkwin();
int tictac();
void board();
int RPS(); 
void HideStdinKeystrokes();
void ShowStdinKeystrokes();

int main(){
	tictac();
}

int RPS()
{ 
	string p1;
	string p2;
    while (true){
	cout << "Rock Paper Scissors!"<< endl;
	cout << "r = rock, p = paper, s= scissors"<< endl;
	cout << "Player 1, your move:"<< endl; 
	HideStdinKeystrokes();
	cin >> p1;
	ShowStdinKeystrokes();
	cout << "Player 2, your move"<< endl;
	HideStdinKeystrokes();
	cin >> p2; 
	ShowStdinKeystrokes();
  if (p1 == p2) 
    { 
        cout <<"\nThere is a tie"<<endl; 
    } 

    else if ( p1 == "r" && p2 == "p") 
    { 
        cout << "\nPaper wraps rock, Player 2 win"<< endl; 
        return 2; 
    } 
    else if (p1 == "r" && p2 == "s") 
    { 
        cout << "\nRock smashes scissors, Player 1 win"<<endl; 
        return 1; 
    } 
    else if (p1 == "p" && p2 == "r") 
    { 
        cout <<"\nPaper wraps rock, Player 1 win"<<endl; 
        return 1; 
    } 
    else if ( p1 == "p" && p2 == "s") 
    { 
        cout <<"\nScissors cut paper, Player 2 win"<<endl;
        return 2; 
    } 
    else if ( p1 == "s" && p2 == "p") 
    { 
        cout << "\nScissors cuts paper, Player 1 win"<<endl; 
        return 1; 
    } 
    else if (p1 == "s" && p2 == "r") 
    { 
        cout << "\nRock smashes scissors, Player 2 win"<<endl; 
        return 1;
    }
    else 
    { cout << "\nerror"<< endl; 
    }
    }
}

int tictac()
{	
	
	int i,choice,player;
	char mark;
	do
	{
		player=RPS();
		board();

		cout << "Player " << player << ", your move:  "<< endl;
		HideStdinKeystrokes();
		cin >> choice;
		ShowStdinKeystrokes();
		mark=(player == 1) ? 'X' : 'O';
		if (choice == 1 && square[1] == '1')
			square[1] = mark;
		else if (choice == 2 && square[2] == '2')
			square[2] = mark;
		else if (choice == 3 && square[3] == '3')
			square[3] = mark;
		else if (choice == 4 && square[4] == '4')
			square[4] = mark;
		else if (choice == 5 && square[5] == '5')
			square[5] = mark;
		else if (choice == 6 && square[6] == '6')
			square[6] = mark;
		else if (choice == 7 && square[7] == '7')
			square[7] = mark;
		else if (choice == 8 && square[8] == '8')
			square[8] = mark;
		else if (choice == 9 && square[9] == '9')
			square[9] = mark;
		else
		{
			cout<<"Invalid move ";
			cin.ignore();
			cin.get();
		}
		i=checkwin();
	}
	
	while(i==-1);
	board();
	if(i==1)
		cout<<"==>\aPlayer "<<player<<" win ";
	else
		cout<<"==>\aGame draw";
	cin.ignore();
	cin.get();
	return 0;
}
int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if (square[7] == square[8] && square[8] == square[9])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[3] == square[6] && square[6] == square[9])
		return 1;
	else if (square[1] == square[5] && square[5] == square[9])
		return 1;
	else if (square[3] == square[5] && square[5] == square[7])
		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else
		return -1;
}
void board()
{
	cout << "\n\n\tTic Tac Toe\n\n";
	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
	cout << "     |     |     " << endl << endl;
}
void HideStdinKeystrokes()
{
    termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    tty.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}
void ShowStdinKeystrokes()
{
   termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    tty.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

