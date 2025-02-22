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

const int N = 1e6 + 11;
int s, n, k, a[N];
vector<int> digit;

int power(int x, int y)
{
    if(y == 0)
        return 1;

    int c = power(x, y / 2);

    if(y % 2 == 0)
        return c * c;
    else
        return c * c * x;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DIGIT.INP","r",stdin);
    freopen("DIGIT.OUT","w",stdout);

    cin >> s >> n >> k;

    while(s > 0)
    {
        digit.push_back(s % 10);
        s /= 10;
    }
    reverse(digit.begin(), digit.end());

    int m = digit.size();
    if(m * power(2, n) < k)
    {
        cout << -1;
        return 0;
    }

    int t = k / m;
    int r = k % m;

    if(r != 0)
    {
        t++;
        if(t % 2 == 0)
            reverse(digit.begin(), digit.end());

        cout << digit[r - 1];
    }
    else
    {
        if(t % 2 == 0)
            reverse(digit.begin(), digit.end());

        cout << digit.back();
    }

    return 0;
}
