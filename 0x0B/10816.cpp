#include <bits/stdc++.h>
using namespace std;

int board[20000002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        board[t+10000000]++;
    }
    

    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        cout << board[t+10000000] << ' ';
    }
    
    


    return 0;
}