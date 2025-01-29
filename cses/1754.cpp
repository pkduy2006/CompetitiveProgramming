// cses
// Coin Piles
// https://cses.fi/problemset/task/1754/

#include <bits/stdc++.h>
using namespace std;

int ntests, a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--) {
        cin >> a >> b;
        int mi = min(a, b), ma = max(a, b);
        if(mi * 2 < ma)
            cout << "NO" << '\n';
        else if((mi - (ma - mi)) % 3 != 0)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }

    return 0;
}