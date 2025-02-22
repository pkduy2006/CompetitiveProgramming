#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 25;
int a[N], n, dp[N], sum[N]; // độ dài dãy con tăng dài nhất nếu lấy phần tử thứ n

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

void Solve()
{
    dp[1] = 1;
    sum[1] = a[1];
    int res = 1, sumRes = 0;

    for(int i = 2; i <= n; i++)
    {
        dp[i] = 1, sum[i] = a[i];
        for(int j = 1; j <= i - 1; j++)
        {
            if(a[i] > a[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                sum[i] = sum[j] + a[i];
            }
        }

        if(res < dp[i])
        {
            res = dp[i];
            sumRes = sum[i];
        }
        else if(res == dp[i])
            sumRes = max(sumRes, sum[i]);
    }

    cout << res << ' ' << sumRes;
}

main()
{
    freopen("Dayconmax.inp","r",stdin);
    freopen("Dayconmax.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
