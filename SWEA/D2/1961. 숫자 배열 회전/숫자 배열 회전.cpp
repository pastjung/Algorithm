#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void func(int N){
    vector<vector<int>> arr(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
        	cin >> arr[i][j];
        }
    }
    for(int i = 0; i < N; i++){
    	for(int j = N-1; j >= 0; j--){
            cout << arr[j][i];
        }
        cout << ' ';
        for(int j = N-1; j >= 0; j--){
            cout << arr[N-1 - i][j];
        }
        cout << ' ';
        for(int j = 0; j < N; j++){
            cout <<  arr[j][N - 1 - i];  
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
        cout << '#' << i << '\n';
        func(N);
    }
    return 0;
}