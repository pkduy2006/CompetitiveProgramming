#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define int long long
using namespace std;

int ntests, m, n;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("COORDINATE.inp","r",stdin);
    freopen("COORDINATE.out","w",stdout);

    cin >> ntests >> m >> n;
    while(ntests--)
    {
        int type;
        cin >> type;

        if(type == 1)
        {
            int x, y;
            cin >> x >> y;

            cout << n * (x - 1) + y << '\n';
        }
        else
        {
            int value;
            cin >> value;

            int y = value % n, x = value / n;

            if(y == 0)
                cout << x << ' ' << n << '\n';
            else
                cout << x + 1 << ' ' << y << '\n';
        }
    }

    return 0;
}
