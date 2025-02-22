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

vector<pair<int, int>> times;
int n, res, cntRes = 0;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("RESTAURANT.INP","r",stdin);
    freopen("RESTAURANT.OUT","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;

        times.push_back({a, 1});
        times.push_back({b, -1});
    }

    sort(times.begin(), times.end());

    int tmp = 0;
    for(auto [t, cnt] : times)
    {
        tmp += cnt;

        if(cntRes < tmp)
        {
            res = t;
            cntRes = tmp;
        }
    }

    cout << cntRes;

    return 0;
}
