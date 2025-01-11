#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    sort(dungeons.begin(), dungeons.end());
    do {
		    int current_k = k;    // 현재 체력
		    int explore_num = 0;  // 탐험한 던전의 수

		    for(vector<int> dungeon : dungeons) {
				    if(dungeon[0] <= current_k){
						    explore_num++;
						    current_k -= dungeon[1];
				    }
		    }
		    
		    if(explore_num > answer){
				    answer = explore_num;
		    }
		    
    } while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}