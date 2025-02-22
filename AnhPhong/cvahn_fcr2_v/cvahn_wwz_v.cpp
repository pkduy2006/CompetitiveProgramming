#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
const long long INF = 1e17 + 16;
int n, m, k, l, s[N], z[N], res = 0;
vector<pair<int, int>> adj[N];
long long zdis[N], pdis[N];
bool mark[N];

void dijkstraForZombie()
{
    fill(zdis, zdis + N, INF);
    for(int i = 1; i <= l; i++)
        zdis[z[i]] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    for(int i = 1; i <= l; i++)
        q.push({0, z[i]});

    while (!q.empty())
    {
        auto[len, v] = q.top();
        q.pop();
        if(len != zdis[v])
            continue;
        
        for(auto [to, w] : adj[v])
        {
            if(zdis[v] + w < zdis[to])
            {
                zdis[to] = zdis[v] + w;
                q.push({zdis[to], to});
            }
        }
    }
}

void dijkstraForPeople()
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    fill(pdis, pdis + N, INF);
    for(int i = 1; i <= k; i++)
    {   
        pdis[s[i]] = 0;
        q.push({0, s[i]});
    }

    while (!q.empty())
    {
        auto [len, v] = q.top();
        q.pop();
        if(pdis[v] != len || pdis[v] >= zdis[v])
            continue;
        
        for(auto [to, w] : adj[v])
        {
            if(pdis[v] + w < pdis[to])
            {
                pdis[to] = pdis[v] + w;
                q.push({pdis[to], to}); 
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("WWZ.INP","r",stdin);
    freopen("WWZ.OUT","w",stdout);

    cin >> n >> m >> k >> l;
    for(int i = 1; i <= k; i++) 
        cin >> s[i];
    for(int i = 1; i <= l; i++) 
        cin >> z[i];
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstraForZombie();
    dijkstraForPeople();

    for(int i = 1; i <= n; i++)
    {
        if(pdis[i] < zdis[i])
            res++;
    }

    cout << res;

    return 0;
}
