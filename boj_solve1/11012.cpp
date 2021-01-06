#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int value;
	int s, e;
	int leftChild, rightChild;
};
node pst[600000];
int nodeCnt;
int treeCnt;
int root[10005];
int initial(int s, int e) {
	int now = nodeCnt++;
	pst[now].s = s;
	pst[now].e = e;
	pst[now].value = 0;
	if (s != e) {
		int mid = (s + e) / 2;
		pst[now].leftChild = initial(s, mid);
		pst[now].rightChild = initial(mid + 1, e);
	}
	return now;
}
int update(int index, int s, int e, int y) {
	if (y < s || e < y) {
		return index;
	}
	int now = nodeCnt++;
	pst[now] = pst[index];
	int mid = (s + e) / 2;
	if (s == e) {
		pst[now].value++;
	}
	else {
		pst[now].leftChild = update(pst[index].leftChild, s, mid, y);
		pst[now].rightChild = update(pst[index].rightChild, mid + 1, e, y);
		pst[now].value = pst[pst[now].leftChild].value + pst[pst[now].rightChild].value;
	}
	return now;
}
void update(int y, int s, int e) {
	root[treeCnt] = update(root[treeCnt - 1], s, e, y);
	treeCnt++;
}
int calc(int index, int l, int r) {
	if (r < pst[index].s || pst[index].e < l) {
		return 0;
	}
	if (l <= pst[index].s && pst[index].e <= r) {
		return pst[index].value;
	}
	return calc(pst[index].leftChild, l, r) + calc(pst[index].rightChild, l, r);
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		nodeCnt = 0;
		treeCnt = 1;
		initial(1, 100001);
		root[0] = 0;
		int n, m;
		cin >> n >> m;
		vector<pair<int, int> > vec;
		vector<int> arr;
		arr.push_back(-1);
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			b++;
			vec.push_back({ a,b });
			arr.push_back(a);
		}
		sort(vec.begin(), vec.end());
		sort(arr.begin(), arr.end());
		for (auto k : vec) {
			update(k.second, 1, 100001);
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			int sx, ex, sy, ey;
			cin >> sx >> ex >> sy >> ey;
			sy++;
			ey++;
			int temp;
			temp = calc(root[upper_bound(arr.begin(), arr.end(), ex) - arr.begin() - 1], sy, ey);
			temp -= calc(root[lower_bound(arr.begin(), arr.end(), sx) - arr.begin() - 1], sy, ey);
			ans += temp;
		}
		cout << ans << "\n";
	}
	return 0;
}