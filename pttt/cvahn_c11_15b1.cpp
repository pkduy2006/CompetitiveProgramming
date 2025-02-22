// author: August9th

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

int k, res;

bool check(int x)
{
    string tmp = to_string(x);
    reverse(tmp.begin(), tmp.end());
    int y = stoi(tmp);

    return __gcd(x, y) == 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai1.inp","r",stdin);
    freopen("Bai1.out","w",stdout);

    cin >> k;
    
    for(int i = 1; i <= k; i++)
    {
        if(check(i))
            res++;
    }

    cout << res;

    return 0;
}
