#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9 + 7, N = 398;
int a[N], mark[N];

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("tratien.inp","r",stdin);
    freopen("tratien.out","w",stdout);

    int n, m;
    cin >> n >> m;
    vector<int> f(m + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i < a[j])
                continue;
            if(f[i] == 0)
                f[i] = f[i - a[j]] + 1;
            else
                f[i] = min(f[i], f[i - a[j]] + 1);
        }
    }

    int res = m;
    while(res > 0)
    {
        for(int i = 1; i <= n; i++)
        {
            if(f[res] == f[res - a[i]] + 1)
            {
                mark[i]++;
                res-=a[i];
                break;
            }
        }
    }

    cout << f[m] << '\n';
    for(int i = 1; i <= n; i++)
        cout << mark[i] << ' ';
    return 0;
}
