// Codeforces Round 996 (Div. 2) A. Two Frogs
// https://codeforces.com/contest/2055/problem/A

#include <bits/stdc++.h>
using namespace std;

int ntests, n, a, b;

void solve() {
    cin >> n >> a >> b;

    if(abs(a - b) % 2 == 0)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
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