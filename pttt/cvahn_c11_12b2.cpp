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

string a, b, res;
int remembered;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai2.inp","r",stdin);
    freopen("Bai2.out","w",stdout);

    cin >> a >> b;
    
    while (a.size() < b.size())
        a = '0' + a;
    while (b.size() < a.size())
        b = '0' + b;
    for(int i = a.size() - 1; i >= 0; i--)
    {
        int digit_a = a[i] - '0', digit_b = b[i] - '0';
        int tmp = digit_a + digit_b + remembered;
        remembered = tmp / 8;
        res += (tmp % 8) + '0';
    }
    if(remembered == 1)
        res += '1';
    reverse(res.begin(), res.end());

    cout << res;

    return 0;
}
