#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+1;
int a[N], b[N];
queue<int> q;
int maxx = -1;
main(){
    freopen("muave.inp","r",stdin); freopen("muave.out","w",stdout);
    int n,m,k;
    cin >> n >> k >> m;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        b[i] = x;
        maxx = max(maxx,x);
        q.push(i);
    }
    for(int i = 1; i <= m; i++){
        int x = q.front();
        q.pop();
        a[x]++;
        if(b[x] > k){
            q.push(x);
        }
        if(q.empty()) break;
        
    }
    int j = 1;
    //cout << '\n';
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    
    
}
