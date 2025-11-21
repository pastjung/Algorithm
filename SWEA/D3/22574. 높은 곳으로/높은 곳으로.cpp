#include <iostream>
#include <vector>
using namespace std;

int solution(int N, int P){
    int height = 0;

    // 충돌이 발생하는지 탐색
    for(int n = 1; n <= N; n++){
        height += n;

        if(height == P){
            // 충돌이 발생하는 경우 -> 최초 선택 시 이동X : 2~N의 합 : N(N+1)/2
            height = N * (N + 1) / 2 - 1;
            break; 
        } else if(height > P){
            // 충돌이 발생하지 않는 경우 -> 모든 선택 이동 : 1~N의 합 : N(N+1)/2
            height = N * (N + 1) / 2;
            break;
        }
    }

    return height;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int TC = 1; TC <= T; TC++){
        int N, P;
        cin >> N >> P;
        cout << solution(N, P) << '\n';
    }
    
    return 0;
}