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

const int N = 3e3 + 11;
int a, b, m, n;
char c[N], d[N];
string result;

string big_multiply(string x, string y)
{
    int d1 = 0, d2 = 0, res[N];
    fill(res, res + N, 0);

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
    //freopen("input.txt","r",stdin);
    freopen("tichdoanso.inp","r",stdin);
    freopen("tichdoanso.out","w",stdout);

    cin >> a >> b >> m >> n;

    result = to_string(a);

    for(int i = a + 1; i <= b; i++)
    {
        string t = to_string(i);

        result = big_multiply(result, t);
    }


    for(int i = 0; i < m; i++)
        cout << result[i];
    cout << ' ';
    for(int i = result.size() - n; i <= result.size() - 1; i++)
        cout << result[i];

    return 0;
}
