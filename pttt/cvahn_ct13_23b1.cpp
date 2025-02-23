#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 1e6 + 16;
int t, res, n;
bool mark[M];
vector<int> prime;

void sieve()
{
    mark[1] = mark[0] = true;
    for(int i = 2; i <= sqrt((int)1e6); i++)
    {
        if(!mark[i])
        {
            for(int j = i * i; j <= (int)1e6; j += i)
                mark[j] = true;
        }
    }

    for(int i = 2; i <= (int)1e6; i++)
    {
        if(!mark[i])
            prime.push_back(i);
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("tichbaso.inp","r",stdin);
    freopen("tichbaso.out","w",stdout);

    sieve();

    cin >> t;
    while (t--)
    {
        cin >> n;

        int l = 0, r = prime.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            //cout << l << ' ' << r << '\n';
            if(prime[mid - 1] * prime[mid] * prime[mid + 1] <= n)
            {
                l = mid + 1;
                res = mid;
            }
            else
                r = mid - 1;
        }
        
        if(prime[res] * prime[res - 1] * prime[res + 1] > n)
            cout << -1 << '\n';
        else
            cout << prime[res] * prime[res - 1] * prime[res + 1] << '\n';
    }

    return 0;
}
