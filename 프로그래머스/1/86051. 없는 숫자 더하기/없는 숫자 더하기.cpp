#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 문제 분석
- 문제 설명
    - numbers에서 0부터 9까지 숫자 중 없는 숫자를 찾아서 더하기
    - numbers의 원소는 서로 다름
- 입력 데인터
    - 0~9 숫자 일부가 들어간 정수 배열 numbers
- 핵심 키워드
    - 중복 X -> set?
    - 정렬 후 0~9 비교 후 없으면 추가
*/

int solution(vector<int> numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());   // numbers 정렬
    
    // 0~9까지 numbers 비교 : i < numbers[top]인 경우 answer에 추가
    int top = 0;
    for(int i = 0; i < 10; i++){
        if(i == numbers[top]){
            top++;
            continue;
        }
        answer += i;
    }
    
    return answer;
}