#include<bits/stdc++.h>
using namespace std;
int a[20],n,i,j;
string s,p;
set <string> x;
bool b[20];
void hoanvi(int i)
{
    for(int j=0;j<n;j++)
        if(b[j]==false)
    {
        p[i]=s[j];
        b[j]=true;
        if(i==n-1)x.insert(p);
        else hoanvi(i+1);
        b[j]=false;
    }
}
int main()
{
    cin>>s;
    n=s.length();
    for(i=0;i<n;i++)
        p=p+'0';
    hoanvi(0);
    for(auto xi=x.begin();xi!=x.end();xi++)
        cout<<*xi<<endl;
    return 0;
}
