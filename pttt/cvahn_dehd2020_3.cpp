#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;

bool check_prime(int val)
{
    if(val < 2)
        return false;

    for(int i = 2; i <= sqrt(val); i++)
    {
        if(val % i == 0)
            return false;
    }

    return true;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int x = sqrt(n);
    while(true)
    {
        if(check_prime(x))
        {
            cout << x * x;
            return 0;
        }
        x++;
    }

    return 0;
}
