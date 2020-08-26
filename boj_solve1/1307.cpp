#include <iostream>
using namespace std;
int arr[301][301];
int main() {
	int n;
	cin >> n;
	if (n % 4 == 0) {
		int arr1[301][301];
		int arr2[301][301];
		int num = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr1[i][j] = num;
				arr2[n - i - 1][n - j - 1] = num;
				num++;
			}
		}
		for (int i = 0; i < n / 4; i++) {
			for (int j = 0; j < n / 4; j++) {
				arr[i][j] = arr1[i][j];
				arr[i + n / 4 * 3][j] = arr1[i + n / 4 * 3][j];
				arr[i][j + n / 4 * 3] = arr1[i][j + n / 4 * 3];
				arr[i + n / 4 * 3][j + n / 4 * 3] = arr1[i + n / 4 * 3][j + n / 4 * 3];
			}
		}
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				arr[i + n / 4][j + n / 4] = arr1[i + n / 4][j + n / 4];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 0) {
					arr[i][j] = arr2[i][j];
				}
			}
		}
	}
	else if (n % 4 == 2) {
		n /= 2;
		int x, y;
		x = 0;
		y = n / 2;
		for (int i = 1; i <= n * n; i++) {
			arr[x][y] = i;
			x--;
			y++;
			if (x < 0 && y >= n) {
				x += 2;
				y--;
			}
			if (x < 0) {
				x = n - 1;
			}
			if (y >= n) {
				y = 0;
			}
			if (arr[x][y] != 0) {
				x += 2;
				y--;
			}
		}
		n *= 2;
		int temp = n / 2;
		for (int i = 0; i < temp; i++) {
			for (int j = 0; j < temp; j++) {
				arr[i + temp][j + temp] = arr[i][j] + temp * temp;
			}
		}
		for (int i = 0; i < temp; i++) {
			for (int j = 0; j < temp; j++) {
				arr[i][j + temp] = arr[i][j] + temp*temp * 2;
			}
		}
		for (int i = 0; i < temp; i++) {
			for (int j = 0; j < temp; j++) {
				arr[i + temp][j] = arr[i][j] + temp *temp* 3;
			}
		}
		for (int i = 0; i < temp; i++) {
			for (int j = 0; j < (n - 2) / 4; j++) {
				int tmp = arr[i][j];
				arr[i][j] = arr[i + temp][j];
				arr[i + temp][j] = tmp;
			}
		}
		for (int i = 0; i < temp; i++) {
			for (int j = n - (n - 6) / 4; j < n; j++) {
				int tmp = arr[i][j];
				arr[i][j] = arr[i + temp][j];
				arr[i + temp][j] = tmp;
			}
		}
		int tmp1 = arr[(temp - 1) / 2][(temp - 1) / 2];
		int tmp2 = arr[(temp - 1) / 2][(temp - 1) / 2 - 1];
		arr[(temp - 1) / 2][(temp - 1) / 2] = arr[(temp - 1) / 2 + temp][(temp - 1) / 2];
		arr[(temp - 1) / 2][(temp - 1) / 2 - 1] = arr[(temp - 1) / 2 + temp][(temp - 1) / 2 - 1];
		arr[(temp - 1) / 2 + temp][(temp - 1) / 2] = tmp1;
		arr[(temp - 1) / 2 + temp][(temp - 1) / 2 - 1] = tmp2;
	}
	else {
		int x, y;
		x = 0;
		y = n / 2;
		for (int i = 1; i <= n * n; i++) {
			arr[x][y] = i;
			x--;
			y++;
			if (x < 0 && y >= n) {
				x += 2;
				y--;
			}
			if (x < 0) {
				x = n - 1;
			}
			if (y >= n) {
				y = 0;
			}
			if (arr[x][y] != 0) {
				x += 2;
				y--;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}