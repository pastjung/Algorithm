#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
풀이 방법
- root 부터 자식 노드 순서로 순차적으로 탐색
- 각 노드 방문시 -> 경로의 합을 저장 ( 즉, 부모 노드의 위치에는 지금까지의 합이 있으므로 부모 노드와 현재 노드를 합쳐서 저장 )
- 중복 경로가 있을 시 더 큰 값을 저장
- 리프 노드의 최대 값이 정답
*/
int solution(vector<vector<int>> triangle) {
    int answer = 0, tSize = triangle.size();
    
    // 각 위치에서 가질 수 있는 최대값 계산
    for(int i = 1; i < tSize; i++){
        for(int j = 0; j < i + 1; j++){
            // 부모 노드의 값
            int left = (j == 0 ? 0 : triangle[i - 1][j - 1]);
            int right = (j == i ? 0 : triangle[i - 1][j]);
            
            // 부모 노드 중 더 큰 값을 더하기 ( ex. 1의 위치에서 3과 8중 8이 더 크니까 8을 더하기 [7을 미리 더하긴 해야 함] )
            triangle[i][j] += max(left, right);
        }
    }
    
    // 리프 노드의 최대값 비교
    answer = *max_element(triangle[tSize - 1].begin(), triangle[tSize - 1].end());
    
    
    return answer;
}