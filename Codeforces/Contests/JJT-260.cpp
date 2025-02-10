// Codeforces Round 1003 (Div. 4) E. Skibidus and Rizz
// https://codeforces.com/contest/2065/problem/E

#include <bits/stdc++.h>
using namespace std;

int ntests, n, m, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--) {
        cin >> n >> m >> k;

        if(abs(n - m) > k || max(m, n) < k)
            cout << -1 << '\n';
        else {
            string res = "";
            if(m > n) {
                while(m >= k && n >= k) {
                    for(int i = 1; i <= k; i++)
                        res += '1';
                    for(int i = 1; i <= k; i++)
                        res += '0';
                    m -= k;
                    n -= k;
                }
                if(m >= k) {
                    for(int i = 1; i <= k; i++)
                        res += '1';
                    m -= k;
                    for(int i = 1; i <= n; i++)
                        res += '0';
                    for(int i = 1; i <= m; i++)
                        res += '1';
                } else {
                    for(int i = 1; i <= m; i++)
                        res += '1';
                    for(int i = 1; i <= n; i++)
                        res += '0';
                }
            } else {
                while(m >= k && n >= k) {
                    for(int i = 1; i <= k; i++)
                        res += '0';
                    for(int i = 1; i <= k; i++) 
                        res += '1';
                    m -= k;
                    n -= k;
                }
                if(n >= k) {
                    for(int i = 1; i <= k; i++)
                        res += '0';
                    n -= k;
                    for(int i = 1; i <= m; i++)
                        res += '1';
                    for(int i = 1; i <= n; i++)
                        res += '0';
                } else {
                    for(int i = 1; i <= n; i++)
                        res += '0';
                    for(int i = 1; i <= m; i++)
                        res += '1';
                }
            }
            cout << res << '\n';
        }
    }

    return 0;
}