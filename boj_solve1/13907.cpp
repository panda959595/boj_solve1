#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, k;
int s, d;
vector<pair<int, int> > road[1005];// destination, cost
vector<pair<int, int> > vec;
int taxArr[30005];
int dij[1005][1005];
struct stru {
	int city;
	int mv;
	int cost;
};
struct compare {
	bool operator() (stru u, stru v) {
		return u.cost > v.cost;
	}
};
void func() {
	priority_queue<stru, vector<stru>, compare> pq;
	pq.push({ s,0,0 });
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			dij[i][j] = 987654321;
		}
	}
	dij[s][0] = 0;
	while (!pq.empty()) {
		stru now = pq.top();
		pq.pop();
		if (dij[now.city][now.mv] < now.cost) {
			continue;
		}
		for (auto k : road[now.city]) {
			if (dij[k.first][now.mv + 1] > now.cost + k.second) {
				dij[k.first][now.mv + 1] = now.cost + k.second;
				pq.push({ k.first, now.mv + 1,dij[k.first][now.mv + 1] });
			}
		}

	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	cin >> s >> d;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a].push_back({ b,c });
		road[b].push_back({ a,c });
	}
	func();

	/*for (int i = 0; i < n; i++) {
		if (dij[d][i] != 1987654321) {
			vec.push_back({ i, dij[d][i] });
		}
	}*/
	for (int i = 1; i <= k; i++) {
		cin >> taxArr[i];
	}
	int tax = 0;
	for (int i = 0; i <= k; i++) {
		int ans = 987654321;
		tax += taxArr[i];
		for (int j = 0; j < n; j++) {
			ans = min(ans, dij[d][j] + tax * j);
		}
		/*for (auto k : vec) {
			ans = min(ans, k.second + tax * k.first);
		}*/
		cout << ans << "\n";
	}
	return 0;
}