#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 16;
const int INF = 1e9 + 7;
int m, n, d, r, h, a[N][N], res = INF, s[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DUONGBANG.inp","r",stdin);
    freopen("DUONGBANG.out","w",stdout);

    cin >> m >> n >> d >> r >> h;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            a[i][j] = abs(a[i][j] - h);
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j]; 
        }
    }

    for(int i = 1; i <= m - d + 1; i++)
    {
        for(int j = 1; j <= n - r + 1; j++)
            res = min(res, s[i + d - 1][j + r - 1] - s[i - 1][j + r - 1] - s[i + d - 1][j - 1] + s[i - 1][j - 1]);
    }

    for(int i = 1; i <= m - r + 1; i++)
    {
        for(int j = 1; j <= n - d + 1; j++)
            res = min(res, s[i + r - 1][j + d - 1] - s[i - 1][j + d - 1] - s[i + r - 1][j - 1] + s[i - 1][j - 1]);
    }

    if(res == INF)
        cout << -1;
    else
        cout << res;

    return 0;
}
