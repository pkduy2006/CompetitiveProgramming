#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 16;
int n, res = N;
string a[N], s;

bool check()
{
    for(int i = 0; i < s.size(); i++)
    {
        bool check = false;
        for(int j = 1; j <= n; j++)
        {
            if(s[i] == a[j][i])
            {
                check = true;
                break;
            }
        }

        if(!check)
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CAU3.INP","r",stdin);
    freopen("CAU3.OUT","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> s;

    if(!check())
    {
        cout << -1;
        return 0;
    }

    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for(int j = 0; j < s.size(); j++)
        {
            if(s[j] != a[i][j])
                cnt++;
        }

        res = min(res, cnt);
    }

    cout << res;

    return 0;
}
