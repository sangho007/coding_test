#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;

    vector<char> s;
    int t;

    bool isValid = true;

    for(auto c:input){
        if (c == '(' || c == '['){
            s.push_back(c);
        }
        else if(c == ')'){
            ;    
        }
        else if(c == ']'){
            ;
        }
    }


    return 0;
}