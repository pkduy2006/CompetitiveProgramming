// Codeforces Round 1004 (Div. 2) C. Devyatkino
// https://codeforces.com/contest/2067/problem/C

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 506;
int ntests, n, res;

bool check(int x) {
    while(x > 0) {
        if(x % 10 == 7)
            return true;
        x /= 10;
    }
    return false;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--) {
        cin >> n;
        
        res = INF;
        if(check(n)) 
            res = 0;
        else {
            if(n % 10 < 7)
                res = min(res, n % 10 + 3);
            else 
                res = min(res, n % 10 - 7);
            string m = to_string(n);
            int a = 9, b = 70, c = n % 10, cnt = 10, d = 79, e = 700;
            for(int i = m.size() - 2; i >= 0; i--) {
                c = cnt * (m[i] - '0') + c;
                if(0 < m[i] - '0' && m[i] - '0' <= 6) {
                    //cout << b << ' ' << c << ' ' << a << '\n';
                    res = min(res, (b - c) / a + ((b - c) % a != 0));
                } else if(m[i] - '0' != 0) {
                    res = min(res, c - d);
                    //cout << e << ' ' << c << ' ' << a * 10 + 9 << '\n';
                    res = min(res, (e - c) / (a * 10 + 9) + ((e - c) % (a * 10 + 9) != 0));
                }
                a = a * 10 + 9;
                b *= 10;
                cnt *= 10;
                d *= 10;
                d += 9;
                e *= 10;
            }
        }
        cout << res << '\n';
    }

    return 0;
}