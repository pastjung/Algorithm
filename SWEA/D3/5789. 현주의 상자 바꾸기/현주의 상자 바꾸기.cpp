#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N, Q;
        cin >> N >> Q;

        vector<int> arr(N, 0);
        for(int q = 1; q <= Q; q++){
            int L, R;
            cin >> L >> R;

            for(int i = L - 1; i < R; i++){
                arr[i] = q;
            }
        }
        cout << '#' << t << ' ';
        for(int i : arr){
            cout << i << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}