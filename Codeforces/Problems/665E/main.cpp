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

//Trie

struct Trie{
    struct Node{
        Node* child[2];
        int cnt;
        Node(){
            child[0] = child[1] = NULL;
            cnt = 0;
        }
    };
    Node* Root;
    Trie(){
        Root = new Node();
    }

    void Add(int x){
        Node* cur = Root;
        for (int i=LG-1; i>=0; i--){
            int idx = ((x>>i)&1);
//            cout << i << " " << idx << endl;
            if (cur->child[idx]==NULL) cur->child[idx] = new Node();
            cur = cur->child[idx];
            ++cur->cnt;
        }
    }

    int Get(int x, int k){
        Node* cur = Root;
        int res = 0;
        for (int i=LG-1; i>=0; i--){
            int idx = ((x>>i)&1);
//            cout << i << " " << idx << endl;
            if (!((k>>i)&1)){
                if (cur->child[(idx+1)%2]!=NULL) res+=cur->child[(idx+1)%2]->cnt;
                if (cur->child[idx]==NULL) return res;
                cur = cur->child[idx];
            }
            else{
                if (cur->child[(idx+1)%2]==NULL) return res;
                cur = cur->child[(idx+1)%2];
            }
        }
        res+=cur->cnt;
        return res;
    }
};

/*Global Variables*/
int n,k;
int a[N];
Trie tr;

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    ll res = 0;
    int cur = 0;
    tr.Add(0);
    for (int i=1; i<=n; i++){
        cur = (cur^a[i]);
//        cout << cur << " " << endl;
        res+=tr.Get(cur,k);
        tr.Add(cur);
    }
    cout << res << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
