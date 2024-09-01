// 교환

#include<iostream>
#include<vector>
using namespace std;

int insertion_sort(vector<int> arr, int K) {
	int count = 0;
	for (int i = 1; i < arr.size(); i++) {
		int loc = i - 1;
		int newItem = arr[i];

		while (0 <= loc && newItem < arr[loc]) {
			arr[loc + 1] = arr[loc];
			loc--;

			count++;
			if (count == K) {
				return arr[loc + 1];
			}
		}

		if (loc + 1 != i) {
			arr[loc + 1] = newItem;

			count++;
			if (count == K) {
				return newItem;
			}
		}
	}
	return -1;
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

	cout << insertion_sort(arr, K) << "\n";
}