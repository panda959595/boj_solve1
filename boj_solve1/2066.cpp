#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define maxCard 4
struct card {
	int num;
	int alpha;
};
struct stru {
	long long success;
	long long total;
	stru(int a, int b) {
		success = a;
		total = b;
	}
	stru() {

	}
};
card arr[9][5];
int charToInt[500];
double dp[5][5][5][5][5][5][5][5][5];
double func(vector<int> now) {
	if (dp[now[0]][now[1]][now[2]][now[3]][now[4]][now[5]][now[6]][now[7]][now[8]] != -1) {
		return dp[now[0]][now[1]][now[2]][now[3]][now[4]][now[5]][now[6]][now[7]][now[8]];
	}
	for (int i = 0; i < 9; i++) {
		if (now[i] != 0) {
			break;
		}
		if (i == 8) {
			return dp[now[0]][now[1]][now[2]][now[3]][now[4]][now[5]][now[6]][now[7]][now[8]] = 1;
		}
	}
	stru ret(0, 0);
	double a;
	int b;
	a = 0;
	b = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < i; j++) {
			if (now[i] == 0 || now[j] == 0) {
				continue;
			}
			if (arr[i][now[i]].num == arr[j][now[j]].num) {
				vector<int> temp = now;
				temp[i]--;
				temp[j]--;
				//stru tmp = func(temp);
				//ret.success += tmp.success;
				//ret.total++;
				a += func(temp);
				b++;
			}
		}
	}
	if (a == 0) {
		return dp[now[0]][now[1]][now[2]][now[3]][now[4]][now[5]][now[6]][now[7]][now[8]] = 0;
	}
	return dp[now[0]][now[1]][now[2]][now[3]][now[4]][now[5]][now[6]][now[7]][now[8]] = a / b;
}
int main() {
	for (int i = 0; i < 4; i++) {
		charToInt[i + '6'] = i + 1;
	}
	charToInt['T'] = 5;
	charToInt['J'] = 6;
	charToInt['Q'] = 7;
	charToInt['K'] = 8;
	charToInt['A'] = 9;

	charToInt['S'] = 1;
	charToInt['D'] = 2;
	charToInt['H'] = 3;
	charToInt['C'] = 4;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < maxCard; j++) {
			string str;
			cin >> str;
			arr[i][j + 1].num = charToInt[str[0]];
			arr[i][j + 1].alpha = charToInt[str[1]];
		}
	}
	for (int i1 = 0; i1 < 5; i1++) {
		for (int i2 = 0; i2 < 5; i2++) {
			for (int i3 = 0; i3 < 5; i3++) {
				for (int i4 = 0; i4 < 5; i4++) {
					for (int i5 = 0; i5 < 5; i5++) {
						for (int i6 = 0; i6 < 5; i6++) {
							for (int i7 = 0; i7 < 5; i7++) {
								for (int i8 = 0; i8 < 5; i8++) {
									for (int i9 = 0; i9 < 5; i9++) {
										dp[i1][i2][i3][i4][i5][i6][i7][i8][i9] = -1;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	vector<int> vec;
	for (int i = 0; i < 9; i++) {
		vec.push_back(maxCard);
	}
	cout << func(vec);
	//cout << dp[maxCard][maxCard][maxCard][maxCard][maxCard][maxCard][maxCard][maxCard][maxCard].success << " " 
	//	<< dp[maxCard][maxCard][maxCard][maxCard][maxCard][maxCard][maxCard][maxCard][maxCard].total << endl;
	//cout << (double)dp[maxCard][maxCard][maxCard][maxCard][maxCard][maxCard][maxCard][maxCard][maxCard].success / 
	//	dp[maxCard][maxCard][maxCard][maxCard][maxCard][maxCard][maxCard][maxCard][maxCard].total;
	return 0;
}