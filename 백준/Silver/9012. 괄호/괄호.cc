#include<iostream>
#include<stack>
#include<string>
using namespace std;

string VPS(stack<int> s, string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') s.push(i);
		else {
			if (s.empty()) return "NO";
			else s.pop();
		}
	}

	if (s.empty()) return "YES";
	else return "NO";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		stack<int> s;
		string str;
		cin >> str;

		cout << VPS(s, str) << "\n";
	}
}