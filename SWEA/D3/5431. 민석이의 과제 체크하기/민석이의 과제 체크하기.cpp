#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int TC = 1; TC <= T; TC++){
        int N, K;
        cin >> N >> K;

        vector<bool> summited(N + 1, false);
        for(int k = 1; k <= K; k++){
            int num;
            cin >> num;
            summited[num] = true;
        }
        
        cout << '#' << TC << ' ';
        for(int n = 1; n <= N; n++){
            if(!summited[n]){
                cout << n << ' ';
            }
        }
        cout << '\n';
    }
    
    return 0;
}