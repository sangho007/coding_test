#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second 

int n;
int board1[102][102];
int board2[102][102];
bool vis1[102][102];
bool vis2[102][102];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

queue<pair<int,int>> q1;
queue<pair<int,int>> q2;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            board1[i][j] = s[j];
            if(s[j] == 'G') board2[i][j] = 'R';
            else board2[i][j] = s[j];
        }
    }

    int num1 = 0;
    // 정상
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis1[i][j]) continue;
            vis1[i][j] = 1;
            q1.push({i,j});
            num1++;

            while(!q1.empty()){
                auto cur = q1.front();q1.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(vis1[nx][ny] == 1 || board1[cur.X][cur.Y] != board1[nx][ny])continue;
                    vis1[nx][ny] = 1;
                    q1.push({nx,ny});
                }
            }
            
        }
    }

    int num2 = 0;
    // 정상
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis2[i][j]) continue;
            vis2[i][j] = 1;
            q2.push({i,j});
            num2++;

            while(!q2.empty()){
                auto cur = q2.front();q2.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(vis2[nx][ny] == 1 || board2[cur.X][cur.Y] != board2[nx][ny])continue;
                    vis2[nx][ny] = 1;
                    q2.push({nx,ny});
                }
            }
            
        }
    }
    cout << num1 << ' ' << num2;
    return 0;
}