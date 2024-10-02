#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio();
    cin.tie(0);

    string init;
    list<char> s;
    
    int M = 0;

    cin >> init;
    for(auto c : init) s.push_back(c);
    auto iter = s.end();

    cin >> M;

    while (M--){
        char a,b;
        cin >> a;

        if(a == 'L'){
            if (iter != s.begin()){
                iter--;
            }
        }
        if(a == 'D'){
            if (iter != s.end()){
                iter++;
            }
        }
        if(a == 'B'){
            if (iter != s.begin()){
                iter--;
                iter = s.erase(iter);
                // 3
            }
        }
        if(a == 'P'){
            cin >> b;
            s.insert(iter,b);            
        }
    }
    
    for (auto c : s) cout << c;

    return 0;
}