#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 16;
int lp[N], q, n, res;
vector<int> prime;

void sieve()
{
    for(int i = 2; i <= (int)1e7; i++)
    {
        if(lp[i] == 0)
        {
            lp[i] = i;
            prime.push_back(i);
        }

        for(int j = 0; j < prime.size() && prime[j] <= lp[i] && prime[j] * i <= (int)1e7; j++)
            lp[prime[j] * i] = prime[j];
    }
}

int extract(int k)
{
    if(k == 1)
        return 1;
    
    int res = 1, cnt = 1, last = lp[k];
    k /= lp[k];

    while (k != 1)
    {
        if(last != lp[k])
        {
            res *= (cnt + 1);
            last = lp[k];
            cnt = 1;
        }
        else
            cnt++;

        k /= lp[k];
    }
    
    res *= (cnt + 1);

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("NUANT.inp","r",stdin);
    freopen("NUANT.out","w",stdout);

    sieve();

    cin >> n;
    
    for(int i = 6; i <= n; i++)
    {
        if(extract(i) == 4)
            res++;
    }

    cout << res;
    
    return 0;
}
