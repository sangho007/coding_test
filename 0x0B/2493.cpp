// #include <bits/stdc++.h>
// using namespace std;

// int board[500002];
// bool vis[500002];

// int n;
// int dx = -1;
// queue<int> q;

// int main(){
//     cin >> n;
//     for(int i = 0; i < n;i++) cin >> board[i];

//     vector<int> v;
//     for(int i = 0; i < n;i++){
//         // fill(vis,vis+n,0);
//         q.push(i);

//         while(!q.empty()){
//             auto cur = q.front(); q.pop();
//             int nx = cur + dx;
//             if (nx < 0) continue;
//             if (board[nx] > board[i]) {
//                 v.push_back(nx+1);
//                 break;
//             }
//             q.push(nx);
//         }
//         if(v.size() != i + 1) v.push_back(0);
//     }

//     for(auto n:v) cout << n << ' ';

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

#define X first 
#define Y second

stack<pair<int, int>> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    s.push({0,100000002});
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        while(s.top().Y < t) s.pop();
        cout << s.top().X << ' ';
        s.push({i,t});
        

    }

    return 0;
}