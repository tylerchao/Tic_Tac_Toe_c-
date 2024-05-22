#include <iostream>
#include <string>
using namespace std;
#include <string.h>

char winner = ' ';
bool gamerunning = true;
bool winnerhasappeard= false;

void print_board(char board[3][3]){
    
    cout <<  board[0][0] << "|" << board[0][1] << "|"  << board[0][2] << endl;
    cout <<  board[1][0] << "|" << board[1][1] << "|"  << board[1][2] << endl;
    cout <<  board[2][0] << "|" << board[2][1] << "|"  << board[2][2] << endl;
    }

void player_input(char board[0][3], char current_player){
    int number;
    cout << "Enter a number from 1 to 9 : " << endl;
    cin >> number;
    
    // Mapping number to board indices
    int row = (number - 1) / 3;
    int col = (number - 1) % 3;

    if (number >= 1 && number <= 9 && board[row][col] == '-' ) {
            board[row][col] = current_player;
    } else {
        cout << "Invalid input. Please enter a number between 1 and 9.\n";
        player_input(board, current_player); // Recursive call for invalid input
    }
}

bool check_raw(char board[3][3]){
    if(board[0][0] == board[0][1] && board[0][1] == board[0][2] &&  board[0][1] != '-') {
        winner = board[0][0];
        return true;
        } else if(board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][1] != '-'){
               winner = board[1][0];
        return true;
            } else if(board[2][0] == board[2][1] &&  board[2][1]== board[2][2] && board[2][1] != '-'){
               winner = board[2][0];
        return true;
            }else {
                    return false;
                }
            
    }

bool check_column(char board[3][3]){
    if(board[0][0] == board[1][0] && board[1][0]== board[2][0] && board[0][0] != '-') {
        winner = board[0][0];
         return true;
        } else if(board[0][1] == board[1][1] && board[1][1]== board[2][1] && board[1][1] != '-'){
               winner = board[1][1];
         return  true;
            } else if(board[0][2] == board[1][2] && board[1][2]== board[2][2] && board[2][2] != '-'){
               winner = board[2][2];
         return true;
            }else {
                return false;
                }
            
    
    }

bool check_diag(char board[3][3]){
    if(board[0][0] == board[1][1] && board[1][1]== board[2][2] && board[1][1] != '-') {
        winner = board[0][0];
         return true;
        } else if(board[0][2] == board[1][1] && board[1][1]== board[2][0] && board[1][1] != '-'){
               winner = board[0][2];
         return true;
            }else{
                return false;
                }
    }

void check_tie(char board[3][3]){
    bool allCellsFilled = true;
    
   for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        if (board[i][j] == '-') {
            allCellsFilled = false;
            break;
        }
    }
}

    if (allCellsFilled && !winnerhasappeard) {
        cout << "It is a tie";
        gamerunning = false;
    }
    
}

void check_win(char board[3][3]){
    if (check_raw(board) || check_column(board) || check_diag(board)){
        print_board(board);
        cout << "game is done. The winner has appeared. The winner is " << winner << endl ;
        gamerunning = false;
        winnerhasappeard = true;
        
    }
    check_tie(board);
    }

// switch player to next player
char switch_player(char currentplayer){
    return (currentplayer == 'o') ? 'x':'o';
    }
    
    


int main(){
    char current_player = 'o';

    char board[3][3] = {
        {'-','-','-'},
        {'-','-','-'},
        {'-','-','-'}
        };
        
    while(gamerunning){
        print_board(board);
        player_input(board,current_player);
        check_win(board);
        current_player = switch_player(current_player);
    }
   
}
