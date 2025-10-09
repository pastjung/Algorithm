#include <string>
#include <vector>
using namespace std;

/* 문제 분석
- 문제 설명
    - 이모티콘 플러스 서비스 가입자 수 증가
    - 이모티콘 할인 행사 목표 ( 1번이 우선 )
        1. 이모티콘 플러스 서비스 가입자 최대한 늘리기
        2. 이모티콘 판매액을 최대한 늘리기
    - n명의 사용자들에게 m개의 이모티콘을 할인하여 판매
    - 이모티콘마다 할인율은 다름 ( 10, 20, 30, 40 중 하나 )
    - 사용자 선택: 이모티콘 구매 or 플러스 가입
        - 각 사용자들의 기준에 따라 일정 비율 이상 할인하는 이모티콘을 모두 구매
        - 각 사용자들의 기준에 따라 이모티몬 구매 비용의 합이 일정 가격 이상일 경우, 이모티콘 구매 대신 플러스 서비스 가입
        -> 즉, 특정 할인율 이상의 이모티콘을 구매 비용의 합이 특정 가격 이상일 경우 플러스 가입, 아니면 모두 구매
    - 결론: 행사 목적을 최대한으로 달성했을 때의 이모티콘 플러스 서비스 가입 수와 이모티콘 매출액 반환
- 입력 데이터
    - 사용자 정보: 최대 100개
        - 특정 할인율
        - 특정 가격: 100의 배수, 최대 100만
    - 이모티콘 정보: 최대 7개
        - 가격
- 핵심 키워드
    - 각 이모티콘의 할인율을 10, 20, 30, 40으로 설정해서 백트래킹 수행?
*/

const int discount[4] = {10, 20, 30, 40};

void evaluate(const vector<vector<int>>& users, const vector<int>& emoticons, vector<int>& answer, vector<int>& rates){
    int buy = 0;
    int plus = 0;
    
    for(vector<int> user: users){
        int sum = 0;
        for(int i = 0; i < emoticons.size(); i++){
            if(user[0] <= rates[i]){
                sum += emoticons[i] * (100 - rates[i]) / 100;
            }
        }
        if(user[1] <= sum){
            plus++;
        } else{
            buy += sum;
        }
    }
    
    if(plus > answer[0]){
        answer = {plus, buy};
    } else if(plus == answer[0] && buy > answer[1]){
        answer = {plus, buy};
    } 
}

void backtracking(const vector<vector<int>>& users, const vector<int>& emoticons, vector<int>& answer, int emoticon, vector<int>& rates){
    // 모든 이모티콘을 확인한 경우 -> answer 갱신
    if(emoticon == emoticons.size()){
        evaluate(users, emoticons, answer, rates);
        return;
    }
    
    // 각 이모티콘에 각 할인율 적용
    for(int d : discount){
        rates.push_back(d);
        backtracking(users, emoticons, answer, emoticon + 1, rates);
        rates.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2, 0);
    vector<int> rates;
    backtracking(users, emoticons, answer, 0, rates);
    return answer;
}