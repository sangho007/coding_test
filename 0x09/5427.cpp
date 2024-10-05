#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second 

char board[1002][1002];
int dist1[1002][1002];
int dist2[1002][1002];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){
    int T;
    cin >> T;


    for(int t = 0; t < T; t++){
        int n,m;
        cin >> m >> n;

        queue<pair<int,int>> q1;
        queue<pair<int,int>> q2;

        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            fill(dist1[i],dist1[i]+ m,-1);
            fill(dist2[i],dist2[i]+ m,-1);
            for(int j = 0; j < m; j++){
                board[i][j] = s[j];
                if (board[i][j] == '*'){
                    dist1[i][j] = 0;
                    q1.push({i,j});
                }
                if (board[i][j] == '@'){
                    dist2[i][j] = 0;
                    q2.push({i,j});
                }
            }
        }   

        while(!q1.empty()){
            auto cur = q1.front();q1.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(board[nx][ny] == '#' || dist1[nx][ny] >= 0) continue;
                dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
                q1.push({nx,ny});
            }
        }
        bool flag = 1;
        while(!q2.empty() && flag){
            auto cur = q2.front();q2.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    cout << dist2[cur.X][cur.Y] + 1 << '\n';
                    flag = 0;
                    break;
                }
                if(board[nx][ny] == '#' || dist2[nx][ny] >= 0) continue;
                if(dist1[nx][ny]!= -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y]+1) continue; //왜지???
                dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
                q2.push({nx,ny});
            }
        }
        if(flag) cout << "IMPOSSIBLE\n";
    }

    return 0;
}