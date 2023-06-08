#include<iostream>
using namespace std;

// You can change boardsize to 9 aur something (if sudoku is 9 x 9)
const int boardsize = 4;
const int cellsize = 2; // cell size is basizally 2 if(9x9) sudoku then cell size will be 3

// This board will be having full solution
int board[boardsize][boardsize];

// helper method to check if a choice is worth exploring.
bool check(int cval, int row,int col){
    // row check
    for(int c=0;c<boardsize;c++){
        if(c!=col && board[row][c]==cval) return false;
    }
    // column check
    for(int r=0;r<boardsize;r++){
        if(r!=row && board[r][col]==cval) return false;
    }
    // checking in the (2x2) box 
    int str = (row/cellsize)*cellsize;
    int stc = (col/cellsize)*cellsize;
    for(int i=0;i<cellsize;i++){
        for(int j=0;j<cellsize;j++){
            if(str+i==row && stc+j==col) continue;
            if(board[str+i][stc+j]==cval) return false;
        }
    }
    return true;
}

// 1. level
int ans = 0;
void rec(int row,int col){
    // base case
    if(col==boardsize){
        rec(row+1,0);
        return;
    }
    if(row==boardsize){
        // ans is here no of solution
        ans++;
        // priinting the solution
        for(int i=0;i<boardsize;i++){
            for(int j=0;j<boardsize;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    // recursive case.
    
    if(board[row][col]==0){
        // choice
        for(int val=1;val<=boardsize;val++){
            // check
            if(check(val,row,col)){
                // move
                board[row][col] = val;
                rec(row,col+1);
                // revert
                board[row][col] = 0; 
            }
        }
    }
    else{
        if(check(board[row][col],row,col)){
            rec(row,col+1);
        }
    }
}

void solve(){
    // taking initial values on the board
    for(int i=0;i<boardsize;i++){
        for(int j=0;j<boardsize;j++){
            cin>>board[i][j];
        }
    }
    // recursive call
    rec(0,0);
}

int main(){
    solve();
}
