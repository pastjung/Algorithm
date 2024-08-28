#include<iostream>
#include<vector>
using namespace std;

bool bubble_sort(vector<int> arr1, vector<int> arr2) {
	if (arr1 == arr2) {
		return true;
	}

	for (int i = arr1.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {

			if (arr1[j] > arr1[j + 1]) {
				int temp = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = temp;

				if (arr1[j] == arr2[j] && arr1[j + 1] == arr2[j + 1]) {
					if (arr1 == arr2) {
						return true;
					}
				}
			}
		}
	}

	return false;
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

	cout << bubble_sort(arr1, arr2) << '\n';
}