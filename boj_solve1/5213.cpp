#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
pair<int, int> tile[500][500];
int tile_num[250005];
vector<int> road[250005];
int n;
pair<int, int> pre[250005];
bool fts(pair<int, int> u, pair<int, int> v) {
	if (u.first == v.second) {
		return true;
	}
	else {
		return false;
	}
}
bool stf(pair<int, int> u, pair<int, int> v) {
	if (u.second == v.first) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	cin >> n;
	int index_i, index_j;
	index_i = index_j = 0;
	int num_temp = 1;
	for (int i = 0; i < n * n - n / 2; i++) {
		cin >> tile[index_i][index_j].first >> tile[index_i][index_j].second;
		tile_num[index_i * n + index_j] = num_temp++;
		pre[index_i * n + index_j] = { 250005,0 };
		index_j++;
		if (index_j + index_i % 2 == n) {
			index_i++;
			index_j = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i % 2; j++) {
			if (i != 0) {
				if (i % 2 == 0 && j != 0 && fts(tile[i][j], tile[i - 1][j - 1])) {//À§
					road[i * n + j].push_back((i - 1) * n + j - 1);

					road[(i - 1) * n + j - 1].push_back(i * n + j);
				}
				else if (i % 2 == 1 && fts(tile[i][j], tile[i - 1][j])) {
					road[i * n + j].push_back((i - 1) * n + j);

					road[(i - 1) * n + j].push_back(i * n + j);
				}
			}
			if (j != 0) {
				if (fts(tile[i][j], tile[i][j - 1])) {// ¿ÞÂÊ
					road[i * n + j].push_back(i * n + j - 1);

					road[i * n + j - 1].push_back(i * n + j);
				}
			}
			if (i != n - 1) {
				if (i % 2 == 0 && j != 0 && fts(tile[i][j], tile[i + 1][j - 1])) {// ¿ÞÂÊ ¾Æ·¡
					road[i * n + j].push_back((i + 1) * n + j - 1);

					road[(i + 1) * n + j - 1].push_back(i * n + j);
				}
				else if (i % 2 == 1 && fts(tile[i][j], tile[i + 1][j])) {
					road[i * n + j].push_back((i + 1) * n + j);

					road[(i + 1) * n + j].push_back(i * n + j);
				}
			}
		}
	}
	queue<int> que;
	que.push(0);
	pre[0] = { 0,0 };
	//pair<int, int> temp = { 0,0 };
	int temp = 0;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		/*if (max(tile[now / n][now % n].first, tile[now / n][now % n].second) > temp.first) {
			temp.first = max(tile[now / n][now % n].first, tile[now / n][now % n].second);
			temp.second = now;
		}*/
		temp = max(temp, now);
		if (now == n * n - 2 + n % 2) {
			//temp.second = n * n - 2 + n % 2;
			temp = n * n - 2 + n % 2;
			break;
		}
		for (auto k : road[now]) {
			if (pre[k].first > pre[now].first + 1) {
				pre[k].first = pre[now].first + 1;
				pre[k].second = now;
				que.push(k);
			}
		}
	}
	int ans = 1;
	stack<int> sta;
	/*if (temp.second != n * n - 2 + n % 2) {
		sta.push(n * n - 2 + n % 2);
		ans++;
	}*/
	/*while (temp.second != 0) {
		ans++;
		sta.push(temp.second);
		temp.second = pre[temp.second].second;
	}*/
	while (temp != 0) {
		ans++;
		sta.push(temp);
		temp= pre[temp].second;
	}
	sta.push(0);
	cout << ans << endl;
	while (!sta.empty()) {
		cout << tile_num[sta.top()] << " ";
		sta.pop();
	}
	return 0;
}