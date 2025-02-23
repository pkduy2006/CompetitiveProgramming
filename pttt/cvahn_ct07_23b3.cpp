#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 16;
string x, y, res, f[N][N];

string comparison(string a, string b)
{
    while (a.size() < b.size())
        a = '0' + a;
    while (b.size() < a.size())
        b = '0' + b;
    
    if(a >= b)
        return a;
    return b;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("number.inp","r",stdin);
    freopen("number.out","w",stdout);

    cin >> x >> y;

    int a = x.size(), b = y.size();
    x = ' ' + x;
    y = ' ' + y;

    for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= b; j++)
        {
            if(x[i] == y[j])
                f[i][j] = f[i - 1][j - 1] + x[i];
            else
                f[i][j] = comparison(f[i - 1][j], f[i][j - 1]);
        }
    }
    
    while (f[a][b][0] == '0' && f[a][b].size() > 1)
        f[a][b].erase(0, 1);
    
    cout << f[a][b]; 

    return 0;
}
