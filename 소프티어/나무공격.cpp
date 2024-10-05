#include <bits/stdc++.h>
using namespace std;

int n,m;
int board[102][102];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    int a,b;

    cin >> a >> b;
    for(int j = a-1; j < b; j++){
        for(int k = 0; k < m; k++){
            if (board[j][k] == 1 ){
                board[j][k] = 0;
                break;
            }
        }
    }

    cin >> a >> b;
    for(int j = a-1; j < b; j++){
        for(int k = 0; k < m; k++){
            if (board[j][k] == 1 ){
                board[j][k] = 0;
                break;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (board[i][j] == 1) ans++;
        }
    }
    
    cout << ans;
    return 0;
}
