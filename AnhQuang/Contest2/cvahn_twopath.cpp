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

const int N = 1e2 + 11, INF = 1e17 + 11;
int m, n, a[N][N], dp[N][N][N];
int jump_y[] = {-1, 0, 1};

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("TWOPATH.inp","r",stdin);
    freopen("TWOPATH.out","w",stdout);

    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }

    memset(dp, -INF, sizeof(dp));
    dp[1][1][n] = a[1][1] + a[1][n];

    for(int x = 2; x <= m; x++)
    {
        for(int y1 = 1; y1 <= n; y1++)
        {
            for(int y2 = 1; y2 <= n; y2++)
            {
                int res = -INF;

                for(int i = 0; i < 3; i++)
                {
                    for(int j = 0; j < 3; j++)
                        res = max(res, dp[x - 1][y1 + jump_y[i]][y2 + jump_y[j]]);
                }

                dp[x][y1][y2] = res;
                dp[x][y1][y2] += a[x][y1] + a[x][y2];

                if(y1 == y2)
                    dp[x][y1][y2] -= a[x][y1];
            }
        }
    }

    cout << dp[m][1][n];

    return 0;
}
