#include <bits/stdc++.h>
using namespace std;

#define X first 
#define Y second 

int arr[105][105];
int vis[105][105];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int mx = 0;
    vector<int> ans;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            mx = max(mx,arr[i][j]);
        }
    }

    for(int k = 1; k <= mx; k++){
        queue<pair<int,int>> q;

        vector<int> cnts;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                vis[i][j] = 0;;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] <= k || vis[i][j]) continue;
                vis[i][j] = 1;
                q.push({i,j});

                int cnt = 0;
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    cnt++;
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(vis[nx][ny] || arr[nx][ny] <= k) continue;
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
                if(cnt != 0) cnts.push_back(cnt);
            }
        }
        ans.push_back(cnts.size());
    }
    if(*max_element(ans.begin(),ans.end()) == 0) cout << 1;
    else cout << *max_element(ans.begin(),ans.end());

    // for(auto n:ans) cout << n << ' ';

    return 0;
}