#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
int n, m, q, par[N], cnt, h[N], parents[N], p[N][25];
vector<pair<int, long long>> adj[N];
long long dis[N];

struct edge
{
    int u, v;
    long long w;
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

void dfs(int u, int pu)
{
    if(pu != -1)
        h[u] = h[pu] + 1;
    parents[u] = pu;

    for(auto [v, w] : adj[u])
    {
        if(v == pu)
            continue;
        
        dis[v] = dis[u] + w;

        dfs(v, u);
    }
}

void Build()
{
    dfs(1, -1);
    memset(p, -1, sizeof p);

    for(int i = 1; i <= n; i++)
        p[i][0] = parents[i];
    
    for(int i = 1; i <= 20; i++)
    {
        for(int x = 1; x <= n; x++)
        {
            if(p[x][i - 1] != -1)
                p[x][i] = p[p[x][i - 1]][i - 1];
        }
    }
}

int getLCA(int x, int y)
{
    if(h[x] < h[y])
        swap(x, y);
    
    int steps = h[x] - h[y];
    for(int i = 20; i >= 0; i--)
    {
        if((steps >> i) & 1)
            x = p[x][i];
    }

    assert(h[x] == h[y]);
    if(x == y)
        return x;
    
    for(int i = 20; i >= 0; i--)
    {
        if(p[x][i] != p[y][i])
        {
            x = p[x][i];
            y = p[y][i];
        }
    }
    
    assert(p[x][0] == p[y][0]);
    return p[x][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("BND.inp","r",stdin);
    freopen("BND.out","w",stdout);

    cin >> n >> m >> q;
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
            cnt++;
            adj[e[i].u].push_back({e[i].v, e[i].w});
            adj[e[i].v].push_back({e[i].u, e[i].w});
        }
    }

    Build();

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        int root = getLCA(x, y);
        cout << dis[y] - dis[root] + dis[x] - dis[root] << '\n';  
    }
    
    return 0;
}
