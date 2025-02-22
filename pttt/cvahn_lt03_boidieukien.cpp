#include<bits/stdc++.h>
using namespace std;
set<char> a;
char x;
long long i,j,n,m,t;
bool kt(long long t)
{
    string s=to_string(t);
    for(int i=0;i<s.length();i++)
    {
        if(a.count(s[i])==0) return 0;
    }
    return 1;
}
int main()
{
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x;
        a.insert(x);
    }
    t=n;
    while(1)
    {
        if(kt(t)) {cout<<t; return 0;}
        t+=n;
    }
    cout<<0;
}
