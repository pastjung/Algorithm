#include<iostream>
#include<algorithm>
using namespace std;

int func(int P, int Q, int R, int S, int W){
    int A = P * W, B = Q;
    if(W - R > 0){
     	B += ( W - R ) * S;
    }
    return min(A, B);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int P, Q, R, S, W;
        cin >> P >> Q >> R >> S >> W;
        cout << '#' << i << ' ' << func(P, Q, R, S, W) << '\n';
    }
    return 0;
}