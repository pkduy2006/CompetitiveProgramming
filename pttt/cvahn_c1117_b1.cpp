#include <bits/stdc++.h>
using namespace std;

int n, res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CAU1.INP","r",stdin);
    freopen("CAU1.OUT","w",stdout);

    cin >> n;
    
    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            res++;

            if(i * i != n)
                res++;
        }
    }

    cout << res;

    return 0;
}
