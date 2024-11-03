#include <iostream>
using namespace std;

int func(long long x, long long y, long long N){
    int count = 0;
    while(!(x > N || y > N)){
        if(x > y){
            y += x;
        }
        else{
            x += y;
        }
        count++;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        long long A, B, N;
        cin >> A >> B >> N;
        cout << func(A, B, N) << "\n";
    }
    
    return 0;
}