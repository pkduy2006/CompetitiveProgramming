#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 16;
int n, q, parents[N], h[N], p[N][31];
vector<int> adj[N];

void dfs(int u, int pu)
{
    parents[u] = pu;
    h[u] = h[pu] + 1;

    for(int v : adj[u])
    {
        if(v == pu)
            continue;
        
        dfs(v, u);
    }
}

void Build()
{
    memset(p, -1, sizeof p);

    for(int i = 1; i <= n; i++)
        p[i][0] = parents[i];
    
    for(int i = 1; i <= 20; i++)
    {
        for(int u = 1; u <= n; u++)
        {
            if(p[u][i - 1] != -1)
                p[u][i] = p[p[u][i - 1]][i - 1];        
        }
    }
}

int LCA(int x, int y)
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
    freopen("LCA.inp","r",stdin);
    freopen("LCA.out","w",stdout);

    cin >> n >> q;
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    Build();

    while (q--)
    {
        int u, v;
        cin >> u >> v;

        cout << LCA(u, v) << '\n';
    }
    
    return 0;
}
