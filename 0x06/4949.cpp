#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input; 
    vector<string> v;

    

    bool is_error = false;
    while(input != "."){
        getline(cin,input);
        v.push_back(input);
    }
    
    for (auto s:v){
        bool is_error = false;
        stack<char> st;

        for (auto c: s){
            if (c == '(') st.push(c);
            if (c == '[') st.push(c);
            if (c == ')') {
                if(!st.empty()){
                    if (st.top() == '('){
                        st.pop();    
                    }
                    else{
                        is_error = true;
                    }
                }
                else{
                    is_error = true;    
                }

            }
            if (c == ']') {
                if(!st.empty()){
                    if (st.top() == '['){
                        st.pop();    
                    }
                    else{
                        is_error = true;
                    }
                }
                else{
                    is_error = true;
                }
            }
        }

        if(*(s.end() -1) != '.') {
            is_error = true;
        }

        if(!st.empty()){
            is_error = true;
        }

        if (s != "."){
            if(!is_error){
                cout << "yes" << '\n';
            }
            else{
                cout << "no" << '\n';
            }
        }
        
    }

    return 0;
}