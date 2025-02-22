#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 25, INF = 1e17 + 25;
int n, a[N], dp[N][2];

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

void Solve()
{
    dp[1][1] = a[1];
    dp[1][0] = INF;
    for(int i = 2; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][0]);
        dp[i][1] = min(dp[i - 1][1] + a[i], a[i]);
    }

    if(n > 1)
        cout << min(dp[n][0], dp[n][1]);
    else
        cout << a[1];
}

main()
{
    freopen("lis.inp","r",stdin);
    freopen("lis.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
