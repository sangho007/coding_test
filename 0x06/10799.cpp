#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;

    int ans = 0;
    int prev = 0;

    stack<char> s;
    for(auto c:input){
        if(c == '(') {
            s.push(c);
            prev = '(';
        }
        if (c == ')') {
            s.pop();
            if (prev == '(') ans += s.size();
            if (prev == ')') ans++;
            prev = ')'; 
        }
    }
    cout << ans;
    return 0;
}