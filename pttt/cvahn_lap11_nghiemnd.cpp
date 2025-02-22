#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("nghiemnd.inp","r",stdin);
    freopen("nghiemnd.out","w",stdout);

    cin >> a >> b >> c >> d;
    for(int x = 1; x * a <= d - b - c; x++)
    {
        for(int y = 1; y * b <= d - a * x - c; y++)
        {
            int z = (d - y * b - x * a) / c;
            if(z > 0 && x * a + y * b + z * c == d)
                res++;
        }
    }

    cout << res;

    return 0;
}
