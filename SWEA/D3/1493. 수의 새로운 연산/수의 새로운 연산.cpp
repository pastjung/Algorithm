#include<iostream>
#include<vector>
using namespace std;

int N = 300;
vector<vector<int>> board(N, vector<int>(N, 0));

int func(int p, int q){
    int px = -1, py, qx =-1, qy;
    for(int i = 1; i < N; i++){
        if(px != -1 && qx != -1) break;
        
        if(px == -1 && i * i + i >= 2 * p){
            for(int j = 0; j < i; j++){
                if(board[i - j][1 + j] == p){
                    py = i - j;
                    px = 1 + j;
                }
            }
        }
        
        if(qx == -1 && i * i + i >= 2 * q){
            for(int j = 0; j < i; j++){
                if(board[i - j][1 + j] == q){
                    qy = i - j;
                    qx = 1+ j;
                }
            }
        }
    }
    return board[py + qy][px + qx];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    int temp = 0;
    for(int i = 1; i < N; i++){
        for(int j = 1; j <= i; j++){
            board[i - j + 1][j] = ++temp;
        }
    }
    
    for(int i = 1; i <= T; i++){
 		int p, q;
        cin >> p >> q;
        cout << '#' << i << ' ' << func(p, q) << '\n';
    }
    return 0;
}