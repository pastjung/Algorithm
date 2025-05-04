#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
풀이 전략
-> BFS ( 최단 경로 탐색 )
1. begin부터 target까지 다른 문자 중 하나만 다른 값이 존재하면 queue에 저장 ( 다른 문자가 모두 2개 이상일 경우 0 반환 )
2. 한번 queue를 전부 거치면 answer++를 하고 다시 queue 돌리기
*/

int cmp(string str1, string str2){
    int answer = 0;
    for(int i = 0; i < str1.size(); i++){
        if(str1[i] != str2[i]) answer++;
    }
        
    return answer;
}

int BFS(string begin, string target, vector<string> words){
    int depth = 0;
    vector<bool> visited(words.size() + 1, false);
    queue<string> q;
    
    // 초기 세팅
    q.push(begin);
    
    while(!q.empty()){
        int qSize = q.size();
        for(int i = 0; i < qSize; i++){
            string current = q.front();
            q.pop();
            
            // target 검증
            if(current == target) return depth;
            
            // BFS 순환
            for(int j = 0; j < words.size(); j++){
                // 현재 단어와 나머지 단어의 문자 차이가 1개인 경우
                if(!visited[j] && cmp(current, words[j]) == 1){
                    visited[j] = true;
                    q.push(words[j]);
                }
            }
        }
        depth++;
    }
    
    // target에 도달하지 못한 경우
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    // target 확인
    auto it = find(words.begin(), words.end(), target);
    if(it != words.end()){
        // 최단 거리 탐색
        answer = BFS(begin, target, words);
    }
    
    return answer;
}