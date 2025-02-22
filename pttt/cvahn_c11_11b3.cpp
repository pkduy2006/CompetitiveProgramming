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

const int N = 1e2 + 16;
const double INF = 1e9 + 7;

int n;
double d[N]; 
struct house_pos
{
    int x, y, status;
}a[N];
vector<pair<int, double>> adj[N];

double prim()
{
    double res = 0;
    fill(d, d + N, INF);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
    for(int i = 1; i <= n; i++)
    {
        if(a[i].status == 1)
        {   
            d[i] = 0;
            q.push({0, i});
        }
    }

    while (!q.empty())
    {
        auto tmp = q.top();
        q.pop();
        double dis = tmp.first;
        int u = tmp.second;

        if(d[u] != dis)
            continue;

        res += d[u];
        d[u] = -INF;

        for(auto &e : adj[u])
        {
            int v = e.first;
            double distance = e.second;
            if(d[v] > distance)
            {
                d[v] = distance;
                q.push({d[v], v});
            }
        }
    }

    return res;
}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai3.inp","r",stdin);
    freopen("Bai3.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y >> a[i].status;

    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            double len = sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
            adj[i].push_back({j, len});
            adj[j].push_back({i, len});
        }
    }

    cout << fixed << setprecision(3) << prim();


    return 0;
}
