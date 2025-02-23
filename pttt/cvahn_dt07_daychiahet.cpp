#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, res, idx = 0;
vector<int> num;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("dchiahet.inp","r",stdin);
    freopen("dchiahet.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        if(num.size() == idx)
        {
            if(num.size() == 0)
                res = 1;
            else
                res = num.back() + 1;
            idx++;
            while (res % idx != 0)
                res++;
            num.clear();
            num.push_back(res);
        }
        else 
        {
            int x = num.back();
            x += idx;
            num.push_back(x);
        }
    }   

    cout << num.back();

    return 0;
}
