#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    queue<int> q;

    while(N--) {
        string op;
        cin >> op;
        if (op == "push"){
            int temp;
            cin >> temp;
            q.push(temp);
        }
        if (op == "pop"){
            if (!q.empty()){
                cout << q.front() << '\n';
                q.pop();
            }
            else{
                cout << -1 << '\n';
            }
        }
        if (op == "size"){
            cout << q.size() << '\n';
        }
        if (op == "empty"){
            cout << q.empty() << '\n';
        }
        if (op == "front"){
            if (!q.empty()){
                cout << q.front() << '\n';
            }
            else{
                cout << -1 << '\n';
            }
        }
        if (op == "back"){
            if (!q.empty()){
                cout << q.back() << '\n';
            }
            else{
                cout << -1 << '\n';
            }
        }
    }   
    return 0;
}