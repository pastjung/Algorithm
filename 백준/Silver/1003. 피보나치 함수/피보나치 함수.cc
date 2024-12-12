#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> memo(41, {-1, -1});

void fibonacci(int N, int& zero, int& one){
    if(memo[N].first != -1 && memo[N].second != -1){
        zero = memo[N].first;
        one = memo[N].second;
        return;
    } 
    if (N == 0) zero++;
    else if (N == 1) one++;
    else {
        int zero1 = 0, one1 = 0;
        int zero2 = 0, one2 = 0;
        
        fibonacci(N - 1, zero1, one1);
        fibonacci(N - 2, zero2, one2);
        
        zero = zero1 + zero2;
        one = one1 + one2;
    }
    
    memo[N] = {zero, one};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        
        int zero = 0, one = 0;
        fibonacci(N, zero, one);
        
        cout << zero << ' ' << one << '\n';
    }
    return 0;
}