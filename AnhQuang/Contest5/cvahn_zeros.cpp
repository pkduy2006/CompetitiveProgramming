#include <bits/stdc++.h>
#define int long long 
using namespace std;

int a, b, cnt = 1, resFive = 0, resTwo = 0;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("ZEROS.inp","r",stdin);
    freopen("ZEROS.out","w",stdout);

    cin >> a >> b;

    if(a == 0)
    {
        cout << 1;
        
        return 0;
    }
    for(int i = 1; i <= 15; i++)
    {
        cnt *= 5;
        
        for(int j = cnt; j <= b; j += cnt)
        {
            if(j < a)
                continue;
            
            resFive++;
        }
    }

    cnt = 1;
    for(int i = 1; i <= 30; i++)
    {
        cnt *= 2;

        for(int j = cnt; j <= b; j += cnt)
        {
            if(j < a)
                continue;

            resTwo++;
        }
    }

    cout << min(resFive, resTwo);

    return 0;
}
