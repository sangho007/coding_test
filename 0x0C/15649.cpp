#include<bits/stdc++.h>
using namespace std;

int n,s;

int arr[10];
bool is_used[10];

void func (int k){
    if(k == s){
        for(int i = 0; i < k; i++)
            cout << arr[i] <<' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!is_used[i]){
            arr[k] = i;
            is_used[i] = 1;
            func(k+1);
            is_used[i] = 0;
        }
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    func(0);

    return 0;
}

