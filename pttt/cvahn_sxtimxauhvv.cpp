#include <bits/stdc++.h>
#define ll long long
#define task "timxauhvv"

using namespace std;

ll k,i;
set <string> ans;
set <string> :: iterator it;
string x;

void hoanvi(string s, ll i)
{
    s += s[0];
    s.erase(s.begin());
    ans.insert(s);
    if (i == s.length())
        return;
    else
        hoanvi(s,i+1);
}

int main()
{
    freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
    cin >> k >> x;
    hoanvi(x,1);
    for (it = ans.begin(),i = 1; it != ans.end(); it++,i++){
        if (i == k){
            cout << *it;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
