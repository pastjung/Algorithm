#include <iostream>
using namespace std;

bool check(int a, int b){
    int low = min(a, b);
    int high = max(a, b);
    
    if(high - low == 1 && low % 2 == 0 && high % 2 == 1){
        return true;
    }
    return false;
}

int solution(int n, int a, int b) {
    a--;
    b--;
    for(int round = 1; round <= 20; round++){
        if(check(a, b)){
            return round;
        }
        a /= 2;
        b /= 2;
    }
}