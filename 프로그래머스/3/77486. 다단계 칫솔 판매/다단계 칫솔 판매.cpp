#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// 해시 테이블 생성
unordered_map<string, int> enroll_map;
unordered_map<string, string> referral_map;

// 판매 실적을 추천인에게 나눠주는 함수
void cal(vector<int>& answer, string seller, int amount){
    int seller_idx = enroll_map[seller];
    
    // 나눠줄 실적(10%) 계산
    int profit = amount / 10;
    
    // 나눠줄 실적이 1원 미만인 경우
    if(profit < 1){
        // 본인이 실적 독점
        answer[seller_idx] += amount;
        return;
    } else{
        // 본인은 나머지 실적(90%) 획득
        answer[seller_idx] += amount - profit;
        
        // 추천인이 없을 경우
        if(referral_map[seller] == "-"){
            return;
        }
        
        // 더 상위 추천인으로 반복
        cal(answer, referral_map[seller], profit);
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount){
    vector<int> answer(enroll.size(), 0);

    // 해시 테이블 초기화
    for(int i = 0; i < enroll.size(); i++){
        referral_map[enroll[i]] = referral[i];
        enroll_map[enroll[i]] = i;
    }

    // seller와 amount의 판매 실적을 트리를 역행하면서 진행
    for(int i = 0; i < seller.size(); i++){
        cal(answer, seller[i], amount[i] * 100);
    }

    return answer;
}