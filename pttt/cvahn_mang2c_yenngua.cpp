#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1037][1038];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, n;
    bool review = false;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    for(int i = 1; i <= n; i++)
    {
        int poscol, posline, value = 0;
        bool check = true;
        for(int j = 1; j <= m; j++)
        {
            if(value < a[i][j])
            {
                value = a[i][j];
                poscol = j;
                posline = i;
            }
        }
        for(int j = 1; j <= n; j++)
        {
            if(value > a[j][poscol])
                check = false;
        }
        if(check == true)
        {
            cout << posline << ' ' << poscol << '\n';
            review = true;
        }
    }
    if(review == false)
        cout << 0;
    return 0;
}
