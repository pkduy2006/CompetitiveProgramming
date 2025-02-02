// Codeforces Round 1002 (Div. 2) D - Graph and Graph
// https://codeforces.com/contest/2059/problem/D

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
const int INF = 1e9 + 7;
int ntests, n, s1, s2, m1, m2, dis[N][N];
vector<int> adj[3][N];

void Dijkstra(int root1, int root2) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) 
            dis[i][j] = INF;
    }
    set<pair<int, pair<int, int>>> q;
    dis[root1][root2] = 0;
    q.insert({0, {root1, root2}});

    while(!q.empty()) {
        auto [u1, u2] = q.begin()->second;
        q.erase(q.begin());
        for(int v1 : adj[1][u1]) {
            for(int v2 : adj[2][u2]) {
                if(dis[u1][u2] + abs(v1 - v2) < dis[v1][v2]) {
                    q.erase({dis[v1][v2], {v1, v2}});
                    dis[v1][v2] = dis[u1][u2] + abs(v1 - v2);
                    q.insert({dis[v1][v2], {v1, v2}});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> ntests;
    while(ntests--) {
        cin >> n >> s1 >> s2;
        for(int i = 1; i <= n; i++) {
            adj[1][i].clear();
            adj[2][i].clear();
        }
        cin >> m1;
        for(int i = 1; i <= m1; i++) {
            int u, v;
            cin >> u >> v;
            adj[1][u].push_back(v);
            adj[1][v].push_back(u);
        }
        cin >> m2;
        for(int i = 1; i <= m2; i++) {
            int u, v;
            cin >> u >> v;
            adj[2][u].push_back(v);
            adj[2][v].push_back(u);
        }
        
        vector<int> good_nodes;
        for(int u = 1; u <= n; u++) {
            set<int> adjacent_nodes1, adjacent_nodes2;
            for(int v : adj[1][u])  
                adjacent_nodes1.insert(v);
            for(int v : adj[2][u])
                adjacent_nodes2.insert(v);
            set<int> common_nodes;
            set_intersection(adjacent_nodes1.begin(), adjacent_nodes1.end(), adjacent_nodes2.begin(), adjacent_nodes2.end(), inserter(common_nodes, common_nodes.begin()));
            if(!common_nodes.empty())
                good_nodes.push_back(u);
        }
        //for(int u : good_nodes)
        //    cout << u << ' ';
        //cout << '\n';
        if(good_nodes.empty()) 
            cout << -1 << '\n';
        else {
            Dijkstra(s1, s2);
            int res = INF;
            for(int u : good_nodes) {
                res = min(res, dis[u][u]);
            }
            if(res == INF)
                cout << -1 << '\n';
            else
                cout << res << '\n';
        }
    }

    return 0;
}