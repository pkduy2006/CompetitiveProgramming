#include <bits/stdc++.h>

using namespace std;
#define int long long

using namespace std;

int c[1001][1001];
string a, b, s;

void taobang()
{
    a = '@' + a;
    b = '@' + b;
    c[0][0] = 0;
    for(int  i = 1; i < a.length(); i++)
        for(int j = 1; j < b.length(); j++)
        if(a[i] == b[j]) c[i][j] = c[i - 1][j - 1] + 1;
        else c[i][j] = max(c[i - 1][j], c[i][j - 1]);
}

void truyhoi()
{
    int i = a.length() - 1, j = b.length() - 1;
    s = "";
    while(c[i][j] > 0)
    {
        if(c[i][j] == c[i - 1][j]) i--;
        else if (c[i][j] == c[i][j - 1]) j--;
        else{
            s = a[i] + s;
            i--; j--;
        }
    }
}

main()
{
    freopen("xauchung.inp","r",stdin);
    freopen("xauchung.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;
    taobang();
    truyhoi();
    cout << s;

    return 0;
}
