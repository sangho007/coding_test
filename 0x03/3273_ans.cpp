#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio();
    cin.tie(0);

    int n,x;
    int arr[100001] = {};
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    cin >> x;

    bool occur[2000001] = {0};
    for (int i = 0; i < n; i++){
        if(((x - arr[i]) > 0) && occur[x - arr[i]]){
            ans++;
        }
        occur[arr[i]] = true;
    } 
    
    
    cout << ans;    

    return 0;
}