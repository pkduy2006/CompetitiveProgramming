#include<bits/stdc++.h>
using namespace std;
int n;
struct dayso{
	int giatri;
	int giatien;
	int vitrisau;
	int maxtien;
	int dem;
};
dayso vitri[100000];
bool cmp (dayso l, dayso r)
{
    if (l.vitrisau < r.vitrisau) return 1;
    else if (l.vitrisau > r.vitrisau) return 0;
    return (l.giatri <= r.giatri);
}
int main(){
	freopen("thuemay.inp","r",stdin);
	freopen("thuemay.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> vitri[i].giatri >> vitri[i].vitrisau >> vitri[i].giatien;
		vitri[i].maxtien = vitri[i].giatien;
		vitri[i].dem = 1;
	}
	sort(vitri+1,vitri+1+n,cmp);
	for(int i = 2; i <= n; i++){
		for(int j = i - 1; j >= 1;j--){
			if(vitri[i].giatri > vitri[j].vitrisau){
				vitri[i].maxtien = max(vitri[i].maxtien, (vitri[j].maxtien + vitri[i].giatien));
			}	
		}
		for(int j = i - 1; j >= 1;j--){
			if(vitri[i].giatri > vitri[j].vitrisau){
				if(vitri[i].maxtien == vitri[j].maxtien + vitri[i].giatien){
					vitri[i].dem = max(vitri[i].dem, (vitri[j].dem + 1));
				}
			}	
		}
	}
	int maxpt = 0;
	int maxdem = 0;
	for(int i = n; i >= 1; i--){
		maxpt = max(vitri[i].maxtien,maxpt);
	}
	for(int i = n; i >= 1; i--){
		if(vitri[i].maxtien == maxpt){
			cout << vitri[i].dem;
			break;
		}
	}
	cout << " " << maxpt;
	return 0;
}
