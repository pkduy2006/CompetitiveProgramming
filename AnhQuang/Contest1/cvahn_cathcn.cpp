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

const int N = 5e2 + 11, INF = 1e17 + 11;
int a, b, dp[N][N];

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CUTTING.INP","r",stdin);
    freopen("CUTTING.OUT","w",stdout);

    cin >> a >> b;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = INF;
        }
    }

    for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= b; j++)
        {
            if(i == j)
                continue;

            for(int k = 1; k < i; k++)
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);

            for(int k = 1; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
        }
    }

    cout << dp[a][b];

    return 0;
}
