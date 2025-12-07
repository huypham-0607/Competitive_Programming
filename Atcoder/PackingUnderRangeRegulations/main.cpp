#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<pii,int>
#define fi first
#define se second

#define NAME "SCHEDULE"

using namespace std;

const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

int n,m;
ll w[N];
int s[N],t[N];
ll cur[N];
vector<piii> v;
priority_queue<pii,vector<pii>,greater<pii>> pq;

bool check(ll x){
    int tme = 0,curt,idx,idx2;
    bool del;
    ll delta,rem,val;

    for (int i=1; i<=n; i++){
        cur[i] = 0;
    }

    while (!pq.empty()) pq.pop();

    for (piii in:v){
        curt = in.fi.fi-1;
        del = in.fi.se;
        idx = in.se;

//        cout << curt+1 << " " << del << " " << idx << endl;

        if (tme!=curt){
            delta = curt-tme;
            rem = 0;
            while (!pq.empty() && (delta||rem)){
                idx2 = pq.top().se;
//                cout << idx2 << endl;
                val = w[idx2]-cur[idx2];
//                cout << val << " ";
                if (val-rem<=0 || (val-rem-1)/x<delta){
                    if (val-rem<=0){
                        rem-=val;
                    }
                    else{
                        val-=rem;
                        rem = 0;
                        delta-=val/x;
                        val%=x;
                        if (rem<val){
                            --delta;
                            rem+=x;
                            rem-=val;
                        }
                    }
                    cur[idx2]=w[idx2];
                    pq.pop();
                }
                else{
                    cur[idx2]+=delta*x+rem;
                    delta=0;
                    rem = 0;
                }
            }
            tme = curt;
        }
        if (del){
            if (cur[idx]!=w[idx]) return true;
        }
        else{
            pq.push({t[idx],idx});
        }
    }
    return false;
}

void Solve(){
    v.clear();
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> s[i] >> t[i];
        w[i] = 1;
        v.push_back({{s[i],0},i});
        v.push_back({{t[i]+1,1},i});
    }
    sort(v.begin(),v.end());
    ll ans = 0, mid;
    ll l=1, r=1;
    while (l<=r){
         mid = (l+r)/2;
//        cout << "mid" << " "  << mid << endl;
        if (check(mid)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    if (!ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        Solve();
    }

    return 0;
}
