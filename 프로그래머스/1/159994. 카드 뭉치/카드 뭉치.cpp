#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    
    // cards1과 cards2의 현재 위치를 나타내는 index 선언
    int idx1 = 0, idx2 = 0;
    
    // goal의 각 값을 순서대로 확인
    for(string str : goal){
	    // cards1의 현재 위치 < cards1.size() && cards1의 현재 위치의 값이 goal의 현재 위치와 동일한 경우
        if(idx1 < cards1.size() && cards1[idx1] == str){
		    idx1++;     // card1의 현재 위치를 한칸 뒤로 이동
            continue;   // 이후 작업 무시
        }
	    
	    // cards2의 현재 위치 < cards2.size() && cards2의 현재 위치의 값이 goal의 현재 위치와 동일한 경우
        if(idx2 < cards2.size() && cards2[idx2] == str){
		    idx2++;     // card2의 현재 위치를 한칸 뒤로 이동
            continue;   // 이후 작업 무시
        }
	    
	    // goal을 만들 수 없으므로 "NO" 선언
        answer = "No";
        break;
    }
    return answer;
}