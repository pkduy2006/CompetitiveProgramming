#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
int n, m, k, fi_infected, se_infected, d1[N], d2[N], d3[N], res;
vector<int> adj[N];
bool infected_city[N], mark1[N], mark2[N], mark3[N];

void dfs1(int x)
{
    mark1[x] = true;
    for(int y : adj[x])
    {
        if(mark1[y])
            continue;
        
        d1[y] = d1[x] + 1;
        dfs1(y);
    }
}

void dfs2(int x)
{
    mark2[x] = true;
    for(int y : adj[x])
    {
        if(mark2[y])
            continue;
        
        d2[y] = d2[x] + 1;
        dfs2(y);
    }
}

void dfs3(int x)
{
    mark3[x] = true;
    for(int y : adj[x])
    {
        if(mark3[y])
            continue;
        
        d3[y] = d3[x] + 1;
        dfs3(y);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("bv.inp","r",stdin);
    freopen("bv.out","w",stdout);

    cin >> n >> m >> k;
    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        infected_city[x] = true;
    }

    dfs1(1);
    for(int i = 1; i <= n; i++)
    {
        if(d1[i] > d1[fi_infected] && infected_city[i])
            fi_infected = i;
    }

    dfs2(fi_infected);
    for(int i = 1; i <= n; i++)
    {
        if(d2[i] > d2[se_infected] && infected_city[i])
            se_infected = i;
    }

    dfs3(se_infected);
    for(int i = 1; i <= n; i++)
    {
        if(d2[i] <= k && d3[i] <= k)
            res++;
    }

    cout << res;

    return 0;
}
