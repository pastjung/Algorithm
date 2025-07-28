#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 정렬 기준 함수
bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if (a.first != b.first)
        return a.first > b.first;     // 1차 정렬: key
    return a.second < b.second;       // 2차 정렬: value
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // 장르별 재생 횟수를 저장할 해시 테이블 생성
    unordered_map<string, int> genre_maps;
    
    // 장르 내 노래의 재생 횟수를 저장할 해시 테이블 생성
    unordered_map<string, vector<pair<int, int>>> song_maps;
    
    // 노래 정보를 두 해시 테이블에 저장
    for(int i = 0; i < plays.size(); i++){
        genre_maps[genres[i]] += plays[i];
        song_maps[genres[i]].push_back({plays[i], i});
    }
    
    // 재생 수에 따라 장르를 정렬하기 위한 배열 선언 및 추가
    vector<pair<int, string>> sortedGenre;
    for (auto& pair : genre_maps) {
        sortedGenre.push_back({pair.second, pair.first});  // {재생수, 장르명}
    }
    
    // 장르별 재생 횟후 정렬
    sort(sortedGenre.begin(), sortedGenre.end(), greater<>());
    
    // 장르별 재생 횟수가 많을 수록 먼저 장르 선택
    for(auto pair : sortedGenre){
        string genre = pair.second;
        
        // 장르 내 노래 정렬
        sort(song_maps[genre].begin(), song_maps[genre].end(), cmp);
        
        // 상위 2개 음악 선택
        answer.push_back(song_maps[genre][0].second);
        if(song_maps[genre].size() > 1){
            answer.push_back(song_maps[genre][1].second);
        }
    }
    
    return answer;
}