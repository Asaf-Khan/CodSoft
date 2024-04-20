#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

int playerTurn() {
	int turn;

	srand(time(NULL));
	turn = rand() % 2 + 1;

	return turn;
}

int checkWin(char array[][3],int row,int col,char P1) {
	if(P1 == 'x') {
		if((array[0][0] == 'x' && array[0][1] == 'x' && array[0][2] == 'x')||
		        (array[1][0] == 'x' && array[1][1] == 'x' && array[1][2] == 'x')||
		        (array[2][0] == 'x' && array[2][1] == 'x' && array[2][2] == 'x') ) {
			cout<<"Player-One wins ^o^"<<endl;
			return 1;
		} else if((array[0][0] == 'x' && array[1][1] == 'x' && array[2][2] == 'x')||
		          (array[0][2] == 'x' && array[1][1] == 'x' && array[2][0] == 'x')) {
			cout<<"Player-One wins ^o^"<<endl;
			return 1;
		} else if((array[0][0] == 'o' && array[0][1] == 'o' && array[0][2] == 'o')||
		          (array[1][0] == 'o' && array[1][1] == 'o' && array[1][2] == 'o')||
		          (array[2][0] == 'o' && array[2][1] == 'o' && array[2][2] == 'o')) {
			cout<<"Player-Two wins ^o^"<<endl;
			return 1;
		} else if((array[0][0] == 'o' && array[1][1] == 'o' && array[2][2] == 'o')||
		          (array[0][2] == 'o' && array[1][1] == 'o' && array[2][0] == 'o')) {
			cout<<"Player-Two wins ^o^"<<endl;
			return 1;
		}

	} else if(P1 == 'o') {
		if((array[0][0] == 'o' && array[0][1] == 'o' && array[0][2] == 'o')||
		        (array[1][0] == 'o' && array[1][1] == 'o' && array[1][2] == 'o')||
		        (array[2][0] == 'o' && array[2][1] == 'o' && array[2][2] == 'o') ) {
			cout<<"Player-One wins ^o^"<<endl;
			return 1;
		} else if((array[0][0] == 'o' && array[1][1] == 'o' && array[2][2] == 'o')||
		          (array[0][2] == 'o' && array[1][1] == 'o' && array[2][0] == 'o')) {
			cout<<"Player-One wins ^o^"<<endl;
			return 1;
		} else if((array[0][0] == 'x' && array[0][1] == 'x' && array[0][2] == 'x')||
		          (array[1][0] == 'x' && array[1][1] == 'x' && array[1][2] == 'x')||
		          (array[2][0] == 'x' && array[2][1] == 'x' && array[2][2] == 'x')) {
			cout<<"Player-Two wins ^o^"<<endl;
			return 1;
		} else if((array[0][0] == 'x' && array[1][1] == 'x' && array[2][2] == 'x')||
		          (array[0][2] == 'x' && array[1][1] == 'x' && array[2][0] == 'x')) {
			cout<<"Player-Two wins ^o^"<<endl;
			return 1;
		}

	} else {
		return 0;
	}
	return 0;
}

int checkDraw(char array[][3],int row,int col,char P1) {
	int check = checkWin(array,row,col,P1);
	if(check == 0) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if(!(array [i][j] == 'x' && array [i][j] == 'o')) {
					cout<<"Match is onogoing"<<endl;
					return 0;
				} else {
					cout<<"Match Draw"<<endl;
					return 1;
				}
			}
		}

	} else {
		return 1;
	}
	return 0;
}

void showBoard(char array[][3],int row,int col) {
	cout<<"      "<<"col-1"<<"|col-2"<<"|col-3\n"<<endl;
	for(int i = 0; i<row; i++) {
		cout<<"Row-"<<i+1;
		for (int j = 0; j < col; j++) {
			cout<<"|  "<<array[i][j]<<"  ";
		}
		if(i!=2)
			cout<<"\n"<<"----------------------"<<endl;
		cout<<endl;
	}
	cout<<endl;
}

