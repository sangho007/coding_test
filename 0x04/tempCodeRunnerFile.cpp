#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio();
    cin.tie(0);

    int N;
    cin >> N;

    while(N--){
        string init;
        cin >> init;

        list<char> s;
        auto cursor = s.begin();

        for(auto op: init){
            if (op == '<'){
                if (cursor != s.begin()) cursor--;
            }
            else if (op == '>'){
                if (cursor != s.end()) cursor++;
            }
            else if (op == '-'){
                if (cursor != s.begin()) {
                    cursor--;
                    cursor = s.erase(cursor);
                }
            }
            else{
                s.insert(cursor,op);
            }
        }
        for (auto c:s) cout << c;
        cout << '\n';
    }

    return 0;
}