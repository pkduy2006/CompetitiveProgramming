#include<bits/stdc++.h>
using namespace std;
int a[20][20],n,dem=0,d,x,y;
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};
void inkq(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
    exit(0);
}
void madituan(int x,int y)
{
    for(int i=0;i<=7;i++)
    if(x+dx[i]>0&&x+dx[i]<=n&&y+dy[i]>0&&y+dy[i]<=n&&a[x+dx[i]][y+dy[i]]==0)
    {
        d++;
        a[x+dx[i]][y+dy[i]]=d;
        if(d==n*n) inkq(n);
        else madituan(x+dx[i],y+dy[i]);
        d--;
        a[x+dx[i]][y+dy[i]]=0;
    }
}
int main()
{
    cin>>n>>x>>y;
    d=1;
    a[x][y]=1;
    madituan(x,y);
    return 0;
}
