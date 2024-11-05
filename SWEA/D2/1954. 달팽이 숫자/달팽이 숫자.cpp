#include<iostream>
#include<vector>
using namespace std;

void func(int N){
    vector<vector<int>> arr(N, vector<int>(N, 0));
    int num = 1;
    for(int i = 0; i < N / 2; i++){
        // 가로 입력
        for(int j = i; j < N - i; j++){
            arr[i][j] = num;
            num++;
        }
        
        // 세로 입력
        for(int j = i + 1; j < N - i; j++){
         	arr[j][N - 1 - i] = num;
            num++;
        }
        
        // 역 가로 입력
        for(int j = N - 2 - i; j >= i; j--){
            arr[N - 1 - i][j] = num;
            num++;
        }
        
        // 역 세로 입력
        for(int j = N - 2 - i; j >= i + 1; j--){
            arr[j][i] = num;
            num++;
        }
    }
    // N이 홀수인 경우
    if(N % 2 == 1){
        arr[N/2][N/2] = num;
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
        
        