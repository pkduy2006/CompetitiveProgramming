#include <bits/stdc++.h>
#define int long long
using namespace std;

set<int> a;
int n;

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a.insert(x);
    }
}

void Solve()
{
    cout << a.size();
}

main()
{
    freopen("Chude.inp","r",stdin);
    freopen("Chude.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
