#include<iostream>
#include<string>
using namespace std;

string table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int charTo6Bit(char c) {
    size_t idx = table.find(c);
    if (idx != string::npos) {
        return static_cast<int>(idx);  // 찾은 인덱스를 6비트 값으로 반환
    }
}

string func(string str) {
    string result = "";

    // 4개씩 묶어서 6비트로 변환 후 8비트씩 나누기
    for (int i = 0; i < str.size(); i += 4) {
        // 각 6비트 문자들을 결합할 32비트 변수
        uint32_t combined = 0;
        
        // 6비트씩 결합
        combined |= (charTo6Bit(str[i]) & 0x3F) << 18;  // 첫 번째 문자
        combined |= (charTo6Bit(str[i + 1]) & 0x3F) << 12;  // 두 번째 문자
        combined |= (charTo6Bit(str[i + 2]) & 0x3F) << 6;   // 세 번째 문자
        combined |= (charTo6Bit(str[i + 3]) & 0x3F);         // 네 번째 문자

        // 결합된 32비트 값을 8비트씩 잘라서 result에 추가
        result += (combined >> 16) & 0xFF;
        result += (combined >> 8) & 0xFF;
        result += combined & 0xFF;
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
        string str;
        cin >> str;
        cout << '#' << i << ' ' << func(str) << '\n';
    }
    return 0;
}