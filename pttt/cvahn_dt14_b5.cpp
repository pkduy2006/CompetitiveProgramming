#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 25;
int a[N], n, d, t;

void Read()
{
    cin >> n >> d >> t;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

void Solve()
{
    for(int i = 1; i <= n; i++)
    {
        if(a[i] < t)
            cout << 1 << ' ';
        else
        {
            int res = 1;
            a[i] -= t;
            res += a[i] / d;

            if(a[i] % d != 0)
                res++;

            cout << res << ' ';
        }
    }
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("bus.inp","r",stdin);
    freopen("bus.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
