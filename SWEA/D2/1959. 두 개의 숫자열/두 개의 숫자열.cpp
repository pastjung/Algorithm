#include<iostream>
#include<vector>
using namespace std;

int func(int N, int M){
    // 입력
    vector<int> a(N), b(M);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < M; i++){
        cin >> b[i];
    }
    
    // 스왑
    if (N > M){
        vector<int> temp = a;
        int tmp = N;
        a = b;
        N = M;
        b = temp;
        M = tmp;
    }
    
    // 최대값 계산
    int max = -99999;
    for(int i = 0; i <= M - N; i++){
        int temp = 0;
		for(int j = 0; j < N; j++){
            temp += a[j] * b[i + j];
        }
        if(max < temp) max = temp;
    }
    return max;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int N, M;
        cin >> N >> M;
        cout << '#' << i << ' ' << func(N, M) <<'\n';
    }
    return 0;
}
    