#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e4 + 25, INF = 1e15 + 25;
int a[N], n, res = -INF, sum[N];

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
}

void Solve()
{
    for(int i = 1; i <= 2 * n; i++)
        sum[i] = sum[i - 1] + a[i];

    for(int i = 1; i <= 2 * n; i++)
    {
        for(int j = i + 1; j <= 2 * n; j++)
        {
            if(j - i <= n)
                res = max(res, sum[j] - sum[i]);
        }
    }

    cout << res;
}

main()
{
    freopen("DOANCONM.inp","r",stdin);
    freopen("DOANCONM.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie();

    Read();

    Solve();

    return 0;
}
