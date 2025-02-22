#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
int n, m, cnt = 0;
long long res;
int par[N];

struct edge
{
    int u, v;
    long long w;
} e[2 * N];

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
    freopen("MST.inp","r",stdin);
    freopen("MST.out","w",stdout);

    cin >> n >> m;
    for(int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;

    sort(e + 1, e + 1 + m, [&] (const edge& me, const edge& her)
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
            res += e[i].w;
            cnt++;
        }
    }

    if(cnt < n - 1)
        cout << -1;
    else
        cout << res;

    return 0;
}
