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

const int N = 1e5 + 11, INF = 1e17 + 11;
int ntests, n, a[N], dp[N]; // số điểm lớn nhất đạt được khi xóa đoạn từ 1 đến i

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

void Solve()
{
    fill(dp, dp + N, 0);

    for(int i = n; i >= 1; i--)
    {
        int x = a[i] + min({dp[i + 2], dp[i + 3], dp[i + 4]});
        int y = a[i] + a[i + 1] + min({dp[i + 3], dp[i + 4], dp[i + 5]});
        int z = a[i] + a[i + 1] + a[i + 2] + min({dp[i + 4], dp[i + 5], dp[i + 6]});

        dp[i] = max({x, y, z});
    }

    cout << dp[1]  << '\n';
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("BRICKS.inp","r",stdin);
    freopen("BRICKS.out","w",stdout);

    cin >> ntests;
    while(ntests--)
    {
        Read();

        Solve();
    }

    return 0;
}
