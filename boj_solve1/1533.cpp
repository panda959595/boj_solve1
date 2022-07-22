#include <iostream>
#include <vector>
using namespace std;
int n, s, e, t;

vector<vector<int>> multipleVec(vector<vector<int> > a, vector<vector<int> > b) {
	vector< vector<int> > ret(n * 5, vector<int>(n * 5, 0));
	for (int i = 0; i < n * 5; i++) {
		for (int j = 0; j < n * 5; j++) {
			long long temp = 0;
			for (int k = 0; k < n * 5; k++) {
				temp += 1LL * a[i][k] * b[k][j];
				temp %= 1'000'003;
			}
			ret[i][j] = temp;
		}
	}
	return ret;
}

vector<vector<int>> powVec(vector<vector<int>> vec, int p) {
	if (p == 1) {
		return vec;
	}
	else if (p == 2) {
		return multipleVec(vec, vec);
	}
	if (p % 2 == 0) {
		vector<vector<int>> v = powVec(vec, p / 2);
		return powVec(v, 2);
	}
	else {
		vector<vector<int>> v = powVec(vec, p / 2);
		v = powVec(v, 2);
		return multipleVec(v, vec);
	}
}

int main() {
	cin >> n >> s >> e >> t;
	vector< vector<int> > vec(n * 5, vector<int>(n * 5, 0));
	s--;
	e--;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			int temp = c - '0';
			if (temp == 0) {
				continue;
			}
			vec[i * 5][j * 5 + temp - 1] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 5; j++) {
			vec[i * 5 + j][i * 5 + j - 1] = 1;
		}
	}
	vector<vector<int> > v = powVec(vec, t);
	cout << v[5 * s][5 * e] << endl;
	return 0;
}