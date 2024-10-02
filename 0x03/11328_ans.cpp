#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio();
    cin.tie(0);


    int N;
    string pre,post;
    cin >> N;

    while(N--){
        int arr[26] = {0};
        cin >> pre >> post;
        for(auto c:pre) arr[c-'a']++;
        for(auto c:post) arr[c-'a']--;

        bool isPossible = true;

        for(int j : arr){
            if (j != 0) isPossible = false;
        }

        if (isPossible){
            cout << "Possible\n";
        }
        else{
            cout << "Impossible\n";
        }
    }  
    return 0;
}