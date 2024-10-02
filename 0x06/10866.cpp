#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    deque<int> dq;

    while(N--){
        string op;
        cin >> op;
        if (op == "push_front"){
            int t;
            cin >> t;
            dq.push_front(t);
        }
        if (op == "push_back"){
            int t;
            cin >> t;
            dq.push_back(t);
        }
        if (op == "pop_front"){
            if(!dq.empty()){
                cout << dq.front() << '\n';        
                dq.pop_front();
            }
            else{
                cout << -1 << '\n';
            }
        }
        if (op == "pop_back"){
            if(!dq.empty()){
                cout << dq.back() << '\n';        
                dq.pop_back();
            }
            else{
                cout << -1 << '\n';
            }
        }
        if (op == "size"){
            cout << dq.size() << '\n';
        }
        if (op == "empty"){
            cout << dq.empty() << '\n';
        }
        if (op == "front"){
            if(!dq.empty()){
                cout << dq.front() << '\n';        
            }
            else{
                cout << -1 << '\n';
            }
        }
        if (op == "back"){
            if(!dq.empty()){
                cout << dq.back() << '\n';        
            }
            else{
                cout << -1 << '\n';
            }
        }

        

    }


    return 0;
}