#include <bits/stdc++.h>
using namespace std;

long long a, b;

namespace sub1
{
    int res = 0;

    bool check(long long x)
    {
        while (x > 0)
        {
            if(x % 10 == 4 || x % 10 == 7)
                return false;

            x /= 10;
        }
        
        return true;
    }
    
    void solve()
    {
        for(long long i = a; i <= b; i++)
        {
            if(check(i))
                res++;
        }

        cout << res;
    }
}

namespace sub2
{
    vector<int> convert(long long x)
    {
        vector<int> ans;

        while (x > 0)
        {
            ans.push_back(x % 10);
            x /= 10;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    long long cnt(long long x)
    {
        vector<int> num = convert(x);
        long long f[25][2];
        memset(f, 0ll, sizeof f);
        f[0][0] = 1ll;

        for(int i = 0; i < num.size(); i++)
        {
            for(int already = 0; already <= 1; already++)
            {
                for(int digit = 0; digit <= 9; digit++)
                {
                    if(digit > num[i] && !already)
                        break;
                    
                    if(digit == 4 || digit == 7)
                        continue;

                    f[i + 1][already || (num[i] > digit)] += f[i][already];  
                }
            }
        }

        return f[num.size()][1] + f[num.size()][0];
    }

    void solve()
    {
        cout << cnt(b) - cnt(a - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("NO47.inp","r",stdin);
    freopen("NO47.out","w",stdout);
    
    cin >> a >> b;

    if(b - a <= (int)1e8)
        sub1::solve();
    else
        sub2::solve();

    return 0;
}
