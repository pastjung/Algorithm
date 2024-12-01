#include<iostream>
#include<vector>
#include<string>
using namespace std;

void func(vector<string> field, int H, int W, int N, string input){
    int sh, sw;
    // 초기 위치 탐색
    for(int h = 0; h < H; h++){
     	for(int w = 0; w < W; w++){
         	if (field[h][w] == '^' || field[h][w] == '<' || field[h][w] == '>' || field[h][w] == 'v' ){
             	sh = h;
                sw = w;
                break;
            }
        }
    }
    
    // 명령어 수행
 	for(char c : input){
     	if(c == 'U'){
            if(sh > 0 && field[sh - 1][sw] == '.') field[sh--][sw] = '.';   
            field[sh][sw] = '^';
        } else if(c == 'D'){
            if(sh < H - 1 && field[sh + 1][sw] == '.') field[sh++][sw] = '.';   
            field[sh][sw] = 'v';
        } else if(c == 'L'){
            if(sw > 0 && field[sh][sw - 1] == '.') field[sh][sw--] = '.';   
            field[sh][sw] = '<';
        } else if(c == 'R'){
            if(sw < W - 1 && field[sh][sw + 1] == '.') field[sh][sw++] = '.';
            field[sh][sw] = '>';
        } else if(c == 'S'){
            if(field[sh][sw] == '^'){
                for(int i = sh - 1; i >= 0; i--){
                 	if(field[i][sw] == '*'){
                        field[i][sw] = '.';
                        break;
                    } else if(field[i][sw] == '#') break;
                }
            } else if(field[sh][sw] == 'v'){
                for(int i = sh + 1; i < H; i++){
                 	if(field[i][sw] == '*'){
                        field[i][sw] = '.';
                        break;
                    } else if(field[i][sw] == '#') break;
                }
            } else if(field[sh][sw] == '<'){
                for(int i = sw - 1; i >= 0; i--){
                 	if(field[sh][i] == '*'){
                        field[sh][i] = '.';
                        break;
                    } else if(field[sh][i] == '#') break;
                }
            } else if(field[sh][sw] == '>'){
                for(int i = sw + 1; i < W; i++){
                 	if(field[sh][i] == '*'){
                        field[sh][i] = '.';
                        break;
                    } else if(field[sh][i] == '#') break;
                }
            }
        } 
    }
    
    // 명령어 수행 후 상태 출력
    for(string HH : field) cout << HH << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int H, W;
        cin >> H >> W;
        
        vector<string> field(H, "");
        for(int h = 0; h < H; h++){
            cin >> field[h];
        }
        
        int N;
        string input;
        cin >> N >> input;
        
        cout << '#' << i << ' ';
        func(field, H, W, N, input);
    }
    return 0;
}