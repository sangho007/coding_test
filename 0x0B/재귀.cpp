#include<bits/stdc++.h>
using namespace std;


int func1(int n){
    if (n == 0){
        return 0;
    }
    cout << n;
    func1(n-1);
}

int func2(int n){
    if (n == 0) return 0;
    return n + func2(n-1);
}



int main(){
    func1(5);
    cout << func2(5);
    return 0;
}

