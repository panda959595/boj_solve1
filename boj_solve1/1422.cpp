#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int arr[1005];
int func(int num) {
	int ret = 0;
	while (num > 0) {
		ret++;
		num /= 10;
	}
	return ret;
}
string itos(int num) {
	string ret = "";
	while (num > 0) {
		char temp= '0' + num % 10;
		ret = temp + ret;
		num /= 10;
	}
	return ret;
}
struct stru {
	int len;
	int num;
	string str;
	stru(int a, int b, string c) {
		len = a;
		num = b;
		str = c;
	}
	bool operator<(const stru& temp) {
		return num < temp.num;
	}
};
vector<stru> vec;
bool bigyo(stru a, stru b) {
	if (a.len == b.len) {
		return a.num > b.num;
	}
	else {
		string x = a.str + b.str;
		string y = b.str + a.str;
		for (int i = 0; i < x.length(); i++) {
			if (x[i] != y[i]) {
				return x[i] > y[i];
			}
		}
		return true;
	}
	/*if (a.second * t[b.first] + b.second > b.second* t[a.first] + a.second) {
		return true;
	}
	else {
		return false;
	}*/
}
int main() {
	int n, k;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		vec.push_back(stru(func(arr[i]), arr[i], itos(arr[i])));
	}
	sort(arr, arr + k);
	for (int i = 0; i < n - k; i++) {
		vec.push_back(stru(func(arr[k - 1]), arr[k - 1], itos(arr[k - 1])));
	}
	sort(vec.begin(), vec.end(), bigyo);
	for (auto k : vec) {
		cout << k.num;
	}
	return 0;
}