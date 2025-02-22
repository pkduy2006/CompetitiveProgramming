#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 16;
int n, m, cnt = 0, res = 0, par[N];

struct edge
{
    int u, v, w;
}e[N];

struct DisJoinSet
{
    int root(int x)
    {
        return (par[x] < 0 ? x : (par[x] = root(par[x])));
    }

    bool MergeNode(int x, int y)
    {
        if((x = root(x)) == (y = root(y)))
            return false;

        if(par[y] < par[x])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
}dsu;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xaydungd.inp","r",stdin);
    freopen("xaydungd.out","w",stdout);

    cin >> n >> m;
    for(int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    
    sort(e + 1, e + 1 + m, [&](const edge& me, const edge& her)
    {
        return me.w < her.w;
    });
    fill(par, par + N, -1);

    for(int i = 1; i <= m; i++)
    {
        if(cnt == n - 1)
            break;

        if(dsu.MergeNode(e[i].u, e[i].v))
        {
            cnt++;
            res = max(res, e[i].w);
        }
    }

    cout << res;

    return 0;
}
