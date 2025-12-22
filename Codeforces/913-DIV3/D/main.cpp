#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 1e9;

int t,n;
vector<pii> v;

bool check(int k){
    int l = 0;
    int r = 0;
    for (auto in:v){
        int newl = max(0,l-k);
        int newr = r+k;
        if (newl > in.se) return false;
        if (newr < in.fi) return false;
        l = max(in.fi,newl);
        r = min(in.se,newr);
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        v.clear();
        cin >> n;
        for (int i=1; i<=n; i++){
            int l,r;
            cin >> l >> r;
            v.push_back({l,r});
        }
        int ans = -1;
        int l = 0;
        int r = INF;
        while (l<=r){
            int mid = ((l+r)>>1);
//            cout << mid << endl;
            if (!check(mid)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        cout << ans+1 << endl;
    }
    return 0;
}
