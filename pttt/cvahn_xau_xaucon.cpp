#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string x, y;
    cin >> x >> y;
    x += x.substr(0, y.size() - 1);
    bool check = true;
    for(int i = 0; i < x.size() - y.size() + 1; i++)
    {
        if(y == x.substr(i, y.size()))
        {
            cout << i + 1 << ' ';
            check = false;
        }
    }
    if(check == true)
        cout << 0;
    return 0;
}
