#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,k;
map<int,int> mp;
vector<ii> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    int cnt = 0;
    for (int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        a.push_back({y,x});
    }
    sort(a.begin(),a.end());
//    for (auto in:a){
//        cout << "(" << in.fi << "," << in.se << ") ";
//    }
//    cout << "\n";
    mp[0] = k;
    for (auto in:a){
        auto it = mp.upper_bound(in.se);
//        for (auto x:mp){
//            cout << x.fi << " " << x.se << "\n";
//        }
//        cout << it->fi << "\n";
        if (it == mp.begin()) continue;
        ++cnt;
        --it;
        int y = it->fi;
        --mp[y];
        if (mp[y] == 0){
            mp.erase(y);
        }
        mp[in.fi]+=1;
    }
    cout << cnt;
    return 0;
}
