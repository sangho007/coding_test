#include <bits/stdc++.h>  
using namespace std;  
  
int main(){  
    ios::sync_with_stdio(0);  
    cin.tie(0);  
  
    int N, M;  
    cin >> N >> M;  
  
    deque<int> dq;  
    for (int i = 1; i <= N; i++) dq.push_back(i);  
  
    int ans = 0;  
    while (M--) {  
        int t;  
        cin >> t;  
  
        // 목표 원소 t의 현재 인덱스를 찾는다.  
        int idx = 0;  
        while (dq[idx] != t) {  
            idx++;  
        }  
  
        // 왼쪽으로 이동하는 횟수와 오른쪽으로 이동하는 횟수를 계산한다.  
        int left_moves = idx;  
        int right_moves = dq.size() - idx;  
  
        // 더 적은 횟수의 이동을 선택한다.  
        if (left_moves <= right_moves) {  
            // 왼쪽으로 이동  
            while (left_moves--) {  
                dq.push_back(dq.front());  
                dq.pop_front();  
                ans++;  
            }  
        } else {  
            // 오른쪽으로 이동  
            while (right_moves--) {  
                dq.push_front(dq.back());  
                dq.pop_back();  
                ans++;  
            }  
        }  
  
        // 첫 번째 원소를 뽑아낸다.  
        dq.pop_front();  
    }  
  
    cout << ans;  
    return 0;  
}  