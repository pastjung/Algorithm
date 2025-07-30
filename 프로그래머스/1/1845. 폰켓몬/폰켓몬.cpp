#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums){
    // 폰켓몬의 종류를 담을 해시 테이블 생성 및 초기화 -> 중복 제거
    unordered_set<int> hash_set(nums.begin(), nums.end());

    // N/2와 해시 테이블의 크기 비교 후 반환
    return min(nums.size() / 2, hash_set.size());
}