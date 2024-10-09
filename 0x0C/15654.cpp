#include <bits/stdc++.h>
using namespace std;

int n,m;

int arr1[10];
int arr2[10];
int is_used[10002];
queue<int> q;

void func(int k){
    if(k == m){
        for(int i = 0; i < m; i++) cout << arr2[arr1[i]] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++){
        if(!is_used[i]){
            arr1[k] = i;
            is_used[i] = 1;
            func(k+1);
            is_used[i] = 0;
        }
    }
}

int main(){
    ios:: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }
    sort(arr2,arr2+n);

    func(0);

    return 0;
}