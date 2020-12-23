#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int n, m, t, d;
int height[30][30];
int arrive[30][30];
int comback[30][30];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
struct stru {
	int x, y;
	int time;
	bool operator==(stru temp) {
		return time == temp.time;
	}
	/*bool operator>(stru temp) {
		return time > temp.time;
	}*/
	bool operator>(stru temp) {
		return time < temp.time;
	}
};
struct compare {
	bool operator()(stru& u, stru& v) {
		return u.time < v.time;
	}
};
int main() {
	cin >> n >> m >> t >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char temp;
			cin >> temp;
			if (temp >= 'a') {
				height[i][j] = temp - 'a' + 26;
			}
			else {
				height[i][j] = temp - 'A';
			}
			arrive[i][j] = 987654321;
			comback[i][j] = 987654321;
		}
	}

	priority_queue<stru, vector<stru>, compare > pq;

	arrive[0][0] = 0;
	pq.push({ 0,0,0 });
	while (!pq.empty()) {
		stru now = pq.top();
		pq.pop();
		if (now.time > arrive[now.x][now.y]) {
			continue;
		}
		for (int i = 0; i < 4; i++) {
			stru temp = now;
			temp.x += dx[i];
			temp.y += dy[i];
			if (temp.x < 0 || temp.x >= n || temp.y < 0 || temp.y >= m) {
				continue;
			}
			if (abs(height[temp.x][temp.y] - height[now.x][now.y]) > t) {
				continue;
			}
			if (height[temp.x][temp.y] <= height[now.x][now.y]) {
				if (now.time + 1 < arrive[temp.x][temp.y]) {
					arrive[temp.x][temp.y] = now.time + 1;
					temp.time = arrive[temp.x][temp.y];
					pq.push(temp);
				}
			}
			else {
				if (now.time + pow(height[temp.x][temp.y] - height[now.x][now.y], 2) < arrive[temp.x][temp.y]) {
					arrive[temp.x][temp.y] = now.time + pow(height[temp.x][temp.y] - height[now.x][now.y], 2);
					temp.time = arrive[temp.x][temp.y];
					pq.push(temp);
				}
			}
		}
	}
	
	comback[0][0] = 0;
	pq.push({ 0,0,0 });
	while (!pq.empty()) {
		stru now = pq.top();
		pq.pop();
		if (now.time > comback[now.x][now.y]) {
			continue;
		}
		for (int i = 0; i < 4; i++) {
			stru temp = now;
			temp.x += dx[i];
			temp.y += dy[i];
			if (temp.x < 0 || temp.x >= n || temp.y < 0 || temp.y >= m) {
				continue;
			}
			if (abs(height[temp.x][temp.y] - height[now.x][now.y]) > t) {
				continue;
			}
			if (height[temp.x][temp.y] >= height[now.x][now.y]) {
				if (now.time + 1 < comback[temp.x][temp.y]) {
					comback[temp.x][temp.y] = now.time + 1;
					temp.time = comback[temp.x][temp.y];
					pq.push(temp);
				}
			}
			else {
				if (now.time + pow(height[temp.x][temp.y] - height[now.x][now.y], 2) < comback[temp.x][temp.y]) {
					comback[temp.x][temp.y] = now.time + pow(height[temp.x][temp.y] - height[now.x][now.y], 2);
					temp.time = comback[temp.x][temp.y];
					pq.push(temp);
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arrive[i][j] + comback[i][j] <= d) {
				ans = max(ans, height[i][j]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}