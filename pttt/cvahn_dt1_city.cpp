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
const int N=250,M=1000000007;
const ll INF=1e18+7;
ll n,m,x,y,z,cost[N][N],og[N][N],sum,ans=0,dem=0;
vector<pair<int,pair<int,int> > >gay;
bool connect[N][N];
int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
   freopen("city.inp","r",stdin);
   freopen("city.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			og[i][j]=-1;
			connect[i][j]=false;
			if(i==j) cost[i][j]=0;
			else cost[i][j]=INF;
		}
	}
	for(int i=0;i<m;++i){
		cin>>x>>y>>z;
		connect[x][y]=true;
		connect[y][x]=true;
		gay.pb({z,{x,y}});
		cost[x][y]=min(cost[x][y],z);
		cost[y][x]=cost[x][y];
		og[x][y]=cost[x][y];
		og[y][x]=og[x][y];
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			if(i==k) continue;
			for(int j=1;j<=n;++j){
				if(j==k) continue;
				sum=cost[i][k]+cost[k][j];
				if(cost[i][j]>=sum){
					cost[i][j]=sum;
					connect[i][j]=false;
					connect[j][i]=false;
				}
			}
		}
	}
	// for(int i=1;i<=n;++i){
	// 	for(int j=1;j<=n;++j){
	// 		cout<<connect[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	for(int i=0;i<m;++i){
		x=gay[i].se.fi; y=gay[i].se.se;
		z=gay[i].fi;
		if(!connect[x][y]) continue;
		if(z>og[x][y]) continue;
		// cout<<x<<" "<<y<<" "<<z<<endl;
		ans+=z; ++dem;
		connect[x][y]=false;
		connect[y][x]=false;
	}
	cout<<dem<<" "<<ans;
	return 0;
}
