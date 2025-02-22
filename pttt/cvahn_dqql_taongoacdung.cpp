#include<bits/stdc++.h>
using namespace std;
int n,i,d;
string s;
void datngoac(int i)
{   for(char j='(';j<=')';j++)
        if(j=='(')
        {
            s[i]=j;
            d++;
            if(i<n-1&&d<=n/2) datngoac(i+1);
            d--;
        }
        else
        {
            s[i]=j;
            d--;
            if(d==0&&i==n-1) cout<<s<<endl;
            else if(d>=0&&i<n-1) datngoac(i+1);
            d++;
        }
}
int main()
{
    cin>>n;
    n=2*n;
    for(i=1;i<=n;i++)
        s=s+'0';
    d=0;
    datngoac(0);
    return 0;
}
