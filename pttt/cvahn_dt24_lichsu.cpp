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
pair<int, int> a[N];
int n, res = 0;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("HISTORY.inp","r",stdin);
    freopen("HISTORY.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[j].first < a[i].first && a[j].second > a[i].second)
            {
                res++;
                break;
            }
        }
    }


    cout << res;

    return 0;
}
