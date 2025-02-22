#include <bits/stdc++.h>
using namespace std;

long long n;
int s[] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144};

namespace sub1
{
    int res = 0;

    int countDigit(int x)
    {
        int ans = 0;

        while (x > 0)
        {
            ans += x % 10;
            x /= 10;
        }
        
        return ans;
    }

    bool check(int x)
    {
        int tmp = countDigit(x);
        int a = sqrt(tmp);

        return a * a == tmp;
    }
    
    void solve()
    {
        for(int i = 1; i <= n; i++)
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

    void solve()
    {
        vector<int> num = convert(n);
        long long f[25][2][192], res = 0ll;
        memset(f, 0ll, sizeof f);
        f[0][0][0] = 1ll;

        for(int i = 0; i < num.size(); i++)
        {
            for(int already = 0; already <= 1; already++)
            {
                for(int sum = 0; sum <= 162; sum++)
                {
                    for(int digit = 0; digit <= 9; digit++)
                    {
                        if(!already && digit > num[i])
                            break;

                        f[i + 1][already || num[i] > digit][sum + digit] += f[i][already][sum];
                    }
                }
            }
        }

        for(int i = 0; i < 12; i++)
            res += f[num.size()][0][s[i]] + f[num.size()][1][s[i]];

        cout << res;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SDIGIT.inp","r",stdin);
    freopen("SDIGIT.out","w",stdout);

    cin >> n;
    
    if(n <= (int)1e6)
        sub1::solve();
    else 
        sub2::solve();

    return 0;
}
