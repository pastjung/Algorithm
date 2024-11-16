#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int func(vector<vector<int>> board, int N){
 	int maxSum = 0, left = 0, right = 0;
    
    // 대각선
    for(int i = 0; i < N; i++){
        left += board[i][i];
        right += board[i][N - 1 - i];
    }
    maxSum = max(max(left, right), maxSum);
    
    // 가로 & 세로
    for(int i = 0; i < N; i++){
        int row = 0, column = 0;
     	for(int j = 0; j < N; j++){
            row += board[i][j];
            column += board[j][i];
        }
        maxSum = max(max(row, column), maxSum);
    }
    return maxSum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T = 10;
    for(int i = 1; i <= T; i++){
        int num;
        cin >> num;
        int N = 100;
        vector<vector<int>> board(N, vector<int>(N, 0));
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
             	cin >> board[j][k];   
            }
        }
        cout << '#' << num << ' ' << func(board, N) << '\n';
    }
    return 0;
}