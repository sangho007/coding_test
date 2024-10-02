#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, L;
    cin >> N >> L;
    
    vector<int> v(N);
    
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    for(int i = 0; i < N; i++) {
        int start = max(0, i - L + 1);
        int end = i + 1;
        
        int min_A = *min_element(v.begin() + start, v.begin() + end);
        cout << min_A << ' ';
    }
    
    return 0;
}