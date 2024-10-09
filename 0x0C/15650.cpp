#include <bits/stdc++.h>
using namespace std;

int n,m;

vector<int> v(10);
bool is_used[10];

void func(int k){
    if(k == m){
        // sort(v.begin(),v.end());
        for(int i = 0; i < k; i++) cout << v[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!is_used[i]){
            if(k == 0 || v[k-1] < i){
                v[k] = i;
                is_used[i] = 1;
                func(k+1);
                is_used[i] = 0;
            }            
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < v.size(); i++) v[i] = INT_MAX;
    
    func(0);

    return 0;
}