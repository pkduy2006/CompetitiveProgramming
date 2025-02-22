#include <bits/stdc++.h>
using namespace std;
const int nm=1e5+1;
char c1[nm], c2[nm];
string s1, s2;
long long t,T,i,d1[nm],d2[nm], n, dem,n1,n2;
int main()
{
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        cin>>s1;
        cin>>s2;
        s1+='@';
        n1=0;        dem=1;
        for(i=0; i<s1.length()-1; i++)
            if(s1[i]==s1[i+1]) dem++;
            else
            {
                n1++;
                c1[n1]=s1[i];
                d1[n1]=dem;
                dem=1;
            }

        s2+='@';
        n2=0;
        dem=1;
        for(i=0; i<s2.length()-1; i++)
            if(s2[i]==s2[i+1]) dem++;
            else
            {
                n2++;
                c2[n2]=s2[i];
                d2[n2]=dem;
                dem=1;
            }

        if(n1!=n2)cout<<"NO"<<endl;
        else
        {
            bool kt=1;
            for(i=1; i<=n1; i++)
                if(c1[i]!=c2[i] || d1[i]>d2[i])
            {
                kt=0;
                break;
            }
            if(kt==1)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
