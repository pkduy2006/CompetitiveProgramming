//Codeforces Round 982 (Div. 2) A. Rectangle Arrangement
//https://codeforces.com/problemset/problem/2027/A
//10/50

#include <bits/stdc++.h>
using namespace std;

const int N = 107;
int ntests, n, w[N], h[N];

void solve()
{   
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> w[i] >> h[i];

    cout << 2 * (*max_element(w + 1, w + 1 + n) + *max_element(h + 1, h + 1 + n)) << '\n';
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