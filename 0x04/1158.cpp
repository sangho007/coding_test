#include <bits/stdc++.h>  
using namespace std;  
  
int main(){  
    ios::sync_with_stdio(false); 
    cin.tie(0);  
  
    int N, K;  
    cin >> N >> K;  
  
    list<int> L;  
    for(int i = 1; i <= N; i++) L.push_back(i);  
  
    auto iter = L.begin();  
    cout << '<';  
  
    while(!L.empty()) {  
        for(int i = 0; i < K - 1; i++) {  
            iter++;  
            if(iter == L.end()) {  
                iter = L.begin();  
            }  
        }  
        cout << *iter;  
        iter = L.erase(iter);  
        if(!L.empty()) {  
            cout << ", ";  
        }  
        if(iter == L.end()) {  
            iter = L.begin();  
        }  
    }  
    cout << '>';  
    return 0;  
}  