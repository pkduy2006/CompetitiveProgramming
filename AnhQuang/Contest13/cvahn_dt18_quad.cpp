#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 16;
const long long INF = 1e17 + 7;
long long res = -INF, g[N][2], f[N][2], a[N], n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("QUAD.inp","r",stdin);
    freopen("QUAD.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    f[0][0] = -INF;
    f[0][1] = -INF;
    for(int i = 1; i <= n - 2; i++)
    {
        if(a[i] >= f[i - 1][0])
        {
            f[i][0] = a[i];
            f[i][1] = f[i - 1][0];
        }
        else
        {
            f[i][0] = f[i - 1][0];
            f[i][1] = max(f[i - 1][1], a[i]);
        }
    }

    g[n + 1][0] = INF;
    g[n + 1][1] = INF;
    for(int i = n; i >= 3; i--)
    {
        if(a[i] <= g[i + 1][0])
        {
            g[i][0] = a[i];
            g[i][1] = g[i + 1][0];
        }
        else
        {
            g[i][0] = g[i + 1][0];
            g[i][1] = min(g[i + 1][1], a[i]);
        }
    }

    for(int i = 2; i <= n - 2; i++)
        res = max(res, f[i][0] + f[i][1] - g[i + 1][0] - g[i + 1][1]);

    cout << res;

    return 0;
}
