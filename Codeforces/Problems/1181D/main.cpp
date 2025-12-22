/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 5e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+(long long)3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m,q;
int a[N];
set<int> st;
vector<pii> v;
int ans[N];
priority_queue<pii,vector<pii>,greater<pii>> pq;

//BIT
int BIT[N];

void Update(int x, int val){
    while (x<=n){
        BIT[x]+=val;
        x+=(x&(-x));
    }
}

int Get(int x){
    int res = 0;
    while (x>0){
        res+=BIT[x];
        x-=(x&(-x));
    }
    return res;
}

int GetIdx(int pos){
    int ans = 0;
    int l=1, r=n;
    while (l<=r){
        int mid = (l+r)/2;
        if (Get(mid)<pos){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
//    cout << ans+1 << endl;
    return ans+1;
}

/*Solution*/
void solve(){
    cin >> m >> n >> q;
    for (int i=1; i<=m; i++){
        int x;
        cin >> x;
        ++a[x];
    }
    for (int i=1; i<=q; i++){
        int x;
        cin >> x;
        pq.push({x,i});
    }
    int cnt = 0;
    int lvl = INF;
    int cur = m;
    for (int i=1; i<=n; i++){
        lvl = min(cur,a[i]);
        v.push_back({a[i],i});
    }
    sort(v.begin(),v.end());
    for (int i=0; i<n; i++){
        lvl = v[i].fi;
        int idx = v[i].se;

        Update(idx,1);
        ++cnt;
        int nxtcur;
        if (i+1==n) nxtcur = LLINF+2;
        else nxtcur = cur+(v[i+1].fi - lvl)*cnt;
//        cout << lvl << " " << idx << " " << cnt << " " << cur << " " << nxtcur << endl;
        while (!pq.empty() && pq.top().fi <= nxtcur){
            int val = pq.top().fi;
            int idx2 = pq.top().se;
//            cout << "rawr " << val << " " << idx2 << endl;
            pq.pop();

            ans[idx2] = GetIdx((val-cur-1)%cnt+1);
        }
        cur = nxtcur;
    }
    for (int i=1; i<=q; i++){
        cout << ans[i] << endl;
    }
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(0);

    return 0;
}
