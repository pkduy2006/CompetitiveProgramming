#include <iostream>
#include <climits>
#include <vector>
using namespace std;

const int N = 1e3 + 1;
int n, dis[N][N], dp[N], ret[N];
bool vis[N];
vector <int> adj[N];

void Dijkstra (int u) {
    fill (dp + 1, dp + n + 1, INT_MAX);
    dp[u] = 0;
    for (auto v : adj[u]) {
        dp[v] = dis[u][v];
        ret[v] = u;
    }
    int min_val;
    do {
        min_val = INT_MAX;
        for (int i = 1; i <= n; i++)
            if (min_val > dp[i] && !vis[i]) {
                min_val = dp[i];
                u = i;
            }
        if (min_val == INT_MAX) break;
        vis[u] = true;
        for (auto v : adj[u]) 
            if (dp[v] > dp[u] + dis[v][u]) {
                dp[v] = dp[u] + dis[v][u];
                ret[v] = u;
            }
    }
    while (min_val < INT_MAX);
}

void Solution (int pos, int u) {
    if (pos != u) {
        Solution (ret[pos], u);
        cout << pos << ' ';
    }
}

int main () {
    freopen ("Dijkstra.INP", "r", stdin);
    freopen ("Dijkstra.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, u;
    cin >> n >> m >> u;
    int i;
    for (i = 1; i <= m; i++) {
        int x, y, dist;
        cin >> x >> y >> dist;
        adj[x].push_back (y);
        adj[y].push_back (x);
        dis[x][y] = dist, dis[y][x] = dist;
    }
    Dijkstra (u);
    for (i = 1; i <= n; i++)
        if (i != u) {
            cout << u << ' ' << i << ' ' << dp[i] << ' ' << u << ' ';
            Solution (i, u);
            cout << endl;
        }
    return 0;
}
