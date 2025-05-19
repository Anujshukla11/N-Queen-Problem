#include <stdio.h>
#include <stdbool.h>

#define N 4

int board[N][N];

void PrintBoard(){
    for(int i = 0 ; i<N ; i++){
        for(int j = 0 ; j<N ; j++){
            if(board[i][j]){
                printf("Q ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int row , int col){
    int i,j;
    for(i = 0 ; i<row ; i++){
        if(board[i][col]){
            return false;
        }
    }

    for(i = row,j=col ; i>=0,j>=0 ; i--,j--){
        if(board[i][j]){
            return false;
        }
    }

    for(i = row,j=col ; i>=0 , j < N ; i--,j++){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}

bool solveNQueen(int row){
    if(row>=N){
        PrintBoard();
        return true;
    }
    int res = false;
    for(int col = 0 ; col < N ; col++){
        if(isSafe(row,col)){
            board[row][col] = 1;
            res = solveNQueen(row+1) || res;
            board[row][col]=0;
        }
    }
    return res;
}
int main() {
    // Your code goes here
    for(int i = 0; i< N; i++){
        for(int j = 0; j< N; j++){
            board[i][j]=0;
        }
    }

    if(!solveNQueen(0)){
        printf("Not Possible\n");
    }
    
    return 0;
}