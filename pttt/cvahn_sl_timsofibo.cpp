#include <bits/stdc++.h>
using namespace std;
const int nm=1e4+1;
string f,f1,f2,a,b;
int i,d;
string congsl(string a, string b)
{
    string c="";
    while(a.length()<b.length())a='0'+a;
    while(a.length()>b.length())b='0'+b;
    int nho=0;
    for(int i=a.length()-1; i>=0; i--)
    {
        nho=nho+a[i]+b[i]-96;
        c=(char)(nho%10+48)+c;
        nho=nho/10;
    }
    c=(char)(nho+48)+c;
    while(c[0]=='0' && c.length()>1) c.erase(0,1);
    return c;
}
bool ss(string a, string b)
{
    while(a.length()<b.length())a='0'+a;
    while(a.length()>b.length())b='0'+b;
    if(a>=b) return true;
    else return false;
}
string trusl(string a, string b)
{
    int i, muon=0;
    string c="";
    while(a.length()<b.length())a='0'+a;
    while(a.length()>b.length())b='0'+b;
    for(i=a.length()-1; i>=0; i--)
    {
        if(a[i]-b[i]-muon>=0)
        {
            c=(char)(a[i]-b[i]-muon+48)+c;
            muon=0;
        }
        else
        {
            c=(char)(a[i]+10-b[i]-muon+48)+c;
            muon=1;
        }
    }
    while(c[0]=='0' && c.length()>1) c.erase(0,1);
    return c;
}
int main()
{
    freopen("demfibo.inp","r",stdin);
    freopen("demfibo.out","w",stdout);
    cin>>a>>b;
    f1="1";
    f2="1";
    if(a=="1")d=2;
    while(ss(b,f)==true)
    {
        f=congsl(f1,f2);
        f2=f1;
        f1=f;
        if(ss(f,a))d++;
    }
    if(ss(b,f)==false) d--;
    cout<<d;
    return 0;
}
