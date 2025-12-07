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
int n,m,t=0;

vector<int> atk,def;
map<int,int> mp1,mp2;

void update1(int u){
    --mp1[u];
    if (!mp1[u]){
        mp1.erase(u);
    }
}

void update2(int u){
    --mp2[u];
    if (!mp2[u]){
        mp2.erase(u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        string s;
        int x;
        cin >> s >> x;
        if (s == "ATK") atk.push_back(x);
        else def.push_back(x);
    }
    for (int i=1; i<=m; i++){
        int x;
        cin >> x;
        t+=x;
        ++mp1[x];
        ++mp2[x];
    }
    sort(atk.begin(),atk.end());
    sort(def.begin(),def.end());
    int res1 = 0;
    for (int i=1; i<=min(m,int(atk.size())); i++){
        int x = atk[i-1];
        auto it = mp1.lower_bound(x);
        if (it == mp1.end()) break;
        int y = (--mp1.end())->fi;
//        cout << x << " " << y << endl;
        res1+=y-x;
        update1(y);
    }
    int res2 = 0;
    int i;
    for (i=1; i<=int(def.size()); i++){
        auto it = mp2.upper_bound(def[i-1]);
        if (it == mp2.end()) break;
        else{
            t-=it->fi;
            update2(it->fi);
        }
    }
    if (i > int(def.size())){
        for (i=0; i<int(atk.size()); i++){
            auto it = mp2.lower_bound(atk[i]);
            if (it == mp2.end()) break;
            else{
                t-=atk[i];
                update2(it->fi);
            }
        }
        if (i == int(atk.size())) res2 = t;
    }
    cout << max(res1,res2);
    return 0;
}
