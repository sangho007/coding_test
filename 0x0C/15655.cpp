#include <bits/stdc++.h>
using namespace std; 

int n,m;

int arr[10];
int is_used[10];
int num[10];

void func(int k){
    if (k == m){
        for(int i = 0; i < k; i++) cout << num[arr[i]] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++){
        if(k == 0 || num[arr[k-1]] <= num[i]){
            if(!is_used[i]){
                arr[k] = i;
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

    for(int i = 0; i < n; i++){ cin >> num[i];}
    sort(num,num+n);

    func(0);

    return 0;
}