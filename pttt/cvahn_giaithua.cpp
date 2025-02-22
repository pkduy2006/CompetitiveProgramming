#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 25;
int n, cnt[N], res = 0;
bool mark[N];
vector<int> prime;

void Build()
{
    mark[0] = true;
    mark[1] = true;

    for(int i = 2; i <= N; i++)
    {
        if(!mark[i])
        {
            for(int j = i * i; j <= N; j += i)
                mark[j] = true;
        }
    }

    for(int i = 2; i <= N; i++)
    {
        if(!mark[i])
            prime.push_back(i);
    }
}

void Read()
{
    cin >> n;

    Build();
}

void Solve()
{
    for(int i = 2; i <= n; i++)
    {
        int t = i;

        for(int j = 0; j < prime.size(); j++)
        {

            while(t % prime[j] == 0)
            {
                cnt[prime[j]]++;
                t /= prime[j];
                res = max(res, prime[j]);
            }
        }
    }

    for(int i = 2; i <= res; i++)
    {
        if(cnt[i] != 0 && mark[i] == false)
            cout << cnt[i] << ' ';
    }
}

main()
{
    freopen("GIAITHUA.inp","r",stdin);
    freopen("GIAITHUA.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
