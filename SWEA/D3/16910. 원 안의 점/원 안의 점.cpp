#include <iostream>
#include <vector>
using namespace std;

int solution(int N){
    int dot = 4 * N + 1;

    for(int i = 1; i <= N; i++){
        int y = 1;
        while(y * y <= (N * N) - (i * i)){
            y++;   
        }
        dot += 4 * (y - 1);
    }

    return dot;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N;
        cin >> N;
        cout << '#' << t << ' ' << solution(N) << '\n';
    }
    
    return 0;
}