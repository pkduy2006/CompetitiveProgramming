//Codeforces Round 979 (Div. 2) A. A Gift From Orangutan
//https://codeforces.com/problemset/problem/2030/A

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int ntests, a[N], n;

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    cout << (n - 1) * (*max_element(a + 1, a + 1 + n) - *min_element(a + 1, a + 1 + n)) << '\n';
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