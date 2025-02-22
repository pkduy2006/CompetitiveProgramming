#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int res=0;
    cin >> s;
    reverse(s.begin(), s.end());
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='1')
            res+=(1<<i);
    }
    cout << res;
    return 0;
}
