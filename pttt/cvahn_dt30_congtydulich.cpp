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

const int N = 1e5 + 25, INF = 1e17 + 11;
int n, m, servedCustom = 0, totalCustomers = 0;
vector<pair<int, int>> travel;

void Read()
{
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        int k, t;
        cin >> k >> t;

        totalCustomers += k;
        travel.push_back({t, k / t});

        if(k % t != 0)
            travel.push_back({k % t, 1});
    }
}

void Solve()
{
    sort(travel.rbegin(), travel.rend());

    for(int i = 0; i < travel.size(); i++)
    {
        if(n == 0)
            break;

        int tmp = min(travel[i].second, n);
        servedCustom += travel[i].first * tmp;
        n -= tmp;
    }

    cout << totalCustomers - servedCustom;
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("Bai2.inp","r",stdin);
    freopen("Bai2.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
