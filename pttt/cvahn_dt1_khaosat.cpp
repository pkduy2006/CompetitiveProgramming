#include<bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
//#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define gcd __gcd
#define getl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
#define mset(a) memset(a, 0, sizeof(a))
#define endl '\n'
const int N=5050,M=1000000007;
const ll INF=1e18+7;
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
   freopen("khaosat.inp","r",stdin);
   freopen("khaosat.out","w",stdout);
    int n,x=0,y=0,u,v,dem=1;
    bool ok[N];
    pair<int,int>A,B,beginning;
    map<pair<int,int>,int>lookup;
    vector<pair<int,int> >gay[N];
    string s;
    cin>>s; n=s.size();
    beginning={0,0};
    lookup[beginning]=dem++;
    for(int i=0;i<n;++i){
        A={x,y};
        if(s[i]=='E') ++y;
        else if(s[i]=='W') --y;
        else if(s[i]=='S') --x;
        else ++x;
        B={x,y};
        if(lookup[B]==0) lookup[B]=dem++;
        u=lookup[A]; v=lookup[B];
        gay[u].pb(B);
        gay[v].pb(A);
    }
    for(int i=1;i<=dem;++i) ok[i]=true;
    queue<pair<pair<int,int>,int> >que;
    que.push({{x,y},0});
    // cout<<x<<" "<<y<<endl;
    while(!que.empty()){
        A=que.front().fi;
        v=que.front().se;
        que.pop();
        u=lookup[A];
        if(!ok[u]) continue;
        ok[u]=false;
        // cout<<"->> "<<A.fi<<" "<<A.se<<endl;
        if(A==beginning){
            cout<<v;
            return 0;
        }
        for(auto tmp:gay[u]){
            que.push({tmp,v+1});
        }
    }
    return 0;
}
