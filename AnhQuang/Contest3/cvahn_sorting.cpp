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

const int N = 1e3 + 11;
int n, m;

struct num
{
    int x, y, value;
};

vector<num> a;

bool cmp(num b, num c)
{
    return b.value < c.value;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SORTING.INP","r",stdin);
    freopen("SORTING.OUT","w",stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int value;
            cin >> value;

            a.push_back({i, j, value});
        }
    }

    sort(a.begin(), a.end(), cmp);

    for(int i = 0; i < a.size(); i++)
        cout << a[i].x << ' ' << a[i].y << '\n';

    return 0;
}
