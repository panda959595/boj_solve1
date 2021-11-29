#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, s;
vector<int> vec[2];
vector<int> v;
int sum;
long long answer = 0;
bool flag;
void func(int num, int index) {
	if (index == vec[num].size()) {
		if (flag && sum == s) {
			answer++;
		}
		if (num == 1 && flag) {
			v.push_back(sum);
		}
		else if (num == 0 && flag) {
			answer += upper_bound(v.begin(), v.end(), s - sum) - lower_bound(v.begin(), v.end(), s - sum);
		}
		return;
	}
	func(num, index + 1);
	flag = true;
	sum += vec[num][index];
	func(num, index + 1);
	sum -= vec[num][index];
}
int main() {
	cin >> n >> s;
	for (int i = 0; i < n / 2; i++) {
		int temp;
		cin >> temp;
		vec[0].push_back(temp);
	}
	for (int i = n / 2; i < n; i++) {
		int temp;
		cin >> temp;
		vec[1].push_back(temp);
	}
	func(1, 0);
	flag = false;
	sort(v.begin(), v.end());
	func(0, 0);
	cout << answer;
	return 0;
}