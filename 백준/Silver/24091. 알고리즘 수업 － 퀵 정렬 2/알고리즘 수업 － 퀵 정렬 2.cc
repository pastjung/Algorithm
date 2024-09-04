// 교환

#include<iostream>
#include<vector>
using namespace std;

int count = 0;

int partition(vector<int>& arr, int K, int p, int r) {
	int x = arr[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (arr[j] <= x) {
			int temp = arr[++i];
			arr[i] = arr[j];
			arr[j] = temp;
			
			::count++;
			if (::count == K) {
				for (int h = 0; h < arr.size(); h++) {
					cout << arr[h] << ' ';
				}
				cout << "\n";
				return -1;
			}
		}
	}

	if (i + 1 != r) {
		int temp = arr[i + 1];
		arr[i + 1] = arr[r];
		arr[r] = temp;

		::count++;
		if (::count == K) {
			for (int h = 0; h < arr.size(); h++) {
				cout << arr[h] << ' ';
			}
			cout << "\n";
			return -1;
		}
	}

	return i + 1;
}

void quick_sort(vector<int>& arr, int K, int p, int r) {
	if (p < r) {
		int q = partition(arr, K, p, r);
		if (q == -1) return;

		quick_sort(arr, K, p, q - 1);
		quick_sort(arr, K, q + 1, r);
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

	quick_sort(arr, K, 0, N - 1);
	if (::count < K) {
		cout << -1 << "\n";
	}
}