#include <bits/stdc++.h>
using namespace std; 

int arr[1000005];
int dist[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int f,s,g,u,d;

    fill(dist, dist+1000005,-1);

    cin >> f >> s >> g >> u >> d;

    dist[s] = 0;
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(cur == g){
            cout << dist[g];
            return 0;
        }
        for(auto dx : {u,-d}){
            int nx = cur + dx;
            if(nx < 1 || nx > f) continue;
            if(dist[nx] >= 0) continue;
            dist[nx] = dist[cur] + 1;
            q.push(nx);
        }
    }

    
    cout << "use the stairs";
    

    return 0;
}