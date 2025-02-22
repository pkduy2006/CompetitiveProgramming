#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 16;
vector<int> adj[N];
int n, res[N], parDis[N];
pair<int, int> childDis[N];

void dfs1(int u, int pu)
{
    for(int v : adj[u])
    {
        if(v == pu)
            continue;

        dfs1(v, u);

        if(childDis[v].first + 1 > childDis[u].second)
            childDis[u].second = childDis[v].first + 1;
        
        if(childDis[u].first < childDis[u].second)
            swap(childDis[u].first, childDis[u].second);
    }
}

void dfs2(int u, int pu)
{
    res[u] = childDis[u].first;

    auto [max1, max2] = childDis[u];
    if(pu != -1)
    {
        parDis[u] = max(parDis[pu], (max1 + 1 == childDis[pu].first ? childDis[pu].second : childDis[pu].first)) + 1;
        res[u] = max(parDis[u], res[u]);
    }

    for(int v : adj[u])
    {
        if(v == pu)
            continue;
        
        dfs2(v, u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("TD.inp","r",stdin);
    freopen("TD.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, -1);
    dfs2(1, -1);

    for(int i = 1; i <= n; i++)
        cout << res[i] << ' ';
    
    return 0;
}
