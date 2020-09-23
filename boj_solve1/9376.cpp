#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
struct stru {
	int cost;
	int x, y;
	bool operator<(stru& temp) {
		return cost < temp.cost;
	}
	bool operator>(stru& temp) {
		return cost > temp.cost;
	}
	bool operator==(stru& temp) {
		return cost == temp.cost;
	}
};
struct bigyo {
	bool operator()(stru a, stru b) {
		return a.cost > b.cost;
	}
};
int n, m;
int jido[105][105];
vector< pair<int, int> > people;
int check[3][105][105];
priority_queue<stru, vector<stru>, bigyo > pq;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void bfs(int num, pair<int, int> s) {
	pq.push({ 0,s.first,s.second });
	check[num][s.first][s.second] = 0;
	while (!pq.empty()) {
		stru now = pq.top();
		pq.pop();
		if (now.cost > check[num][now.x][now.y]) {
			continue;
		}
		for (int i = 0; i < 4; i++) {
			stru temp;
			temp.x = now.x + dx[i];
			temp.y = now.y + dy[i];
			if (temp.x<0 || temp.x>n + 1 || temp.y<0 || temp.y>m + 1 || jido[temp.x][temp.y] == 2) {
				continue;
			}
			if (jido[temp.x][temp.y] == 0) {
				temp.cost = now.cost;
			}
			else {
				temp.cost = now.cost + 1;
			}
			if (check[num][temp.x][temp.y] <= temp.cost) {
				continue;
			}
			pq.push(temp);
			check[num][temp.x][temp.y] = temp.cost;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 105; j++) {
				for (int k = 0; k < 105; k++) {
					check[i][j][k] = n * m + 5;
					jido[j][k] = 0;
				}
			}
		}
		people.clear();
		for (int i = 1; i <= n; i++) {
			string str;
			cin >> str;
			for (int j = 1; j <= m; j++) {
				if (str[j - 1] == '#') {
					jido[i][j] = 1;
				}
				else if (str[j - 1] == '*') {
					jido[i][j] = 2;
				}
				else {
					jido[i][j] = 0;
				}
				if (str[j - 1] == '$') {
					people.push_back({ i,j });
				}
			}
		}
		
		bfs(0, { 0,0 });
		bfs(1, people[0]);
		bfs(2, people[1]);
		int ans = n * m + 5;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int temp = 0;
				for (int k = 0; k < 3; k++) {
					temp += check[k][i][j];
				}
				if (jido[i][j] == 1) {
					temp -= 2;
				}
				ans = min(ans, temp);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}