#include <bits/stdc++.h>
using namespace std;

int board[1000002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> board[i];

    stack<int> s;
    for(int i = n-1; i >= 0; i--){
        if(s.empty()) s.push(-1);
        else if(board[i] < board[i+1]) s.push(board[i+1]);
        else if(board[i] >= board[i+1] && board[i] < s.top()) s.push(s.top());
        else if(board[i] >= board[i+1] && board[i] >= s.top()) s.push(-1);
    }
    
    for(int i = 0; i < n; i++) {
        cout << s.top() << ' ';
        s.pop();
    }

    return 0;
}