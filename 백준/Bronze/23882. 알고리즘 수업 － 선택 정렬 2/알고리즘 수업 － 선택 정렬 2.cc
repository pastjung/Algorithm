#include<iostream>
#include<vector>
using namespace std;

void selection_sort(vector<int> arr, int K) {
	int count = 0;
	for (int i = arr.size() - 1; i > 0; i--) {
		// 최대값 탐색
		int last = i;
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[last]) {
				last = j;
			}
		}

		// 최대값 우측에 배치
		if (last != i) {
			int temp = arr[i];
			arr[i] = arr[last];
			arr[last] = temp;
			count++;
		}

		if (count == K) {
			for (int j = 0; j < arr.size(); j++) {
				cout << arr[j] << ' ';
			}
			cout << "\n";
			break;
		}
	}

	if (count < K) {
		cout << -1 << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> arr;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		arr.push_back(A);
	}

	selection_sort(arr, K);
}