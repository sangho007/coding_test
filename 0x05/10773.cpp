#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int K, ans = 0;
    cin >> K;
    stack<int> s; 

    while(K--){
        int tmp;
        cin >> tmp;
        if (tmp == 0) s.pop();
        else s.push(tmp);
    }
    while(!s.empty()){
        ans += s.top();
        s.pop();
    } 
    cout << ans;

    return 0;
}