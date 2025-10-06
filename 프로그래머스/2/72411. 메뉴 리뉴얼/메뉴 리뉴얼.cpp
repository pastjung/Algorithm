#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/* 문제 분석
- 문제 설명
    - 새로운 메뉴 구성: 단품 조합 -> 코스 요리 형태로 재구성
    - 각 손님들이 주문할 때 가장 많이 함께 주문한 단품 메뉴들을 코스 요리로 구성
    - 코스 요리는 최소 2가지 이상 단품 메뉴로 구성
    - 최소 2명 이상의 손님으로부터 주문된 단품 메뉴 조합에 대해서만 코스 요리 후보에 포함
- 입력 데이터
    - 손님이 주문단 단품 메뉴들 orders
        - 각 원소는 크기가 2 이상 10 이하인 문자열 ( 중복 X )
    - 추가하고 싶은 코스 요리를 구성하는 단품 메뉴들의 갯수 course
        - 오름차순
        - 2 이상 10 이하
- 핵심 키워드
    - 각 손님이 단품 메뉴를 2개 이상 주문
    - n개의 코스 요리 중 가장 많은 주문 횟수를 가진 경우만 저장 ( 동일 개수면 전부 저장 )
*/

// 주문 조합
map<string, int> combi;

// nCr 조합 함수
void combination(string order, string temp, int len){
    if(temp.size() == len){
        combi[temp]++;
        return;
    }
    
    for(int i = 0; i < order.size(); i++){
        combination(order.substr(i+1), temp + order[i], len);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    // 주문 정렬
    for(string& order : orders){
        sort(order.begin(), order.end());   
    }
    
    // course에 해당하는 길이의 모든 조합 생성
    for(int len : course){
        // 각 길이 별 조합 생성 -> 주문 조합에 저장
        for(string order : orders){
            combination(order, "", len);
        }
    
        // course에 해당하는 길이의 조합들 중 가장 많은 횟수를 가진 조합 추출
        int maxCount = 0;
        for(auto[str, count] : combi){
            maxCount = max(maxCount, count);
        }
        
        for(auto[str, count] : combi){
            if(maxCount >= 2 && maxCount == count){
                answer.push_back(str);
            }
        }
        
        combi.clear();
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}