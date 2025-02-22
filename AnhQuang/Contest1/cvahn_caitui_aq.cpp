#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, c, dp[1011][100011], v[111], w[111], k[111], idx = 0;

struct newThing
{
    int volume, value;
} a[1011];

main()
{
    freopen("bknapsack.inp","r",stdin);
    freopen("bknapsack.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    for(int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> k[i];

    for(int i = 1; i <= n; i++)
    {
        int cnt = 1;
        while(cnt <= k[i])
        {
            a[++idx] = {v[i] * cnt, w[i] * cnt};
            k[i] -= cnt;
            cnt *= 2;
        }

        if(k[i])
            a[++idx] = {v[i] * k[i], w[i] * k[i]};
    }

    for(int i = 1; i <= idx; i++)
    {
        for(int j = c; j >= 0; j--)
        {
            if(a[i].volume <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i].volume] + a[i].value);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[idx][c];

    return 0;
}
