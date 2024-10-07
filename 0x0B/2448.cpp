#include <bits/stdc++.h>
using namespace std;

char board[4000][4000];

void func(int x,int y, int N){
    if(N == 1){
        if(x==2) board[x][y] = '*';
        if(x==1 && (y==1 || y==3)) board[x][y] = '*';
        if(x==0 && (y==2)) board[x][y] = '*';
        return;
    }
    int k = N/3
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        fill(board[i],board[i]+N,' ');
    }

    func(0,0,N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << board[i][j];
        }
        cout << '\n';
    }
    
        


    return 0;
}