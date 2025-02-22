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

const int N = 1e5 + 11, INF = 1e17 + 11;
int n, a[N], res = INF;
vector<int> bigNumPos, smallNumPos;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("MMSEG.inp","r",stdin);
    freopen("MMSEG.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    int x = *max_element(a + 1, a + 1 + n);
    int y = *min_element(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++)
    {
        if(x == a[i])
            bigNumPos.push_back(i);
        else if(y == a[i])
            smallNumPos.push_back(i);
    }

    for(int i = 0; i < bigNumPos.size(); i++)
    {
        int idx = *lower_bound(smallNumPos.begin(), smallNumPos.end(), bigNumPos[i]);

        if(idx == 0)
            continue;

        res = min(res, idx - bigNumPos[i] + 1);
    }

    for(int i = 0; i < smallNumPos.size(); i++)
    {
        int idx = *lower_bound(bigNumPos.begin(), bigNumPos.end(), smallNumPos[i]);

        if(idx == 0)
            continue;

        res = min(res, idx - smallNumPos[i] + 1);
    }

    cout << res;

    return 0;
}
