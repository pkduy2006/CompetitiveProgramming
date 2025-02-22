#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while(ntest--)
    {
        int n, res=0;
        string s;
        char k;
        cin >> n >> k;
        for(int i=1; i<=n; i++)
        {
            cin >> s;
            for(int j=0; j<s.size(); j++)
            {
                if(s[j]==k)
                    res++;
            }
        }
        cout << res << '\n';
    }
    return 0;
}
