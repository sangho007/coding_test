#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio();
    cin.tie(0);

    string s1, s2;
    int ans = 0;

    cin >> s1 >> s2;

    int arr[26] = {0};

    for(auto c: s1) arr[c - 'a']++;
    for(auto c: s2) arr[c - 'a']++;

    for(auto a:arr) {
        if (a != 0) {
            ans += abs(a);
        }
    }
    cout << ans;
    return 0;
}