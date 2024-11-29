#include<iostream>
#include<string>
using namespace std;

string func(int N, string str) {
    for (int i = 0; i < str.size(); i++) {
        int size = 0;
        if (str[i] == str[i + 1]) {
            size += 2;
            while ( str[i + 1 + (size / 2)] == str[i - (size / 2)] ) {
                size += 2;
                if (N - 1 == i + 1 + (size / 2)) break;
            }
            str.replace(i + 1 - ( size / 2 ), size, "");
            i -= size / 2;
        }
    }
    return str;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 10;
    for (int i = 1; i <= T; i++) {
        int N;
        string str;
        cin >> N >> str;
        cout << '#' << i << ' ' << func(N, str) << '\n';
    }
    return 0;
}