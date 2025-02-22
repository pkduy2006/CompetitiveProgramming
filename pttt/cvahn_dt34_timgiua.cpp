#include <bits/stdc++.h>
#define int long long 
using namespace std;

int Left, Right, res;

int sum(int x, int y)
{
    return (y - x + 1) * (x + y) / 2;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("BAI6.INP","r",stdin);
    freopen("BAI6.OUT","w",stdout);

    cin >> Left >> Right;
    
    int l = Left, r = Right, res = Right;
    while (l < r)
    {
        int mid = (l + r) / 2;

        if(abs(sum(Left, mid) - sum(mid + 1, Right)) < abs(sum(Left, res) - sum(res + 1, Right)))
            res = mid;
       
       if(sum(Left, mid) > sum(mid + 1, Right))
            r = mid;
        else
            l = mid + 1;
    }
    
    cout << res;

    return 0;
}
