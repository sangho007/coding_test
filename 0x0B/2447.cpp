#include <bits/stdc++.h>
using namespace std;

char board[10000][10000];

void func(int x, int y, int n){
    if(n == 1){
        if (!(x == 1 && y == 1))
            board[x][y] = '*';        
        return;
    }
    int k = n/3;
    for(int i = 0; i < 3 ; i++)
    for(int j = 0; j < 3 ; j++){
        if(!(i == 1 && j == 1))
            func(x + i * k, y + j * k, k);
    }
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