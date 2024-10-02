#include<bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v(3);
    int tmp;

    for(int i = 0; i<3; i++) cin >>v[i];

    sort(v.begin(), v.end());

    for(auto n:v) cout << n << ' ';

    return 0;
}