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

const int N = 5e3 + 11, INF = 1e17 + 11;
int dp[N][N], a[N], n;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("RGAME.INP","r",stdin);
    freopen("RGAME.OUT","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            dp[i][j] = -INF;
    }

    for(int i = 1; i <= n; i++)
    {
        dp[i][i] = a[i];

        if(i < n)
            dp[i][i + 1] = max(a[i], a[i + 1]);
    }

    for(int i = n - 2; i >= 1; i--)
    {
        for(int j = i + 2; j <= n; j++)
            dp[i][j] = max({dp[i][j], min(dp[i + 1][j - 1], dp[i + 2][j]) + a[i], min(dp[i + 1][j - 1], dp[i][j - 2]) + a[j]});
    }

    cout << dp[1][n];

    return 0;
}
