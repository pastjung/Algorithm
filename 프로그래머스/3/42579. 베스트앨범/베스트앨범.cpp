#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

/*
장르별 가장 많이 재생된 노래 2개씩
1. 속한 노래 -> 장르 수록
2. 가장 많이 재생된 노래 수록
3. 재생 횟수가 동일하면 고유번호가 낮은 순
*/

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> musicMap;  // 장르별 총 재생 횟수
    map<string, multimap<int, int, greater<int>>> musicMultiMap;  // 장르별 노래 재생 횟수와 고유번호 (내림차순)
    int N = genres.size();

    // 데이터 삽입
    for(int i = 0; i < N; i++) {
        string genre = genres[i];
        int play = plays[i];

        // 장르별 총 재생 횟수 업데이트
        musicMap[genre] += play;

        // 장르별 노래 재생 횟수와 고유번호 저장
        musicMultiMap[genre].insert({play, i});
    }

    // 총 재생 횟수에 따라 장르 정렬
    vector<pair<string, int>> genreList;
    for (const auto& entry : musicMap) {
        genreList.push_back(entry);
    }

    // 장르별로 가장 많이 재생된 노래 2개씩 뽑기
    sort(genreList.begin(), genreList.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;  // 총 재생 횟수 내림차순
    });

    // 각 장르에 대해 상위 2개 노래를 뽑아 결과에 추가
    for (const auto& genreEntry : genreList) {
        string genre = genreEntry.first;
        auto& songs = musicMultiMap[genre];
        auto it = songs.begin();

        // 가장 많이 재생된 노래 1개
        if (it != songs.end()) {
            answer.push_back(it->second);
            ++it;
        }
        // 두 번째로 많이 재생된 노래 1개
        if (it != songs.end()) {
            answer.push_back(it->second);
        }
    }

    return answer;
}

