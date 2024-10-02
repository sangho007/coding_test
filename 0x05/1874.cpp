#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,tmp;
    int cnt = 1;
    cin >> n;

    stack<int> s;
    string ans;

    while (n--) {
        cin >> tmp;
        while( cnt <= tmp){
            s.push(cnt++);
            ans += "+\n";
        }
        if (s.top() != tmp ){
            cout << "No\n";
            return 0;
        }
        s.pop();
        ans += "-\n";
    }

    cout << ans;
    return 0;
}