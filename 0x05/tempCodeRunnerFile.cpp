#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    stack<int> s;

    while(N--){
        string op;
        int x;
        cin >> op;
        if (op == "push") cin >> x, s.push(x);
        if (op == "pop") {
            if (!s.empty()) {
                cout << s.top() << '\n';
                s.pop();
            }
            else {
                cout << -1<< '\n';
            }
        }
        if (op == "size") cout << s.size()<< '\n';
        if (op == "empty") cout << s.empty()<< '\n';
    }

    return 0;
}