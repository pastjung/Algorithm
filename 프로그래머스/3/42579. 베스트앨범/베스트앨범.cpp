#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare (pair<int, int> left, pair<int, int> right){
    if(left.first > right.first){
        return true;
    }else if(left.first == right.first){
        if(left.second < right.second){
            return true;
        }
    }
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> sumMap;                      // 장르별 총 재생 횟수 { genres 장르 : 해당 장르의 노래 재생 횟수 총합 }
    unordered_map<string, vector<pair<int, int>>> musicMap; // 장르별 노래 재생 횟수와 고유번호 (내림차순) { 장르 : { 노래 횟수 : 고유번호 } }
    
    // 데이터 삽입
    for (int i = 0; i < genres.size(); i++) {
        // 장르별 총 재생 횟수 업데이트
        sumMap[genres[i]] += plays[i];
        
        // 장르별 노래 재생 횟수와 고유번호 저장
        musicMap[genres[i]].push_back({plays[i], i});
    }
    
    // 재생 수에 따라 장르를 정렬하기 위한 전처리 - vector 생성
    vector<pair<int, string>> sortedGenre; // { 재생횟수 : 장르 }
    for (auto music : sumMap) {
        sortedGenre.push_back({music.second, music.first});
    }
    
    // 장르별 재생 횟수를 기준으로 오름차순 정렬 : 가장 많이 재생된 장르부터 순차적으로 처리하기 위함
    stable_sort(sortedGenre.begin(), sortedGenre.end());
    
    // 장르별 상위 2개 음악 고르기
    while (sortedGenre.size() > 0) {
        pair<int, string> genre = sortedGenre.back(); // 재생횟수가 가장 많은 장르
        sortedGenre.pop_back();
        
        vector<pair<int, int>> findTopTwo = musicMap[genre.second]; // 재생횟수가 가장 많은 장르의 노래들
        
        // 해당 장르의 노래들을 key와 value를 사용해 정렬
        sort(findTopTwo.begin(), findTopTwo.end(), compare);
        
        // 상위 2개 음악 선택
        answer.push_back(findTopTwo[0].second);
        if(findTopTwo.size() > 1){
            answer.push_back(findTopTwo[1].second);
        }
    }

    return answer;
}