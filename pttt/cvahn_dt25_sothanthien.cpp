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

int n, res = 0;

bool check(int t)
{
    int tmp = 0, cnt = 1, b = t;
    vector<int> digit;

    while(t > 0)
    {
        digit.push_back(t % 10);
        t /= 10;
    }

    for(int i = digit.size() - 1; i >= 0; i--)
    {
        tmp += digit[i] * cnt;
        cnt *= 10;
    }

    return __gcd(tmp, b) == 1;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Sothanthien.inp","r",stdin);
    freopen("Sothanthien.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        if(check(i))
            res++;
    }

    cout << res;

    return 0;
}
