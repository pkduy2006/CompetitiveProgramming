#include<bits/stdc++.h>
using namespace std;
struct hocsinh
{
	string ht,ns,gt,kq;
	float toan,van,tin,td;
};
hocsinh hs[1001];
int i,j,n;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin.ignore();
		getline(cin,hs[i].ht);
		cin>>hs[i].ns>>hs[i].gt>>hs[i].toan>>hs[i].van>>hs[i].tin;
		hs[i].td=hs[i].toan+hs[i].van+hs[i].tin;
		if(hs[i].td>=15&&hs[i].toan>=2&&hs[i].van>=2&&hs[i].tin>=2) hs[i].kq="do";
		else hs[i].kq="truot";
	}
	for(i=1;i<=n;i++)
		cout<<hs[i].ht<<' '<<hs[i].ns<<' '<<hs[i].gt<<' '<<hs[i].toan<<' '<<hs[i].van<<' '<<hs[i].tin<<' '<<hs[i].td<<' '<<hs[i].kq<<endl;
	for(i=1;i<=n;i++)
		if(hs[i].kq=="do")
		cout<<hs[i].ht<<' '<<hs[i].ns<<' '<<hs[i].gt<<' '<<hs[i].toan<<' '<<hs[i].van<<' '<<hs[i].tin<<' '<<hs[i].td<<' '<<hs[i].kq<<endl;
	for(i=1;i<=n;i++)
		if(hs[i].td>=24&&hs[i].toan>=8&&hs[i].van>=8&&hs[i].tin>=8)
		cout<<hs[i].ht<<' '<<hs[i].ns<<' '<<hs[i].gt<<' '<<hs[i].toan<<' '<<hs[i].van<<' '<<hs[i].tin<<' '<<hs[i].td<<' '<<hs[i].kq<<endl;
	return 0;
}
