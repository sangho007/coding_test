#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second 

int m,n,t,k;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int,int>> q;


int main(){

    cin >> t;
    
    for(int i = 0; i < t; i++){
        int ans = 0;

        int board[52][52] = {0};
        bool vis[52][52] = {0};

        cin >> m >> n >> k;
        for(int j = 0; j < k; j++){
            int a,b;
            cin >> a >> b;
            board[b][a] = 1;
        }
        for(int j = 0; j < n; j++){
            for(int p = 0; p < m; p++){
                if(vis[j][p] == 1 || board[j][p] == 0) continue;
                vis[j][p] = 1;
                q.push({j,p});
                ans++;
                
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir = 0; dir < 4;dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }

            }
        }
        cout << ans << '\n';
    }

    return 0;
}