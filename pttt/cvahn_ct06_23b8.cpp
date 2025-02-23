#include <bits/stdc++.h>
#define int long long
#define TASK "KINHDOANH"

using namespace std;
const int NM = 1e5+7;
const int INF = 1e9+7;

int n,m,cnt,mx1 = 0,mx2 = 0;

vector<int> a[NM];

bool b[NM];

void dfs(int u) {
    b[u] = 1;
    for (int i = 0; i < a[u].size(); i++) {
        int x = a[u][i];
        if (b[x] == 0) {
            cnt++;
            dfs(x);
        }
    }
}

main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen(TASK".inp","r",stdin); freopen(TASK".out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (b[i] == 0 ) {
            cnt = 1;
            dfs(i);

            if (cnt > mx1) {
                mx2 = mx1;
                mx1 = cnt;
            }
            else {
                mx2 = max(mx2, cnt);
            }

            //cout << i << " " << mx1 << " " << mx2 << '\n';

        }
    }

    cout << mx1 + mx2;

    return 0;
}
