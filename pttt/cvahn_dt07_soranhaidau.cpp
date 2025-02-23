#include <bits/stdc++.h>
#define int long long 
using namespace std;

int a, b, factor = 100;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("serpent.inp","r",stdin);
    freopen("serpent.out","w",stdout);

    cin >> a >> b;
    while ((factor * a + b) % 89 != 0)
        factor *= 10;

    cout << (factor * a + b) / 89;

    return 0;
}
