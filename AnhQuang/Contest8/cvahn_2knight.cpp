#include <bits/stdc++.h>
using namespace std;

long long n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("2KNIGHT.INP","r",stdin);
    freopen("2KNIGHT.OUT","w",stdout);
    
    cin >> n;
    for(long long i = 1; i <= n; i++)
        cout << i * i * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2) << '\n';

    return 0;
}
