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

const int N = 1e4 + 11, INF = 1e17 + 11;
int a[N], n, res = -1;

bool check(int cnt)
{
    int b[N], c[N];

    for(int i = 1; i <= cnt; i++)
        b[i] = a[i];

    for(int i = cnt + 1; i <= 2 * cnt; i++)
        c[i - cnt] = a[i];

    sort(b + 1, b + 1 + cnt);
    sort(c + 1, c + 1 + cnt);

    for(int i = 1; i <= cnt; i++)
    {
        if(b[i] >= c[i])
            return false;
    }

    return true;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("rusdoll.inp","r",stdin);
    freopen("rusdoll.out","w",stdout);
    //freopen("input.txt","r",stdin);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = n / 2; i >= 1; i--)
    {
        if(check(i))
        {
            res = i;
            break;
        }
    }

    cout << res;

    return 0;
}
