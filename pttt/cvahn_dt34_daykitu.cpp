#include <bits/stdc++.h>
#define int long long 
using namespace std;

int n;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DKT.inp","r",stdin);
    freopen("DKT.out","w",stdout);

    cin >> n;
    cout << char((n * (n + 1) / 2) % 26 + 'A');

    return 0;    
}
