#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int TC = 1; TC <= T; TC++){
        int N;
        cin >> N;
        vector<int> possible(10, 1);
        for(int n = 1; n <= N; n++){
            vector<int> questions(4, 0);
            for(int i = 0; i < 4; i++){
                cin >> questions[i];
            }
            
            string cmd;
            cin >> cmd;
            if(cmd == "YES"){
                for(int question : questions){
                    possible[question]++;
                }
            } else if(cmd == "NO"){
                for(int question : questions){
                    possible[question] = 0;
                }
            }
        }

        int answer = distance(possible.begin(), max_element(possible.begin(), possible.end()));
        cout << '#' << TC << ' ' << answer << '\n';
    }
    
    return 0;
}