#include <algorithm>
#include <vector>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = dist.size() + 1;
    
    int len = weak.size();
    
    // weak 배열 확장 : weak 배열이 원형 구조이기 때문에 2n 길이로 늘려서 한 줄로 생각
    for(int i = 0; i < len; i++){
        weak.push_back(weak[i] + n);
    }
    
    // 시작 점 설정 및 친구 순열 생성
    for(int start = 0; start < len; start++){
        do{
            // 친구 배치 및 수 계산
            int cnt = 1;
            int position = weak[start] + dist[cnt - 1];
            
            // 다음 weak 지점 확인
            for(int index = start; index < start + len; index++){
                if(position < weak[index]){
                    cnt++;
                    
                    // 친구 수 초과 확인
                    if(cnt > dist.size()) break;
                    
                    position = weak[index] + dist[cnt - 1];
                }
            }
            
            answer = min(answer, cnt);  // 최소 친구 수 업데이트
        } while(next_permutation(dist.begin(), dist.end())); // 순열 생성
    }
    
    return answer > dist.size() ? -1 : answer;  // 결과 반환
}