#include <bits/stdc++.h>
using namespace std;

int board[3000][3000];

int cnt[3];

bool check(int x, int y, int k){
    for(int i = x; i < x+k;i++){
        for(int j = y; j < y+k;j++){
            if (board[x][y] != board[i][j]) return false;
        }
    }
    return true;
}

void func(int x, int y, int k){
    if(check(x,y,k)){
        cnt[board[x][y] + 1] += 1;
        return;
    }
    int n = k / 3;
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3;j++){
            func(x + i*n ,y + j*n,n);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            cin >> board[i][j];
        }
    }

    func(0,0,n);

    for(int i = 0; i < 3; i++) cout << cnt[i] << '\n';

    return 0;
}