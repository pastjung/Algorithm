#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
using namespace std;

/* 문제 분석
- 문제 설명
    - 두 사람이 선물을 주고 받은 기록 존재 -> 더 많이 선물을 준 사람에게 선물 1개 받음
    - 주고받은 기록이 X or == -> 선물 지수가 더 큰 사람이 작은 사람에게 1개 받음
    - 선물 지수 : 자신이 친구들에게 준 선물의 수 - 받은 선물의 수
    - 만약 선물 지수도 동일하다면 다음 달에 선물을 주고 받지 않음
    - 결론: 선물을 주고받은 기록을 바탕으로 다음 달에 가장 많은 선물을 받은 선물의 수 예측
- 입력 데이터
    - friends : 친구들의 이름 -> 최대 50
    - gifts : 선물 기록 -> 최대 10,000 => O(N^2) 가능
- 핵심 키워드
    - 동명이인 X
    - 두 사람이 주고 받은 기록, 전체 기록 => 2차원 배열
    - 문자열 분리
    - 이번 달 선물 기록 계산 -> 단순 구현
*/

// split 함수
vector<string> split(string str, char c = ' '){
    vector<string> result;
    stringstream ss(str);
    string token;
    
    while(getline(ss, token, c)){
        result.push_back(token);
    }
    return result;
}

unordered_map<string, int> names;

int solution(vector<string> friends, vector<string> gifts) {
    int N = friends.size();
    
    vector<vector<int>> present(N, vector<int>(N, 0));  // 선물을 주고 받은 정보를 저장할 2차원 배열
    vector<int> score(N, 0);    // 선물 점수
    
    // 이름과 인덱스 정보 저장
    for(int i = 0; i < N; i++){
        names[friends[i]] = i;
    }
    
    // 이번 달 선물 준/받은 횟수 계산
    for(string sGift : gifts){
        vector<string> gift = split(sGift);
        int from = names[gift[0]];
        int to = names[gift[1]];
        
        // 선물 정보
        present[from][to]++;
        
        // 이번 달 선물 지수 계산
        score[from]++;
        score[to]--;
    }
    
    // 다음 달 결과 예측
    vector<int> nextScore(N, 0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            
            if(present[i][j] > present[j][i]){
                nextScore[i]++;
            } else if(present[i][j] == present[j][i]){
                if(score[i] > score[j]){
                    nextScore[i]++;
                }
            }
        }
    }
    
    return *max_element(nextScore.begin(), nextScore.end());
}