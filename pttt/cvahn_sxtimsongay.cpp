#include <bits/stdc++.h>

using namespace std;

struct cay
{
	int la,vt;
};

vector<cay> a;
set<int> ok;
int n,x,d;

bool ss(cay a, cay b)
{
	if (a.la==b.la)
	{
		return a.vt<b.vt;
	}
	return a.la<b.la;
}

int main()
{
    freopen("treedie.inp","r",stdin); freopen("treedie.out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		a.push_back({x,i});
	}
	sort(a.begin(),a.end(),ss);
	for (int i = 0; i < n; ++i)
	{
		if (ok.count(a[i].vt)==0)
		{
			d++;
			ok.insert(a[i].vt);
			ok.insert(a[i].vt-1);
			ok.insert(a[i].vt+1);
		}
	}
	cout << d;
	return 0;
}
