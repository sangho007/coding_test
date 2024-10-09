#include <bits/stdc++.h>  
using namespace std;  
#define X first   
#define Y second  
  
int n;  
int cnt;  
  
pair<int,int> arr[15];  // 퀸의 위치를 저장하는 배열  

  
void func(int k){  
    if (k == n){  // N개의 퀸을 모두 배치했을 때  
        cnt++;  
        return;  
    }  
    for(int i = 0; i < n; i++) {  
        bool is_possible = true;  
        
        // 이전에 놓은 퀸들과 비교  
        for(int prev = 0; prev < k; prev++) {  
            // 같은 행, 같은 열 확인  
            if(i == arr[prev].Y || abs(arr[prev].Y - i) - abs(k-prev) == 0) {  
                is_possible = false;  
                break;  
            }  
        }
                         
        if(is_possible) {  
            arr[k] = {k,i};  // k 
            func(k+1);  // 다음 퀸을 배치하러 이동  
        }    
    }
    
}  
  
int main(){  
    ios::sync_with_stdio(0);  
    cin.tie(0);  
  
    cin >> n;  
    func(0);  // 0번째 퀸부터 배치 시작  
    cout << cnt;  // 가능한 배치 경우의 수 출력  
    return 0;  
}  