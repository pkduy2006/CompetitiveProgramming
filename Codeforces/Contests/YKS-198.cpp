// Codeforces Round 1004 (Div. 2) A. Adjacent Digit Sums
// https://codeforces.com/contest/2067/problem/A#

#include <bits/stdc++.h>
using namespace std;

int ntests, x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--) {
        cin >> x >> y;
        if(y - x == 1 || (x - y + 1) % 9 == 0 && x - y + 1 > 0)
            cout << "YES" << '\n';
        else 
            cout << "NO" << '\n';
    }

    return 0;
}