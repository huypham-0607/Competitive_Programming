/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piiii pair<pii,pii>
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

int Getidx(char& c){
    if (c=='A') return 0;
    if (c=='C') return 1;
    if (c=='G') return 2;
    if (c=='U') return 3;
    return 4;
}

//Rawr
struct Point{
    int x,y;
    Point(){
        x = y = 0;
    }
};


/*Global Variables*/
string a[N],b[N],c[N],d[N];
Point pts[N];
pii qx[N], qy[N];
int ans[N];

int n,m;

//BIT
struct BIT{
    int n;
    int pre[N];

    BIT(int n_): n(n_){
        for (int i=1; i<=n; i++){
            pre[i] = 0;
        }
    };

    void Add(int pos){
        while (pos<=n){
            ++pre[pos];
            pos += (pos&(-pos));
        }
    }

    int GetPre(int pos){
        int res = 0;
        while (pos>0){
            res+=pre[pos];
            pos-=(pos&(-pos));
        }
        return res;
    }

    int Get(int l, int r){
        if (l==0 || r==0) return 0;
        return GetPre(r)-GetPre(l-1);
    }
};

//Trie
struct Trie{
    struct Node{
        Node* child[4];
        vector<int> query,lst;
        int cnt;
        Node(){
            for (int idx=0; idx<4; idx++){
                child[idx] = NULL;
                cnt = 0;
            }
        }
    };

    Node* Root;
    Trie(){
        Root = new Node();
    }

    void AddString(string s, int x){
        Node* cur = Root;
        for (auto c:s){
            int idx = Getidx(c);
            if (cur->child[idx]==NULL) cur->child[idx] = new Node();
            cur = cur->child[idx];
            ++cur->cnt;
        }
        cur->lst.push_back(x);
    }

    void AddQuery(string s, int x){
        Node* cur = Root;
        for (auto c:s){
            int idx = Getidx(c);
            if (cur->child[idx]==NULL) cur->child[idx] = new Node();
            cur = cur->child[idx];
        }
        cur->query.push_back(x);
    }

    void Traverse(Node* cur, int& rawr, pii p[], bool xaxis){
        if (cur->lst.size()!=0 || cur->query.size()!=0) ++rawr;
        for (auto i:cur->lst){
            if (xaxis) pts[i].x = rawr;
            else pts[i].y = rawr;
        }
        for (auto i:cur->query){
            p[i].fi = rawr;
        }
//        cout << rawr << endl;
        for (int idx=0; idx<4; idx++){
            if (cur->child[idx]!=NULL){
//                cout << idx << " ";
                Traverse(cur->child[idx],rawr,p,xaxis);
            }
        }
//        cout << l << " " << r << endl;
        for (auto i:cur->query){
            p[i].se = rawr;
        }
    }
};

Trie pre,suf;

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        pre.AddString(a[i],i);
        b[i] = a[i];
        reverse(b[i].begin(),b[i].end());
        suf.AddString(b[i],i);
    }
    for (int i=1; i<=m; i++){
        cin >> c[i];
        pre.AddQuery(c[i],i);
        cin >> d[i];
        reverse(d[i].begin(),d[i].end());
        suf.AddQuery(d[i],i);
    }
    int limx = 0;
    pre.Traverse(pre.Root,limx,qx,true);
    int limy = 0;
    suf.Traverse(suf.Root,limy,qy,false);

    BIT fw(limy);
    vector<piiii> v,query;
    for (int i=1; i<=n; i++){
        v.push_back({{pts[i].x,i},{pts[i].y,pts[i].y}});
    }
    for (int i=1; i<=m; i++){
        query.push_back({{qx[i].fi-1,-i},{qy[i].fi,qy[i].se}});
        query.push_back({{qx[i].se,i},{qy[i].fi,qy[i].se}});
    }
    sort(v.begin(),v.end());
    sort(query.begin(),query.end());
    int i = 0;
    int j = 0;
    for (int idx=0; idx<=limx; idx++){
        while (i!=(int)v.size() && v[i].fi.fi==idx){
            fw.Add(v[i].se.fi);
            ++i;
        }
        while (j!=(int)query.size() && query[j].fi.fi==idx){
            if (query[j].fi.se<0){
                ans[-query[j].fi.se] -= fw.Get(query[j].se.fi,query[j].se.se);
            }
            else ans[query[j].fi.se] += fw.Get(query[j].se.fi,query[j].se.se);
            ++j;
        }
    }
//    cout << i << " " << j << endl;
    for (int i=1; i<=m; i++){
        cout << ans[i] << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
