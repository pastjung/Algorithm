#include<iostream>
using namespace std;

void func(int score){
    cout << score / 50000 << ' ';
    score %= 50000;
    cout << score / 10000 << ' ';
    score %= 10000;
    cout << score / 5000 << ' ';
    score %= 5000;
    cout << score / 1000 << ' ';
    score %= 1000;
    cout << score /500 << ' ';
    score %= 500;
    cout << score /100 << ' ';
    score %= 100;
    cout << score /50 << ' ';
    score %= 50;
    cout << score /10 << ' ';
    score %= 10;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
     	int score;
        cin >> score;
        cout << '#' << i << '\n';
        func(score);
        cout << '\n';
    }
    return 0;
}