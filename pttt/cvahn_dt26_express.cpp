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

const int N = 1e3 + 11;
int n, a[N], posFirst, posSecond, tmp = 0, posMid = -1, res = 0;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("express.inp","r",stdin);
    freopen("express.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n - 3; i++)
    {
        for(int j = i + 2; j <= n - 1; j++)
        {
            if(a[i] * a[i + 1] + a[j] * a[j + 1] > tmp)
            {
                posFirst = i;
                posSecond = j;
                tmp = a[i] * a[i + 1] + a[j] * a[j + 1];
            }
        }
    }

    for(int i = 1; i <= n - 2; i++)
    {
        if(a[i] * a[i + 1] * a[i + 2] > tmp)
        {
            tmp = a[i] * a[i + 1] * a[i + 2];
            posMid = i;
        }
    }

    if(posMid == -1)
    {
        for(int i = 1; i <= n; i++)
        {
            if(posFirst == i || posSecond == i)
            {
                res += a[i] * a[i + 1];
                i++;
            }
            else
                res += a[i];
        }
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            if(posMid == i)
            {
                res += a[i] * a[i + 1] * a[i + 2];
                i += 2;
            }
            else
                res += a[i];
        }
    }

    cout << res;

    return 0;
}
