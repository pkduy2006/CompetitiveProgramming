//Codeforces Round 979 (Div. 2) B. Minimise Oneness
//https://codeforces.com/problemset/problem/2030/B

#include <bits/stdc++.h>
using namespace std;

int ntests, n;

void solve()
{
    cin >> n;

    cout << 1;
    for(int i = 2; i <= n; i++)
        cout << 0;
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