#include <bits/stdc++.h>
using namespace std;

int ntests;

void solve() {
    int l, r;
    cin >> l >> r;
    
    if(l == 1 && r == 1)
        cout << 1 << '\n';
    else
        cout << r - l << '\n';
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