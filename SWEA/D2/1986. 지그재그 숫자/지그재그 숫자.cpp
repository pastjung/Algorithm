#include<iostream>
using namespace std;

int func(int N){
    if(N % 2 == 0) return -1 * ( N / 2 );
    else return N - ( N / 2 );
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int N;
        cin >> N;
        cout << '#' << i << ' ' << func(N) << '\n';
    }
    return 0;
}