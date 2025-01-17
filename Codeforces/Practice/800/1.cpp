// Codeforces Round 977 (Div. 2, based on COMPFEST 16 - Final Round) A. Meaning Mean
// https://codeforces.com/problemset/problem/2021/A
// 14/50

#include <bits/stdc++.h>
using namespace std;

const int N = 57;
int a[N], n, ntests, res;

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);
    res = (a[1] + a[2]) / 2;
    for(int i = 3; i <= n; i++)
        res = (res + a[i]) / 2;
    cout << res << '\n';
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