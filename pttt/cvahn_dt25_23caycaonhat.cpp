#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 16;
int n, res_d, res_root, d[N];
vector<int> adj[N];
bool mark[N];

void dfs(int u)
{
    mark[u] = true;
    for(int v : adj[u])
    {
        if(mark[v])
            continue;

        d[v] = d[u] + 1;
        dfs(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Hightree.inp","r",stdin);
    freopen("Hightree.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++)
    {
        fill(mark + 1, mark + 1 + n, false);
        fill(d + 1, d + 1 + n, 0);
        dfs(i);
        for(int j = 1; j <= n; j++)
        {
            if(d[j] > res_d)
            {
                res_d = d[j];
                res_root = i;
            }
        }
    }

    cout << res_root << ' ' << res_d;

    return 0;
}
