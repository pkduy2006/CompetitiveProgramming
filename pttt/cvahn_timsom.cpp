#include <bits/stdc++.h>
#define int long long
using namespace std;

int a, b, c;

void Read()
{
    cin >> a >> b >> c;
}

void Solve()
{
    if((a + b) % c == 0)
        cout << 0;
    else
        cout << c - (a + b) % c;
}

main()
{
    freopen("Timsom.inp","r",stdin);
    freopen("Timsom.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
