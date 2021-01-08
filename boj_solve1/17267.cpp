#include <iostream>
#include <queue>
using namespace std;
int check[1005][1005];
bool wall[1005][1005];
struct stru {
	int x, y;
	int l, r;
};
struct compare {
	bool operator()(stru u, stru v) {
		return u.l + u.r < v.l + v.r;
	}
};
int dx[2] = { 1,-1 };
int dy[2] = { 0,0 };
int main() {
	int n, m;
	int l, r;
	cin >> n >> m;
	cin >> l >> r;
	int x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == '1') {
				wall[i][j] = true;
			}
			else {
				wall[i][j] = false;
				if (c == '2') {
					x = i;
					y = j;
				}
			}
			check[i][j] = -1;
		}
	}
	priority_queue<stru, vector<stru>, compare> pq;
	pq.push({ x,y,l,r });
	check[x][y] = l + r;
	while (!pq.empty()) {
		stru now = pq.top();
		pq.pop();
		if (now.l + now.r < check[now.x][now.y]) {
			continue;
		}
		stru temp;
		for (int i = 0; i < 2; i++) {
			temp = now;
			temp.x = now.x + dx[i];
			temp.y = now.y + dy[i];
			if (temp.x < 0 || temp.x >= n || wall[temp.x][temp.y] || check[temp.x][temp.y] >= now.l + now.r) {
				continue;
			}
			check[temp.x][temp.y] = temp.l + temp.r;
			pq.push(temp);
		}
		if (now.l > 0) {
			temp = now;
			temp.y = now.y - 1;
			temp.l--;
			if (temp.y >= 0 && !wall[temp.x][temp.y] && check[temp.x][temp.y] < now.l + now.r) {
				check[temp.x][temp.y] = temp.l + temp.r;
				pq.push(temp);
			}
		}
		if (now.r > 0) {
			temp = now;
			temp.y = now.y + 1;
			temp.r--;
			if (temp.y < m && !wall[temp.x][temp.y] && check[temp.x][temp.y] < now.l + now.r) {
				check[temp.x][temp.y] = temp.l + temp.r;
				pq.push(temp);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] != -1) {
				ans++;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}