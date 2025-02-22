#include <bits/stdc++.h>
#define int long long

using namespace std;

string m, n, c, tn;

bool ss(string a, string b)
{
    while(a.length() > b.length()) b = '0' + b;
    while(a.length() < b.length()) a = '0' + a;
    if(a >= b) return 1;
    else return 0;
}

string add(string a, string b)
{
    int len = max(a.length(), b.length());
    while (a.length() < len) a = "0" + a;
    while (b.length() < len) b= "0" + b;
    string res = "";
    int rem = 0;
    for (int i= len - 1; i >= 0; i--)
    {
        int n1 = a[i] - '0';
        int n2 = b[i] - '0';
        int s = n1 + n2 + rem;

        char res_tmp = s % 10 + '0';
        res = res_tmp + res;
        rem = s / 10;
    }
    if (rem != 0)
        return char(rem + '0') + res;
    return res;
}

string sub(string a, string b)
{
    int muon = 0; c = "";
    while(a.length() > b.length()) b = '0' + b;
    while(a.length() < b.length()) a = '0' + a;
    for(int i = a.length() - 1; i >= 0; i--)
    {
        if(a[i] - b[i] - muon >= 0)
        {
            c = (char)(a[i] - b[i] - muon + 48) + c;
            muon = 0;
        }
        else{
            c = (char)(a[i] + 10 - b[i] - muon + 48) + c;
            muon = 1;
        }
    }
    while(c[0] == '0' && c.length() > 1) c.erase(0,1);
    return c;
}

string tinhtong(string n)
{
    string x;
    c = n;
    for(int i = 0; i < n.length(); i++)
    {
        x = n[i];
        c = add(c,x);
    }
    return c;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> m;
    if(m.length() < 4) n = '1';
    else{
        tn = to_string(m.length()*9);
        n = sub(m, tn);
    }
    while(ss(m, n))
    {
        if(tinhtong(n) == m) {cout << n; return 0;}
        else n = add(n,"1");
    }
    cout << 0;
    return 0;
}
