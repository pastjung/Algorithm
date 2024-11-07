#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string func(string num, int count){
    string result = num;
 	string maxNum = num;
    stable_sort(maxNum.begin(), maxNum.end(), greater<char>());
    
    bool doubleCheck = false;
    for(char c : result){
     	int pos = result.find(c);   
        if(pos != string::npos && result.find(c, pos + 1) != string::npos) {
         	doubleCheck = true;
            break;
        }
    }
    
    for(int i = 1; i <= count; i++){
        if(result == maxNum){
            if(doubleCheck == true) break;
            
         	char temp = result[result.size() - 1];
            result[result.size() - 1] = result[result.size() - 2];
            result[result.size() - 2] = temp;
        } else{
            for(int j = count - i; j < maxNum.size(); j++){
             	if(result[j] == maxNum[j]) continue;
                
                int index = result.rfind(maxNum[j]);
                 	char temp = result[j];
                    result[j] = result[index];
                    result[index] = temp;
                    break;
            }
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        string num;
        int count;
        cin >> num >> count;
        cout << '#' << i << ' ' << func(num, count) << '\n';
    }
    return 0;
}