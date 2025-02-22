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

const int N = 1e3 + 11, MAXSNT = 1e6 + 11;
int n, a[N], mark[MAXSNT];
string ans = "1";

void extract(int x)
{
    int t = x;

    for(int i = 2; i <= sqrt(x); i++)
    {
        if(t % i == 0)
        {
            int num = 0;

            while(t % i == 0)
            {
                t /= i;
                num++;
            }

            mark[i] = max(mark[i], num);
        }
    }

    if(t > 1)
        mark[t] = max(1ll, mark[t]);
}

string big_multiply(string x, string y)
{
    int d1 = 0, d2 = 0, res[N], d[N], c[N];
    fill(res, res + N, 0);
    fill(c, c + N, 0);
    fill(d, d + N, 0);

    for(int i = x.size() - 1; i >= 0; i--)
        c[++d1] = x[i] - '0';
    for(int i = y.size() - 1; i >= 0; i--)
        d[++d2] = y[i] - '0';

    for(int i = 1; i <= d1; i++)
    {
        for(int j = 1; j <= d2; j++)
        {
            int tmp = c[i] * d[j];

            res[i + j - 1] += tmp;
            res[i + j] += res[i + j - 1] / 10;
            res[i + j - 1] %= 10;
        }
    }

    int len = (res[d1 + d2]) ? d1 + d2 : d1 + d2 - 1;
    string answer = "";
    for(int i = len; i >= 1; i--)
        answer += (res[i] + '0');

    return answer;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai1.inp","r",stdin);
    freopen("Bai1.out","w",stdout);
    //freopen("input.txt","r",stdin);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];

        extract(a[i]);
    }

    for(int i = 2; i <= 1000000; i++)
    {
        if(mark[i] != 0)
        {
            while(mark[i] > 0)
            {
                ans = big_multiply(ans, to_string(i));
                mark[i]--;
            }
        }
    }

    cout << ans;

    return 0;
}
