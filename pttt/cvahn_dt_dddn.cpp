#include<bits/stdc++.h>
using namespace std;

const int nm=1e7+1;
int i,j,n,m,x,y,d,u,v,ans;
bool b[nm];
vector<int> a[nm];

void dfs(int k) {
    for(int i=0;i<a[k].size();i++)
    {
        if(b[a[k][i]]==0) {
            b[a[k][i]]=1;
            d++;
            if(a[k][i]==v) ans=max(ans,d);
                else dfs(a[k][i]);
            b[a[k][i]]=0;
            d--;
        }
    }
}

int main ()
{
    freopen("DDDN.INP","r",stdin);
    freopen("DDDN.OUT","w",stdout);
    cin>>n>>m>>u>>v;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    d=0; b[u]=1; ans=0;
    dfs(u);
    cout<<ans;
}
