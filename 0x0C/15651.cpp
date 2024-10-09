#include<bits/stdc++.h>
using namespace std;

int n,s;

int arr[10];

void func (int k){
    if(k == s){
        for(int i = 0; i < k; i++)
            cout << arr[i] <<' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if (k == 0 || arr[k-1] <= i){
            arr[k] = i;
            func(k+1);
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

