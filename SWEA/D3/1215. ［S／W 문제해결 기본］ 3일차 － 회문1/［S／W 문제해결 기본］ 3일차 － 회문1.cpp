#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool checkRow(vector<string> board, int N, int x, int y){
    for(int i = 0; i < N / 2; i++){
     	if(board[x][y + i] != board[x][y + N - 1 - i]) return false;
    }
    return true;
} 

bool checkCol(vector<string> board, int N, int x, int y){
    for(int i = 0; i < N / 2; i++){
     	if(board[x + i][y] != board[x + N - 1 - i][y]) return false;
    }
    return true;
}

int func(vector<string> board, int N){
    int count = 0;
   for(int i = 0; i < 8; i++){
    	for(int j = 0; j < 8; j++){
            if(j + N <= 8 && checkRow(board, N, i, j)) count++;
            if(i + N <= 8 && checkCol(board, N, i , j)) count++;
        }
   }
    return count;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for(int i = 1; i <= 10; i++){
        int N;
        cin >> N;
        vector<string> board(8, "");
        for(int j = 0; j < 8; j++){
            cin >> board[j];
        }
        cout << '#' << i << ' ' << func(board, N) << '\n';
    }
    return 0;
}
        