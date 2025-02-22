#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 11;
bool mark[N];
int ntests;
vector<int> prime, ProductPrime;

void Build()
{
    mark[1] = true;
    mark[0] = true;
    
    for(int i = 2; i <= sqrt(N); i++)
    {
        if(!mark[i])
        {
            for(int j = i * i; j < N; j += i)
                mark[j] = true;
        }
    }

    for(int i = 2; i < N; i++)
    {
        if(!mark[i])
            prime.push_back(i);
    }

    for(int i = 0; i < prime.size() - 2; i++)
        ProductPrime.push_back({prime[i] * prime[i + 1] * prime[i + 2]});
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai4.inp","r",stdin);
    freopen("Bai4.out","w",stdout);

    Build();
    cin >> ntests;
    while (ntests--)
    {
        long long x;
        cin >> x;

        auto res = upper_bound(ProductPrime.begin(), ProductPrime.end(), x);
        int pos = upper_bound(ProductPrime.begin(), ProductPrime.end(), x) - ProductPrime.begin() - 1;

        if(res == ProductPrime.end())
            cout << -1 << '\n';
        else
            cout << ProductPrime[pos] << '\n';
    }

    return 0;
}
