#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll ans = 0;
    int n;
    cin >> n;
    stack<int> s;
    

    for(int i = 0; i < n; i++){
        ll t;
        cin >> t;  
        if(s.empty()) s.push(t);
        else{
            while(!s.empty() && s.top() <= t){
                s.pop();
            }
            ans += s.size();
            s.push(t);            
        }
    }

    cout << ans;

    return 0;
}