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
using namespace std;

long long n, res;
bool check(long long k)
{
    if(k < 2)
        return false;

    for(long long i = 2; i <= sqrt(k); i++)
    {
        if(k % i == 0)
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("uocnt.inp","r",stdin);
    freopen("uocnt.out","w",stdout);

    cin >> n;
    for(long long i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            if(check(i))
                res = max(res, i);
            
            if(i * i != n)
            {
                if(check(n / i))
                    res = max(res, n / i);
            }
        }
    }
    cout << res;

    return 0;
}
