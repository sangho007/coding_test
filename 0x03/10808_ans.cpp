#include <bits/stdc++.h>
// #include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio();
    cin.tie(0);

    int arr[26] = {0};
    string s;
    cin >> s;
    for(auto c : s) arr[c - 'a']++;
    for(int a: arr) cout << a << ' ';

    

    return 0;
}
