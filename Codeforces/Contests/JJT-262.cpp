// Hello 2025 A. MEX Table
// https://codeforces.com/contest/2057/problem/A

#include <bits/stdc++.h>
using namespace std;

int ntests, n, m;

void solve()
{
    cin >> n >> m;

    cout << max(m, n) + 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--)
        solve();
    
    return 0;
}