#include <bits/stdc++.h>
using namespace std;

int n;
set<string> a;
string s;

void ss(string x)
{
    if(x.size() == n)
    {
        a.insert(x);
        return;
    }

    if(x.back() == 'A')
    {
        ss(x + 'B');
        ss(x + 'A');
    }
    else
    {
        x += 'A';
        ss(x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Taoxau.inp","r",stdin);
    freopen("Taoxau.out","w",stdout);

    cin >> n;

    s = "A";
    ss(s);
    s = "B";
    ss(s);

    for(auto it = a.begin(); it != a.end(); it++)
        cout << *(it) << '\n';

    return 0;
}
