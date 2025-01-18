#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if(a[0] != b[0]) {
        return a[1] < b[1];
    } else {
        return a[0] < b[0];
    }
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end(), cmp);
    int camera = routes[0][1];    // 마지막으로 설치된 카메라의 위치
    
    for(vector<int> route : routes) {
        if(camera < route[0]) {
            camera = route[1];
            answer++;
        }
    }
    
    
    return answer;
}