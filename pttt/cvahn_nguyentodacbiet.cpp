#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e6 + 25;
bool mark[N];
vector<int> prime;
int l, r;

int sum(int n)
{
    int ans = 0;
    while(n > 0)
    {
        ans += n % 10;
        n /= 10;
    }

    return ans;
}

void Build()
{
    mark[1] = true;
    mark[0] = true;
    for(int i = 2; i <= sqrt(N); i++)
    {
        if(!mark[i])
        {
            for(int j = i * i; j <= N; j+=i)
                mark[j] = true;
        }
    }

    for(int i = 2; i <= N; i++)
    {
        if(!mark[i] && sum(i) % 5 == 0)
            prime.push_back(i);
    }
}

void Read()
{
    cin >> l >> r;
}

void Solve()
{
    int res = 0;
    for(int i = 0; i < prime.size(); i++)
    {
        if(l <= prime[i] && prime[i] <= r)
            res++;
    }
    cout << res << '\n';
}

main()
{
    freopen("sprime.inp","r",stdin);
    freopen("sprime.out","w",stdout);
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
