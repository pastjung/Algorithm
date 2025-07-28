#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    // want의 데이터를 저장할 해시 테이블 생성
    unordered_map<string, int> wants;
    
    // 특정 날에 회원가입 했을 때 구매할 수 있는 물품들을 저장할 해시 테이블 생성
    unordered_map<string, int> goods;
    
    // 초기 세팅 - 해시 테이블에 want 데이터 저장
    for(int i = 0; i < want.size(); i++){
        wants[want[i]] = number[i];
    }
    
    // 초기 세팅 - 해시 테이블에 첫 날에 회원가입시 10일동안 구매 가능한 물품 저장
    for(int i = 0; i < 10; i++){
        goods[discount[i]]++;
    }
    
    // 두 해시 테이블이 동일할 경우 -> answer++
    if(wants == goods){
        answer++;
    }
    
    // 전체 기간 동안 두 해시 테이블 비교
    for(int i = 0; i < discount.size() - 10; i++){
        // 10칸 박스를 한 칸 옆으로 이동
        if(goods[discount[i]] == 1){
            goods.erase(discount[i]);
        } else{
            goods[discount[i]]--;
        }
        goods[discount[i + 10]]++;
        
        // 두 해시 테이블이 동일할 경우 -> answer++
        if(wants == goods){
            answer++;
        }
    }
    
    return answer;
}