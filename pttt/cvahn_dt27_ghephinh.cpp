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

pair<int, int> a[4];
bool mark[4][3];
int maxLen = 0, s = 0;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("ghephinh.inp","r",stdin);
    freopen("ghephinh.out","w",stdout);

    for(int i = 1; i <= 3; i++)
    {
        cin >> a[i].first >> a[i].second;
        maxLen = max({maxLen, a[i].first, a[i].second});

        s += a[i].first * a[i].second;
    }

    if(maxLen * maxLen == s)
        cout << maxLen;
    else
        cout << 0;

    return 0;
}
