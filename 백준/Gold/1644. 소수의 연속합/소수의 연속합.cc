#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int num){
    if(num <= 1) return false;
    if(num == 2) return true;
    if(num % 2 == 0) return false;

    for(int i = 3; i <= sqrt(num); i++){
        if( num % i == 0) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> primes;
    for(int i = 2; i <= N; i++){
        if(isPrime(i)) {
            primes.push_back(i);
        }
    }

    int answer = 0;
    int left = 0, sum = 0;

    for(int right : primes){
        sum += right;

        while(sum >= N){
            if(sum == N) {
                answer++;
            }
            sum -= primes[left];
            left++;
        }
    }

    cout << answer << '\n';
    
    return 0;
}
