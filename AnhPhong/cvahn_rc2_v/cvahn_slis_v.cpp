#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 11, INF = 1e9 + 11;
int n, x, a[N], f[N], res = 0;

namespace sub1
{
    void Solve()
    {
        f[1] = -INF;
        fill(f + 2, f + N, INF);
        for(int i = 1; i <= n; i++)
        {
            int tmp = upper_bound(f + 1, f + 1 + res, a[i]) - f;

            f[tmp] = a[i];
            res = max(res, tmp);
        }

        cout << res;
    }
}

namespace sub2
{
    void Solve()
    {
        f[1] = -INF;
        fill(f + 2, f + N, INF);
        for(int i = 1; i <= n; i++)
        {
            int tmp = lower_bound(f + 1, f + 1 + res, a[i] - x) - f;

            if(f[tmp] == -INF)
                f[tmp] = a[i];
            else if(f[tmp] == a[i] - x)
            {   
                f[tmp + 1] = a[i];
                res = max(res, tmp + 1);
            }
            else
                f[tmp] = min(f[tmp], a[i]);
            res = max(res, tmp);
        }

        cout << res;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SLIS.inp","r",stdin);
    freopen("SLIS.out","w",stdout);

    cin >> n >> x;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    if(x == 0)
        sub1::Solve();
    else
        sub2::Solve();

    return 0;
}
