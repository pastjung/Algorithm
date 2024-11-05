#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string temp;

    // 구분자(delimiter)를 기준으로 문자열을 나누기
    while (getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }

    return result;
}

int func(vector<string> rowArr, vector<string> columnArr, int K){
 	int count = 0;    
    string findStr(K, '1');		// K개 연속된 '1'

    // 행(row)에서 찾기
    for(string str : rowArr) {
        vector<string> arr = split(str, '0');
        for(string s : arr){
         	if(s == findStr) count++;
        }
    }
    
    // 열(column)에서 찾기
    for(string str : columnArr) {
        vector<string> arr = split(str, '0');
        for(string s : arr){
         	if(s == findStr) count++;
        }
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){        
        int N, K;
        cin >> N >> K;
        vector<string> rowArr(N);
        vector<string> columnArr(N);
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
            	char block;
            	cin >> block;
                rowArr[j] += block;
                columnArr[k] += block;
            }
        }
        cout << '#' << i << ' ' << func(rowArr, columnArr, K) << '\n';
    }
    return 0;
}
    