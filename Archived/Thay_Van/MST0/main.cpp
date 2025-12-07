#include <bits/stdc++.h>
#define maxn 101
#define inf 1000000000
using namespace std;

int pri[101],trace[101],m,n,x,y,w;
vector <pair<int,int> > a[101];
bool mst[101];

int nextvertex(){
    int mn = inf+1, res;
    for (int i = 0; i<n; i++){
        if (!mst[i] && pri[i] < mn){
            res = i;
            mn = pri[i];
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    while (m--){
        cin >> x >> y >> w;
        a[x].push_back({y,w});
        a[y].push_back({x,w});
    }
    for (int i=0; i<n; i++){
        pri[i] = inf;
    }

    pri[0] = 0;
    trace[0] = -1;
    w = 0;

    int c = n;
    //cout << c << endl;
    while (c--){
        int u = nextvertex();
        //cout << "meow "<< u << endl;
        mst[u] = true;
        w+=pri[u];
        for (auto v:a[u]){
            if (!mst[v.first]){
                if (v.second < pri[v.first]){
                    pri[v.first] = v.second;
                    trace[v.first] = u;
                }
            }
        }
    }
    cout << w << "\n";
    for (int i=1; i<n; i++){
        cout << trace[i] << " " << i << "\n";
    }
    return 0;
}
