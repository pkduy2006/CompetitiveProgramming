#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CAU1.INP","r",stdin);
    freopen("CAU1.OUT","w",stdout);

    cin >> n;

    if(n % 2 == 0)
    {
        cout << n / 2;

        return 0;
    }

    for(int i = 3; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            cout << n / i;
            break;
        }
    }

    return 0;
}
