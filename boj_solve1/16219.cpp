#include <iostream>
using namespace std;
int arr[200005];
int check;
void swap_func(int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
	if (i == arr[i]) {
		check--;
	}
	if (j == arr[j]) {
		check--;
	}
	if (i == arr[j]) {
		check++;
	}
	if (j == arr[i]) {
		check++;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i != arr[i]) {
			check++;
		}
	}
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		swap_func(a, b);
		if (n == 1) {
			cout << 0 << " ";
		}
		else if (n == 2) {
			if (check == 2) {
				cout << 1 << " ";
			}
			else {
				cout << 0 << " ";
			}
		}
		else {
			if (check == 0) {
				cout << 0 << " ";
			}
			else {
				cout << -1 << " ";
			}
		}
	}
	return 0;
}