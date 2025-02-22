#include<bits/stdc++.h>
using namespace std;
int i,j,n,dem,maxa,t,d,k;
set<string> a;
string s,x;
int main()
{
    cin>>k>>s;
    dem=s.size();
    s=s+s;
    for(i=0;i<dem;i++)
    {
        x=s.substr(i,dem);
        a.insert(x);
    }
    if(a.size()<k) cout<<-1;
    else{
        d=0;
        for(auto i=a.begin();i!=a.end();i++)
        {
            d++;
            if(d==k)
            {
                cout<<*i;
                break;
            }
        }
    }
    return 0;
}
