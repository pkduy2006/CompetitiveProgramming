#include <bits/stdc++.h>
using namespace std;

double a, b, c, d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("TBS.inp","r",stdin);
    freopen("TBS.out","w",stdout);

    cin >> a >> b >> c >> d;

    if(a * b * c * d == 0)
        cout << 0;
    else if(a * b * c * d < 0)
        cout << -1;
    else
        cout << 1;

    return 0;
}
