#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
using namespace std;

/* 문제 분석
- 문제 설명
    - 이진트리를 수로 표현하는 방법
        1. 이진수를 저장할 빈 문자열 생성
        2. 이진트리에 더미 노드를 추가하여 포화 이진 트리 생성 -> 루트 노드는 그대로 유지
        3. 만들어진 포화 이진트리의 노드들을 가장 왼쪽 노드부터 가장 오른쪽 노드까지, 왼쪽에 있는 순서대로 설정(노드의 높이는 상관 X)
        4. 더미 노드라면, 문자열 뒤에 0을 추가
            아니라면, 문자열 뒤에 1을 추가
        5. 문자열에 저장된 이진수를 십진수로 변환
    - 숫자들이 주어졌을 때, 그 숫자를 2진수로 변환시켰을 때, 그 2진수가 이진트리를 수료 표현한 방법과 같은 형태라면 1을 반환
- 입력 데이터
    - 변환시킬 숫자들 numbers
- 핵심 키워드
    - 숫자를 2진수로 변환 -> 포화 이진 트리 형태로 변환(노드의 개수는 2^k - 1개) -> 이진트리를 수료 표현한 방식과 동일한지 파악
*/

bool isBinaryTree(string tree, int k){
    int root = tree.size() / 2;
    queue<pair<int, int>> q;
    
    if(tree[root] == '1'){
        q.push({0, tree.size() - 1});
    }
    
    while(!q.empty()){
        auto[start, end] = q.front();
        q.pop();
        int mid = start + (end - start) / 2;
        tree[mid] = '0';
        
        // 현재 리프 노드일 경우 종료
        if(start == end){
            continue;
        }
        
        int left = start + (mid - 1 - start) / 2;
        int right = mid + 1 + (end - mid - 1) / 2;
        
        if(tree[left] == '1'){
            q.push({start, mid - 1});
        }
        if(tree[right] == '1'){
            q.push({mid + 1, end});
        }
    }
    
    // 트리 전체에 '1'이 남아 있다면 false
    for(int i = 0; i < tree.size(); i++){
        if(tree[i] == '1'){
            return false;
        }
    }
    return true;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(long long number : numbers){
        // 10진수를 2진수로 변환
        bitset<64> bits = number;
        string binary = bits.to_string();
        
        binary = binary.substr(binary.find('1'));
        
        // 2진수의 길이를 2^k - 1개로 변환
        int k = 1;
        while((1 << k) - 1 < binary.size()){
            k++;
        }
        int len = (1 << k) - 1;
        binary = string(len - binary.size(), '0') + binary;
        
        // 이진트리를 수로 표현한 방식과 동일한지 파악 -> 동일하면 1, 아니면 0
        if(isBinaryTree(binary, k)){
            answer.push_back(1);
        } else{
            answer.push_back(0);
        }
    }
    
    return answer;
}