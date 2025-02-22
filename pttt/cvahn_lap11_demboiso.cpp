#include <bits/stdc++.h>
using namespace std;

int k, m, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("Demboi.inp","r",stdin);
    freopen("Demboi.out","w",stdout);

    cin >> k >> m >> n;
   
    cout << n / m + n / k - n / (m * k / __gcd(m, k)); 

    return 0;
}
