#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5098;
int a[N], b[N], dp[N][N];
vector<int> res;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Daydx.inp","r",stdin);
    freopen("Daydx.out","w",stdout);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[n - i + 1] = a[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    int c = n, d = n;
    while(c > 0 && d > 0)
    {
        if(a[c] == b[d])
        {
            res.push_back(a[c]);
            c--;
            d--;
        }
        else
        {
            if(dp[c - 1][d] < dp[c][d - 1])
                d--;
            else
                c--;
        }
    }

    cout << dp[n][n] << '\n';
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    return 0;
}
