#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 정렬 기준
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    // 귤의 크기별로 분류
    unordered_map<int, int> hash_count;
    for(int i : tangerine){
        hash_count[i]++;
    }
    vector<pair<int, int>> count(hash_count.begin(), hash_count.end());
    
    // 귤의 종류가 많은 순서로 정렬
    sort(count.begin(), count.end(), cmp);
    
    // 귤의 크기가 최소가 되도록 판매하는 방법 계산
    for(auto [size, num] : count){
        if(k <= 0) break;
        
        answer++;
        k -= num;
    }
    
    return answer;
}