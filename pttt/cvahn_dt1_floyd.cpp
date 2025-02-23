#include <iostream>
#include <climits>
#include <vector>
using namespace std;

const int N = 1e3 + 1;
long long n, dis[N][N], ret[N][N];

void prep_retrieval () {
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            ret[u][v] = u;
}

void Floyd () {
    prep_retrieval ();
    for (int k = 1; k <= n; k++)
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++)
                if (dis[u][v] > dis[u][k] + dis[k][v]) {
                    dis[u][v] = dis[u][k] + dis[k][v];
                    dis[v][u] = dis[u][v];
                    ret[u][v] = ret[k][v];
                    ret[v][u] = ret[k][u];
                }
}

void Solution (int pos, int u) {
    if (pos != u) {
        Solution (ret[u][pos], u);
        cout << pos << ' ';
    }
}

int main () {
    freopen ("Floyd.INP", "r", stdin);
    freopen ("Floyd.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    cin >> n >> m;
    int i, j;
    for (i = 1; i <= n; i++)
        fill (dis[i] + 1, dis[i] + n + 1, INT_MAX);
    for (i = 1; i <= m; i++) {
        int x, y, dist;
        cin >> x >> y >> dist;
        dis[x][y] = dist, dis[y][x] = dist;
    }
    Floyd ();
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (i != j) {
                cout << i << ' ' << j << ' ' << dis[i][j] << ' ' << i << ' ';
                Solution (j, i);
                cout << endl;
            }
    return 0;
}
