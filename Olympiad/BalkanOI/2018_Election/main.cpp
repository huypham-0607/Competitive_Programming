/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "elections"

using namespace std;

/*Constants*/
const int N = 5e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

vector<int> a(N);

struct Node{
    int t;
    int pre, suf;
    int mid;
    int ans;

    Node(){
        t = 0;
        pre = 0;
        suf = 0;
        mid = 0;
        ans = INF;
    }

    void DB(){
        cout << t << " ";
        cout << pre << " ";
        cout << suf << " ";
        cout << mid << " ";
        cout << ans << " ";
        cout << endl;
    }
};

Node Comb(Node x, Node y){
    if (x.ans == INF) return y;
    if (y.ans == INF) return x;
    Node res;

    res.ans = 0;

    res.t = x.t + y.t;

    res.pre = x.pre;
    res.suf = y.suf;

    int tpre = y.pre + y.mid;
    int tsuf = x.suf + x.mid;
    int mpre = 0;
    int msuf = 0;

    tpre = max(0,tpre + x.t);
    int deltapre = max(0,tpre - (x.pre+x.mid));
    if (deltapre < y.mid){
        res.mid+=deltapre;
        res.suf+=abs(y.mid - deltapre);
    }
    else{
        res.mid+=y.mid;
        mpre+=abs(deltapre - y.mid);
    }

    tsuf = max(0,tsuf + y.t);
    int deltasuf = max(0,tsuf - (y.suf+y.mid));
    if (deltasuf < x.mid){
        res.mid+=deltasuf;
        res.pre+=abs(x.mid - deltasuf);
    }
    else{
        res.mid+=x.mid;
        msuf+=abs(deltasuf - x.mid);
    }

    res.pre += mpre - min(mpre,msuf);
    res.suf += msuf - min(mpre,msuf);
    res.mid += min(mpre,msuf);
    res.ans += res.pre + res.suf + res.mid;

    return res;
}

struct SegTree{
    vector<Node> ST;
    int n;

    SegTree(){}

    void Build_Rec(int idx, int l, int r){
        if (l==r){
            ST[idx].t = a[l];
            if (a[l] == 1) ST[idx].mid = 1;
            else ST[idx].mid = 0;
            ST[idx].pre = 0;
            ST[idx].suf = 0;
            ST[idx].ans = ST[idx].mid;
            return;
        }
        else{
            int mid = (l+r)/2;
            Build_Rec(idx*2,l,mid);
            Build_Rec(idx*2+1,mid+1,r);
            ST[idx] = Comb(ST[idx*2],ST[idx*2+1]);
            return;
        }
    }

    void Build(int _n){
        n = _n;
        ST.resize(n*4+10);
        Build_Rec(1,1,n);
    }

    Node Query_Rec(int idx, int l, int r, int x, int y){
        if (r < x || y < l) return Node();
        if (x<=l && r<=y){
            return ST[idx];
        }
        int mid = (l+r)/2;
        return Comb(Query_Rec(idx*2,l,mid,x,y),Query_Rec(idx*2+1,mid+1,r,x,y));
    }

    int Query(int l, int r){
        Node res = Query_Rec(1,1,n,l,r);
        return res.ans;
    }
} ST;

/*Global Variables*/
int n,q;

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        char c; cin >> c;
        if (c == 'C') a[i] = -1;
        else a[i] = 1;
    }

    ST.Build(n);

    cin >> q;
    for (int i=1; i<=q; i++){
        int l,r; cin >> l >> r;
        cout << ST.Query(l,r) << endl;
    }

}

/*Driver Code*/
signed main(){
//    freopen(NAME".in","r",stdin);
//    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
