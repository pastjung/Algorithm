#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, d, K, c;
    cin >> N >> d >> K >> c;

    vector<int> plate(N);
    for(int n = 0; n < N; n++){
        cin >> plate[n];
    }

    unordered_map<int, int> sushi;
    int answer;
    
    // 초기 세팅
    for(int k = 0; k < K; k++){
        sushi[plate[k]]++;
    }
    answer = sushi.count(c) ? sushi.size() : sushi.size() + 1;

    // 최댓값 계산
    for(int start = 1; start < N; start++){
        int remove_sushi = plate[start - 1];
        sushi[remove_sushi]--;
        if(sushi[remove_sushi] == 0){
            sushi.erase(remove_sushi);
        }

        int add_sushi = plate[(start + K - 1) % N];
        sushi[add_sushi]++;

        int temp = sushi.count(c) ? sushi.size() : sushi.size() + 1;
        answer = max(answer, temp);
    }

    cout << answer << "\n";  
    return 0;
}