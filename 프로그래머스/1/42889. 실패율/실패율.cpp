#include <algorithm>
#include <vector>

using namespace std;

// 정렬 기준 함수 ( 실패율을 기준으로 내림차순, 실패율이 동일할 경우 stage를 기준으로 오름차순 )
bool cmp(pair<int, double> a, pair<int, double> b){
    if(a.second == b.second){
        return a.first < b.first;
    } 
    return a. second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    // 전체 유저 수 변수 선언
    int totalUsers = 0;
    
    // 각 스테이지에 머무르고 있는 유저 수를 정의한 배열 선언
    vector<int> users(N + 1, 0);
    
    // 각 스테이지에 머무르고 있는 유저 수 계산
    for(int stage : stages){
        users[stage]++;
        totalUsers++;
    }
	  
    // 각 스테이지의 실패율을 정의한 배열 선언 {stage, 실패율}
    vector<pair<int, double>> failRates;
    
    // 반복문 ( 스테이지가 낮은 순서부터 계산 )
    for(int i = 1; i <= N; ++i) {
        // 현재 스테이지에 머무르고 있는 사람 계산
        int stayedUsers = users[i];

        // 현재 스테이지에 머무르고 있는 사람이 0인 경우 0으로 입력
        if(stayedUsers == 0){
            failRates.push_back({i, 0});
            continue;
        }

        // 이미 해당 스테이지를 해결한 사람 계산 ( 남은 유저의 수 -= 현재 스테이지에 머무른 유저 수 )
        totalUsers -= stayedUsers;
        int clearedUsers = totalUsers;

        // 실패율 계산
        double failRate = 1.0 * stayedUsers / clearedUsers;
        failRates.push_back({i, failRate});
    }

    // 실패율을 기준으로 내림차순 정렬
    sort(failRates.begin(), failRates.end(), cmp);
    
    // answer에 stage 정보 입력
    for(const auto pair : failRates){
        answer.push_back(pair.first);
    }
    
    return answer;
}