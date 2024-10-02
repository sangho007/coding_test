#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,ans = 0;
    cin >> N;

    while(N--){
        stack<char> s;
        string input;
        cin >> input;
        int isValid = true;

        for (auto c:input){
            if(!s.empty()){
                if(s.top() != c && c == ')'){
                    s.pop();
                }
                else{
                    s.push(c);
                }
            }
            else{
                s.push(c);
            }
            
        }

        if(s.empty()) cout << "YES\n";
        else cout << "NO\n";

    }

    
    return 0;
}