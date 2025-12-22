/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n;

//Segment Tree
struct SegmentTree{
    struct Node{
        int val,pos;
        Node(){
            val = INF;
            pos = INF;
        }
    };

    int n;
    vector<Node> IT;

    Node comb(Node l, Node r){
        if (l.val == INF) return r;
        if (r.val == INF) return l;

        Node i;
        i.val = max(l.val,r.val);
        i.pos = ((l.val == i.val)? l.pos : r.pos);

        return i;
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].val = 0;
            IT[idx].pos = 0;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, int val, int pos){
        if (r < x || x < l) return;
        if (l==r){
            IT[idx].val = val;
            IT[idx].pos = pos;
            return;
        }
        int mid = (l+r)/2;
        update(idx*2,l,mid,x,val,pos);
        update(idx*2+1,mid+1,r,x,val,pos);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    Node getNode(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return Node();
        if (x <= l && r <= y){
            return IT[idx];
        }

        int mid = (l+r)/2;
        return comb(getNode(idx*2,l,mid,x,y),getNode(idx*2+1,mid+1,r,x,y));

    }

    void init(int _n){
        n = _n;
        IT.resize(n*4+10, Node());
        build(1,1,n);
    }
};

void Ask(vector<int>& v){
    cout << "? ";
    int cnt = 0;
    for (int i=1; i<=n*n+1; i++){
        if (!v[i]) ++cnt;
    }
    cout << cnt << " ";
    for (int i=1; i<=n*n+1; i++){
        if (!v[i]) cout << i << " ";
    }
    cout << "\n";
    cout.flush();
}

void Print(vector<int>& ans){
    cout << "! ";
    for (int i=0; i<n+1; i++){
        int x = ans[i];
        cout << x << " ";
    }
    cout << "\n";
    cout.flush();
}


/*Solution*/
void solve(){
    cin >> n;
    if (n==-1) exit(0);
    vector<int> v(n*n+5,0);
    vector<int> trace(n*n+5,0);
    SegmentTree IT;
    IT.init(n*n+2);
    for (int idx=1; idx<=n; idx++){
        Ask(v);
        int k;
        cin >> k;
        if (k==-1) exit(0);
        vector<int> res;
        while (k--){
            int x; cin >> x;
            if (x==-1) exit(0);
            res.push_back(x);
        }

//        if (res.size() >= n+1){
//            Print(res);
//            return;
//        }
        for (int i=(int)res.size()-1; i>=0; i--){
////            cout << i << " " << res[i] << endl;
            v[res[i]] = idx;
            SegmentTree::Node node = IT.getNode(1,1,n*n+2,res[i]+1,n*n+2);
            int val = i+1+node.val;
//            cout << node.pos << " " << node.val << " " << val << endl;
            if (val >= n+1){
                vector<int> ans;
                for (int j=0; j<=i; j++){
                    ans.push_back(res[j]);
                }
                int pos = node.pos;
                while (pos){
//                    cout << pos << endl;
                    ans.push_back(pos);
                    pos = trace[pos];
                }
                Print(ans);
                return;
            }

            trace[res[i]] = node.pos;
            IT.update(1,1,n*n+2,res[i],node.val+1,res[i]);
        }
    }

    for (int i=1; i<=n*n+1; i++){
        if (!v[i]) v[i] = n+1;
    }

    vector<int> sus;
    int cur = n+1;
    for (int i=n*n+1; i>0; i--){
        if (v[i] == cur){
            --cur;
            sus.push_back(i);
        }
    }
    reverse(all(sus));
    Print(sus);
    return;
    vector<int> tmp;
    for (int i=1; i<=n+1; i++){
        tmp.push_back(i);
    }
    Print(tmp);
//    cout << 0/0;
}

/*Driver Code*/
signed main(){
//    cin.tie(0) -> sync_with_stdio(0);

    int testCount = 1;
    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
