#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 125;
int n;
string a[N];

bool cmp(string x, string y)
{
    return x + y > y + x;
}

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

void Solve()
{
    sort(a + 1, a + 1 + n, cmp);
    for(int i = 1; i <= n; i++)
        cout << a[i];
}

main()
{
    freopen("numjoin.inp","r",stdin);
    freopen("numjoin.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
