#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "SEQ"

using namespace std;

const int N = 3e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

int n,k;
int a[N];
int cnt[N];
vector<int> nen;

void Init(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        nen.push_back(a[i]);
    }
    sort(all(nen));
    nen.resize(unique(all(nen)) - nen.begin());
    for (int i=1; i<=n; i++){
        a[i] = lower_bound(all(nen),a[i]) - nen.begin()+1;
    }
}

bool CheckSub1(){
    return true;
}

bool Check(int x){
    for (int i=1; i<=(int)nen.size(); i++){
        cnt[i] = 0;
    }
    for (int i=1; i<=n; i++){
        if (i>x){
            --cnt[a[i-x]];
        }
        cnt[a[i]]++;
        if (cnt[a[i]]>=x-k){
            return true;
        }
    }
    return false;
}

void SolveSub1(){
    int ans = 0;
    int l = 1;
    int r = n;
    while (l<=r){
        int mid = (l+r)/2;
        if (Check(mid)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    for (int i=1; i<=n; i++){
        cout << a[i] << endl;
    }
    cout << ans;
}

signed main()
{
    freopen(NAME ".inp","r",stdin);
    freopen(NAME ".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Init();
    if (CheckSub1()) return SolveSub1(), 0;

    return 0;
}
