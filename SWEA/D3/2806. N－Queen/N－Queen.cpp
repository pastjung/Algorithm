#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool check(vector<int> board, int col){
    for(int i = 0; i < col; i++){
     	if(board[col] == board[i] || col - i == abs(board[col] - board[i])) return false;
    }
    return true;
}

int nQueen(vector<int> board, int N, int cnt){
    if(cnt == N) {
        return 1;
    }
    
    int result = 0;
    for(int i = 0; i < N; i++){
        board[cnt] = i;		// cnt번째 행, i번째 열에 queen을 놓는다.
        if(check(board, cnt)) result += nQueen(board, N, cnt + 1);
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 	
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int N;
        cin >> N;
        vector<int> board(N, 0);
        cout << '#' << i << ' ' << nQueen(board, N, 0) << '\n';
    }
    return 0;
}