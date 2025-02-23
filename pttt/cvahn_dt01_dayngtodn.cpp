#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 16;
bool mark[N];
int n, a[N], c, res;
vector<int> ans;

bool check(int x)
{
    if(x < 2)
        return false;

    for(int i = 2; i <= sqrt(x); i++)
    {
        if(x % i == 0)
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("dayconnt.inp","r",stdin);
    freopen("dayconnt.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++)
    {
       if(check(a[i]))
        {
            int cnt = 1;
            for(int j = i + 1; j <= n; j++)
            {
                if(check(a[j]))
                    cnt++;
                else
                    break;
            }

            if(res < cnt)
            {
                res = cnt;
                c = 1;
                ans.clear();
                for(int j = i; j <= i + res - 1; j++)
                    ans.push_back(a[j]);
            }
            else if(res == cnt)
                c++;
        }
    }

    cout << c << ' ' << res << '\n';
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';

    return 0;
}
