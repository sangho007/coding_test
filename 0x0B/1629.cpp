#include <bits/stdc++.h>
using namespace std;

long long func(long long a,long long b, long long c){
    if(b == 1) return a % c;

    long long val = func(a,b/2,c);
    val = val * val % c;

    if(b & 0x01) return val * a % c;
    return val;

}

int main(){
    long long a,b,c;
    cin >> a >> b >> c;
    cout << func(a,b,c);
}