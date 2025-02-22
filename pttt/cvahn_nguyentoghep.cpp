#include <bits/stdc++.h>
#define int long long
using namespace std;

int k;
const int N = 2e5 + 25;
bool mark[N];
vector<int> prime, SPrime;

bool check(int m)
{
    if(m < 2)
        return false;

    for(int i = 2; i <= sqrt(m); i++)
    {
        if(m % i == 0)
            return false;
    }

    return true;
}

void Build()
{
    mark[1] = true;
    mark[0] = true;

    for(int i = 2; i <= sqrt(N); i++)
    {
        if(mark[i] == false)
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

    for(int i = 0; i < prime.size(); i += 2)
    {
        string a = to_string(prime[i]), b = to_string(prime[i + 1]);
        string r = a + b;
        int cnt = 1, c = 0;

        for(int i = r.size() - 1; i >= 0; i--)
        {
            c += (cnt * (r[i] - '0'));
            cnt *= 10;
        }

        if(check(c))
            SPrime.push_back(c);
    }
}

void Read()
{
    cin >> k;
}

void Solve()
{
    Build();

    cout << SPrime[k - 1];
}

main()
{
    freopen("Ngtoghep.inp","r",stdin);
    freopen("Ngtoghep.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
