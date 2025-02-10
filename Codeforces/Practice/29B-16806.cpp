#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

int ntests, n, m;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--) {
        vector<pair<int, int>> b;
        int res = 0;

        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            vector<int> a(m);
            int sum = 0, score = 0;
            for(int i = 0; i < m; i++) {
                cin >> a[i];
                sum += a[i];
                score += (m - i) * a[i];
            }
            b.push_back({sum, score});
        }
        sort(b.begin(), b.end(), [](const pair<int, int>& me, const pair<int, int>& her) {
            return me.first > her.first;
        });
        //for(const auto& x : b)
            //cout << x.first << ' ' << x.second << '\n';
        for(int i = 0; i < b.size(); i++) {
            res += b[i].second;
           // cout << res << '\n';
            res += b[i].first * (n - i - 1) * m;
           // cout << res << '\n';
        }
        cout << res << '\n';
    }

    return 0;
}