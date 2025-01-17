//Refact.ai Match 1 (Codeforces Round 985) A. Set
//https://codeforces.com/problemset/problem/2029/A
// 9/50

#include <bits/stdc++.h>
using namespace std;

int ntests, l, r, k;

void solve()
{
    cin >> l >> r >> k;
    
    cout << max(r / k - l + 1, 0) << '\n';
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