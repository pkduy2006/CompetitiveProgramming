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

const int N = 2e5 + 11, INF = 1e15 + 11;
int n, k, a[N], l = -INF, r = 0, valueMAX = 0;

int cnt(int value)
{
    int ans = 0, total = 0;

    for(int i = 1; i <= n; i++)
    {
        if(total + a[i] > value)
        {
            ans++;
            total = a[i];
        }
        else
            total += a[i];
    }

    return ans + 1;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("ARRDIV.INP","r",stdin);
    freopen("ARRDIV.OUT","w",stdout);
    //freopen("input.txt","r",stdin);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];

        l = max(l, a[i]);
        r += a[i];
    }

    valueMAX = l;

    while(l <= r)
    {
        int mid = (l + r) / 2;

        if(cnt(mid) <= k)
            r = mid - 1;
        else
            l = mid + 1;
    }

    cout << l;

    return 0;
}
