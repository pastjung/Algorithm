#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool check(string str, int N, int index){
    for(int i = 0; i < N / 2; i++){
     	if(str[index + i] != str[index + N - 1 - i]) return false;
    }
    return true;
} 

int findMax(string str, int preMax){
    int max = 1;
    for(int len = 100; len > preMax; len--){
        for(int index = 0; index <= 100 - len; index++){
            if(check(str, len, index)) if(max < len) max = len;
        }
    }
 	return max;   
}

int func(vector<string> row) {
    int max = 1;
    vector<string> column(100, "");
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            column[j] += row[i][j];
        }
    }
    
    for(string str : row){
     	int len = findMax(str, max);
        if(max < len) max = len;
    }
    
    for(string str : column){
     	int len = findMax(str, max);
        if(max < len) max = len;
    }
    
    return max;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T = 10;
    while(T--){
        int N;
        cin >> N;
        vector<string> board(100, "");
        for(int i = 0; i < 100; i++) cin >> board[i];
        
        cout << '#' << N << ' ' << func(board) << '\n';
    }
    return 0;
}