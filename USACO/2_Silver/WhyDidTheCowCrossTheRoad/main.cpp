#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int test;
int n,m;
vector<pii> v;
map<int,int> mp;

void update(int u){
    --mp[u];
    if (mp[u] == 0){
        mp.erase(u);
    }
}

int main(){
    freopen("helpcross.in","r",stdin);
    freopen("helpcross.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        ++mp[x];
    }
    mp[INF] = 1;
    for (int i=1; i<=m; i++){
        int x,y;
        cin >> x >> y;
        v.push_back({y,x});
    }
    sort(v.begin(),v.end());
    int cnt = 0;
    for (auto in:v){
        int l = in.se;
        int r = in.fi;

        map<int,int>::iterator it = mp.lower_bound(l);
        int x = it->fi;
        if (x <= r){
            ++cnt;
            update(x);
        }
    }
    cout << cnt;
    return 0;
}
