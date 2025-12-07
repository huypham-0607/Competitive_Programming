#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "ROAI"

using namespace std;

const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

int n,cover=0;
int k;
vector<int> v;
vector<pii> seg;
int segcnt = 0;

void Init(){
    cin >> n >> k;
    v.push_back(0);
    v.push_back(n);
    for (int i=1; i<=k; i++){
        int l,r;
        cin >> l >> r;
        v.push_back(l);
        v.push_back(r);
    }
    sort(all(v));
    for (int i=0; i<=k; i++){
        int l = v[i*2];
        int r = v[i*2+1];
//        cout << l << " " << r << endl;
        if (l==r) continue;
        ++segcnt;
        seg.push_back({l*2,r*2});
        cover+=(r*2)-(l*2);
    }
}

namespace Sub5{
    bool CheckSub(){
        return true;
    }

    int k;
    int change;
    int ans, cur;
    vector<pii> event;

    void SolveSub(){
        k = segcnt;
        cur = cover;
        ans = cover;

//        cout << k << endl;
//        cout << cur << endl;

        change = k;
        for (int i=0; i<k; i++){
            int org = seg[i].se;
            if (org - seg[i].fi <= n) event.push_back({org - seg[i].fi,-1});
            for (int j=i-1; j>=0; j--){
                if (org - seg[j].se <=n) event.push_back({org - seg[j].se,+1});
                else break;
                if (org - seg[j].fi <=n) event.push_back({org - seg[j].fi,-1});
                else break;
            }

            org = seg[i].fi;
            for (int j=i-1; j>=0; j--){
                if (org - seg[j].se <=n) event.push_back({org - seg[j].se,-1});
                else break;
                if (org - seg[j].fi <=n) event.push_back({org - seg[j].fi,+1});
                else break;
            }
        }

        event.push_back({n,0});

        sort(all(event));
        int pre = 0;
        for (int idx=0; idx<(int)event.size(); idx++){
            int t = event[idx].fi;
            int val = event[idx].se;

            int delta = t-pre;
            cur+=change*delta;
            ans = max(ans,cur);
            pre = t;

//            cout << t << " " << val << " " << cur << " " << change << endl;

            change+=val;
        }

        cout << ans << endl;
    }
}

signed main(){
    freopen(NAME ".inp","r",stdin);
    freopen(NAME ".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Init();
    if (Sub5::CheckSub()) return Sub5::SolveSub(),0;

    return 0;
}

