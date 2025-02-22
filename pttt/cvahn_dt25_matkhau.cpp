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

string s;
int n, res = 0;

bool check(int l, int r)
{
    bool N = false, L = false, U = false;

    for(int i = l; i <= r; i++)
    {
        if('A' <= s[i] && s[i] <= 'Z')
            L = true;

        if('a' <= s[i] && s[i] <= 'z')
            U = true;

        if('0' <= s[i] && s[i] <= '9')
            N = true;
    }

    return L == true && U == true && N == true;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("matkhau.inp","r",stdin);
    freopen("matkhau.out","w",stdout);
    //freopen("input.txt","r",stdin);

    cin >> s;
    n = s.size();

    for(int i = 0; i <= n - 6; i++)
    {
        for(int j = i + 5; j <= n - 1; j++)
        {
            if(check(i, j))
            {
                res += n - j;

                break;
            }
        }
    }

    cout << res;

    return 0;
}
