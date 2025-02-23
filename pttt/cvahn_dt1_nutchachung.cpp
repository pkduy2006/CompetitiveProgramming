#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define pii pair <int,int>

using namespace std;

const int mxn=1e4+1;

int n,k,i,u,v,x,y;
vector <int> rA[mxn],cha1;

bool find(int l, int r, int x)
{
    int mid;
    while (l <= r){
        mid = (l+r)/2;
        if (x == cha1[mid])
            return 1;
        else if (x > cha1[mid])
            l = mid+1;
        else
            r = mid-1;
    }
    return 0;
}

int main()
{
    freopen("Ances.inp","r",stdin); freopen("Ances.out","w",stdout);
    cin >> n >> k;
    for (i=1; i<=n-1; i++){
        cin >> u >> v;
        rA[v].PB(u);
    }
    cin >> x >> y;
    cha1.PB(x);
    while (x != k){
        x = rA[x][0];
        cha1.PB(x);
    }
    sort(cha1.begin(),cha1.end());
    while (true){
        if (find(0,cha1.size()-1,y) == 1){
            cout << y;
            return 0;
        }
        y = rA[y][0];
    }
    return 0;
}
