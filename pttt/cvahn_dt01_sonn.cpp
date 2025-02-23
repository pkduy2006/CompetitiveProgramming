#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define bend(a) a.begin(),a.end()
#define rev(x) reverse(bend(x))
#define mset(a) memset(a, 0, sizeof(a))
#define fi first
#define se second
#define gcd __gcd
#define getl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
#define endl '\n'
const int N=200050,M=1000000007;
const ll INF=1e18+7;
int cnt(ll n){
	int dem=0;
	while(n>0){
		if(n%10==5) ++dem;
		n/=10;
	}
	return dem;
}
ll brute(ll n,ll k){
	++n;
	while(true){
		if(cnt(n)==k) return n;
		++n;
	}
	return -1;
}
ll full(ll n,ll k){
	ll ans=0;
	string s;
	stringstream ss;
	ss<<n;
	ss>>s;
	int m=s.size();
//	cout<<m<<" "<<k<<endl;
	if(m<k){
		while(k--) ans=ans*10+5;
		return ans;
	}
	else if(m==k){
		bool ok=false;
		for(int i=0;i<m;++i){
			if(s[i]>'5') break;
			else if(s[i]<'5'){
				ok=true;
				break;
			}
		}
		if(!ok) ans=1;
		while(k--) ans=ans*10+5;
		return ans;
	}
	ll cnt=k;
	ll minis=INF;
	for(int i=0;i<m;++i){
//		cout<<"i: "<<i<<endl;
		if(s[i]=='9') continue;
		if(s[i]=='4'){
			if(cnt>0){
				if(cnt<=(m-i)){
					ans=0;
					for(int j=0;j<i;++j) ans=ans*10+(s[j]-'0');
					ans=ans*10+(s[i]-'0'+1);
					for(int j=0;j<(m-i-cnt);++j) ans*=10;
					for(int j=1;j<cnt;++j) ans=ans*10+5;
					minis=min(minis,ans);
//					cout<<"#1 --> "<<ans<<endl;
				}
			}
			else{
				ans=0;
				for(int j=0;j<i;++j) ans=ans*10+(s[j]-'0');
				ans=ans*10+(s[i]-'0'+2);
				for(int j=i+1;j<m;++j) ans*=10;
				minis=min(minis,ans);
//				cout<<"#2 --> "<<ans<<endl;
			}
				
		}
		else{
			if(cnt<=(m-i-1)){
				ans=0;
				for(int j=0;j<i;++j) ans=ans*10+(s[j]-'0');
				ans=ans*10+(s[i]-'0'+1);
				for(int j=0;j<(m-i-1-cnt);++j) ans*=10;
				for(int j=0;j<cnt;++j) ans=ans*10+5;
				minis=min(minis,ans);
//				cout<<"#3 --> "<<ans<<endl;
			}
			if(s[i]<'5' and cnt>0){
				if(cnt<=(m-i)){
					ans=0;
					for(int j=0;j<i;++j) ans=ans*10+(s[j]-'0');
					ans=ans*10+5;
					for(int j=0;j<(m-i-cnt);++j) ans*=10;
					for(int j=1;j<cnt;++j) ans=ans*10+5;
					minis=min(minis,ans);
//					cout<<"#4 --> "<<ans<<endl;
				}
			}
		}
		if(s[i]=='5'){
			--cnt;
			if(cnt<0) break;
		}
	}
	if(minis==INF){
		ans=1;
		for(int i=0;i<(m-k);++i) ans*=10;
		for(int i=0;i<k;++i) ans=ans*10+5;
		return ans;
	}
	return minis;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    freopen("min.inp","r",stdin);
    freopen("min.out","w",stdout);
	ll n,k;
    cin>>n>>k;
    cout<<full(n,k);
    return 0;
}
