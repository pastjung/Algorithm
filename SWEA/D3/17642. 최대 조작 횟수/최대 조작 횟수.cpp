#include <iostream>
using namespace std;

long solution(long A, long B){
    // A > B 인 경우, A == B인 경우, A + 1 == B인 경우
    if(A == B){
        return 0;
    } else if(B - A <= 1){
        return -1;
    }

    return (B - A) / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int TC = 1; TC <= T; TC++){
        long A, B;
        cin >> A >> B;
        cout << '#' << TC << ' ' << solution(A, B) << '\n';
    }
    
    return 0;
}