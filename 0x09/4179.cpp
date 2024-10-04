#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second 

string board[1002];
int dist1[1002][1002];
int dist2[1002][1002];
int r,c;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int,int>> q1;
queue<pair<int,int>> q2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    for(int i = 0; i < r; i++){
        fill(dist1[i],dist1[i] + c,-1);
        fill(dist2[i],dist2[i] + c,-1);
    }


    for(int i = 0; i < r; i++){
        cin >> board[i];
        for (int j = 0; j < c; j++){
            if (board[i][j] == 'J') {
                q2.push({i,j});
                dist2[i][j] = 0;
            }
            if (board[i][j] == 'F') {
                q1.push({i,j});
                dist1[i][j]= 0;
            }
        }
    }

    while(!q1.empty()){
        auto cur = q1.front();
        q1.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(board[nx][ny] == '#' || dist1[nx][ny] >= 0) continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            q1.push({nx,ny});
        }
    }

    while(!q2.empty()){
        auto cur = q2.front();
        q2.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) {
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            }
            if(board[nx][ny] == '#' || dist2[nx][ny] >= 0) continue;
            if(dist1[nx][ny] != -1 && dist2[cur.X][cur.Y] +1 >= dist1[nx][ny]) continue;
            
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            q2.push({nx,ny});
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}