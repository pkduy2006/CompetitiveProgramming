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

const int N = 5e3 + 16;
int n, len[N];
pair<int, int> a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai3.inp","r",stdin);
    freopen("Bai3.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
         cin >> a[i].first >> a[i].second;

    sort(a + 1, a + 1 + n);

    len[1] = a[1].second - a[1].first;
    for(int i = 2; i <= n; i++)
    {
        len[i] = a[i].second - a[i].first;
        for(int j = 1; j < i; j++)
        {
            if(a[j].second >= a[i].first)
                len[i] = max(len[i], len[j] + a[i].second - a[j].second);
        }

    }

    cout << *max_element(len + 1, len + 1 + n);

    return 0;
}
