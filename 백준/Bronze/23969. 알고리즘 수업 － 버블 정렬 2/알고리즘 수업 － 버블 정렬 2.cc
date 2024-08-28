#include<iostream>
#include<vector>
using namespace std;

void bubble_sort(vector<int> v, int k) {
	int count = 0;

	for (int i = v.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) {
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;

				count++;
			}
			if (count == k) break;
		}
		if (count == k) break;
	}

	if (count < k) {
		cout << -1 << '\n';
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> v;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		v.push_back(A);
	}

	bubble_sort(v, K);
}