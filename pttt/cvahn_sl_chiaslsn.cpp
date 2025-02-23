#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("chiaslsn.inp","r",stdin);
    freopen("chiaslsn.out","w",stdout);
    string a;
    long long int b, du=0;
    cin>>a>>b;
    string c="";
    for(int i=0; i<a.length(); i++)
    {
        du=du*10+a[i]-48;
        c=c+char(du/b+48);
        du=du%b;
    }
    while(c[0]=='0' && c.length()>1) c.erase(0,1);
    cout<<c<<endl;
    cout<<du;
    return 0;
}
