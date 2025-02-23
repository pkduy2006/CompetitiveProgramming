#include <bits/stdc++.h>
using namespace std;

int n, res;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("house.inp","r",stdin);
    freopen("house.out","w",stdout);

    cin >> n >> s;
    for(int i = 0; i < n - 1; i++)
    {
        if(s[i] == s[i + 1])
        {
            res++;
            i++;
        }
    }

    cout << res;

    return 0;
}
