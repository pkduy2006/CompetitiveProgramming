#include <bits/stdc++.h>
using namespace std;

int n;
map<string, int> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("timxau.inp","r",stdin);
    freopen("timxau.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string x;
        cin >> x;
        s[x]++;
    }

    for(auto it : s)
    {
        if(it.second % 2 == 1)
        {   
            cout << it.first;
            break;
        }
    }

    return 0;
}
