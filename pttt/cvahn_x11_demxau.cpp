#include <bits/stdc++.h>
using namespace std;

vector<int> res;
string a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DEMXAU.inp","r",stdin);
    freopen("DEMXAU.out","w",stdout);

    cin >> a >> b;
    for(int i = 0; i < b.size(); i++)
    {
        string tmp = b.substr(i, a.size());
        if(tmp == a)
            res.push_back(i + 1);
    }

    cout << res.size() << '\n';
    for(int i = 0; i < res.size(); i++) 
        cout << res[i] << ' ';

    return 0;
}
