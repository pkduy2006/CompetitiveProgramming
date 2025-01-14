//CodeTON Round 9 (Div. 1 + Div. 2, Rated, Prizes!) A. Shohag Loves Mod
//https://codeforces.com/problemset/problem/2039/A

#include <bits/stdc++.h>
using namespace std;
 
int ntests, n;
 
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cout << 2 * i - 1 << ' ';
    cout << '\n';
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