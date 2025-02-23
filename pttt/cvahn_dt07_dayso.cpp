#include <bits/stdc++.h>
#define int long long
using namespace std;

int k;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Dayso.inp","r",stdin);
    freopen("Dayso.out","w",stdout);

    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;

        cout << (((n + 1) % 10) * ((n + 1) % 10)) % 10 << '\n';
    }
    
    return 0;
}
