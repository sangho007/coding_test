#include <bits/stdc++.h>
using namespace std;

int board[102][102][102];
int dist[102][102][102];
int m,n,h;

int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {1,-1,0,0,0,0};
queue<tuple<int,int,int>> q;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;

    for(int k = 0; k < h; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){            
                cin >> board[i][j][k];
                if(board[i][j][k] == 1) {
                    dist[i][j][k] = 0;
                    q.push({i,j,k});
                }else{
                    dist[i][j][k] = -1;
                }
            }
        }
    }


    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 6; dir++){
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur) + dz[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if (board[nx][ny][nz] == -1 || dist[nx][ny][nz] >= 0) continue;
            dist[nx][ny][nz]  = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            q.push({nx,ny,nz});
        }
    }


    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < h; k++){
                if(board[i][j][k] != -1 && dist[i][j][k] == -1){
                    cout << -1;
                    return 0;
                }
                ans = max(ans,dist[i][j][k]);
            }
        }
    }
    
    cout << ans;
    return 0;    
}