#include <bits/stdc++.h>
using namespace std;

int n, res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while (n != 1)
    {
        if(n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
        res++;
    }
    
    cout << res;

    return 0;
}
