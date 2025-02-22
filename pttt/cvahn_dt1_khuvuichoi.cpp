#include <bits/stdc++.h>
using namespace std;
const int nm=10001;
int n,m, i,j,x,y,u,v,c[nm],tong;
vector <int> a[nm];
bool b[nm];
struct xy{
    int x,y;
};
int bfs (int u, int v){
    int x, y;
    queue <xy> q;
    q.push ({u,0});
    fill (b+1, b+1+n, 0);
    b[u]=1;
   while (q.empty () !=1){
        x=q.front ().x;
        y=q.front ().y;
        q.pop ();
        for (int i=0;i<(int)a[x].size ();i++)
            if (b[a[x] [i]]==0){
            q. push ( {a[x] [i],y+1});
            b[a[x] [i]]=1;
            if (a[x] [i]==v) return y+1;
   }
}
}
int main (){
    freopen ("kvuichoi.inp","r",stdin);
    freopen ("kvuichoi.out","w", stdout);
    cin>>n;
    for (i=1;i<=n-1;i++){
        cin>>x>>y;
       a[x].push_back (y);
       a[y].push_back (x);
    }
    cin>>m;
    for (i=1;i<=m;i++)
        cin>>c[i];
    for (i=1;i<=m-1;i++)
       tong=tong+bfs (c[i],c[i+1]);
    cout<<tong;
    return 0;
}
