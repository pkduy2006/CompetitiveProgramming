#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1e5;
int a, b, c, res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai1.inp","r",stdin);
    freopen("Bai1.out","w",stdout);

    cin >> a >> b >> c;
    for(int x = 1; x <= LIMIT; x++)
    {
        if((c - a * x) % b == 0)
        {
            int y = (c - a * x) / b;
            if(__gcd(x, y) == 1 && y > 0)
                res++;
        } 
    }

    cout << res;

    return 0;
}
