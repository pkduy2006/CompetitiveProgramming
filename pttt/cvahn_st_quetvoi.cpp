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
const int N=1050,M=1000000007;
const ll INF=1e18+7;
void fastscan(int &number){
    bool negative=false;
    register int c;
    number=0;
    c=getchar();
    if(c=='-'){
        negative=true;
        c=getchar();
    }
    for(;(c>47&&c<58);c=getchar()) number=number*10+c-48;
    if(negative) number*=-1;
}
int n,m,a[N][N],voi;
bool ok[N][N];
void loang(int x,int y){
	if(x<1||y<1||x>n||y>m||!ok[x][y]) return;
	ok[x][y]=false;
	voi+=max(0,a[x][y]-a[x+1][y])+max(0,a[x][y]-a[x-1][y])+max(0,a[x][y]-a[x][y+1])+max(0,a[x][y]-a[x][y-1]);
//	cout<<x<<" "<<y<<" "<<voi<<endl;
	loang(x+1,y);
	loang(x-1,y);
	loang(x,y+1);
	loang(x,y-1);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
    int i,j,num=0,maxvoi=-1,maxnum=-1,sumvoi=0;
	cin>>n>>m;
    for(i=0;i<=m;++i){
    	a[0][i]=0;
    	a[n+1][i]=0;
	}
    for(i=1;i<=n;++i){
    	a[i][0]=0;
    	a[i][m+1]=0;
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			cin>>a[i][j];
			if(a[i][j]==0) ok[i][j]=false;
			else ok[i][j]=true;
		}
	}
    for(i=1;i<=n;++i){
    	for(j=1;j<=m;++j){
    		if(ok[i][j]){
    			++num; voi=0;
    			loang(i,j);
    			if(voi>maxvoi){
    				maxvoi=voi;
    				maxnum=num;
				}
    			sumvoi+=voi;
			}
		}
	}
	cout<<num<<endl<<sumvoi<<endl<<maxnum<<" "<<maxvoi;
    return 0;
}
