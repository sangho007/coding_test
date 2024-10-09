#include <bits/stdc++.h>
using namespace std; 

int n,m,l; // n : 행 개수, m : 열 개수, l : cctv 개수
tuple<int,int,int> info[10]; // cctv <번호,x좌표,y좌표> 
int answer = INT_MAX;

void deepCopy(int src[10][10], int dest[10][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            dest[i][j] = src[i][j];
        }
    }
}

void func(int k, int map[10][10]){
    if(k == l){     // 종료조건. 전달받은 map에서 0개수를 세서 작은값 나오면 update 
        int t = 0;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(map[i][j] == 0) t++;
        }
        answer = min(answer,t);
        return ;
    }

    for(int i = 0; i < 4; i ++){ // 90도 방향 탐색이므로 4번 반복
        auto cur = info[k]; // 
        auto cur_type = get<0>(cur);
        auto cur_x = get<1>(cur);
        auto cur_y = get<2>(cur);

        int temp_map[10][10];   
        deepCopy(map,temp_map); // 얕은복사 방지

        if(cur_type == 1){
            if(i == 0){
                for(int j = cur_y + 1; j < m; j++) { // 동
                    if(temp_map[cur_x][j] == 6) break;
                    temp_map[cur_x][j] = 7;
                }
            }
            if(i == 1){
                for(int j = cur_y - 1; j >= 0; j--) { //서
                    if(temp_map[cur_x][j] == 6) break;
                    temp_map[cur_x][j] = 7;
                }
            }
            if(i == 2){
                for(int j = cur_x + 1; j < n; j++) { //남
                    if(temp_map[j][cur_y] == 6) break;
                    temp_map[j][cur_y] = 7;
                }
            }
            if(i == 3){
                for(int j = cur_x - 1; j >= 0; j--) { // 북
                    if(temp_map[j][cur_y] == 6) break;
                    temp_map[j][cur_y] = 7;
                }
            }
        }
        if(cur_type == 2){
            if(i == 0){
                for(int j = cur_y + 1; j < m; j++) { //동
                    if(temp_map[cur_x][j] == 6) break;
                    temp_map[cur_x][j] = 7;
                }
                for(int j = cur_y - 1; j >= 0; j--) {//서
                    if(temp_map[cur_x][j] == 6) break;
                    temp_map[cur_x][j] = 7;
                }
            }
            if(i == 1){
                for(int j = cur_x + 1; j < n; j++) {//남
                    if(temp_map[j][cur_y] == 6) break;
                    temp_map[j][cur_y] = 7;
                }
                for(int j = cur_x - 1; j >= 0; j--) {//북
                    if(temp_map[j][cur_y] == 6) break;
                    temp_map[j][cur_y] = 7;
                }
            }
            if(i == 2){
                continue;;
            }
            if(i == 3){
                continue;;
            }
        }
        if(cur_type == 3){
            if(i == 0){
                for(int j = cur_y + 1; j < m; j++) {
                    if(temp_map[cur_x][j] == 6) break;
                    temp_map[cur_x][j] = 7;
                }
                for(int j = cur_x - 1; j >= 0; j--) {
                    if(temp_map[j][cur_y] == 6) break;
                    temp_map[j][cur_y] = 7;
                }
            }
            if(i == 1){
                for(int j = cur_y - 1; j >= 0; j--) {
                    if(temp_map[cur_x][j] == 6) break;
                    temp_map[cur_x][j] = 7;
                }
                for(int j = cur_x - 1; j >= 0; j--) {
                    if(temp_map[j][cur_y] == 6) break;
                    temp_map[j][cur_y] = 7;
                }
            }
            if(i == 2){
                for(int j = cur_y - 1; j >= 0; j--) {
                    if(temp_map[cur_x][j] == 6) break;
                    temp_map[cur_x][j] = 7;
                }
                for(int j = cur_x + 1; j < n; j++) {
                    if(temp_map[j][cur_y] == 6) break;
                    temp_map[j][cur_y] = 7;
                }
            }
            if(i == 3){
                for(int j = cur_y - 1; j >= 0; j--) {
                    if(temp_map[cur_x][j] == 6) break;
                    temp_map[cur_x][j] = 7;
                }
                for(int j = cur_x - 1; j >= 0; j--) {
                    if(temp_map[j][cur_y] == 6) break;
                    temp_map[j][cur_y] = 7;
                }
            }
        }
        if(cur_type == 4){ // x-
            if(i == 0){
                for(int j = cur_y + 1; j < m; j++) {
                    if(temp_map[cur_x][j] == 6) break;
                    temp_map[cur_x][j] = 7;
                }
                for(int j = cur_y - 1; j >= 0; j--) {
                    if(temp_map[cur_x][j] == 6) break;
                    temp_map[cur_x][j] = 7;
                }
                for(int j = cur_x + 1; j < n; j++) {
                    if(temp_map[j][cur_y] == 6) break;
                    temp_map[j][cur_y] = 7;
                }
            }
            if(i == 1){ //y+
                for(int j = cur_y - 1; j >= 0; j--) {
                    if(temp_map[cur_x][j] == 6) break;
                    temp_map[cur_x][j] = 7;
                }
                for(int j = cur_x + 1; j < n; j++) {
                    if(temp_map[j][cur_y] == 6) break;
                    temp_map[j][cur_y] = 7;
                }
                for(int j = cur_x - 1; j >= 0; j--) {
                    if(temp_map[j][cur_y] == 6) break;
                    temp_map[j][cur_y] = 7;
                }
            }
            if(i == 2){ // y-
                for(int j = cur_x + 1; j < n; j++) {
                    if(temp_map[j][cur_y] == 6) break;
                    temp_map[j][cur_y] = 7;
                }
                for(int j = cur_x - 1; j >= 0; j--) {
                    if(temp_map[j][cur_y] == 6) break;
                    temp_map[j][cur_y] = 7;
                }
                for(int j = cur_y + 1; j < m; j++) {
                    if(temp_map[cur_x][j] == 6) break;
                    temp_map[cur_x][j] = 7;
                }
            }
            if(i == 3){ //x+
                for(int j = cur_x - 1; j >= 0; j--) {
                    if(temp_map[j][cur_y] == 6) break;
                    temp_map[j][cur_y] = 7;
                }
                for(int j = cur_y + 1; j < m; j++) {
                    if(temp_map[cur_x][j] == 6) break;
                    temp_map[cur_x][j] = 7;
                }
                for(int j = cur_y - 1; j >= 0; j--) {
                    if(temp_map[cur_x][j] == 6) break;
                    temp_map[cur_x][j] = 7;
                }
            }
        }
        if(cur_type == 5){
            if(i == 0){
                for(int j = cur_y + 1; j < m; j++) {
                    if(temp_map[cur_x][j] == 6) break;
                    temp_map[cur_x][j] = 7;
                }
                for(int j = cur_y - 1; j >= 0; j--) {
                    if(temp_map[cur_x][j] == 6) break;
                    temp_map[cur_x][j] = 7;
                }
                for(int j = cur_x + 1; j < n; j++) {
                    if(temp_map[j][cur_y] == 6) break;
                    temp_map[j][cur_y] = 7;
                }
                for(int j = cur_x - 1; j >= 0; j--) {
                    if(temp_map[j][cur_y] == 6) break;
                    temp_map[j][cur_y] = 7;
                }
            }
            if(i == 1){
                continue;
            }
            if(i == 2){
                continue;
            }
            if(i == 3){
                continue;
            }
        }

        func(k+1,temp_map);        
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int board[10][10]; // 보드는 넘겨줄 것이므로 지역변수에 넣자 

    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
        cin >> board[i][j];
        if(board[i][j] != 0 && board[i][j] != 6) {
            info[l] = {board[i][j],i,j}; // l은 cctv개수 
            l++;
        }
    }

    func(0, board);
    cout << answer; 

    return 0;
}