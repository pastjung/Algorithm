#include<iostream>
using namespace std;

#define MOD 1234567891

long long pow(long long N, long long R){
    long long result = 1;
    while(R){
     	if( R % 2 ) result = ( result * N ) % MOD;
        N = ( N * N ) % MOD;
        R /= 2;
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
        int N, R;
        cin >> N >> R;
        
        long long A = 1, B = 1;
        for(int j = N; j >= N - R + 1; j--) A = ( A * j ) % MOD;
        for(int j = R; j >= 1; j--) B = ( B * j ) % MOD;
        
        cout << '#' << i << ' ' << ( A * pow(B, MOD - 2) ) % MOD << '\n';
    }
    return 0;
}