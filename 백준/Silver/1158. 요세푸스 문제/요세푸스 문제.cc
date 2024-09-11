#include<iostream>
#include<queue>
using namespace std;

queue<int> q;
int N, K;

void Josephus(int N, int K) {
	while (N--) {
		for (int i = 0; i < K - 1; i++) {
			int temp = q.front();
			q.pop();
			q.push(temp);
		}

		int temp = q.front();
		q.pop();
		cout << temp;
		if (N != 0) cout << ", ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) q.push(i);

	cout << "<";
	Josephus(N, K);
	cout << ">";
}