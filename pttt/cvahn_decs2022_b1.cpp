#include <bits/stdc++.h>
#define int long long
using namespace std;

double s1, s2, v1, v2;

void Read()
{
    cin >> s1 >> v1 >> s2 >> v2;
}

void Solve()
{
    if(v1 == v2)
    {
        cout << -1;
        return;
    }

    double t = (s2 - s1) / (v1 - v2);

    if(t > 0)
        cout << (int)t;
    else
        cout << -1;

}

main()
{
    freopen("DRB.inp","r",stdin);
    freopen("DRB.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
