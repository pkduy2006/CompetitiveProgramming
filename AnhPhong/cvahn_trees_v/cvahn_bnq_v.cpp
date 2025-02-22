#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 16;
int n, m, par[N], h[N], p[N][25], cnt, q, parents[N];
vector<int> mst[N];

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

void dfs(int u, int pu)
{
    if(pu != -1)
        h[u] = h[pu] + 1;
    parents[u] = pu;

    for(int v : mst[u])
    {
        if(v == pu)
            continue;
        
        dfs(v, u);
    }
}

void Build()
{
    dfs(1, -1);
    memset(p, -1, sizeof p);

    for(int i = 1; i <= n; i++)
        p[i][0] = parents[i];
    
    for(int i = 0; i <= 18; i++)
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
    for(int i = 18; i >= 0; i--)
    {
        if((steps >> i) & 1)
            x = p[x][i];
    }
    
    assert(h[x] == h[y]);
    if(x == y)
        return x;
    
    for(int i = 18; i >= 0; i--)
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
    freopen("BNQ.inp","r",stdin);
    freopen("BNQ.out","w",stdout);

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
            mst[e[i].u].push_back(e[i].v);
            mst[e[i].v].push_back(e[i].u);
        }
    }

    Build();

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        int root = getLCA(x, y);
        cout << h[x] - h[root] + 1 + h[y] - h[root] << '\n';
    }
    
    return 0;
}
