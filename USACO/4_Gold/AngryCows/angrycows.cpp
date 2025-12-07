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
const int N = 2e5+10;
const int INF = 2e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,mx=0,mn=INF;
int a[N];
int sus[N];

bool check2(int mid, int lvl){
    int pos = lower_bound(a+1,a+1+n,mid)-a-1;
    for (int i=1; i<=n; i++){
        sus[i] = -1;
    }
    int j = pos;
    while (mid-lvl<=a[j]){
        sus[j] = max(sus[j],max((int)0,lvl-2));
        --j;
    }
    for (int i=pos; i>0; i--){
        if (sus[i]<0) return false;
        while (a[i]-sus[i]<=a[j]){
            sus[j] = max(sus[j],max((int)0,sus[i]-2));
            --j;
        }
    }
    return true;
}

bool check3(int mid, int lvl){
    int pos = lower_bound(a+1,a+1+n,mid)-a-1;
    for (int i=1; i<=n; i++){
        sus[i] = -1;
    }
    int j = pos;
    while (mid+lvl>=a[j]){
        sus[j] = max(sus[j],max((int)0,lvl-2));
        ++j;
    }
    for (int i=pos; i<=n; i++){
        if (sus[i]<0) return false;
        while (a[i]+sus[i]>=a[j]){
            sus[j] = max(sus[j],max((int)0,sus[i]-2));
            ++j;
        }
    }
    return true;
}

bool check1(int mid2){
    int lans = mn;
    int l = mn, r = mx;
    while (l<=r){
        int mid = (l+r)/2;
        if (check2(mid,mid2)){
            lans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }

    int rans = mx;
    l = mn, r = mx;
    while (l<=r){
        int mid = (l+r)/2;
        if (check3(mid,mid2)){
            rans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
//    check2(26,mid2);
//    for (int i=1; i<=n; i++){
//        cout << sus[i] << " ";
//    }
//    cout << endl;
//    check3(rans,mid2);
//    for (int i=1; i<=n; i++){
//        cout << sus[i] << " ";
//    }
//    cout << endl;
//    cout << mid2 << " " << lans << " " << rans << endl << endl;
    if (lans<rans) return false;
    else return true;
}

/*Solution*/
void solve(){
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
//    freopen("angrycows.inp","r",stdin);
//    freopen("angrycows.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        a[i]*=2;
        mx = max(mx,a[i]);
        mn = min(mn,a[i]);
    }
    sort(a+1,a+1+n);
    a[0] = -INF*2;
    a[n+1] = INF*3;
    int ans = INF+1;
    int l = 0, r = INF;
    while (l<=r){
        int mid = (l+r)/2;
        if (check1(mid)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << fixed << setprecision(1) << ((long double)1.0*ans)/2 << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
