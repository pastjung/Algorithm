#include <string>
#include <vector>
#include <sstream>
using namespace std;

/* 문제 분석
- 문제 설명
    - 표 편집 프로그램 작성
    - 표의 크기는 50*50 고정 -> 초기 셀을 비어 있음
    - 각 셀은 문자열 값을 가질 수 있고, 다른 셀과 병합 가능
    - 명령어
        1. update r c value: (r, c) 위치의 셀의 값을 value로 변경
        2. update v1 v2: v1값을 가지고 있는 모든 셀을 v2로 변경
        3. merge r1 c1 r2 c2: (r1, c1) 위치의 셀과 (r2, c2)위치의 셀 병합
            - 선택한 두 위치의 셀이 같은 셀일 경우 무시
            - 인접하지 않은 셀일 수도 있음 ( 중간 셀은 영향 X )
            - 병합 내용
                - 두 셀 중 한 셀만 값이 있는 경우 -> 두 셀 모두 그 값을 가짐
                - 두 셀 모두 값을 가지고 있을 경우 모두 (r1, r2)의 값을 가짐
                - 이후 두 셀 중 어느 위치를 선택해도 병합된 셀로 접근
        4. unmerge r c: (r, c) 위치의 셀과 병합된 모든 셀을 해제
            - 병합된 셀들은 초기 상태로 돌아감
            - 병합을 해제하기 전 셀이 값을 가지고 있었을 경우 (r, c) 위치의 셀이 그 값을 가짐
        5. print r c: (r, c) 위치의 셀의 값 출력
            - 비어 있을 경우 "EMPTY" 출력
- 입력 데이터
    - 명령어 집합 commands : 최대 1000
- 핵심 키워드
    - 병합하는 거기 때문에 -> 포인터 사용하면 편할듯? -> 병합은 쉬운데, unmerge가 어려울 듯?
        - 부모 노드의 위치를 저장하면 될듯? -> 처음에는 본인 위치로 초기화를 하고 -> 그렇게 해도, 자식을 찾기 위해서는 완탐을 해야 한다.
        - vector<vector<stack<int>>> 형태로 자식, 부모 노드를 각각 저장하는 배열 생성
            - 명령어 집합 * 50*50 = 2,500,000 -> 시간 안에 탐색 가능
    - 비어 있을 경우 -> 처음에 "EMPTY"로 초기화
    - 셀 병합: union&find
*/

const int SIZE = 51;
vector<vector<string>> table(SIZE, vector<string>(SIZE, "EMPTY"));
vector<vector<pair<int, int>>> parents(SIZE, vector<pair<int, int>>(SIZE, {0, 0}));     // 부모 노드를 저장할 배열

vector<string> split(string str, char c = ' '){
    vector<string> answer;
    stringstream ss(str);
    string token;
    
    while(getline(ss, token, c)){
        answer.push_back(token);
    }
    return answer;
}

pair<int, int> find(pair<int, int> child){
    int x = child.first;
    int y = child.second;
    
    if(parents[x][y] != child){
        parents[x][y] = find(parents[x][y]);
    }
    return parents[x][y];
}

void unionSet(pair<int, int> x, pair<int, int> y){
    pair<int, int> rootX = find(x);
    pair<int, int> rootY = find(y);
    
    if(rootX == rootY){
        return;
    }
    
    if(table[rootX.first][rootX.second] != "EMPTY"){
        parents[rootY.first][rootY.second] = rootX;
        table[rootY.first][rootY.second] = "EMPTY";
    } else{
        parents[rootX.first][rootX.second] = rootY;
        table[rootX.first][rootX.second] = "EMPTY";
    }
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for(int i = 1; i < SIZE; i++){
        for(int j = 1; j < SIZE; j++){
            parents[i][j] = {i, j};
        }
    }
    
    for(string command : commands){
        // 명령어 분리
        vector<string> tokens = split(command);
        
        // 1번인 경우 -> 값 변경
        if(tokens[0] == "UPDATE"){
            if(tokens.size() == 4){
                int r = stoi(tokens[1]);
                int c = stoi(tokens[2]);
                pair<int, int> root = find({r, c});
                table[root.first][root.second] = tokens[3];
            } else{
                for(int i = 1; i < SIZE; i++){
                    for(int j = 1; j < SIZE; j++){
                        if(parents[i][j].first == i && parents[i][j].second == j && table[i][j] == tokens[1]){
                            table[i][j] = tokens[2];
                        }
                    }
                }
            }
        } else if(tokens[0] == "MERGE"){
            int r1 = stoi(tokens[1]);
            int c1 = stoi(tokens[2]);
            int r2 = stoi(tokens[3]);
            int c2 = stoi(tokens[4]);
            unionSet({r1, c1}, {r2, c2});
        } else if(tokens[0] == "UNMERGE"){
            int r = stoi(tokens[1]);
            int c = stoi(tokens[2]);
            pair<int, int> root = find({r, c});
            string rootStr = table[root.first][root.second];
            
            vector<pair<int, int>> to_unmerge;
            for(int i = 1; i < SIZE; i++){
                for(int j = 1; j < SIZE; j++){
                    if(find({i, j}) == root){
                        to_unmerge.push_back({i, j});
                    }
                }
            }
            for (auto const& cell : to_unmerge) {
                parents[cell.first][cell.second] = cell;
                table[cell.first][cell.second] = "EMPTY";
            }
            table[r][c] = rootStr;
            
        } else if(tokens[0] == "PRINT"){
            int r = stoi(tokens[1]);
            int c = stoi(tokens[2]);
            pair<int, int> root = find({r, c});
            answer.push_back(table[root.first][root.second]);
        }     
    }
    
    return answer;
}