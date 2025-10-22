#include <iostream>
#include <vector>
using namespace std;

string solution(const vector<string>& cards, int N){
    string answer = "";

    int left = 0, right = N / 2;
    if(N % 2 == 1){
        right++;
    }

    for(int n = 1; n <= N; n++){
        answer += " ";
        answer += (n % 2 == 1) ? cards[left++] : cards[right++];
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int TC = 1; TC <= T; TC++){
        int N;
        cin >> N;
        vector<string> cards(N, "");
        for(int n = 0; n < N; n++){
            cin >> cards[n];
        }

        cout << '#' << TC << solution(cards, N) << '\n';
    }
    return 0;
}