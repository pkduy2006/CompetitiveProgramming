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

const int N = 5e2 + 11, SN = 1e6 + 11, INF = 1e17 + 11;
int n, m, b[SN], a[N][N], total[N][N];

main()
{
    //freopen("input.txt","r",stdin);
    freopen("maxsum.inp","r",stdin);
    freopen("maxsum.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;

    if(m == 1)
    {
        int sum = 0, ans = -INF, cur = 0;

        for(int i = 1; i <= n; i++)
            cin >> b[i];

        for(int i = 1; i <= n; i++)
        {
            sum += b[i];
            ans = max(ans, sum - cur);
            cur = min(cur, sum);
        }

        cout << ans;
        return 0;
    }

    int res = -INF;

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            total[i][j] = total[i][j - 1] + a[j][i];
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = i; j <= m; j++)
        {
            int sum = 0, cur = 0;

            for(int k = 1; k <= n; k++)
            {
                sum += total[k][j] - total[k][i - 1];
                res = max(res, sum - cur);
                cur = min(sum, cur);
            }
        }
    }

    cout << res;
    return 0;
}
