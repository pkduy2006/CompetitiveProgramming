#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e3 + 25;
int n, a[N], b[N], dp[N][N]; // dp[i][j] là độ dài dãy con dài nhất kết thúc tại phần tử thứ i của dãy A và thứ j của dãy B
vector<int> res;

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[n - i + 1] = a[i];
    }
}

void Solve()
{
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

    if(dp[n][n] < 2)
    {
        cout << 0;
        return;
    }

    cout << dp[n][n] << '\n';

    int t = n, m = n;

    while(t > 0 && m > 0)
    {
        if(a[t] == b[m])
        {
            res.push_back(a[t]);
            t--;
            m--;
        }
        else
        {
            if(dp[t - 1][m] < dp[t][m - 1])
                m--;
            else
                t--;
        }
    }

    for(int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << ' ';
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("Daydx.inp","r",stdin);
    freopen("Daydx.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
