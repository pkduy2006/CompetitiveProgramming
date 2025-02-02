// Codeforces Alpha Round 20 (Codeforces format) C - Dijkstra?
// https://codeforces.com/contest/20/problem/C

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const long long INF = 1e11 + 7;
int n, m, p[N];
long long dis[N];
vector<pair<int, int>> adj[N];

void Dijkstra(int root) {
    set<pair<int, int>> q;
    fill(dis, dis + N, INF);
    q.insert({0, root});
    dis[1] = 0;
    fill(p, p + N, -1);

    while(!q.empty()) {
        auto u = q.begin()->second;
        q.erase(q.begin()); 
        for(auto [v, len] : adj[u]) {
            if(dis[u] + len < dis[v]) {
                q.erase({dis[v], v});
                dis[v] = dis[u] + len;
                p[v] = u;
                q.insert({dis[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Dijkstra(1);
    if(dis[n] == INF)
        cout << -1;
    else {
        int node = n;
        vector<int> res;
        while(node != -1) {
            res.push_back(node);
            node = p[node];
        }
        for(int i = res.size() - 1; i >= 0; i--)
            cout << res[i] << ' ';
    }
    return 0;
}