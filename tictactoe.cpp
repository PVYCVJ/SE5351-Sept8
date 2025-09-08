#include <iostream>
#include <cstring>

using namespace std;

bool isWin(char game[3][3]){
	bool win = false;
	if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && game[0][0] != ' ') win = true;
	if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && game[1][0] != ' ') win = true;
	if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && game[2][0] != ' ') win = true;
	// column
	if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && game[0][0] != ' ') win = true;
	if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && game[0][1] != ' ') win = true;
	if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && game[0][2] != ' ') win = true;
	// diagonal
	if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[0][0] != ' ') win = true;
	if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && game[0][2] != ' ') win = true;
	return win;
}

int main(){
	int i, j;
	char game[3][3]; // Tic-tac-toe
	memset(game, ' ', sizeof(game));
	char player1 = 'X';
	char player2 = 'O';
	bool turn = true; // false for player 1's turn, true for player 2's turn. Player 1 first.
	cout << "X = Player 1" << endl << "O = Player 2" << endl;
	int n;  // declare it outsize 'for' to use it later
       for (n=0; n<9; n++){
			turn = !turn;  // use the not-operator to change true to false or false to true.
			while (1) {  // loop until user gives legal input
                if (turn == false)
                    cout << "Player 1: ";
                else
                    cout << "Player 2: ";
                cout << "Which cell to mark? i:[0..2], j:[0..2]: "; 
                cin >> i >> j;
                if (!(0<=i && i<=2 && 0<=j && j<=2) || game[i][j]!=' ') {
                    cout << "Bad input." << endl;
                } else {
                    break;
                }
			}
			if (turn == false)
			   game[i][j] = player1;
			else 
			   game[i][j] = player2;
			if (isWin(game)){
				cout << (turn==false ? "Player 1 " : "Player 2 ");
				cout << "Win!" << endl;
				break; // need to terminate the problem
			}
		}
	if (n==9) // 9 cells are all filled, no winner yet
	   cout << "Tie!" << endl;

	// show the game to console
	cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << endl;
	cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << endl;
	cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << endl;
	return 0;
}
