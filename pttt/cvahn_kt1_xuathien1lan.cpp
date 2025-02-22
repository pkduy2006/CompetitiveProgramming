#include <bits/stdc++.h>
using namespace std;
int n,x,dem;
map<int, int> mdem;

int main()
{
    cin >> n;
    while(n--)
    {
        cin >> x;
        mdem[x]++;
    }
    bool kt = 0;
    for(auto i = mdem.begin(); i != mdem.end(); i++)
        if((*i).second == 1) dem++;
    cout << dem << '\n';
    for(auto i = mdem.begin(); i != mdem.end(); i++)
        if(mdem[(*i).first] == 1)
            cout << (*i).first << ' ';
    return 0;
}
