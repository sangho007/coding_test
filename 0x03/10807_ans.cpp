#include <bits/stdc++.h>
using namespace std;

int N,v;
int arr[101];

int main(){
    ios::sync_with_stdio();
    cin.tie(0);

    int ans = 0;

    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    cin >> v;

    for(int i = 0; i < N; i++){
        if (arr[i] == v) ans++;
    }

    cout << ans;
    return 0;
}