#include <string>
#include <vector>
using namespace std;

/* 문제 분석
- 문제 설명
    - arr를 쿼드 트리(4개의 균일한 정사각형으로 분리 -> 압축)와 같은 방식으로 압축
- 입력 데이터
    - arr : 0과 1로 이루어진 2^n x 2^n 크기의 2차원 정수 배열 -> n은 최대 10, 행의 개수는 최대 1024
- 핵심 키워드
    - 쿼드 트리 방식으로 분리 -> 백트래킹
*/

bool checkSum(const vector<vector<int>>& arr, int x, int y, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[y][x] != arr[y + j][x + i]){
                return false;
            }
        }
    }
    return true;
}

// 백트래킹
void backtracking(const vector<vector<int>>& arr, vector<int>& answer, int x, int y, int n){
    // 기저 조건 : 정사각형의 길이가 1인 경우
    if(n == 1){
        return;
    }
    
    // 현재 위치의 모든 정사각형의 값이 일치하는지 확인 -> 일치하는 경우 현재 위치의 모든 0또는 1을 하나로 병합
    if(checkSum(arr, x, y, n)){
        answer[arr[y][x]] -= n * n - 1;
        return;
    }
    
    // 4개의 정사각형으로 쪼갠 후 다음 선택지 탐색
    backtracking(arr, answer, x, y, n / 2);
    backtracking(arr, answer, x + (n / 2), y, n / 2);
    backtracking(arr, answer, x, y + (n / 2), n / 2);
    backtracking(arr, answer, x + (n / 2), y + (n / 2), n / 2);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer = {0, 0};
    
    // arr의 0과 1의 개수 파악
    for(vector<int> i : arr){
        for(int j : i){
            answer[j]++;
        }
    }
    backtracking(arr, answer, 0, 0, arr.size());  // 백트래킹 수행
    return answer;
}