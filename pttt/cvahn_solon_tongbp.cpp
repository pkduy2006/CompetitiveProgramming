#include<bits/stdc++.h>
using namespace std;
string a,b,c;
int i;
string congsl(string a,string b)
{
    while(a.length()<b.length()) a='0'+a;
    while(a.length()>b.length()) b='0'+b;
    int nho=0;
    for(i=a.length()-1;i>=0;i--)
    {
        nho=nho+a[i]+b[i]-96;
        c=(char)(nho%8+48)+c;
        nho=nho/8;
    }
    c=(char)(nho+48)+c;
    while(c[0]=='0'&&c.length()>1) c.erase(0,1);
    return c;
}
int main()
{
    cin>>a>>b;
    cout<<congsl(a,b);
    return 0;
}
