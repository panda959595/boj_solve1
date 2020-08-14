#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
vector<int> road[205];
vector<double> len[205][205];
double fire[205];
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		double c;
		cin >> a >> b >> c;
		a--;
		b--;
		if (len[a][b].size() == 0) {
			road[a].push_back(b);
			road[b].push_back(a);
		}
		len[a][b].push_back(c);
		len[b][a].push_back(c);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sort(len[i][j].begin(), len[i][j].end());
		}
	}
	double ans = 2000000000;
	for (int s = 0; s < n; s++) {
		priority_queue < pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;
		for (int i = 0; i < n; i++) {
			fire[i] = 2000000000;
		}
		pq.push({ 0, s });
		fire[s] = 0;
		while (!pq.empty()) {
			pair<double, int> now = pq.top();
			pq.pop();
			if (now.first > fire[now.second]) {
				continue;
			}
			for (auto k : road[now.second]) {
				for (auto cost : len[now.second][k]) {
					if (now.first + cost < fire[k]) {
						fire[k] = now.first + cost;
						pq.push({ fire[k],k });
					}
				}
			}
		}
		double temp = 0;
		for (int i = 0; i < n; i++) {
			temp = max(temp, fire[i]);
			for (int j : road[i]) {
				for (int k : len[i][j]) {
					temp = max(temp, (fire[i] + fire[j] + k) / 2);
				}
			}
		}
		ans = min(ans, temp);
	}
	cout << fixed;
	cout.precision(1);
	cout << ans << "\n";
	return 0;
}