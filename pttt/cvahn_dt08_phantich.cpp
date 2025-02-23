#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>

typedef long long ll;

const int N = 1e5 + 5;
const ll oo = 1e9;
const int MOD = 1e9 + 7;

int cnt, j, i, a[N], d, dem, dmax =-oo, vt, dm;
bool check, b[N];
vector<int> v, prime;
map<int, int> m;


void sieve()
{
    int square = sqrt(N);
    for (int i = 2; i <= N; i++)
        if (!b[i])
            for (int j = i * i; j <= N; j += i)
                b[j] = 1;
    for (int i = 2; i <= N; i++)
        if (!b[i]) prime.push_back(i);
}
main()
{
    freopen("PHANTICH.inp","r",stdin);
    freopen("PHANTICH.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    int n; cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int k = i, j = 0;
        while (k > 1)
        {
            if (k % prime[j] == 0)
            {
                m[prime[j]]++;
                k /= prime[j];
            }
            else j++;
        }
    }
    for (auto i = m.begin(); i != m.end(); i++)
        cout << (*i).fi << " " << (*i).se << '\n';

}



/*
8 10
3 5 -7 4 2 3 -5 6
*/
