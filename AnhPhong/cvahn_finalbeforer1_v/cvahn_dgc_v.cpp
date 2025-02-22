#include <bits/stdc++.h>
using namespace std;

int q, n;

void solve()
{
    if(n < 9)
    {
        cout << n << '\n';

        return;
    }

    int t = n;
    while (n % 10 != 9)
        n--;

    cout << t - ((n - 9) / 10 + 1) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DGC.inp","r",stdin);
    freopen("DGC.out","w",stdout);

    cin >> q;
    while (q--)
    {
        cin >> n;

        solve();
    }
    

    return 0;
}
