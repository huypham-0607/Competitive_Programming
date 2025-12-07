/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e6+10;
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
int n,m,ans=0;
int a[N];
int tmp[N];
int pi[N];
vector<pii> v;

//BIT
int BIT[N];

void rawr(int n){
    for (int i=1; i<=n; i++){
        BIT[i] = 0;
    }
}

void update(int x, int val, int mx){
    while(x<=mx){
        BIT[x]+=val;
        x+=(x&(-x));
    }
}

int get(int x){
    int ans = 0;
    while (x>0){
        ans+=BIT[x];
        x-=(x&(-x));
    }
    return ans;
}

void KMP1(){
    pi[1] = 0;
    int l = 2;
    for (int i=2; i<=n; i++){
        update(a[i],1,n);
        int j = pi[i-1];
        while (j>0 && get(a[i])!=tmp[j+1]){
            j = pi[j];
            while (l<i-j){
                update(a[l],-1,n);
                ++l;
            }
        }
        if (get(a[i]) == tmp[j+1]){
            pi[i] = j+1;
        }
        else pi[i] = 0;
    }
}

void KMP2(){
    int prev = 0;
    int l = 1;
    for (int i=1; i<=m; i++){
        update(a[i],1,m);
        int j = prev;
        while (j>0 && get(a[i])!=tmp[j+1]){
            j = pi[j];
            while (l<i-j){
                update(a[l],-1,m);
                ++l;
            }
        }
        if (get(a[i]) == tmp[j+1]){
            prev = j+1;
            if (prev == n){
                ++ans;
                v.push_back({i-n+1,0});
            }
        }
        else prev = 0;
    }
}

/*Solution*/
void solve(){
    cin >> n >> m;
    int x;
    for (int i=1; i<=n; i++){
        cin >> x;
        a[x] = i;
    }
    for (int i=1; i<=n; i++){
        update(a[i],1,n);
        tmp[i] = get(a[i]);
    }
    rawr(n);
    KMP1();
    pi[n+1] = -1;
    rawr(n);
    for (int i=1; i<=m; i++){
        cin >> x;
        v.push_back({x,i});
    }
    sort(v.begin(),v.end());
    for (int i=0; i<m; i++){
        a[v[i].se] = i+1;
    }
    v.clear();
    KMP2();
    cout << ans << endl;
    for (int i=0; i<ans; i++){
        cout << v[i].fi << " ";
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
