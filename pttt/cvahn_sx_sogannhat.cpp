#include<bits/stdc++.h>
using namespace std;

int i,j,k,dem,so1,so2,vt1,dl,vt2,nl;
string n;


int main()
{
    vt1=-1;
    getline (cin,n);
    nl=n.length();
    for (i=n.length()-1;i>=1;i--)
    {
        if (n[i]>n[i-1])
        {
            vt1=i-1; break;
        }
    }
    if (vt1==-1) {cout<<0; return 0;}
    dl=10;
    for (i=vt1+1;i<n.length();i++)
    {
        if (n[i]>n[vt1]&&dl>n[i]-n[vt1])
        {
            vt2=i; dl=n[i]-n[vt1];
        }
    }
    swap (n[vt1],n[vt2]);
    sort (n.begin()+vt1+1,n.end());
    for (i=0;i<n.length();i++)
    {
        cout<<n[i];
    }
}
