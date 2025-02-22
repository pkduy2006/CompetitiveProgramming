#include<bits/stdc++.h>
using namespace std;
const int nm=30;
bool c[nm],cc[nm],cp[nm];
int h[nm][nm],dem,n;
void inkq()
{
    dem++;
    cout<<dem<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<h[i][j]<<" ";
    cout<<endl;
    }
}
void dathau(int i)
{
    for(int j=1;j<=n;j++)
        if(c[j]==0&&cc[i-j+n]==0&&cp[i+j]==0)
    {
        h[i][j]=i;
        c[j]=1;
        cc[i-j+n]=1;
        cp[i+j]=1;
        if(i==n) inkq();
        else dathau(i+1);
        h[i][j]=0;
        c[j]=0;
        cc[i-j+n]=0;
        cp[i+j]=0;
    }
}
int main()
{
    cin>>n;
    dathau(1);
    return 0;
}
