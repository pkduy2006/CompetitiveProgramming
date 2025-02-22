#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 8;
int res = 0, cnt = 0;

struct edge
{
    int u, v, w;
} e[N];

struct DSU
{
    vector<int> par;

    void init(int n)
    {
        par = vector<int> (n + 1, -1);
    }

    int root(int u)
    {
        return par[u] < 0 ? u : (par[u] = root(par[u]));
    }

    bool Merge(int x, int y, int length)
    {
        if((x = root(x)) == (y = root(y)))
            return true;

        if(par[y] < par[x])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
        res += length;
        return false;
    }
} dsu;

main()
{
    freopen("Krukal.inp","r",stdin);
    freopen("Krukal.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    dsu.init(n);
    sort(e + 1, e + 1 + m, [&](const edge& me, const edge& her)
    {
        return me.w < her.w;
    });

    for(int i = 1; i <= m; i++)
    {
        if(cnt == n - 1)
            break;

        if(!dsu.Merge(e[i].u, e[i].v, e[i].w))
            cnt++;
    }

    cout << res;
    return 0;
}
