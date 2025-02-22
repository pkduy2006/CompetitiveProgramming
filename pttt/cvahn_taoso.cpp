#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<string> prime;

bool cmp(string x, string y)
{
    return x + y > y + x;
}

void extract(int m)
{
    int t = m;
    for(int i = 2; i <= sqrt(m); i++)
    {
        while(t % i == 0)
        {
            string h = to_string(i);
            prime.push_back(h);
            t /= i;
        }
    }

    if(t != 1)
        prime.push_back(to_string(t));
}

void Read()
{
    cin >> n;
}

void Solve()
{
    extract(n);

    sort(prime.begin(), prime.end(), cmp);

    for(int i = 0; i < prime.size(); i++)
        cout << prime[i];
}

main()
{
    freopen("Taoso.inp","r",stdin);
    freopen("Taoso.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
