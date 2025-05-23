#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N;
        cin >> N;
        vector<int> score(N, 0);
        int total = 0;
        for(int n = 0; n < N; n++){
            cin >> score[n];
            total += score[n];
        }

        vector<bool> dp(total + 1, false);
        dp[0] = true;

        for(int s : score){
            for(int i = total; i >= 0; i--){
                if(dp[i]){
                     dp[i + s] = true;
                }
            }
        }

        int count = 0;
        for (bool x : dp) {
            if (x) count++;
        }

        cout << "#" << t << " " << count << "\n";
    }
    
    
    return 0;
}