#include <iostream>
#include <vector>
using namespace std;
int n;
int cnt;
int answer[2];
int m;
bool sum[30];
bool cha[30];
vector<pair<int, int> > vec[2];
void func(int q, int i) {
	answer[q] = max(answer[q], cnt);
	if (i >= vec[q].size()) {
		return;
	}
	func(q, i + 1);
	if (sum[vec[q][i].first + vec[q][i].second] && cha[vec[q][i].first - vec[q][i].second + 10]) {
		sum[vec[q][i].first + vec[q][i].second] = false;
		cha[vec[q][i].first - vec[q][i].second + 10] = false;
		cnt++;
		func(q, i + 1);
		cnt--;
		sum[vec[q][i].first + vec[q][i].second] = true;
		cha[vec[q][i].first - vec[q][i].second + 10] = true;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			if (temp == 1) {
				vec[(i + j) % 2].push_back({ i, j });
			}
		}
	}
	for (int i = 0; i < 30; i++) {
		sum[i] = cha[i] = true;
	}
	cnt = 0;
	func(0, 0);
	func(1, 0);
	cout << answer[0] + answer[1] << "\n";
	return 0;
}