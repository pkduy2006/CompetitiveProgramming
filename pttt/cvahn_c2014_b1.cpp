#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;
    int GCD = __gcd(abs(a), b);
    
    if(a != 0)
        cout << a / GCD << ' ' << b / GCD;
    else
        cout << a << ' ' << b;

    return 0;
}
