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
const int LG = 31;
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
int n;
set<int> pos;
int Kyrie[N];
int last[N];
int pre[N],a[N];
int cnt[N],cnt2[N];

//SEGGS
int IT[N*4];

void Build(int idx, int l, int r){
    if (l==r){
        if (cnt2[l]%2==0) IT[idx] = 1;
        else IT[idx] = 0;
        return;
    }
    int mid = (l+r)/2;
    Build(idx*2,l,mid);
    Build(idx*2+1,mid+1,r);
    IT[idx] = IT[idx*2] + IT[idx*2+1];
}

int Get(int idx, int l, int r, int x, int y){
    if (r<x || y<l) return 0;
    if (x<=l && r<=y) return IT[idx];

    int mid = (l+r)/2;
    return Get(idx*2,l,mid,x,y) + Get(idx*2+1,mid+1,r,x,y);
}


/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        last[i] = Kyrie[i] = pre[i] = cnt[i] = 0;
        cin >> a[i];
        int x = a[i];
        pre[i] = (pre[i-1]^x);
    }
    for (int i=1; i<=n; i++){
        for (int idx=0; idx<LG; idx++){
            if (pre[i]&(1<<idx)) ++cnt[i];
        }
    }
    int cur = 0;
    for (int i=0; i<LG; i++){
        cur += (1<<i);
    }
    int c = 31;
    pos.insert(0);
    ll res =0;
//    for (int i=1; i<=n; i++){
//        cout << cnt[i] << " ";
//    }
//    cout << endl;
    for (int i=n; i>0; i--){
        cnt2[i] = (cnt[i-1]%2);
    }
    Build(1,1,n);
//    for (int i=1; i<=n; i++){
//        cout << cnt[i] << " ";
//    }
//    cout << endl;
    for (int i=1; i<=n; i++){
        bool v = 0;
        for (int idx=0; idx<LG; idx++){
            if (!(a[i]&(1<<idx))){
                if (!(cur&(1<<idx))){
                    Kyrie[last[idx]]--;
                    if (Kyrie[last[idx]]==0) pos.erase(last[idx]);
                }
                else --c;
                last[idx] = i;
                Kyrie[i]++;
                if (!v) pos.insert(i);
                v = true;
            }
        }
        cur = (cur&a[i]);
//        cout << c << " " << cur << endl;
        int tmp = c;
        for (auto it=pos.begin(); it!=pos.end(); it++){
            int j = *it;
            auto it2 = next(it);
            if (j==i) continue;
            tmp+=Kyrie[j];
//            cout << i << " " << j  << " " << tmp << endl;
            if (((tmp)%2)){
                int cock = Get(1,1,n,j+1,*it2);
                if (cnt[i]%2==1) cock = (*it2-j)-cock;
//                cout << "rawr: " << i << " " << j << " " << tmp << " " << cock << " " << *it2 << endl;
                res+=cock;
            }
        }
    }
    pos.clear();
//    cout << Get(1,1,n,1,2) << endl;
    cout << res << endl;
}

/*Driver Code*/
signed main(){
    freopen("SUBARRAY.inp","r",stdin);
    freopen("SUBARRAY.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
