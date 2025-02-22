#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 98, MAX = -1e9 - 7;
int a[N][N], dp[N][N];

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n;
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    dp[1][1] = a[1][1];
    for(int i = 2; i <= m; i++)
        dp[i][1] = dp[i - 1][1] + a[i][1];
    for(int i = 2; i <= n; i++)
            dp[1][i] = dp[1][i - 1] + a[1][i];

    for(int i = 2; i <= m; i++)
    {
        for(int j = 2; j <= n; j++)
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + a[i][j];
    }

    cout << dp[m][n];
    return 0;
}