int main() {
	char playerOne,playerTwo;
	char Board[3][3]= {
		{'-','-','-'},
		{'-','-','-'},
		{'-','-','-'}
	};

	int turn = playerTurn();
	char row,col;

	if(turn == 1) {
		playerOne = 'x';
		playerTwo = 'o';
	} else {
		playerOne = 'o';
		playerTwo = 'x';
	}
	cout<<"-----------Welcome To Tic-Tac-toe Game-----------\n"<<endl;
	cout<<"\t\t\tPlayer-One = "<<playerOne<<"\n"
	    <<"\t\t\tPlayer-Two = "<<playerTwo<<endl;
	showBoard(Board,3,3);
	cout<<endl;


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int counter = 1 ;
			int check;
			if(playerOne == 'x') {

				while (( check = checkDraw(Board,3,3,playerOne)) == 0) {


					if(counter%2 != 0) {
						cout<<"Player-One turn "<<endl;
						char rw,cl;
						cout<<"Enter row number : ";
						cin>>rw;

						switch (rw) {
							case '1':
								cout<<"Enter column number : ";
								cin>>cl;
								switch (cl) {
									case '1':
										if(Board[0][0] != 'x' && Board[0][0] != 'o') {
											Board[0][0] = 'x';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '2':
										if(Board[0][1] != 'x' && Board[0][1] != 'o') {
											Board[0][1] = 'x';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
											;
										}
										break;
									case '3':
										if(Board[0][2] != 'x' && Board[0][2] != 'o') {
											Board[0][2] = 'x';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									default:
										cout<<"Invalid input"<<endl;
										break;
								}
								break;
							case '2':
								cout<<"Enter column number : ";
								cin>>cl;
								switch (cl) {
									case '1':
										if(Board[1][0] != 'x' && Board[1][0] != 'o') {
											Board[1][0] = 'x';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '2':
										if(Board[1][1] != 'x' && Board[1][1] != 'o') {
											Board[1][1] = 'x';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '3':
										if(Board[1][2] != 'x' && Board[1][2] != 'o') {
											Board[1][2] = 'x';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									default:
										cout<<"Invalid input"<<endl;
										break;
								}
								break;
							case '3':
								cout<<"Enter column number : ";
								cin>>cl;
								switch (cl) {
									case '1':
										if(Board[2][0] != 'x' && Board[2][0] != 'o') {
											Board[2][0] = 'x';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '2':
										if(Board[2][1] != 'x' && Board[2][1] != 'o') {
											Board[2][1] = 'x';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '3':
										if(Board[2][2] != 'x' && Board[2][2] != 'o') {
											Board[2][2] = 'x';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									default:
										cout<<"Invalid input"<<endl;
										break;
								}
								break;

							default:
								cout<<"Invalid input"<<endl;
								break;

						}

					} else {
						cout<<"Player-Two turn "<<endl;
						char rw,cl;
						cout<<"Enter row number : ";
						cin>>rw;

						switch (rw) {
							case '1':
								cout<<"Enter column number : ";
								cin>>cl;
								switch (cl) {
									case '1':
										if(Board[0][0] != 'x' && Board[0][0] != 'o') {
											Board[0][0] = 'o';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '2':
										if(Board[0][1] != 'x' && Board[0][1] != 'o') {
											Board[0][1] = 'o';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '3':
										if(Board[0][2] != 'x' && Board[0][2] != 'o') {
											Board[0][2] = 'o';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									default:
										cout<<"Invalid input"<<endl;
										break;
								}
								break;
							case '2':
								cout<<"Enter column number : ";
								cin>>cl;
								switch (cl) {
									case '1':
										if(Board[1][0] != 'x' && Board[1][0] != 'o') {
											Board[1][0] = 'o';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '2':
										if(Board[1][1] != 'x' && Board[1][1] != 'o') {
											Board[1][1] = 'o';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '3':
										if(Board[1][2] != 'x' && Board[1][2] != 'o') {
											Board[1][2] = 'o';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									default:
										cout<<"Invalid input"<<endl;
										break;
								}
								break;
							case '3':
								cout<<"Enter column number : ";
								cin>>cl;
								switch (cl) {
									case '1':
										if(Board[2][0] != 'x' && Board[2][0] != 'o') {
											Board[2][0] = 'o';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '2':
										if(Board[2][1] != 'x' && Board[2][1] != 'o') {
											Board[2][1] = 'o';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '3':
										if(Board[2][2] != 'x' && Board[2][2] != 'o') {
											Board[2][2] = 'o';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									default:
										cout<<"Invalid input"<<endl;
										break;
								}
								break;

							default:
								cout<<"Invalid input"<<endl;
								break;

						}
					}
				}
				return 0;

			} else {
				while (( check = checkDraw(Board,3,3,playerOne)) == 0) {


					if(counter%2 != 0) {
						cout<<"Player-One turn "<<endl;
						char rw,cl;
						cout<<"Enter row number : ";
						cin>>rw;

						switch (rw) {
							case '1':
								cout<<"Enter column number : ";
								cin>>cl;
								switch (cl) {
									case '1':
										if(Board[0][0] != 'x' && Board[0][0] != 'o') {
											Board[0][0] = 'o';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '2':
										if(Board[0][1] != 'x' && Board[0][1] != 'o') {
											Board[0][1] = 'o';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '3':
										if(Board[0][2] != 'x' && Board[0][2] != 'o') {
											Board[0][2] = 'o';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									default:
										cout<<"Invalid input"<<endl;
										break;
								}
								break;
							case '2':
								cout<<"Enter column number : ";
								cin>>cl;
								switch (cl) {
									case '1':
										if(Board[1][0] != 'x' && Board[1][0] != 'o') {
											Board[1][0] = 'o';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '2':
										if(Board[1][1] != 'x' && Board[1][1] != 'o') {
											Board[1][1] = 'o';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '3':
										if(Board[1][2] != 'x' && Board[1][2] != 'o') {
											Board[1][2] = 'o';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									default:
										cout<<"Invalid input"<<endl;
										break;
								}
								break;
							case '3':
								cout<<"Enter column number : ";
								cin>>cl;
								switch (cl) {
									case '1':
										if(Board[2][0] != 'x' && Board[2][0] != 'o') {
											Board[2][0] = 'o';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '2':
										if(Board[2][1] != 'x' && Board[2][1] != 'o') {
											Board[2][1] = 'o';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '3':
										if(Board[2][2] != 'x' && Board[2][2] != 'o') {
											Board[2][2] = 'o';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									default:
										cout<<"Invalid input"<<endl;
										break;
								}
								break;

							default:
								cout<<"Invalid input"<<endl;
								break;

						}

					} else {
						cout<<"Player-Two turn "<<endl;
						char rw,cl;
						cout<<"Enter row number : ";
						cin>>rw;

						switch (rw) {
							case '1':
								cout<<"Enter column number : ";
								cin>>cl;
								switch (cl) {
									case '1':
										if(Board[0][0] != 'x' && Board[0][0] != 'o') {
											Board[0][0] = 'x';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '2':
										if(Board[0][1] != 'x' && Board[0][1] != 'o') {
											Board[0][1] = 'x';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '3':
										if(Board[0][2] != 'x' && Board[0][2] != 'o') {
											Board[0][2] = 'x';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									default:
										cout<<"Invalid input"<<endl;
										break;
								}
								break;
							case '2':
								cout<<"Enter column number : ";
								cin>>cl;
								switch (cl) {
									case '1':
										if(Board[1][0] != 'x' && Board[1][0] != 'o') {
											Board[1][0] = 'x';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '2':
										if(Board[1][1] != 'x' && Board[1][1] != 'o') {
											Board[1][1] = 'x';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '3':
										if(Board[1][2] != 'x' && Board[1][2] != 'o') {
											Board[1][2] = 'x';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									default:
										cout<<"Invalid input"<<endl;
										break;
								}
								break;
							case '3':
								cout<<"Enter column number : ";
								cin>>cl;
								switch (cl) {
									case '1':
										if(Board[2][0] != 'x' && Board[2][0] != 'o') {
											Board[2][0] = 'x';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '2':
										if(Board[2][1] != 'x' && Board[2][1] != 'o') {
											Board[2][1] = 'x';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									case '3':
										if(Board[2][2] != 'x' && Board[2][2] != 'o') {
											Board[2][2] = 'x';
											system("cls");
											showBoard(Board,3,3);
											++counter;
										} else {
											cout<<"Filled try another one "<<endl;
										}
										break;
									default:
										cout<<"Invalid input"<<endl;
										break;
								}
								break;

							default:
								cout<<"Invalid input"<<endl;
								break;

						}
					}
				}

				return 0;
			}
		}
	}

	return 0;

}
