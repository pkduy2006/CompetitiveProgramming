#include <bits/stdc++.h>
using namespace std;

long long n, f[70][2][90];
int k;

vector<int> convert(long long x)
{
    vector<int> ans;

    while(x > 0)
    {
        ans.push_back(x % 2);
        x /= 2;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("KONES.INP","r",stdin);
    freopen("KONES.OUT","w",stdout);
    
    cin >> n >> k;
    vector<int> num = convert(n);
    f[0][0][0] = 1;
    for(int i = 0; i < num.size(); i++)
    {
        for(int already = 0; already <= 1; already++)
        {
            for(int cnt = 0; cnt <= k; cnt++)
            {
                for(int add = 0; add <= 1; add++)
                {
                    if(!already && add > num[i])
                        break;

                    f[i + 1][already || num[i] > add][cnt + (add == 1)] += f[i][already][cnt];
                }
            }
        }
    }

    cout << f[num.size()][1][k] + f[num.size()][0][k];

    return 0;
}
