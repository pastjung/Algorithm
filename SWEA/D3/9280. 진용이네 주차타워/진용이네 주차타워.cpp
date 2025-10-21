#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* 문제 분석
- 문제 설명
    - 유로 주차장 n개의 주차 공간
    - 빈 공간이 생길 때까지 입구에서 대기 -> 순서대로 대기
    - 빈 공간이 생기면 번호가 가장 적은 주차 공간에 주차
    - 주차요금: 차량 무게 * 주차 공간마다 따로 책정된 단위 무게당 금액
    - 종일 이용권만 판매(이용시간 고려X)
    - m대의 차량들이 들어오고 나가는 순서를 앎
    - 결론: 오늘 하루 벌어들일 총 수입 계산
- 입력 데이터
- 핵심 키워드
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC;

    for(int T = 1; T <= TC; T++){
        int answer = 0;
        int n, m;
        cin >> n >> m;    

        vector<int> cost(n, 0);
        vector<int> weight(m, 0);

        for(int i = 0; i < n; i++){
            cin >> cost[i];
        }
        for(int i = 0; i < m; i++){
            cin >> weight[i];
        }

        queue<int> waited;
        vector<int> parked(n, 0);
        int available_space = n;
        for(int i = 0; i < 2*m; i++){
            int car;
            cin >> car;

            if(car > 0) {
                if(available_space == 0){
                    waited.push(car);
                    continue;
                }
                for(int space = 0; space < n; space++){
                    if(parked[space] == 0){
                        parked[space] = car;
                        available_space--;
                        answer += cost[space] * weight[car - 1];
                        break;
                    }
                }
            } else {  // 출차
                car = -car;
                int space = 0;
                for(; space < n; space++){
                    if(parked[space] == car){
                        parked[space] = 0;
                        available_space++;
                        break;
                    }
                }

                // 대기 차량이 있는 경우 바로 채워줌
                if(!waited.empty()){
                    int next = waited.front();
                    waited.pop();
                    parked[space] = next;
                    answer += cost[space] * weight[next - 1];
                    available_space--;
                }
            } 
        }

        cout << '#' << T << ' ' << answer << '\n';
    }
    
    return 0;
}