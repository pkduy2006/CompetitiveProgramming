#include<bits/stdc++.h>
using namespace std;
int a[100],n,i,tong,dem;
long long tich,tichmax;
vector<int>b;
bool ktnt(int n)
{
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0) return 0;
    return 1;
}
void taphop(int i,int tong,long long tich)
{
    for(int j=a[i-1]+1;j<b.size();j++)
    {
        a[i]=j;
        if(tong+b[j]==n)
        {
            dem++;
            if(tich*b[j]>tichmax) tichmax=tich*b[j];
        }
        if(tong+b[j]<n) taphop(i+1,tong+b[j],tich*b[j]);
    }
}
int main()
{
    cin>>n;
    b.push_back(0);
    for(i=2;i<n;i++)
    if(ktnt(i)) b.push_back(i);
    taphop(1,0,1);
    cout<<dem<<endl<<tichmax;
    return 0;
}
