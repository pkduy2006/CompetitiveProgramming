// Codeforces Round 970 (Div. 3) C. Longest Good Array
// https://codeforces.com/problemset/problem/2008/C
// 24/50

#include <bits/stdc++.h>
using namespace std;

int ntests, l, r;

void solve() {
    vector<int> res;

    cin >> l >> r;
    int d = 1;
    while(l <= r) {
        res.push_back(l);
        l += d;
        d++;
    }
    cout << res.size() << '\n';
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