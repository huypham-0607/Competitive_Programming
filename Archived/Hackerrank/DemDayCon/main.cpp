#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 5e5+10;
const int INF = 2e9;

int n,m;
map<int,int> mp,idx;
int cnt[maxn],a[maxn],pre[maxn];
vector<pii> v;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    mp[0] = INF;
    mp[n+1] = INF;
    idx[INF] = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        v.push_back({-a[i],i});
    }
    sort(v.begin(),v.end());
    int c = 0;
    for (auto in:v){
        int val = -in.fi;
        int i = in.se;
//        cout << i << " " << val << " ";
        auto meow = mp.upper_bound(i);
        int r = meow -> fi;
        --meow;
        int l = meow -> fi;
        if (idx.find(val) == idx.end()){
            idx[val] = ++c;
        }
//        cout << idx[val] << " " << (i-l)*(r-i) << endl;
        cnt[idx[val]]+=((i-l)*(r-i));

        mp[i] = val;
    }
    for (int i=c; i>=1; i--){
        cnt[i] += cnt[i+1];
    }
    idx[0] = c+1;
    cin >> m;
    while (m--){
        int l,r;
        cin >> l >> r;
        int r2 = 1+(idx.upper_bound(r) -> se);
        int l2 = 1+(idx.lower_bound(l) -> se);
//        cout << r2 << " " << l2 << " " << idx.upper_bound(r) -> fi << " " << idx.lower_bound(l) -> fi << endl;
        cout << cnt[r2] - cnt[l2] << endl;
    }
    return 0;
}
