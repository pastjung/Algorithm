#include<iostream>
#include<vector>
using namespace std;

void func(int N){
    vector<vector<int>> arr(N, vector<int>(N, 0));
    
    int dir_num = 3;	// 초기 이동 방향
    int x = 0, y = 0;	// 초기 위치
    
    // ( dx, dy ) = 동남서북 순서 -> 시계 방향 순
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, -1, 0, 1 };
    
    for(int i = 1; i <= N * N; i++){
        arr[x][y] = i;
        
        // ( nx, ny ) = 다음 위치
        int nx = x + dx[dir_num];
    	int ny = y + dy[dir_num];
        
        if( 0 <= nx && nx < N && 0 <= ny && ny < N && arr[nx][ny] == 0){
            // 다음 위치가 올바른 범위인지 확인
            x = nx;
            y = ny;
        } else{
            // 방향 변경 -> 90도 회전
            dir_num = (dir_num + 1) % 4;
            x += dx[dir_num];
            y += dy[dir_num];
        }
    }
    
    // 출력
    for(vector<int> v : arr){
     	for(int i : v){
            cout << i << ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int N; 
        cin >> N;
        cout << "#" << i << '\n';
        func(N);
    }
    return 0;
}
        
        