#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[127][128], mark[129], win[130], lose[131], draw[132];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 1;
    cin >> n;
    for(int i = 1 ; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            mark[i] += a[i][j];
            if(a[i][j] == 3)
                win[i] ++;
            if(a[i][j] == 0 && i != j)
                lose[i] ++;
            if(a[i][j] == 1)
                draw[i] ++;
        }
        if(mark[i] > mark[ans])
            ans = i;
    }
    for(int i = 1; i <= n; i++)
    {
        if(mark[i] == mark[ans])
            cout << i << ' ' <<  mark[i] << ' ' <<  win[i] << ' ' << draw[i] << ' ' << lose[i] << '\n';
    }
    bool check = false;
    for(int i = 1; i <= n; i++)
    {
        if(win[i] > lose[i])
        {
            cout << i << ' ';
            check = true;
        }
    }
    if(check == false)
        cout << 0;
    cout << '\n';
    bool checkJr = false;
    for(int i = 1; i <= n; i++)
    {
        if(lose[i] == 0)
        {
            cout << i << ' ';
            checkJr = true;
        }
    }
    if(checkJr == false)
        cout << 0;
    return 0;
}
