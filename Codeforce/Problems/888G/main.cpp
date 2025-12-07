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
int n;
vector<int> a;

struct Trie{

    struct Node{
        Node* child[2];
        int cnt;
        int l,r;
        Node(){
            child[0] = child[1] = NULL;
            cnt = 0;
            l = INF;
            r = 0;
        }
    };

    Node* Root;
    int cnt;
    Trie(){
        Root = new Node();
        cnt = 0;
    }

    void Init(){
        clr(Root);
    }
    void clr(Node* cur){
        if (cur->child[0]!=NULL){
            clr(cur->child[0]);
            cur->child[0]=NULL;
        }
        if (cur->child[1]!=NULL){
            clr(cur->child[1]);
            cur->child[1]=NULL;
        }
        if (cur!=Root) delete cur;
    }
    void Add(int x, int pos){
        Node* cur = Root;
        for (int i=29; i>=0; i--){
            int idx = ((x>>i)&1);
            if (cur->child[idx] == NULL) cur->child[idx] = new Node();
            cur = cur->child[idx];
            cur->cnt++;
            cur->l = min(cur->l,pos);
            cur->r = max(cur->r,pos);
        }
    }
    int Get(int x, Node* cur, int lg){
        int res = 0;
        if (cur->cnt<=0) return INF;
        for (int i=lg; i>=0; i--){
            int idx = ((x>>i)&1);
            if (cur->child[idx] == NULL){
                res = res+(1<<i);
                cur = cur->child[(idx+1)%2];
            }
            else{
                cur = cur->child[idx];
            }
        }
        return res;
    }
    void DC(Node* cur, ll&ans, int lg){
//        cout << cur->l << " " << cur->r << " " << lg << endl;
        if (cur!=Root && cur->cnt<=1) return;
//        int msk = (1<<lg);
        int res = INF;
        Node* lnode = cur->child[0];
        Node* rnode = cur->child[1];
        if (lnode!=NULL && rnode!=NULL){
            for (int i=rnode->l; i<=rnode->r; i++){
//                cout << i << " ";
                res = min(res,Get(a[i],lnode,lg-1));
            }
//            cout << endl;
        }
        if (res != INF){
            ans+=res+(1<<lg);
        }
//        cout << "res: " << res << endl;
        if (lnode!=NULL) DC(lnode,ans,lg-1);
        if (rnode!=NULL) DC(rnode,ans,lg-1);
}
};

Trie TR;

//void DC(int l, int r, ll&ans, int rawr){
//    TR.cnt = 0;
//    if (l >= r) return;
//    int msk = (1<<rawr);
//    int bar = 0;
//    int res = INF;
//    for (int i=l; i<=r; i++){
//        if (!bar && (a[i]&msk)) bar = i;
//        if (bar) res = min(res,TR.Get(a[i],rawr));
//        else{
//            TR.cnt++;
//            TR.Add(a[i],rawr);
//        }
//    }
//    if (!bar) bar = r+1;
//    if (res != INF){
//        ans+=res;
//    }
//    DC(l,bar-1,ans,rawr-1);
//    DC(bar,r,ans,rawr-1);
//}

/*Solution*/
void solve(){
    cin >> n;
    a.push_back(-1);
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    n = a.size()-1;
    for (int i=1; i<=n; i++){
        TR.Add(a[i],i);
    }
    ll ans = 0;
    TR.DC(TR.Root,ans,29);
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(0);

    return 0;
}
