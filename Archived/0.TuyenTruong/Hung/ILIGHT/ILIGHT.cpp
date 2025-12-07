/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<pii,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e5+10;
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
int n,m,k;
vector<int> nen;
int org[N];
int lst[N];
int a[N][2];
int query[N];
priority_queue<piii> pq;

//Seggs
int ST[N*3*4];

void UpdateST(int idx, int l, int r, int x, int val){
    if (x < l || r < x) return;
    if (l == r){
        ST[idx] = max(ST[idx],val);
        return;
    }
    int mid = (l+r)/2;
    UpdateST(idx*2,l,mid,x,val); UpdateST(idx*2+1,mid+1,r,x,val);
    ST[idx] = max(ST[idx*2],ST[idx*2+1]);
}

int QueryST(int idx, int l, int r, int x, int y){
    if (y < l || r < x) return 0;
    if (x <= l && r <= y) return ST[idx];
    int mid = (l+r)/2;
    return max(QueryST(idx*2,l,mid,x,y),QueryST(idx*2+1,mid+1,r,x,y));
}

//BIT
int BIT[N];

void UpdateBIT(int x, int val){
    while (x<=k){
        BIT[x]+=val;
        x+=(x&(-x));
    }
}

int QueryBIT(int x){
    int res = 0;
    while (x>0){
        res+=BIT[x];
        x-=(x&(-x));
    }
    return res;
}

int GetBIT(int x){
    return (QueryBIT(k)-QueryBIT(x-1));
}

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i][0] >> a[i][1];
        if (a[i][0] > a[i][1]){
            swap(a[i][0],a[i][1]);
            org[i] = 1;
        }
//        cout << org[i] << endl;
        nen.push_back(a[i][0]);
        nen.push_back(a[i][1]);
    }
    for (int i=1; i<=k; i++){
        cin >> query[i];
        nen.push_back(query[i]);
    }
    nen.push_back(0);
    sort(nen.begin(),nen.end());
    nen.resize(unique(nen.begin(),nen.end()) - nen.begin());
    m = nen.size();
    for (int i=1; i<=n; i++){
        a[i][0] = lower_bound(nen.begin(),nen.end(),a[i][0])-nen.begin();
        a[i][1] = lower_bound(nen.begin(),nen.end(),a[i][1])-nen.begin();
//        cout << a[i][0] << " " << a[i][1] << endl;
    }
    for (int i=1; i<=k; i++){
        query[i] = lower_bound(nen.begin(),nen.end(),query[i])-nen.begin();
        UpdateST(1,1,m,query[i],i);
        pq.push({{query[i],n+1},i});
    }
    for (int i=1; i<=n; i++){
        lst[i] = QueryST(1,1,m,a[i][0],a[i][1]-1);
//        cout << lst[i] << endl;
        if (lst[i]!=0){
            org[i] = 1;
        }
        pq.push({{a[i][1],i},lst[i]+1});
    }
    while (!pq.empty()){
        int idx = pq.top().fi.se;
        int pos = pq.top().se;
        pq.pop();

        if (idx>n){
            UpdateBIT(pos,1);
        }
        else{
//            cout << idx << " " << pos << " " << GetBIT(pos) << endl;
            org[idx] = (org[idx]+GetBIT(pos))%2;
        }
    }
    ll ans = 0;
//    cout << endl;
    for (int i=1; i<=n; i++){
//        cout << org[i] << " " << nen[a[i][org[i]]] << endl;
        ans+=nen[a[i][org[i]]];
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
//    freopen("ILIGHT.inp","r",stdin);
//    freopen("ILIGHT.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
