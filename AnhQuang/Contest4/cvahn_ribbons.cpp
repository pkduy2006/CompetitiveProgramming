#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 5e3 + 11, INF = 1e9 + 11;
int sum[N], a[N], n, f[N]; // giá trị đẹp của đoạn ruy băng từ vị trí i có độ dài j

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("RIBBONS.inp","r",stdin);
    freopen("RIBBONS.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    fill(f, f + N, -INF);
    f[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
            f[i] = max(f[j - 1] + (i - j + 1) * (sum[i] - sum[j - 1]), f[i]);
    }

    cout << f[n];

    return 0;
}
