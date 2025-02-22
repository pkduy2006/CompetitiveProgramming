#include <bits/stdc++.h>
using namespace std;

string a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("XAUCON.inp","r",stdin);
    freopen("XAUCON.out","w",stdout);
    
    cin >> a >> b;
    a += a;

    for(int i = 0; i < a.size() / 2; i++)
    {
        string tmp = a.substr(i, b.size());
        if(tmp == b)
            cout << i + 1 << ' ';
    }

    return 0;
}
