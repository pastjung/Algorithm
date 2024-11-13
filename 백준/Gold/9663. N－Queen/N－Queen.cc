#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
 
int board[15] = {0,};
int N, result = 0;

bool check(int col){
    for(int i = 0; i < col; i++){
        if(board[col] == board[i] || col - i == abs(board[col] - board[i])) return false;
    }
    return true;
}
 
void nQueen(int cnt){
    if(cnt == N) {
        result++;
    }
    else{
        for(int i = 0; i < N; i++){
            board[cnt] = i;     // cnt번째 행, i번째 열에 queen을 놓는다.
            if(check(cnt)) nQueen(cnt + 1);
        }    
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     
    cin >> N;
    nQueen(0);
    cout << result << '\n';
    return 0;
}