#include<bits/stdc++.h>
using namespace std;

char board[66][66];

bool check(int x,int y, int k){
    for(int i = x; i < x+k; i++)
    for(int j = y; j < y+k; j++){
        if(board[x][y] != board[i][j]) 
            return false;
    }
    return true;
}

void func(int x,int y, int k){
    if(check(x,y,k)){
        cout << board[x][y];
        return;
    }

    int half = k/2;

    cout << '(';
    func(x,y,half);
    func(x,y+half,half);
    func(x+half,y,half);
    func(x+half,y+half,half);
    cout << ')';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            board[i][j] = s[j];
        }
    }
    func(0,0,n);

    return 0;
}