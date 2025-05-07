#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

/*
풀이 방법 ( Bottom-Up 방식 )
- 구간 [i, j]의 최댓값(dp_max)과 최솟값(dp_min)을 각각 계산
- 점화식은 구간을 나누는 지점 k를 기준으로 나누어 생각
    - 연산자가 "+"인 경우 : 전체 식의 최댓값을 구하기 위해 -> 부분 식의 최댓값 + 최댓값
    - 연산자가 "-"인 경우 : 전체 식의 최댓값을 구하기 위해 -> 부분 식의 최댓값 - 최솟값
*/
int solution(vector<string> arr) {
    int n = arr.size();
    int N = (n + 1) / 2;
    
    // dp[i][j] : 구간 [i, j]의 최댓값 또는 최솟값
    vector<vector<int>> dp_max(N, vector<int>(N, INT_MIN));
    vector<vector<int>> dp_min(N, vector<int>(N, INT_MAX));
    
    // 초기화 : 길이가 1인 DP
    for(int i = 0; i < N; i++){
        dp_max[i][i] = stoi(arr[i * 2]);
        dp_min[i][i] = stoi(arr[i * 2]);
    }
    
    // 길이 2 이상인 구간에 대한 DP
    for(int len = 2; len <= N; len++){
        for(int i = 0; i <= N - len; i++){
            int j = i + len - 1;                // i : 구간의 시작, j : 구간의 끝, k : 구간 내 연산자 위치
            for(int k = i; k < j; k++){
                string op = arr[k * 2 + 1];     // op : 연산자
                if(op == "+"){
                    dp_max[i][j] = max(dp_max[i][j], dp_max[i][k] + dp_max[k+1][j]);
                    dp_min[i][j] = min(dp_min[i][j], dp_min[i][k] + dp_min[k+1][j]);
                } else if(op == "-"){
                    dp_max[i][j] = max(dp_max[i][j], dp_max[i][k] - dp_min[k+1][j]);
                    dp_min[i][j] = min(dp_min[i][j], dp_min[i][k] - dp_max[k+1][j]);
                }
            }
        }
    }
    
    return dp_max[0][N - 1];
}