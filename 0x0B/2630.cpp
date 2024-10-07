#include <bits/stdc++.h>
using namespace std;

int board[130][130];
int cnt[2];

bool check(int x, int y, int k){
    for(int i = x; i < x + k; i++)
    for(int j = y; j < y + k; j++){
        if(board[x][y] != board[i][j])
            return false;
    }
    return true;
}

void func(int x, int y, int k){
    if(check(x,y,k)){
        cnt[board[x][y]]++;
        return;
    }
    int n = k/2;
    for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++){
        func(x + i * n, y + j * n, n);
    }
}


int main(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
        cin >> board[i][j];
    }

    func(0,0,n);

    cout << cnt[0] << '\n';
    cout << cnt[1] << '\n';

    return 0;
}