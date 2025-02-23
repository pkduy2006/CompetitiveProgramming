#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e3 + 5;
int l = 1, r = 1, mod_left = 1, mod_right = 1, a, b, m, n;

string nhan(string a, string b)
{
    int nho=0,i,j;
    string c="";
    for (i=0;i<a.size()/2;i++) swap(a[i],a[a.length()-i-1]);
    for (i=0;i<b.length()/2;i++) swap(b[i],b[b.length()-i-1]);
    for (i=0;i<a.length()+b.length();i++) c=c+'0';

    for (i=0;i<a.length();i++)
    {
        nho=0;
        for (j=0;j<b.length();j++)
        {
            nho=nho+c[i+j]-48+(a[i]-48)*(b[j]-48);
            c[i+j]=char(nho%10+48);
            nho=nho/10;
        }
        c[i+b.length()]=c[i+b.length()]+nho;
    }
    while (c[c.length()-1]=='0' and c.length()>1) c.erase(c.length()-1,1);
    for (i=0;i<c.length()/2;i++) swap(c[i],c[c.length()-i-1]);
    return c;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    freopen("tichdoanso.inp", "r", stdin);
    freopen("tichdoanso.out", "w", stdout);
    
    cin >> a >> b >> m >> n;

    string sum = "1";
    for (int i = a; i <= b; i++)
        sum = nhan(sum, to_string(i));
    for (int i = 0; i < m; i++)
        cout << sum[i];
    cout << ' ' ;

    for (int i = sum.size() - n; i < sum.size(); i++)
        cout << sum[i];
        
    return 0;
}
