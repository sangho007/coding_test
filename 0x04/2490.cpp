#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cnt, ans = 0;

    for ( int i = 0; i<3;i++){   
        ans = 0;    
        for(int j = 0; j < 4; j++){
            int tmp = 0;
            cin >> tmp;
            ans += tmp; 
        }
        if (ans == 4) cout << "E\n";
        if (ans == 3) cout << "A\n";
        if (ans == 2) cout << "B\n";
        if (ans == 1) cout << "C\n";
        if (ans == 0) cout << "D\n";
    }

    return 0;
}