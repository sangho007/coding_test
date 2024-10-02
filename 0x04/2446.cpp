#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N;i++){
        for (int j = 0; j < i ;j++) cout <<' ';
        for (int j = 2*N-1 - 2*i; j > 0 ;j--) cout <<'*';
        // for (int j = 0; j < i ;j++) cout <<' '; 
        cout << '\n';
               
    }
    for (int i = 1; i < N ;i++){
        for (int j = 1; j < N-i ;j++) cout <<' ';
        for (int j = 0; j < 2*i+1 ;j++) cout <<'*';
        // for (int j = 1; j < N-i ;j++) cout <<' ';        
        cout << '\n';
    }

    return 0;
}