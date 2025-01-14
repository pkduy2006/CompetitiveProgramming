//Codeforces Round 980 (Div. 2) A. Profitable Interest Rate
//https://codeforces.com/contest/2024/problem/A
// 12/50

#include <bits/stdc++.h>
using namespace std;

int ntests, a, b;

void solve()
{
    cin >> a >> b;

    if(a >= b)
        cout << a << '\n';
    else
        cout << max(2 * a - b, 0) << '\n';
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