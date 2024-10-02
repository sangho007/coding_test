#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    


    while(T--){
        string op;
        cin >> op;

        int n;
        cin >> n;

        string input;
        cin >> input;

        deque<int> dq;
        bool is_error = false;
        bool is_R = false;

        if(input.length() > 2) {  // Check if input is not "[]"
            input = input.substr(1, input.length() - 2); // Remove brackets
            stringstream ss(input);
            string token;
            while (getline(ss, token, ',')) {
                if (!token.empty()) {
                    dq.push_back(stoi(token));
                }
            }
        }
        
        for(auto c:op){
            if (c == 'R'){
                is_R = !is_R;
            }
            if (c == 'D'){
                if (!dq.empty()){
                    if (!is_R)
                        dq.pop_front();
                    else
                        dq.pop_back();
                }
                else{
                    is_error = true;
                }
            }
        }
        
        if(!is_error){
            if(!is_R){
                cout << '[';
                for (int i = 0; i < dq.size();i++){
                    cout << dq[i];
                    if (i != dq.size()-1){
                        cout << ',';
                    }
                }
                cout << ']' << '\n';
            }
            if(is_R){
                cout << '[';
                for (int i = dq.size() - 1; i >= 0;i--){
                    cout << dq[i];
                    if (i != 0){
                        cout << ',';
                    }
                }
                cout << ']' << '\n';
            }
            
        }
        else{
            cout << "error" << '\n';
        }        
    }
    return 0;
}