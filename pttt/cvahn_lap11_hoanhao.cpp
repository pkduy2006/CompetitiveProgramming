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

int l, r;

bool check(int n)
{
    int cnt = 1;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            cnt += i;
            cnt += n / i;
        }
    }

    if(cnt == n)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("hoanhao.inp","r",stdin);
   freopen("hoanhao.out","w",stdout);

    cin >> l >> r;
    /*for(int i = l + 1; i < r; i++)
    {
        if(check(i))
            cout << i << ' ';
    }
    */

   if(l < 6 && 6 < r)
        cout << 6 << ' ';
if(l < 28 && 28 < r)
        cout << 28 << ' ';
    if(l < 496 && 496 < r)
        cout << 496 << ' ';
    if(l < 8128 && 8128 < r)
        cout << 8128 << ' ';
    return 0;
}
