#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    // 몸무게를 오름차순으로 정렬
    sort(people.begin(), people.end());
    
    int light = 0; // 가장 가벼운 사람의 인덱스
    int heavy = people.size() - 1; // 가장 무거운 사람의 인덱스
    
    while (light <= heavy) {
        // 가장 가벼운 사람과 가장 무거운 사람의 몸무게 합이 limit 이하인 경우
        if (people[light] + people[heavy] <= limit) {
            light++; // 가벼운 사람 탑승
        }
        heavy--; // 무거운 사람은 항상 탑승
        answer++; // 구명보트 1대 사용
    }
    
    return answer;
}