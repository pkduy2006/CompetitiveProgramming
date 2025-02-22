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
using namespace std;

const int N = 1e4 + 16;
int p, par[N];

struct DisJoinSet
{
    int root(int x)
    {
        return (par[x] < 0 ? x : (par[x] = root(par[x])));
    }

    bool Merge(int x, int y)
    {
        if((x = root(x)) == (y = root(y)))
            return false;

        if(par[y] < par[x])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
} dsu;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("bin.inp","r",stdin);
    freopen("bin.out","w",stdout);

    cin >> p;
    fill(par, par + N, -1);
    while (p--)
    {
        int x, y, type;
        cin >> x >> y >> type;

        if(type == 1)
            dsu.Merge(x, y);
        else
            cout << (dsu.root(x) == dsu.root(y)) << '\n';
    }
    
    return 0;
}
