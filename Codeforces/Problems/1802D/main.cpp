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
int n;
set<int> st;
map<int,int> mp;
vector<pii> v;

void update(int u){
    --mp[u];
    if (!mp[u]){
        mp.erase(u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n;
        int x,y;
        v.clear();
        st.clear();
        mp.clear();
        v.push_back({-1,0});
        for (int i=1; i<=n; i++){
            cin >> x >> y;
            ++mp[y];
            v.push_back({x,y});
        }
        mp[-INF] = 1;
        st.insert(-INF);
        st.insert(INF);
        sort(v.begin(),v.end());
        int res = INF;
        for (int i=1; i<=n; i++){
            int x = v[i].fi;
            int y = v[i].se;
            update(y);
            if (x == v[i-1].fi){
                st.insert(y);
            }
            auto it = st.upper_bound(x);
            int b = *it;
            int a = *(--it);
            auto it2 = mp.end();
            int bruh = (--it2)->fi;
            int meow = abs(bruh - x);
            if (a > bruh) meow = min(meow,x-a);
            if (b > bruh) meow = min(meow,b-x);
            res = min(res,meow);
//            cout << x << " " << a << " " << b << " " << bruh << " " << res << endl;
            if (x!=v[i-1].fi) st.insert(y);
        }
//        if (res == 75) cout << 7 << endl;
        cout << res << endl;
    }
    return 0;
}
