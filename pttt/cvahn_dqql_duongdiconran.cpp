#include<bits/stdc++.h>
using namespace std;
int a[100][10],b[10][10],m,n,i,j,db,maxb;
char c,d;
int xi[4]={1,0,-1,0};
int yi[4]={0,1,0,-1};
void loanga(int x,int y,int k)
{
    if(a[x+xi[k]][y+yi[k]]==0)
    {
        db++;
        a[x+xi[k]][y+yi[k]]=db;
        loanga(x+xi[k],y+yi[k],k);
    }
    else if(a[x+xi[k]][y+yi[k]]>1)
    {
        cout<<db-1<<endl;
        return;
    }
    else
    {
        k++;
        if(k>3) k=0;
        loanga(x,y,k);
    }
}
void loangb(int x,int y,int k)
{
    if(b[x+xi[k]][y+yi[k]]>1)
        {maxb=max(maxb,db);}
    else 
    if(b[x+xi[k]][y+yi[k]]==0)
    {
        db++;
        b[x+xi[k]][y+yi[k]]=db;
        loangb(x+xi[k],y+yi[k],k);
        b[x+xi[k]][y+yi[k]]=0;
        db--;
    }
    else
    if(b[x+xi[k]][y+yi[k]]==-1)
    {
        bool kt=false;
        for(int i=0;i<4;i++)
            if(b[x+xi[i]][y+yi[i]]==0)
        {
            kt=true;
            loangb(x,y,i);
        }
        if(kt==false) maxb=max(maxb,db);
    }
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>c>>d;
        a[d-48][c-64]=-1;
    }
    for(i=0;i<=9;i++)
    {
        a[0][i]=-1;
        a[i][0]=-1;
        a[9][i]=-1;
        a[i][9]=-1;
    }
    for(i=0;i<=9;i++)
        for(j=0;j<=9;j++)
            b[i][j]=a[i][j];
    db=1;
    a[1][1]=2;
    loanga(1,1,0);
    db=1;
    b[1][1]=2;
    loangb(1,1,0);
    cout<<maxb-1;
    return 0;
}
