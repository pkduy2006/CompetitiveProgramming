#include <bits/stdc++.h>
using namespace std;
string x,y,s,c[1001][1001];
bool ss(string a,string b)
{
    while(a.length()<b.length())a='0'+a;
    while(b.length()<a.length())b='0'+b;
    if(a>=b) return true;
    else return false;
}
void taobang()
{
    x='@'+x;
    y='@'+y;
    c[0][0]="0";
    for(int i=1; i<x.length(); i++)
        for(int j=1; j<y.length(); j++)
        if(x[i]==y[j]) c[i][j]=c[i-1][j-1]+x[i];
        else
        {
            if(ss(c[i-1][j], c[i][j-1]))
                c[i][j] = c[i-1][j];
            else c[i][j]=c[i][j-1];
        }
}
void truyhoi()
{
    int i=x.length()-1;
    int j=y.length()-1;
    s="";
    while(c[i][j]>"0")
    {
        if(c[i][j]==c[i-1][j])i--;
        else if(c[i][j]==c[i][j-1])j--;
        else
        {
            s=x[i]+s;
            i--;
            j--;
        }
    }
    while(s[0]=='0' && s.length()>1) s.erase(0,1);
}
int main()
{
    cin>>x>>y;
    taobang();
    truyhoi();
    cout<<s;
    return 0;
}
