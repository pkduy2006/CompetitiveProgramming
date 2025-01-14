//Codeforces Global Round 27 A. Sliding
//https://codeforces.com/problemset/problem/2035/A

#include <bits/stdc++.h>
#define int long long
using namespace std;

int ntests, n, m, r, c;

void solve()
{
    cin >> n >> m >> r >> c;

    cout << (2 * m - 1) * (n - r) + m - c << '\n';
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--)
        solve();
    
    return 0;
}