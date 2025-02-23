#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e2 + 16;
int a[N][N], preference[N][N], m, n, k, res;

int GetPreference (int x1, int y1, int x2, int y2)
{
    return preference[x2][y2] - preference[x1 - 1][y2] - preference[x2][y1 - 1] + preference[x1 - 1][y1 - 1];
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("land.inp","r",stdin);
    freopen("land.out","w",stdout);

    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            preference[i][j] = preference[i - 1][j] + preference[i][j - 1] - preference[i - 1][j - 1] + a[i][j];
        }
    }

    for (int x1 = 1; x1 <= m; x1++)
    {
        for (int y1 = 1; y1 <= n; y1++)
        {
            for (int x2 = x1; x2 <= m; x2++)
            {
                for (int y2 = y1; y2 <= n; y2++)
                {
                    if (GetPreference (x1, y1, x2, y2) <= k)
                    {
                        int area = (x2 - x1 + 1) * (y2 - y1 + 1);
                        res = max (res, area);
                    }
                }
            }
        }
    }

    cout << res;

    return 0;
}
