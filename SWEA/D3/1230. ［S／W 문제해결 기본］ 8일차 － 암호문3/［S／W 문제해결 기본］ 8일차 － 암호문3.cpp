#include <iostream>
#include <list>
using namespace std;

const int T = 10;
const int PRINT_COUNT = 10;

void print(list<int>& lt){
    list<int>::iterator it = lt.begin();
    
    for(int i = 0; i < PRINT_COUNT; i++, it++){
        cout << *it << ' ';
    }
    cout << '\n';
}

void solution(list<int>& lt){
    int command_count;
    cin >> command_count;
    for(int c = 0; c < command_count; c++){
        char command;
        cin >> command;

        int x, y;
        if(command == 'I'){           
            cin >> x >> y;

            list<int>::iterator it = lt.begin();
            advance(it, x);
            
            for(int i = 0; i < y; i++){
                int s;
                cin >> s;
                lt.insert(it, s);
                x++;
            }
        } else if(command == 'D'){
            cin >> x >> y;
            
            list<int>::iterator it = lt.begin();
            advance(it, x);

            for(int i = 0; i < y; i++){
                it = lt.erase(it);
            }
            
        } else if(command == 'A'){
            cin >> y;

            for(int i = 0; i < y; i++){
                int s;
                cin >> s;
                lt.push_back(s);
            }
        }
    }

    print(lt);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int t = 1; t <= T; t++){
        int N;
        cin >> N;
        
        list<int> lt;
        for(int i = 0; i < N; i++){
            int temp;
            cin >> temp;
            lt.push_back(temp);
        }

        cout << '#' << t << ' ';
        solution(lt);
    }

    return 0;
}