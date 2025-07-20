#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    // 최종 행렬 곱의 결과를 저장할 벡터 선언
    vector<vector<int>> answer;
    
    // arr1과 arr2의 행렬 곱을 수행했을 때 최종 행렬의 크기만큼 공간을 할당
    answer.assign(arr1.size(), vector<int>(arr2[0].size(), 0));
    
    // arr1의 각 행과 arr2의 각 열에 대해 반복문 수행
    for(int i = 0; i < arr1.size(); ++i){
        for(int j = 0; j < arr2[0].size(); ++j){
            for(int k = 0; k < arr2.size(); ++k){
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    
    // 결과 반환    
    return answer;
}