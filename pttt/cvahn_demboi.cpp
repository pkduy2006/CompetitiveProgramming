#include <bits/stdc++.h>
#define int long long
using namespace std;

int l, r, a, b;

void Read()
{
    cin >> l >> r >> a >> b;
}

void Solve()
{
    int f = (a * b) / __gcd(a, b);
    int c = l / a, d = l / b, e = l / f;
    if(l % a != 0)
        c++;

    if(l % b != 0)
        d++;

    if(l % f != 0)
        e++;

    if(a % b == 0)
        cout << r / b - d + 1 << '\n';
    else if(b % a == 0)
        cout << r / a - c + 1 << '\n';
    else
        cout << r / a - c + 1 + r / b - d + 1 - r / f + e - 1  << '\n';
}

main()
{
    freopen("Demboi.inp","r",stdin);
    freopen("Demboi.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ntests;
    cin >> ntests;
    while(ntests--)
    {
        Read();

        Solve();
    }

    return 0;
}
