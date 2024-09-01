#include<iostream>
#include<vector>
using namespace std;

int selection_sort(vector<int> arr, vector<int> brr) {
	if (arr == brr) {
		return true;
	}

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

			if (arr == brr) {
				return 1;
			}
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr1, arr2;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		arr1.push_back(A);
	}

	for (int i = 0; i < N; i++) {
		int B;
		cin >> B;
		arr2.push_back(B);
	}

	cout << selection_sort(arr1, arr2) << '\n';
}