#include <bits/stdc++.h>
#define int long long
using namespace std;
map<string, int> cntword;
main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string s;
        int l;
        cin >> l >> s;
        if(l == 1)
            cntword[s]++;
        else
            cout << cntword[s] << '\n';
    }
    return 0;
}
