#include<bits/stdc++.h>
using namespace std;
int a[20][20],n,m,dem=0,d,dm,x,y;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void timduong(int x,int y)
{
    for(int i=0;i<=3;i++)
        if(a[x+dx[i]][y+dy[i]]==0)
    {
        d++;
        a[x+dx[i]][y+dy[i]]=d;
        if(x+dx[i]==1||x+dx[i]==m||y+dy[i]==1||y+dy[i]==1||y+dy[i]==n) dm=max(dm,d);
        else timduong(x+dx[i],y+dy[i]);
        d--;
        a[x+dx[i]][y+dy[i]]=0;
    }
}
int main()
{
    cin>>m>>n>>x>>y;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    d=0;
    a[x][y]=1;
    timduong(x,y);
    cout<<dm;
    return 0;
}
