#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 문제 분석
- 문제 설명
    - 각 N명씩 두 팀으로 나눠 숫자 게임
    - 팀당 한 명씩 나와서 숫자가 큰 쪽이 승리 -> 승리시 승점 1점
    - 먄약 숫자가 동일하면 승점 X
    - A팀원들의 순서는 고정
- 입력 데이터
    - A팀원의 순서
    - B팀원의 점수
- 핵심 키워드
    - A팀의 순서는 고정 & B팀의 최대 승점 계산 -> 오름차순 정렬하여 계산해도 상관 없음
    - 아이디어: A, B 모두 정렬 후 -> B가 큰 숫자부터 생각 -> B가 큰 숫자들이 이길 수 있는 경우를  계산
        -> A보다 제일 조금 큰 B를 선택해야 하기 때문에 오름차순으로 정령해야 함
        -> 내림차순으로 정렬하게 되면 A를 이길 수 있는 선택지 중에서 B가 낭비되기 때문
*/

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int a = 0;
    for(int b = 0; a < A.size() && b < B.size(); b++){
        if(A[a] < B[b]){
            answer++;
            a++;
        }
    }
    
    return answer;
}