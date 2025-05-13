#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    int answer = 0;
    vector<int> arr(N, 0);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    int left = 0, right = 0, sum = 0;
    while(right != N + 1){
        if(sum >= M) sum -= arr[left++];
        else if(right == N) break;
        else sum += arr[right++];

        if(sum == M) answer++;
    }

    cout << answer << "\n";
    return 0;
}