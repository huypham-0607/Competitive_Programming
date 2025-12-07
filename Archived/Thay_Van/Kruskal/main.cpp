#include <bits/stdc++.h>
#define pb push_back
#define fii pair<float,pair<int,int>>
#define fi first
#define se second

using namespace std;

vector <int> parent;
vector <fii> e;
int m,n;
int u[100000],v[1000000];

void InitSet(int n){
    for (int i=0; i<n; i++){
        parent.pb(i);
    }
}

int FindSet(int x){
    if (parent[x] == x) return x;
    else{
        parent[x] = FindSet(parent[x]);
        return parent[x];
    }
}

int SameSet(int x,int y){
    return (FindSet(x) == FindSet(y));
}

void UnionSet(int x, int y){
    parent[FindSet(x)] = FindSet(y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int x,y;
        float v;
        cin >> x >> y >> v;
        e.pb(make_pair(v,make_pair(x,y)));
    }

    sort(e.begin(),e.end());
    InitSet(n);

    int c=0;
    float sum=0;
    for (int i=0; i<m; i++){
        int x = e[i].se.fi;
        int y = e[i].se.se;
        float val = e[i].fi;
        if (!SameSet(x,y)){
            sum+=val;
            u[c] = x;
            v[c] = y;
            c++;
            UnionSet(x,y);
        }
    }
    cout << fixed << setprecision(2) << sum << endl;
    for (int i=0; i<c; i++){
        cout << u[i] << " " << v[i] << endl;
    }
    return 0;
}
