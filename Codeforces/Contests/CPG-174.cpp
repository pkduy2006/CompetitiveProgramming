// Codeforces Round 1003 (Div. 4) D. Skibidus and Sigma
// https://codeforces.com/contest/2065/problem/D 

#include <bits/stdc++.h>
#define int long long
using namespace std;

int ntests, n, m;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--) {
        cin >> n >> m;
        vector<tuple<long long, long long, long long>> sum;
        for(int i = 1; i <= n; i++) {
            vector<int> a(m);
            long long s = 0, w = 0;
            for(int j = 0; j < m; j++) {
                cin >> a[j];
                s += a[j];
                w += (long long)(j + 1) * a[j];
            }
            sum.push_back({-s, s, w});
        }

        sort(sum.begin(), sum.end());
        long long total = 0;
        for(int i = 0; i < n; i++) {
            long long s = get<1>(sum[i]);
            long long w = get<2>(sum[i]);
            long long tmp = s * (m * (n - i) + 1) - w;
            total += tmp;
        }
        cout << total << '\n';
    }

    return 0;
}