#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,k;
vector<int> v;
map<int,int> mp;

signed main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    queue<int> q;
    sort(v.begin(),v.end());
//    for (auto x:v){
//        cout << x << " ";
//    }
//    cout << "\n";
    int ans = 0;
    mp[-INF] = 1;
    for (auto x:v){
        int fnd = x - k;
        auto it = --mp.upper_bound(fnd);
        if (it != mp.begin()){
            int key = it->fi;
            //cout << x << " " << key << "\n";
            mp[key]--;
            if (mp[key] == 0) mp.erase(key);
        }
        mp[x]++;
        //cout << mp.begin() -> fi << " ";
    }
    for (auto it = mp.begin(); it!=mp.end(); it++){
        if (it == mp.begin()) continue;
        int key = it->fi;
        ans+= key*mp[key];
    }
    cout << ans << "\n";
    return 0;
}
