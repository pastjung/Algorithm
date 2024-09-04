#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

#define SIZE 500001
int arr[SIZE] = { 0, };
map<int, int, greater<int>> arr_map;
int N, K, cnt = 0;

void check(int i, int j) {
	if (cnt == K) {
		if (arr[i] < arr[j]) {
			cout << arr[i] << ' ' << arr[j] << "\n";
		}
		else {
			cout << arr[j] << ' ' << arr[i] << "\n";
		}
		exit(0);
	}
}

void swap(int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;

	arr_map[arr[j]] = j;

	cnt++;
	check(i, j);
}

void selection_sort() {
	for (int i = N; i >= 2; i--) {
		// 최대값 탐색
		map<int, int>::iterator itr = arr_map.begin();
		int max_value = itr->first;
		int max_index = itr->second;
		arr_map.erase(max_value);
		
		// 최대값 우측에 배치
		if (max_index != i) {
			swap(i, max_index);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr_map.insert(make_pair(arr[i], i));	// map은 key값을 기준으로 오름차순으로 정렬되어 삽입 ( key 값 중복 X )
	}

	selection_sort();

	if (cnt < K) {
		cout << -1 << "\n";
	}
}