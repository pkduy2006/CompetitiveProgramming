// author: August9th

#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 16;
const double INF = 1e9 + 7;
int n, start, stop, p[N];
double m, d[N];
pair<int, int> a[N];
vector<pair<int, double>> adj[N];
vector<int> trace;

void dijkstra(int root)
{
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
    q.push({0, root});
    fill(d, d + N, INF);
    d[root] = 0;
    while (!q.empty())
    {
        auto [w, u] = q.top();
        q.pop();

        if(w != d[u])
            continue;
        
        for(auto [v, len] : adj[u])
        {
            if(d[u] + len < d[v])
            {
                d[v] = d[u] + len;
                p[v] = u;
                q.push({d[v], v}); 
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai4.inp","r",stdin);
    freopen("Bai4.out","w",stdout);

    cin >> n >> m >> start >> stop;
    for(int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;

    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            double len = sqrt((a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second));
            if(len <= m)
            {
                adj[i].push_back({j, len});
                adj[j].push_back({i, len});
            }
        }
    }

    dijkstra(start);

    int pos = stop;
    while (pos != start)
    {
        trace.push_back(pos);
        pos = p[pos];
    }
    trace.push_back(start);
    for(int i = trace.size() - 1; i >= 0; i--)
        cout << trace[i] << ' ';
    cout << '\n';
    cout << fixed << setprecision(3) << d[stop];
    
    return 0;
}
