#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 25;
int n, m, a[N], b[N];

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> b[i];
}

void Solve()
{
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);

    int res = 0;

    for(int i = 1; i <= m; i++)
    {
        int t = *lower_bound(a + 1, a + 1 + n, b[i]);

        if(t == b[i])
            res++;
    }

    cout << res;
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("dempt.inp","r",stdin);
    freopen("dempt.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
