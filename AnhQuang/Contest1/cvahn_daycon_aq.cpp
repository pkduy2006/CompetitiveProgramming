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

const int N = 1e6 + 11;
int n, a[N], dp[N], res = 0, f[N];

int findAns(int x)
{
    int l = 1, r = res;

    while(l <= r)
    {
        int mid = (l + r) / 2;

        if(a[dp[mid]] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return r;
}

main()
{
    freopen("LIS.inp","r",stdin);
    freopen("LIS.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    fill(f + 1, f + N, 1);

    for(int i = 1; i <= n; i++)
    {
        int idx = findAns(a[i]);

        dp[idx + 1] = i;
        f[i] = idx + 1;
        res = max(res, f[i]);
    }

    cout << res;

    return 0;
}
