#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10;
int a[N][N];
int db;
int d, c;
int k;
int maxb = -1;
int x,y;
int xi[4] = {1 , 0 , -1 , 0};
int yi[4] = {0 , 1 , 0 , -1};
void loang(int x, int y, int k){
    if(a[x+xi[k]][y+yi[k]] > 1){
        maxb = max(maxb,db);
    }
    else
    if(a[x+xi[k]][y+yi[k]] == 0){
        db++;
        a[x+xi[k]][y+yi[k]] = db;
        loang(x+xi[k],y+yi[k],k);
        a[x+xi[k]][y+yi[k]] = 0;
        db--;
    }
    else 
    if(a[x+xi[k]][y+yi[k]] == -1){
        bool kt = true;
        for(int i = 0; i < 4; i++)
            if(a[x+xi[i]][y+yi[i]] == 0){
                kt = false;
                loang(x,y,i);
            }
            if(kt) maxb = max(maxb,db);
    }
}
main(){
    freopen("snail.inp","r",stdin); freopen("snail.out","w",stdout);
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> d >> c;
        a[d][c] = -1;
    }
    for(int i = 0; i <= 9; i++){
        a[0][i] = -1;
        a[i][0] = -1;
        a[9][i] = -1;
        a[i][9] = -1;
    }
    db = 1;
    a[1][1] = 2;
    loang(1,1,0);
    cout << maxb - 1;
}
