#include <bits/stdc++.h>
#define int long long 
using namespace std;

int a, b, c;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Timsom.inp","r",stdin);
    freopen("Timsom.out","w",stdout);

    cin >> a >> b >> c;

    cout << (((a + b) % c == 0) ? 0 : c - (a + b) % c);

    return 0;
}
