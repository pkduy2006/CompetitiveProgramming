#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e8;
vector<int> prime;
int n;
bool mark[N];

bool check(int m)
{
    for(int i = 2; i <= sqrt(m); i++)
    {
        if(m % i == 0)
            return false;
    }

    return true;
}

void Read()
{
    cin >> n;
}

void Solve()
{
    bool review = false;
    for(int i = 3; i <= sqrt(n); i++)
    {
        if(check(i) && check(i * i + 4) && i * i + 4 <= n)
        {
            review = true;
            cout << 2 << ' ' << i << ' ' << i * i + 4 << '\n';
        }
    }
    if(!review)
        cout << -1;
}

main()
{
    freopen("Bobaso.inp","r",stdin);
    freopen("Bobaso.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
