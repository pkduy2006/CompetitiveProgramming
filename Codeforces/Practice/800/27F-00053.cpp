//Codeforces Round 978 (Div. 2) A. Bus to Pénjamo
//https://codeforces.com/problemset/problem/2022/A
// 13/50

#include <bits/stdc++.h>
using namespace std;

const int N = 107;
int n, r, a[N], ntests, res, sum;

void solve()
{
    res = 0;
    sum = 0;

    cin >> n >> r;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    for(int i = 1; i <= n; i++)
    {
        res += a[i] - a[i] % 2;
        r -= (a[i] - a[i] % 2) / 2;
        a[i] %= 2;
        sum += a[i];
    }
    if(r - sum >= 0)
        res += sum;
    else
    {
        sum -= r;
        res += r - sum;
    }
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