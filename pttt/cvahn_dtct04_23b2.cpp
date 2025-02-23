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

const int N = 1e3 + 16;
int n, h, a[N], milestone, res = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Chianhom.inp","r",stdin);
    freopen("Chianhom.out","w",stdout);

    cin >> n >> h;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);
    
    milestone = a[1] + h;
    for(int i = 2; i <= n; i++)
    {
        if(a[i] > milestone)
        {
            res++;
            milestone = a[i] + h;
        }
    }

    cout << res;

    return 0;
}
