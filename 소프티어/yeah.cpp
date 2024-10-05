#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<char> v;

    for(auto c: s){
        if (c == '('){
            if (!v.empty()){
                if(v.back() == ')'){
                    v.push_back('+');
                    v.push_back('(');
                }
                if(v.back() == '('){
                    v.push_back('(');
                }
                
            }
            else{
                v.push_back('(');
            }
        }
        if( c == ')'){
            if(v.back() == '('){
                    v.push_back('1');
                    // v.push_back(')');
            }
            if(v.back() == ')'){
                    v.push_back('+');
                    v.push_back('1');
                    v.push_back(')');
            }
        }

    }

    for(auto c:v) cout << c;
    return 0;
}
