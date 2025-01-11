#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// k : 현재 피로도, dungeons : { 최소 필요도, 소모 피로도 }
// answer = 유저가 탐험할 수 있는 최대 던전 수

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    vector<vector<int>> sequence;   // 던전 탐사 순서
    
    vector<int> index(dungeons.size());
    iota(index.begin(), index.end(), 1);
    // 순열을 통한 조합 찾기
    do{
        sequence.push_back(index);
    } while(next_permutation(index.begin(), index.end()));
    
    vector<int> exploreNum(sequence.size(), 0); // 탐사한 던전의 수
    
    // 탐사 가능한 던전 수 계산
    for(int i = 0; i < sequence.size(); i++){
        int K = k;
        for(int idx : sequence[i]){
            if(K < dungeons[idx - 1][0]){
                break;  
            } else {
                K -= dungeons[idx - 1][1];
                exploreNum[i]++;
            }
        }
    }
    
    return *max_element(exploreNum.begin(), exploreNum.end());
}