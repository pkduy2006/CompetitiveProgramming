#include <bits/stdc++.h>
#define int long long
using namespace std;

int a, b;

int power(int t, int m)
{
    if(m == 0)
        return 1;

    int c = power(t, m / 2);

    if(m % 2 == 0)
        return c * c;
    return c * c * t;
}

void Read()
{
    cin >> a >> b;
}

void Solve()
{
    int x = 1;
    while((power(10, x) * a + b) % 89 != 0)
        x++;

    cout << (power(10, x) * a + b) / 89;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
