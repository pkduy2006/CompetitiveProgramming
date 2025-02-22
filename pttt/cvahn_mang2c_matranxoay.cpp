#include<bits/stdc++.h>
using namespace std;
const int nm=1e3+1;
int so,c1,c2,a[nm][nm],n,i,j;
int main()
{
    cin>>n;
    so=0;
    c1=0;c2=n+1;
    while(so<n*n)
    {
        c1++;
        for(j=1;j<=n;j++)
        if(a[c1][j]==0){so++;a[c1][j]=so;}
        c2--;
        for(i=1;i<=n;i++)
        if(a[i][c2]==0){so++;a[i][c2]=so;}
        for(j=n;j>=1;j--)
        if(a[c2][j]==0){so++;a[c2][j]=so;}
        for(i=n;i>=1;i--)
        if(a[i][c1]==0){so++;a[i][c1]=so;}
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
