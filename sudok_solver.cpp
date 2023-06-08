#include<iostream>
using namespace std;

const int boardsize = 4;
const int cellsize = 2;

int board[boardsize][boardsize];
int ans[boardsize][boardsize];
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
        ans++;
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
        for(int val=1;val<=boardsize;val++){
            if(check(val,row,col)){
                board[row][col] = val;
                rec(row,col+1);
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
    for(int i=0;i<boardsize;i++){
        for(int j=0;j<boardsize;j++){
            cin>>board[i][j];
        }
    }
    rec(0,0);
    // for(int i=0;i<boardsize;i++){
    //         for(int j=0;j<boardsize;j++){
    //             cout<<ans[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
}

int main(){
    solve();
}