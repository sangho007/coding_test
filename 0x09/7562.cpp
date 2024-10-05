#include <bits/stdc++.h>
using namespace std;

#define X first 
#define Y second 

int board[302][302];
int dist[302][302];

int dx[8] = {1,1,-1,-1,2,2,-2,-2};
int dy[8] = {2,-2,2,-2,1,-1,1,-1};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 0;
    cin >> t;

    for(int i = 0; i < t; i++){
        int ans = 0;
        
        int l = 0;
        cin >> l;

        for(int j = 0; j < l; j++){
            for(int k = 0; k < l; k++){
                fill(board[j],board[j]+l,0);
                fill(dist[j],dist[j]+l,-1);
            }
        }

        queue<pair<int,int>> q;
        int a,b;
        cin >> a >> b; // 현재위치
        board[a][b] = 1;
        dist[a][b] = 0;
        q.push({a,b});

        cin >> a >> b; // 목표 
        board[a][b] = 1;

        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(int dir = 0; dir < 8; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if(dist[nx][ny] >= 0) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({nx,ny});
                if(board[nx][ny] == 1) break;
            }
        }

        ans = dist[a][b];

        cout << ans << '\n';
    }

    return 0;
}