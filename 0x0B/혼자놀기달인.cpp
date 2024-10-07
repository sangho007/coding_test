#include<bits/stdc++.h>
using namespace std;

int board[102];
int vis[102];

queue<int> q;
int solution(vector<int> cards) {
    int answer = 1;

    vector<int> v;

    for(auto c:cards){
        if (vis[c] == 1) continue;
        vis[c] = 1;
        q.push(c);
        
        int score = 0;

        while(!q.empty()){
            auto cur = q.front(); q.pop();
            // cout << cur << ' ';
            score++;
            int nx = cards[cur-1];
            if(vis[nx] == 1){
                v.push_back(score);
                continue;
            }
            vis[nx] = 1;
            q.push(nx);
        }
    }

    sort(v.begin(),v.end());
    
    answer *= v.back(); v.pop_back();
    answer *= v.back(); v.pop_back();
    // for(auto c:v) cout << c << endl;

    return answer;
}

int main(){

    vector<int> v = {8,6,3,7,2,5,1,4};
    cout << solution(v);
    return 0;
}