#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e3 + 1;
int n, dis[N][N];
bool vis[N];
vector <int> adj[N];

struct uz {
	int u;
    long long z;
};

int bfs (int u, int v) {
	queue <uz> q;
	q.push ({u, 0});
	int x;
    long long z;
	fill (vis + 1, vis + n + 1, false);
	vis[u] = true;
	while (!q.empty()) {
		x = q.front().u;
		z = q.front().z;
		q.pop();
		for (auto i : adj[x]) 
			if (i == v) return z + dis[x][i];
			else
				if (!vis[i]) {
					vis[i] = true;
					q.push ({i, z + dis[x][i]});
				}
	}
	return 0;
}

int main () {
	freopen ("DongCo.INP", "r", stdin);
    freopen ("DongCo.OUT", "w", stdout);
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);
    int q;
	cin >> n >> q;
	int i;
	for (i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back (v);
		adj[v].push_back (u);
        dis[u][v] = w, dis[v][u] = w;
	}
	for (i = 1; i <= q; i++) {
		int u, v;
        cin >> u >> v;
        cout << bfs (u, v) << endl;
    }
	return 0;
}
