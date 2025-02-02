// cses 
// Digit Queries
// https://cses.fi/problemset/task/2431

#include <bits/stdc++.h>
using namespace std;

int q;
long long k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while(q--) {
        cin >> k;
        
        if(k <= 9)
            cout << k << '\n';
        else {
            long long cnt = 0, a = 9, b = 1, c = 1;
            while(cnt + a * b <= k) {
                cnt += a * b;
                a *= 10;
                b++;
                c *= 10;
            }
            long long d = k - cnt;
            long long e = d / b;
            long long f = c + e;
            if(d % b == 0) {
                f--;
                cout << f % 10 << '\n';
            } else {
                string g = to_string(f);
                cout << g[d % b - 1] << '\n';
            }
        }
    }
    return 0;
}