#include <bits/stdc++.h>
using namespace std;
string m, n, c, tn;
int i;
string congsl(string a, string b)
{
    c = "";
    while(a.length() < b.length()) a = '0' + a;
    while(a.length() > b.length()) b = '0' + b;
    int nho = 0;
    for(i = a.length() - 1; i >= 0; i--)
    {
        nho = nho + a[i] + b[i] - 96;
        c = (char)(nho % 10 + 48) + c;
        nho = nho / 10;
    }
    c =(char)(nho + 48) + c;
    while(c[0] == '0' && c.length() > 1) c.erase (0, 1);
    return c;
}
bool ss(string a, string b)
{
    while(a.length() < b.length()) a = '0' + a;
    while(a.length() > b.length()) b = '0' + b;
    if(a >= b)
        return true;
    else
        return false;
}
string trusl(string a, string b)
{
    int i, muon = 0;
    c = "";
    while(a.length() < b.length()) a = '0' + a;
    while(a.length() > b.length()) b = '0' + b;
    for (i = a.length() - 1; i >= 0; i--)
    {
        if(a[i] - b[i] - muon >= 0)
        {
            c = (char)(a[i] - b[i] - muon + 48) + c;
            muon = 0;
        }
        else
        {
            c = (char)(a[i] + 10 - b[i] - muon + 48) + c;
            muon = 1;
        }
    }
     while (c[0] == '0' && c.length() > 1) c.erase (0, 1);
    return c;
}
string tinhtong(string n)
{
    int i;
    string x;
    c = n;
    for(i = 0; i < n.length(); i++)
    {
        x = n[i];
        c = congsl(c, x);
    }
    return c;
}
int main()
{
    freopen("songuon.inp","r",stdin);
    freopen("songuon.out","w",stdout);
    cin >> m;
    if(m.length() < 4)
        n = "1";
    else
    {
        tn = to_string(m.length() * 9);
        n = trusl(m, tn);
    }
    while(ss(m, n))
    {
        if(tinhtong(n) == m)
        {
            cout << n;
            return 0;
        }
         else
            n = congsl(n, "1");
    }
    cout << 0;
    return 0;
}
