#include <bits/stdc++.h>

using namespace std;
map<string, long long>mthisinh;
map<string, long long>mbaithi;
set<string>sten;
string ten, tenbai, ketqua;
long long diem;
int main()
{
    long long N, P, S;
    cin >> N >> P >> S;

    while(N--)
    {
        cin >> ten;
        mthisinh[ten] = 0;
        sten.insert(ten);
    }

    while(P--)
    {
        cin >> tenbai >> diem;
        mbaithi[tenbai] = diem;
    }

    while(S--)
    {
        cin >> ten >> tenbai >> ketqua;
        if(sten.count(ten)==1 && ketqua == "AC") mthisinh[ten] += mbaithi[tenbai];
    }

    for(auto i=mthisinh.begin(); i!=mthisinh.end(); i++)
        cout << (*i).first << " " << (*i).second << endl;
    return 0;
}
