/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const int BSIZE = 316;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,q,K;
int a[N];
vector<piii> query;
int cnt[BSIZE+10];


/*Solution*/
void solve(){
    cin >> n >> q;
    int K = floor(sqrt(n));
    for (int i=1; i<=q; i++){
        int s,l,d;
        cin >> s >> l >> d;
        if (d<K){
            query.push_back({d,{s,1}});
            query.push_back({d,{s+l*d,-1}});
        }
        else{
            for (int i=0; i<l; i++){
                a[s+d*i]++;
            }
        }
    }
    sort(all(query));
    int idx = 0;
    for (int x=1; x<K; x++){
        for (int i=1; i<=n; i++){
            int md = i%x;
            while (idx!=(int)query.size() && query[idx].fi==x && query[idx].se.fi==i){
                cnt[md]+=query[idx].se.se;
                ++idx;
            }
            a[i]+=cnt[md];
        }
        while (idx!=(int)query.size() && query[idx].fi==x){
            int md = query[idx].se.fi%x;
            cnt[md]+=query[idx].se.se;
            ++idx;
        }
    }
    for (int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

