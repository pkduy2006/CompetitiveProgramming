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

const int N = 1e5 + 11;
int ntests, a[N], b[N], n;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("ARRAY.inp","r",stdin);
    freopen("ARRAY.out","w",stdout);

    cin >> n >> ntests;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    while(ntests--)
    {
        int u, v, d;
        cin >> u >> v >> d;

        b[u] += d;
        b[v + 1] -= d;
    }

    for(int i = 1; i <= n; i++)
        b[i] += b[i - 1];

    for(int i = 1; i <= n; i++)
        cout << a[i] + b[i] << ' ';

    return 0;
}
