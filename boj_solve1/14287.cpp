#include <iostream>
#include <vector>
using namespace std;
int parent[100005];
int ans[100005];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		parent[i] = temp - 1;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b;
		if (a == 1) {
			cin >> c;
			b--;
			while (b >= 0) {
				ans[b] += c;
				b = parent[b];
			}
		}
		else {
			cout << ans[b - 1] << endl;
		}
	}

	return 0;
}