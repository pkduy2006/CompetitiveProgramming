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
string s;
int n, dp[N][N], res = 0, first = 0, last = 0;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("xaugandx.inp","r",stdin);
    freopen("xaugandx.out","w",stdout);

    cin >> s;
    n = s.size();
    s = ' ' + s;

    for(int i = n; i >= 1; i--)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i >= j)
                continue;

            if(s[i] != s[j])
                dp[i][j] = dp[i + 1][j - 1] + 1;
            else
                dp[i][j] = dp[i + 1][j - 1];

            if(dp[i][j] == 1 || dp[i][j] == 0)
            {
                if(j - i + 1 > res)
                {
                    first = i;
                    last = j;
                    res = j - i + 1;
                }
            }
        }
    }

    cout << dp[1][n] << '\n' << res << '\n';
    for(int i = first; i <= last; i++)
        cout << s[i];

    return 0;
}
