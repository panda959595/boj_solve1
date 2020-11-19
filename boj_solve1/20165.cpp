#include <iostream>
using namespace std;
int n, m, r;
int domino[105][105];
int now[105][105];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int flag_arr[26];
int attack(int x, int y, int flag)
{
    int ret = 1;
    while (1)
    {
        if (x < 0 || x >= n || y < 0 || y >= m)
        {
            break;
        }
        if (now[x][y] != -1)
        {
            x += dx[flag];
            y += dy[flag];
            continue;
        }
        now[x][y] = 0;
        int p = x, q = y;
        for (int i = 0; i < domino[x][y] - 1; i++)
        {
            p += dx[flag];
            q += dy[flag];
            if (p < 0 || p >= n || q < 0 || q >= m)
            {
                break;
            }
            if (now[p][q] > 0)
            {
                ret++;
                now[p][q] = -1;
            }
        }
        x += dx[flag];
        y += dy[flag];
    }
    return ret;
}
int main()
{
    //cout<<"123";
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> domino[i][j];
            now[i][j] = domino[i][j];
        }
    }
    flag_arr['E' - 'A'] = 0;
    flag_arr['W' - 'A'] = 1;
    flag_arr['S' - 'A'] = 2;
    flag_arr['N' - 'A'] = 3;
    int ans = 0;
    r *= 2;
    for (int rnd = 0; rnd < r; rnd++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (rnd % 2 == 0)
        {
            char c;
            cin >> c;
            if (now[a][b] == 0)
            {
                continue;
            }
            now[a][b] = -1;
            ans += attack(a, b, flag_arr[c - 'A']);
        }
        else
        {
            now[a][b] = domino[a][b];
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (now[i][j] == 0)
            {
                cout << "F ";
            }
            else
            {
                cout << "S ";
            }
        }
        cout << endl;
    }
    return 0;
}