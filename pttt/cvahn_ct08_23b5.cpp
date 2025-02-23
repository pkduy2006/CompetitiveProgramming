#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 16;
int m, n, t, a[N][N], res;
bool mark[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DICHUYENCAY.inp","r",stdin);
    freopen("DICHUYENCAY.out","w",stdout);

    cin >> m >> n >> t;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }

    for(int i = 1; i <= m; i++)
    {
        int cnt = 1, value;
        for(int j = 1; j <= n; j++)
        {
            if(j == 1)
            {
                while (a[i][j] == 0 && j <= n)
                    j++;
                value = a[i][j];
                j++;
            }
            
            //cout << i << ' ' << j << ' ' << value << '\n';
            if(a[i][j] == value)
                cnt++;
            else
            {
                if(cnt >= t)
                {
                    for(int k = j - 1; k >= j - cnt; k--)
                        mark[i][k] = true;
                }
                cnt = 1;
                while (a[i][j] == 0 && j <= n)
                    j++;
                
                value = a[i][j];
            }

            if(j == n && cnt >= t)
            {
                for(int k = j; k >= j - cnt + 1; k--)
                    mark[i][k] = true;
            }
        }
    }

    for(int j = 1; j <= n; j++)
    {
        int cnt = 1, value;
        for(int i = 1; i <= m; i++)
        {
            if(i == 1)
            {
                while (a[i][j] == 0 && i <= m)
                    i++;
                value = a[i][j];
                i++;
            }

            //if(j == 5)
             //   cout << i << ' ' << value << '\n';

            if(a[i][j] == value)
                cnt++;
            else
            {
                if(cnt >= t)
                {
                    for(int k = i - 1; k >= i - cnt; k--)
                        mark[k][j] = true;
                }
                cnt = 1;
                while (a[i][j] == 0 && i <= m)
                    i++;
                value = a[i][j];            
            }

            if(i == m && cnt >= t)
            {
                for(int k = i; k >= i - cnt + 1; k--)
                    mark[k][j] = true;
            }
        }
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(!mark[i][j] && a[i][j])
                res++;
        }
    }

    cout << res;

    return 0;
}
