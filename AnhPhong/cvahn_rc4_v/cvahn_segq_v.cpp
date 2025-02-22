#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 16;
int q;
long long maxCord;

struct queries
{
    int t;
    long long a, b;
};

vector<queries> task;

namespace sub1And2
{
    int st[4 * N];

    void update(int id, int l, int r, int pos, int value)
    {
        if(pos < l || r < pos)
            return;

        if(pos == l && r == l)
        {
            st[id] += value;

            return;
        }

        int mid = (l + r) / 2;

        update(id * 2, l, mid, pos, value);
        update(id * 2 + 1, mid + 1, r, pos, value);

        st[id] = st[id * 2] + st[id * 2 + 1]; 
    }

    int get(int id, int l, int r, int x, int y)
    {
        if(r < x || y < l)
            return 0;
        
        if(x <= l && r <= y)
            return st[id];

        int mid = (l + r) / 2;

        return get(id * 2, l, mid, x, y) + get(id * 2 + 1, mid + 1, r, x, y);
    }

    void solve()
    {
        for(int i = 0; i < task.size(); i++)
        {
            int type = task[i].t;

            if(type == 1)
            {
                int x = task[i].a, y = task[i].b;

                update(1, 1, maxCord, x, 1);
                update(1, 1, maxCord, y + 1, -1);
            }
            else
            {
                int pos = task[i].a;

                cout << get(1, 1, maxCord, 1, pos) << '\n';
            }
        }
    }
}

namespace sub3
{
    int st[4 * N];
    vector<long long> coordinates;
    
    void SpecifyNum()
    {
        for(int i = 0; i < task.size(); i++)
        {   
            if(task[i].t == 1)
            {   
                coordinates.push_back(task[i].a);
                coordinates.push_back(task[i].b);
            }
            else
                coordinates.push_back(task[i].a);
        }   

        sort(coordinates.begin(), coordinates.end());
        coordinates.resize(unique(coordinates.begin(), coordinates.end()) - coordinates.begin());
    }

    void update(int id, int l, int r, int pos, int value)
    {
        if(pos < l || r < pos)
            return;

        if(pos == l && r == l)
        {
            st[id] += value;

            return;
        }

        int mid = (l + r) / 2;

        update(id * 2, l, mid, pos, value);
        update(id * 2 + 1, mid + 1, r, pos, value);

        st[id] = st[id * 2] + st[id * 2 + 1]; 
    }

    int get(int id, int l, int r, int x, int y)
    {
        if(r < x || y < l)
            return 0;
        
        if(x <= l && r <= y)
            return st[id];

        int mid = (l + r) / 2;

        return get(id * 2, l, mid, x, y) + get(id * 2 + 1, mid + 1, r, x, y);
    }

    void solve()
    {
        SpecifyNum();

        for(int i = 0; i < task.size(); i++)
        {
            int type = task[i].t;

            if(type == 1)
            {
                int x = lower_bound(coordinates.begin(), coordinates.end(), task[i].a) - coordinates.begin() + 1;
                int y = lower_bound(coordinates.begin(), coordinates.end(), task[i].b) - coordinates.begin() + 1;

                update(1, 1, coordinates.size(), x, 1);
                update(1, 1, coordinates.size(), y + 1, -1);
            }
            else
            {
                int pos = lower_bound(coordinates.begin(), coordinates.end(), task[i].a) - coordinates.begin() + 1;

                cout << get(1, 1, coordinates.size(), 1, pos) << '\n';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("SEGQ.inp","r",stdin);
    freopen("SEGQ.out","w",stdout);

    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;

        if(type == 1)
        {
            long long x, y;
            cin >> x >> y;
            
            maxCord = max({x, y, maxCord});
            task.push_back({1, x, y});
        }
        else
        {
            long long pos;
            cin >> pos;

            maxCord = max(maxCord, pos);
            task.push_back({2, pos, 0});
        }
    }
    
    if(maxCord <= (int)1e5)
        sub1And2::solve();
    else
        sub3::solve();

    return 0;
}
