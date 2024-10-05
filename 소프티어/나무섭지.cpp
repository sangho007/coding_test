#include <bits/stdc++.h>
using namespace std;

#define X first 
#define Y second 

char board[1002][1002];
int dist1[1002][1002];
int dist2[1002][1002];


int n,m;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int,int>> q1;
queue<pair<int,int>> q2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int x,y;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            board[i][j] = s[j];
            dist1[i][j] = -1;
            dist2[i][j] = -1;
            if(board[i][j] == 'G'){
                dist1[i][j] = 0;
                q1.push({i,j});                
            }
            if(board[i][j] == 'N'){
                dist2[i][j] = 0;
                q2.push({i,j});                
            }
            if(board[i][j] == 'D'){
                x = i;
                y = j;               
            }
        }
    }

    while(!q1.empty()){
        auto cur = q1.front(); q1.pop();
        if(dist1[x][y] == -1) dist1[x][y] = abs(cur.X-x) + abs(cur.Y-y);
        else dist1[x][y] = min(dist1[x][y], abs(cur.X-x) + abs(cur.Y-y));
    }

    while(!q2.empty()){
        auto cur = q2.front(); q2.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == '#' || dist2[nx][ny] >= 0) continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            q2.push({nx,ny});

            if(board[nx][ny] == 'D' && dist2[nx][ny] < dist1[nx][ny]){
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}