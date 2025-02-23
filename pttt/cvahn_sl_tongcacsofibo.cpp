#include <bits/stdc++.h>
using namespace std;
const int nm=1e4+1;
string f[nm],kq[nm],n;
int i;
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
    freopen("tongfb.inp","r",stdin);
    freopen("tongfb.out","w",stdout);
    cin>>n;
    f[1]="1";f[2]="1";
    i=2;
    do
    {
        i++;
        f[i]=congsl(f[i-1],f[i-2]);
    }
    while(ss(n,f[i])==true);
    while(ss(f[i],n))i--;
    int m=i, k=0;
    while(n!="0")
    {
        if(ss(n,f[m])){n=trusl(n,f[m]);k++;kq[k]=f[m];}
        m--;
    }
    for(i=k; i>0; i--)cout<<kq[i]<<' ';
    return 0;
}
