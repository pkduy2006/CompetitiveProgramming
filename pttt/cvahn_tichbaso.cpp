#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 25;
int n, res = -1, mark[N];
vector<int> prime, mprime;

void Build()
{
    for(int i = 2; i <= N; i++)
        mark[i] = i;

    for(int i = 2; i <= sqrt(N); i++)
    {
        if(mark[i] == i)
        {
            for(int j = i * i; j <= N; j += i)
                mark[j] = i;
        }
    }

    for(int i = 2; i <= N; i++)
    {
        if(mark[i] == i)
            prime.push_back(i);
    }

    for(int i = 0; i < prime.size() - 2; i++)
        mprime.push_back(prime[i] * prime[i + 1] * prime[i + 2]);
}

void Read()
{
    cin >> n;
}

void Solve()
{
    int l = 0, r = mprime.size() - 1;

    while(l <= r)
    {
        int mid = (l + r) / 2;

        if(mprime[mid] <= n)
        {
            res = mprime[mid];
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    cout << res << '\n';
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("tichbaso.inp","r",stdin);
    freopen("tichbaso.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Build();

    int ntests;
    cin >> ntests;
    while(ntests--)
    {
        Read();

        Solve();
    }

    return 0;
}
