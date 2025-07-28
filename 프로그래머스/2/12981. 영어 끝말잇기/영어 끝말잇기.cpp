#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    // 해시 테이블 생성
    unordered_set<string> hash_set;
    
    // 시작 문자 선언
    char start_char = words[0][0];
    
    // words의 단어가 중복되었는지 확인
    for(int turn = 0; turn < words.size(); turn++){
        // 탈락자가 있는 경우 -> 시작 문자가 다른 경우 or 해시 테이블에 값이 있는 경우
        if(words[turn][0] != start_char || hash_set.find(words[turn]) != hash_set.end()){
            // turn mod n 연산을 통해 탈락자 확인
            int participant = turn % n + 1;
            
            // 라운드 계산
            int round = turn / n + 1;
            
            // 탈락자와 라운드를 answer에 채운 후 반복문 종료
            answer = {participant, round};
            break;
        }
            
        // 해시 테이블에 단어 추가
        hash_set.insert(words[turn]);
        
        // 시작 문자 변경
        start_char = words[turn][words[turn].size() - 1];
    }
    
    // 탈락자가 없을 경우 [0, 0] 채우기
    if(answer.empty()){
        answer = {0, 0};
    }

    return answer;
}