/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e6+10;
const int INF = 1e9+7;
const int LG = 20;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,P,q;
int a[N],b[N];
int DNC[LG+2][N];
int mask[N];
int x = 0;

void BuildDNC(int l, int r, int lg){
    if (l==r) return;
    int mid = (l+r)/2;
//    cout << lg << " " << mid << endl;
    DNC[lg][mid] = a[mid]; DNC[lg][mid+1] = a[mid+1];
    for (int i=mid-1; i>=l; i--) DNC[lg][i] = (DNC[lg][i+1]*a[i])%P;
    for (int i=mid+2; i<=r; i++) DNC[lg][i] = (DNC[lg][i-1]*a[i])%P;
    for (int i=l; i<=mid; i++) mask[i]^=((ll)1<<lg);
    BuildDNC(l,mid,lg+1); BuildDNC(mid+1,r,lg+1);
}

/*Solution*/
void solve(){
    cin >> n >> P >> q;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    BuildDNC(0,n-1,0);

//    cerr << "meow" << endl;

    for (int i=0; i<q/64+2; i++){
        cin >> b[i];
    }
    int ans;
    int l,r;
    x = 0;
    for (int i=0; i<q; i++){
        if (i%64==0){
            l = (b[i/64]+x)%n;
            r = (b[i/64+1]+x)%n;
            if (l>r) swap(l,r);
        }
        else{
            l = (l+x)%n;
            r = (r+x)%n;
            if (l>r) swap(l,r);
        }
        if (l<0 || l>=n || r<0 || r>=n){
            while (true) cout << "rawr" << endl;
        }
        if (l==r) ans = a[l];
        else{
            int lg = __builtin_ctzll(mask[l]^mask[r]);
            ans = (DNC[lg][l]*DNC[lg][r])%P;
        }
        x = (ans+1)%P;
//        cout << l << " " << r << " " << ans << endl;
    }
    cout << x << endl;
    for (int i=0; i<n; i++){
        a[i] = 0;
        mask[i] = 0;
    }
    for (int i=0; i<q/64+2; i++){
        b[i] = 0;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
