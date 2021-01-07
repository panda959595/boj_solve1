#include <iostream>
using namespace std;
struct node {
	char value;
	int len;
	int s, e;
	int leftChild, rightChild;
};
node pst[20'000'005];
int nodeCnt = 0;
int treeCnt = 0;
int root[1000001];
int init(int s, int e) {
	int now = nodeCnt++;
	pst[now].s = s;
	pst[now].e = e;
	pst[now].len = 0;
	if (s == e) {
		pst[now].value = '0';
		return now;
	}
	int mid = (s + e) / 2;
	pst[now].leftChild = init(s, mid);
	pst[now].rightChild = init(mid + 1, e);
	return now;
}
int update(int index, int inputIndex, int s, int e, char c) {
	if (inputIndex<s || inputIndex>e) {
		return index;
	}
	int now = nodeCnt++;
	pst[now] = pst[index];
	if (s == e) {
		pst[now].value = c;
		pst[now].len = 1;
	}
	else {
		int mid = (s + e) / 2;
		pst[now].leftChild = update(pst[index].leftChild, inputIndex, s, mid, c);
		pst[now].rightChild = update(pst[index].rightChild, inputIndex, mid + 1, e, c);
		pst[now].len = pst[pst[now].leftChild].len + pst[pst[now].rightChild].len;
	}
	return now;
}
char calc(int index, int searchIndex, int s, int e) {
	if (s == e) {
		return pst[index].value;
	}
	else {
		int mid = (s + e) / 2;
		if (searchIndex <= mid) {
			return calc(pst[index].leftChild, searchIndex, s, mid);
		}
		else {
			return calc(pst[index].rightChild, searchIndex, mid + 1, e);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	init(1, 1000001);
	root[treeCnt++] = 0;
	int len = 0;
	while (T--) {
		char flag;
		cin >> flag;
		if (flag == 'T') {
			char c;
			cin >> c;
			root[treeCnt] = update(root[treeCnt - 1], pst[root[treeCnt - 1]].len + 1, 1, 1000001, c);
			treeCnt++;
		}
		else  if (flag == 'U') {
			int a;
			cin >> a;
			root[treeCnt] = root[treeCnt - a - 1];
			treeCnt++;
		}
		else {
			int a;
			cin >> a;
			char c = calc(root[treeCnt - 1], a + 1, 1, 1000001);
			cout << c << "\n";
		}
	}
	return 0;
}