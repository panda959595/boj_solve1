#include <iostream>
#include <set>
#include <vector>
using namespace std;
int arr[35][2005];
int k, n;
void func(int a, int b) {
	set<int> s;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			s.insert(arr[a][i] + arr[b][j]);
			cnt++;
			if (s.size() != cnt) {
				cout << a << " " << b << endl;
				cout << arr[a][i] << " " << arr[b][j] << endl;
				return;
			}
		}
	}
}

bool check[5'000'000];
vector<int> prime;
int main() {

	for (int i = 2; i < 5'000'000; i++) {
		if (!check[i]) {

		}
	}

	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 1 + (2001 + i) * (j + 1);
		}
	}
	for (int i = 0; i < 4; i += 3) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			func(i, j);
		}
	}
	return 0;
}