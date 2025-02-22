#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 16;
int n, q, minDist[N], parents[N], p[N][31];
vector<int> adj[N];
bool mark[N];

void bfs(int root)
{
    queue<int> q;
    q.push(root);
    mark[root] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v : adj[u])
        {
            if(mark[v])
                continue;
            
            mark[v] = true;
            parents[v] = u;
            minDist[v] = minDist[u] + 1;
            q.push(v);
        }
    }
}

void Build()
{
    for(int i = 1; i <= n; i++)
        p[i][0] = parents[i];
    
    for(int j = 1; j <= 29; j++)
    {
        for(int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];
    }
}   

void solve(int u, int steps)
{
    for(int i = 20; i >= 0; i--)
    {
        if((steps >> i) & 1)
            u = p[u][i];
    }

    cout << u << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("ANK.inp","r",stdin);
    freopen("ANK.out","w",stdout);

    cin >> n >> q;
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);
    Build();

    while(q--)
    {
        int x, k;
        cin >> x >> k;

        if(k > minDist[x])
            cout << -1 << '\n';
        else
            solve(x, k);
    }

    return 0;
}
