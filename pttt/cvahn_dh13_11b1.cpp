#include<bits/stdc++.h>
#define int long long
using namespace std;

const int NM = 3e5 + 7;
int n, a[NM], s, sum, ans = NM;

signed main(){
    
	cin.tie(0)->sync_with_stdio(0);
	freopen("cseq.inp", "r", stdin);
	freopen("cseq.out", "w", stdout);
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin	 >> a[i];
		s += a[i];
	}
	
	for(int i = 1; i <= n; i++)
	{
		sum += a[i];
		ans = min(ans, sum);
		if(sum > 0) sum = 0;
	}
	
	cout << s - 2 * ans;
}
