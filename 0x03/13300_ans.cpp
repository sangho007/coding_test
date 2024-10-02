#include<bits/stdc++.h>
using namespace std;


int N,K;
int S[1000][2]; // 성별 학년 
int grade[2][7];
// 남자 123456
// 여자 123456
int main(){
    ios::sync_with_stdio();
    cin.tie(0);

    int ans = 0;

    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> S[i][0] >> S[i][1];

    for(int i = 0; i < N; i++){
        if (S[i][0] == 0){ // 남자인경우
            grade[0][S[i][1]]++; // 해당 학년의 배열원소에 + 1
        }
        if (S[i][0] == 1){ // 여자인경우
            grade[1][S[i][1]]++;
        }
    }
    for(int i = 0; i < 2; i++){
        for (int j = 1; j < 7; j++){
            ans += (grade[i][j] + (K-1)) / K; // 반올림처리를 위해 k-1을 더한 후 k로 나눈다. 
        }
    }
    
    cout << ans;
    return 0;
}