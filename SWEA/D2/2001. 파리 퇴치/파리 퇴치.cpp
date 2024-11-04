#include<iostream>
#include<vector>
using namespace std;

// N * N 판
// M * M 파리채
int func(vector<vector<int>> arr, int N, int M){
    int max = 0;
    // 세로 방향으로 계산
    for(int i = 0; i <= N - M; i++){
        // 파리채에 잡히는 파리 수 ( 오른쪽으로 이동하기 전 값 )
    	int count = 0;
        for(int j = i; j < i + M; j++){
         	for(int k = 0; k < M; k++){
             	   count += arr[j][k];
            }
        }
        
        // 최대값 비교
        if(max < count) max = count;
        
        // 가로로 이동
        for(int j = 0; j < N - M; j++){
            // 수정된 파리채 값 ( 좌우 한줄씩만 수정 )
         	for(int k = 0; k < M; k++){
                count -= arr[i + k][j];
                count += arr[i + k][j + M];
            }
            
            // 최대값과 비교
            if(max < count) max = count;
        }
    }
    
    return max;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int N, M;
        cin >> N >> M;
        vector<vector<int>> arr(N);
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
            	int temp;
            	cin >> temp;
            	arr[j].push_back(temp);    
            }
        }
        cout << "#" << i << ' ' << func(arr, N, M) << '\n';
    }
    return 0;
}