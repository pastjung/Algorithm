#include<iostream>
#include<string>
#include<vector>
using namespace std;

int func(vector<string> farm, int N){
    int result = 0;
    
    int count = 1;
    for(int i = 0; i < N / 2; i++){
    	for(int j = 1; j <= count; j++){
         	result += farm[i][( N - count ) / 2 + j - 1] - '0';
        }
        count += 2;
    }
    for(int i = N/2; i < N; i++){
    	for(int j = 1; j <= count; j++){
         	result += farm[i][( N - count ) / 2 + j - 1] - '0';
        }
        count -= 2;
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
        vector<string> farm(N, "");
        for(int j = 0; j < N; j++){
            cin >> farm[j];
        }
        cout << '#' << i << ' ' << func(farm, N) << '\n';
    }
    return 0;
}