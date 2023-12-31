#include <iostream>

using namespace std;

void StartBoard(char board[3][3]){
    for(int i = 0; i < 3; i++){
        cout << " ";
        for( int j = 0; j < 3; j++){
             board[i][j] = ' ';
        }
    }

}

void Printboard(char board[3][3]){
    cout << " 0 1 2 \n";
    for(int i = 0; i < 3; i++){
        cout << i << " ";
        for(int j = 0; j < 3; j++){
            cout << board[i][j];
            if(j < 2){
                cout << "|";
            }
        }
        cout << endl;
        if (i < 2){
            cout << " -------\n";
        }
    }
    cout << endl;
}

bool WinVerification(char board[3][3], char player){
    for (int i = 0; i < 3; i++ ){
        if((board[i][0] == player && board[i][1] == player && board[i][2] == player) || (board[0][i] == player && board[1][i] == player && board[2][i] == player)){
            return true;
        }
    }

    if((board[0][0] == player && board[1][1] == player && board[2][2] == player)||(board[2][0] == player && board[1][1] == player && board[0][2] == player)){
        return true;
    }
    return false;
}

bool TieVerification(char board[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}


int main(){

    char board[3][3];
    char player = ' ';
    char Select = ' ';
    int row, column;


    cout << "Player 1, What your choose? [X/O]: ";
    cin >> Select;

    if(Select == 'X' || Select == 'x'){
        player = 'X';
        cout << "Player 2, your are: O" << endl;
    }
    else{
        player = 'O';
        cout << "Player 2, your are: X" << endl;
    }


    
    StartBoard(board);

    do{
        Printboard(board);

        cout << "Player " << player <<" is your turn";
        cout << " Type a row: ";
        cin >> row;
        cout << "Type a column: ";
        cin >> column;
    
        if(row < 0 || row > 2 || column < 0 || column > 2 || board[row][column] != ' '){
            cout << "This move is not possible !" << endl;
            continue;
        }

        board[row][column] = player;

        if(WinVerification(board,player)){
            cout << "\nPlayer " << player << " WIN !!!!" << endl;
            break;
        }

        if(TieVerification(board)){
            cout << "Tie !!!" << endl;
            break;
        }


        player = (player == 'X') ? 'O' : 'X';


    }
    while(true);
    
    Printboard(board);
    


    return 0;
}