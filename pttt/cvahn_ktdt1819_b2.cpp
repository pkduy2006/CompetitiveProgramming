#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 25, INF = 1e17 + 25;
int n, a[N], res =-INF;

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

void Solve()
{
    sort(a + 1, a + 1 + n);

    res = max(a[n] * a[1] * a[2], res);
    res = max(a[n] * a[n - 1] * a[n - 2], res);
    res = max(a[1] * a[2] * a[3], res);

    cout << res;
}

main()
{
    freopen("Bai2.inp","r",stdin);
    freopen("Bai2.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
