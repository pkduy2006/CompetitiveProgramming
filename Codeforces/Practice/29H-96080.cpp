#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int ntests, deg[N], res, n;
vector<int> adj[N];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) 
        adj[i].clear();
    fill(deg + 1, deg + 1 + n, 0);
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    multiset<int> s;
    res = 0;
    for(int i = 1; i <= n; i++)
        s.insert(deg[i]);
    for(int i = 1; i <= n; i++) {
        auto it = s.find(deg[i]);
        s.erase(it);
        for(int v : adj[i]) {
            auto it2 = s.find(deg[v]);
            s.erase(it2);
            s.insert(deg[v] - 1);
        }
        res = max(res, deg[i] + *s.rbegin() - 1);
        s.insert(deg[i]);
        for(int v : adj[i]) {
            s.erase(s.find(deg[v] - 1));
            s.insert(deg[v]);
        }
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--)
        solve();

    return 0;
}