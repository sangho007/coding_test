#include <bits/stdc++.h>
using namespace std;

#define X first 
#define Y second 


int board[102][102];
int vis[102][102];
int n,m,k;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

queue<pair<int,int>> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;

    for(int i = 0; i < k; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        for(int j = a; j < c;j++){
            for(int k = b; k < d;k++){
                board[j][k] = 1;
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){    
    //         cout << board[i][j];
    //     }
    //     cout << endl;
    // }
    

    vector<int> v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){    
            if(board[i][j] == 1 || vis[i][j] == 1) continue;
            vis[i][j] = 1;
            q.push({i,j});

            int area = 0;
            
            while(!q.empty()){
                auto cur = q.front();q.pop();
                area++;
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] == 1 || board[nx][ny] == 1) continue;
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }

            }
            if( area != 0) v.push_back(area);

        }
    }

    sort(v.begin(),v.end());
    cout << v.size() << '\n';
    for(auto n:v) cout << n << ' ';

    return 0;
}