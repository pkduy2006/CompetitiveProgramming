#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 11;
int n, a[N], b[N], sum[N], res = 0;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("arrdif.inp","r",stdin);
    freopen("arrdif.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];

        b[i] = a[i];
    }

    sort(b + 1, b + 1 + n);
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + b[i];

    for(int i = 1; i <= n; i++)
    {
        int pos = lower_bound(b + 1, b + 1 + n, a[i]) - b;
        res +=  (sum[n] - sum[pos - 1]) - (n - pos + 1) * a[i];
        res += (pos - 1) * a[i] - sum[pos - 1];
    }

    cout << res / 2;

    return 0;
}
