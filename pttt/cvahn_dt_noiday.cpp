#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define fi first
#define se second

const int N = 1e4 + 1;
int n, dis[N];
vector <pair <int, int> > w[N];

int Prim (int u) {
    int res = 0;
    fill (dis + 1, dis + n + 1, INT_MAX);
    dis[u] = 0;
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;
    q.push ({dis[u], u});
    while (!q.empty()) {
        auto top = q.top();
        q.pop();
        int curDis = top.fi, u = top.se;
        if (curDis != dis[u]) continue;
        res += dis[u], dis[u] = -INT_MAX;
        for (auto e : w[u]) {
            int v = e.fi, weig = e.se;
            if (dis[v] > weig) {
                dis[v] = weig;
                q.push ({dis[v], v});
            }
        }
    }
    return res;
}

int main () {
    freopen ("Noiday.INP", "r", stdin);
    freopen ("Noiday.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    cin >> n >> m;
    int i;
    for (i = 1; i <= m; i++) {
        int u, v, weig;
        cin >> u >> v >> weig;
        w[u].push_back ({v, weig});
        w[v].push_back ({u, weig});
    }
    cout << Prim (1);
    return 0;
}
