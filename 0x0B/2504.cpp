#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> s;

    int answer = 0;
    int temp = 0;

    string ss;
    cin >> ss;
    for(auto c:ss) {
        if(c == '(' || c == '[') s.push(c);
        if(c == ')'){
            if(s.empty() || s.top() != '('){
                cout << 0;
                return 0;
            }
            else{
                s.pop();
                
            }
        }
        if(c == ']'){
            if(s.empty() || s.top() != '['){
                cout << 0;
                return 0;
            }
            else{
                s.pop();
                
            }
        }
        
    }

    cout << answer;
    return 0;
}