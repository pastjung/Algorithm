#include<iostream>
#include<string>
#include<vector>
using namespace std;

string func(vector<string> stone, int N){
    for(int i = 2; i < N - 2; i++){
     	for(int j = 2; j < N - 2; j++){
            if(stone[i][j] == 'o'){
            	if(stone[i+1][j+1] == 'o' && stone[i+2][j+2] == 'o' && stone[i-1][j-1] == 'o' && stone[i-2][j-2] == 'o') return "YES";
            	if(stone[i-1][j+1] == 'o' && stone[i-2][j+2] == 'o' && stone[i+1][j-1] == 'o' && stone[i+2][j-2] == 'o') return "YES";    
            }
        }
    }
    for(int i = 2; i < N - 2; i++){
     	for(int j = 0; j < N; j++){
            if(stone[i][j] == 'o' && stone[i+1][j] == 'o' && stone[i+2][j] == 'o' && stone[i-1][j] == 'o' && stone[i-2][j] == 'o') return "YES";
        }
    }
    for(int i = 0; i < N; i++){
     	for(int j = 2; j < N - 2; j++){
         	if(stone[i][j] == 'o' && stone[i][j+1] == 'o' && stone[i][j+2] == 'o' && stone[i][j-1] == 'o' && stone[i][j-2] == 'o') return "YES";
        }
    }
    return "NO";
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
        vector<string> stone(N, "");
        for(int i = 0; i < N; i++){
         	cin >> stone[i];   
        }
        cout << '#' << i << ' ' << func(stone, N) << '\n';
    }
    return 0;
}