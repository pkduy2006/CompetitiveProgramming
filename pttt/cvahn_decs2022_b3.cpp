#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 25;
int x, y, z;

void Read()
{
    cin >> x >> y >> z;
}

void Solve()
{
    int t = (z * x) / y;

    if((z * x) % y != 0)
        t++;

    while(z > 0)
    {
        if(t * y >= z * x)
        {
            t--;
            z--;
        }
        else
            break;
    }

    cout << t;
}

main()
{
    freopen("TBG.inp","r",stdin);
    freopen("TBG.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
