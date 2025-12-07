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

struct Node{
    int l,r,cnt;
    Node(): l{0},r{0},cnt{0}{};

    void Init(int x){
        l = 0;
        r = 0;
        if (x==2) l = 1;
        if (x==1) r = 1;
    }
};

/*Global Variables*/
int n;
int exist[N];
vector<int> a,b;
vector<Node> High,Low;

void Comb(Node& x, Node& l, Node& r){
    int mn = min(l.r, r.l);
    x.cnt = l.cnt+r.cnt+mn;
    x.l = l.l+r.l-mn;
    x.r = r.r+l.r-mn;
}

void Build(vector<Node>& IT, int idx, int l, int r){
    if (l == r){
//        cout << idx << " " << l << " " << r << " " << exist[l] << endl;
        IT[idx].Init(exist[l]);
        return;
    }
    int mid = (l+r)/2;
    Build(IT,idx*2,l,mid); Build(IT,idx*2+1,mid+1,r);
    Comb(IT[idx],IT[idx*2],IT[idx*2+1]);
}

void Update(vector<Node>& IT, int idx, int l, int r, int x, int val){
    if (x < l || r < x) return;
    if (l == r){
        IT[idx].Init(val);
        return;
    }
    int mid = (l+r)/2;
    Update(IT,idx*2,l,mid,x,val); Update(IT,idx*2+1,mid+1,r,x,val);
    Comb(IT[idx],IT[idx*2],IT[idx*2+1]);
}

/*Solution*/
void solve(){
    cin >> n;
    n = 2*n;
    High.resize(N*4); Low.resize(N*4);
    a.push_back(0); b.push_back(0);
    for (int i=1; i<=n/2; i++){
        int x;
        cin >> x;
        b.push_back(x);

        exist[x] = 2;
    }
    for (int i=n; i>0; i--){
        if (!exist[i]){
            exist[i] = 1;
            a.push_back(i);
        }
    }
//    for (int i=1; i<=n; i++){
//        cout << exist[i] << " ";
//    }
//    cout << endl;
    int ans = 0;
    Build(Low,1,1,n);
//    cout << High[1].cnt << " " << Low[1].cnt << endl;
    ans = max(ans,High[1].cnt+Low[1].cnt);
    for (int i=1; i<=n/2; i++){
        Update(Low,1,1,n,a[i],0);
        Update(Low,1,1,n,b[i],0);
        Update(High,1,1,n,a[i],2);
        Update(High,1,1,n,b[i],1);
//        cout << High[1].cnt << " " << Low[1].cnt << endl;
        ans = max(ans,High[1].cnt+Low[1].cnt);
    }
    cout << ans;
}

/*Driver Code*/
int main(){
    freopen("cardgame.in","r",stdin);
    freopen("cardgame.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
