/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,k;
int a[N];
vector<int> v,pal,pos,cnt;

/*Solution*/
void solve(){
    v.clear();
    pal.clear();
    pos.clear();
    cnt.clear();
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        v.push_back(a[i]);
    }
    if (k == 1){
        cout << "YES" << endl;
        return;
    }
    sort(all(v));
    int x = v[k-2];
    for (int i=1; i<=n; i++){
        if (a[i]<x){
            pal.push_back(a[i]);
            pos.push_back(i);
        }
    }
    int m = pal.size();
    for (int i=0; i<m/2; i++){
        if (pal[i]!=pal[m-i-1]){
            cout << "NO" << endl;
            return;
        }
    }

    int sz = m+1;
    cnt.resize(sz,0);
    for (int i=1; i<=n; i++){
        if (a[i] == x){
            int idx = lower_bound(all(pos),i)-pos.begin();
            cnt[idx]++;
        }
    }

//    bool ver = false;
//    if ((sz%2) && cnt[sz/2]) ver = true;
    int total = 0;
    for (int i=0; i<sz/2; i++){
        total = total + min(cnt[i],cnt[sz-i-1])*2;
    }
    if (sz%2) total = total + cnt[sz/2];
    if (total>=k-1-m){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
//    cout << m << " " << total << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
