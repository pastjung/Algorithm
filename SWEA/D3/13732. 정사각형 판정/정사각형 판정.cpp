#include <iostream>
#include <vector>
using namespace std;

bool solution(const vector<vector<char>>& board, const pair<int, int>& start, pair<int, int>& end){
    int N = board.size();
    
    if(end == make_pair(-1, -1)){
        return true;
    }

    if(end.first - start.first != end.second - start.second){
        return false;
    }
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            if(start.first <= y && y <= end.first && start.second <= x && x <= end.second){
                if(board[y][x] != '#'){
                    return false;
                }    
            } else{
                if(board[y][x] == '#'){
                    return false;
                }
            }
        }
    }
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for(int TC = 1; TC <= T; TC++){
        int N;
        cin >> N;
        
        vector<vector<char>> board(N, vector<char>(N, ' '));
        pair<int, int> start = {-1, -1};
        pair<int, int> end = {-1, -1};
        
        for(int y = 0; y < N; y++){
            for(int x = 0; x < N; x++){
                cin >> board[y][x];

                if(board[y][x] == '#'){
                    if(start == make_pair(-1, -1)){
                        start = make_pair(y ,x);
                    } else {
                        end = make_pair(y, x);
                    }
                }
            }
        }
        cout << '#' << TC << ' ' << (solution(board, start, end) ? "yes" : "no") << '\n';
    }
    return 0;
}