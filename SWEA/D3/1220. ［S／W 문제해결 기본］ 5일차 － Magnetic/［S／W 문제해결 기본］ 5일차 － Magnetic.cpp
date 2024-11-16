#include<iostream>
#include<vector>
using namespace std;

int func(vector<vector<int>> board, int N){
 	int count = 0;
    for(int i = 0; i < N; i++){
        int now = 0;
     	for(int j = 0; j < N; j++){
            if (board[j][i] == 1){
                now = 1;
            } else if(board[j][i] == 2 && now == 1){
                now = 2;
             	count++;   
            }
        }
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T = 10;
    for(int i = 1; i <= T; i++){
        int N = 100;
        cin >> N;
        vector<vector<int>> board(N, vector<int>(N, 0));
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
             	cin >> board[j][k];   
            }
        }
        cout << '#' << i << ' ' << func(board, N) << '\n';
    }
    return 0;
}