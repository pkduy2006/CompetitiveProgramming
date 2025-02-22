#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e5 + 16;
int n, maxX, maxY;
pair<int, int> a[N];

namespace sub1
{
    int res = 0;

    bool check(int x, int y, int z)
    {
        if(a[x].first == a[y].first && a[x].second == a[z].second)
            return true;

        return false;
    }
    
    void solve()
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                for(int k = 1; k <= n; k++)
                {
                    if(check(i, j, k) && i != j & j != k && k != i)
                        res++;
                }
            }
        }

        cout << res;
    }
}

namespace sub2
{
    int cntX[N], cntY[N], res = 0;

    void solve()
    {
        fill(cntX, cntX + N, 0);
        fill(cntY, cntY + N, 0);

        for(int i = 1; i <= n; i++)
        {
            cntX[a[i].first]++;
            cntY[a[i].second]++;
        }

        for(int i = 1; i <= n; i++)
            res += (cntX[a[i].first] - 1) * (cntY[a[i].second] - 1);
    
        cout << res;
    }
}

namespace sub3
{
    int res = 0;
    
    void solve()
    {
        map<int, int> X, Y;

        for(int i = 1; i <= n; i++)
        {   
            X[a[i].first]++;
            Y[a[i].second]++;
        }

        for(int i = 1; i <= n; i++)
            res += ((X[a[i].first] - 1) * (Y[a[i].second] - 1));

        cout << res;
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("SQT.inp","r",stdin);
    freopen("SQT.out","w",stdout);
    
    cin >> n;
    for(int i = 1; i <= n; i++)
    {   
        cin >> a[i].first >> a[i].second;
        maxX = max(maxX, a[i].first);
        maxY = max(maxY, a[i].second);
    }

    if(n <= 100)
        sub1::solve();
    else if(maxX <= (int)1e5 && maxY <= (int)1e5)
        sub2::solve();
    else
        sub3::solve();
    
    return 0;
}
