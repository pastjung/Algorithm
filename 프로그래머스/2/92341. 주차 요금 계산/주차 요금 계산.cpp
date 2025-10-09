#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <stack>
using namespace std;

/* 문제 분석
- 문제 설명
    - 주차장 요금표, 입차, 출차 기록
    - 차량별 주차 요금 계산
        - 누적 주차 시간이 기본 시간 이하: 기본 요금 청구
        - 초과: 기본 요금 + 초과한 시간(분)에 대해서 단위 시간(분) 마다 단위 요금 청구
            - 초과한 시간이 나눠 떨어지지 않으면 올림 처리
    - 결론: 차량 번호가 작은 자동차부터 청구할 주차 요금을 차례대로 반환
- 입력 데이터
    - 요금표 fees
    - 입/출차 기록 records
- 핵심 키워드
    - 입차 후 출차 기록이 없을 경우 23:59에 출차된 것으로 간주
    - 모든 출차 기록을 바탕으로 계산 -> map<차량번호, stack<시각>> -> 홀수번: 입차, 짝수번: 출차
    - records의 원소들은 시각을 기준으로 오름차순으로 정렬되어 주어짐 -> stack에 저장해서 홀수면 23:59를 저장하고 -> pop 하면서 시간 총합 계산
*/

vector<string> split(string str, char c){
    vector<string> answer;
    stringstream ss(str);
    string token;
    
    while(getline(ss, token, c)){
        answer.push_back(token);
    }
    return answer;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, stack<string>> vehicles;
    
    // records 정리 -> 차량 번호에 따라서 stack에 저장
    for(string record : records){
        vector<string> info = split(record, ' ');
        vehicles[info[1]].push(info[0]);
    }
    
    // 모든 차량에 대해서 각 시간 총합(분) 계산
    for(auto& [vehicle, s] : vehicles){
        // 만약 stack의 개수가 홀수인 경우 23:59 삽입
        if(s.size() % 2 != 0){
            s.push("23:59");
        }
        
        // stack이 비어있을 때 까지 2개의 데이터를 pop하여 시간 추가
        int time = 0;
        while(!s.empty()){
            vector<string> end = split(s.top(), ':');
            s.pop();
            vector<string> start = split(s.top(), ':');
            s.pop();
            
            time += 60 * (stoi(end[0]) - stoi(start[0])) + stoi(end[1]) - stoi(start[1]);
        }
        
        // 차량의 주차 요금 계산 후 저장
        int cost = fees[1];
        int extra_fee = 0;
        if(time > fees[0]){
            extra_fee = (time - fees[0]) / fees[2];
            if((time - fees[0]) % fees[2] != 0){
                extra_fee++;
            }
            extra_fee *= fees[3];
        }
        answer.push_back(cost + extra_fee);
    }
    
    return answer;
}