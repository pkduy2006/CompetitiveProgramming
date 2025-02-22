#include <bits/stdc++.h>
#define int long long 
using namespace std;

int get(int n, int p) {
    if (n < p) return 0;
    return n/p + get(n/p, p);
}

main() 
{
    int n, p;
    cin >> n >> p;
    int res = 1000111;
    for(int i = 2; i <= p; i++) if (p % i == 0) {
        int cnt = 0;
        while (p % i == 0) {
            p /= i;
            cnt++;
        }
        res = min(res, get(n, i) / cnt);
    }
    cout << res << endl;
    return 0;
}
