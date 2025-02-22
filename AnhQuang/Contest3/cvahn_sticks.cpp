#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 11;
int n, a[N], len, res = 0;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("STICKS.INP","r",stdin);
    freopen("STICKS.OUT","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);

    if(n % 2 == 1)
        len = a[(n + 1) / 2];
    else
        len = a[n / 2];

    for(int i = 1; i <= n; i++)
        res += abs(len - a[i]);

    cout << res;

    return 0;
}
