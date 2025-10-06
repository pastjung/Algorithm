#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/* 문제 분석
- 문제 설명
    - 불량 사용자: 비정상적인 방법으로 당첨을 시도한 응모자 -> 당첨 처리 제외
    - 개인정보 보호를 위해 사용자 아이디 중 일부 문자를 '*'' 문자로 가려서 전달 -> 1개 이상 사용
    - 제재 아이디: 불량 사용자 + '*' 문자
    - 결론: 당첨에서 제외되어야 할 제재 아이디 목록의 경우의 수 찾기
- 입력 데이터
    - 이벤트 응모자 아이디 목록 user_id
        - 배열의 크기: 1~8
        - 원소의 길이: 8이하
        - 중복 X
        - 소문자 + 숫자
    - 불량 사용자 아이디 목록 banned_id
        - 배열의 크기: 1~user_id크기
        - 원소의 길이: 8이하
- 핵심 키워드
    - 불량 사용자 아이디 하나는 응모자 아이디 중 하나에 해당하고 같은 응모자 아이디가 중복해서 제재 아이디 목록에 들어가는 경우는 없음
    - 제재 아이디 목록들을 구했을 때 아이디들이 나열된 순서와 관계없이 아이디 목록의 내용이 동일하다면 같은 것으로 처리하여 하나로 계산
    - user_id, banned_id 개수가 적음 -> 각 banned_id를 user_id에 비교해서 맞는지 알아봐도 시간 여유 있음 
        -> 같은 길이인 것들끼리만 모아서 모든 경우의 수 따져도 괜찮을듯?
*/

// banned_id와 일치하는 조합
unordered_set<string> combi;

// user_id와 banned_id 비교 함수
bool compare(string user, string banned){
    if(user.size() != banned.size()){
        return false;
    }
    
    for(int i = 0; i < user.size(); i++){
        if(banned[i] == '*'){
            continue;
        }
        if(user[i] != banned[i]){
            return false;
        }
    }
    return true;
}

// backtracking으로 모든 조합 생성
void combination(const vector<string>& user_id, const vector<string>& banned_id, vector<bool>& used, string selected){
    int depth = selected.size();
    
    if(depth == banned_id.size()){
        sort(selected.begin(), selected.end());
        combi.insert(selected);
        return;
    }
    
    for(int i = 0; i < user_id.size(); i++){
        if(used[i]){
            continue;
        }
        
        if(compare(user_id[i], banned_id[depth])){
            used[i] = true;
            combination(user_id, banned_id, used, selected + to_string(i));
            used[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<bool> used(user_id.size(), false);
    combination(user_id, banned_id, used, "");
    return combi.size();
}