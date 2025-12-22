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
const int N = 1e3+10;
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
vector<pii> v;
string ans[N];

struct Trie{
    struct Node{
        Node* child[2];
        bool IsFull;
        Node(){
            child[0] = child[1] = NULL;
            IsFull = false;
        }
    };

    Node* Root;
    Trie(){
        Root = new Node();
    }

    void Recur(Node* cur, int x, int h){
//        cout << x << " " << h << endl;
        if (h==x){
            cur->IsFull = true;
            return;
        }
        if (cur->child[0] == NULL){
            cur->child[0] = new Node();
            Recur(cur->child[0],x,h+1);
        }
        else if (!cur->child[0]->IsFull){
            Recur(cur->child[0],x,h+1);
        }
        else{
            if (cur->child[1] == NULL) cur->child[1] = new Node();
            Recur(cur->child[1],x,h+1);
        }
        if (cur->child[1]!=NULL && cur->child[0]->IsFull && cur->child[1]->IsFull) cur->IsFull = true;
    }

    void Add(int x){
        Recur(Root,x,0);
    }
    void DFS(Node* cur, string& s, int &cnt){
        if (cur->child[0] == NULL && cur->child[1] == NULL){
            ++cnt;
            ans[v[cnt].se] = s;
            return;
        }
        if (cur->child[0]!=NULL){
            s+="0";
            DFS(cur->child[0],s,cnt);
            s.pop_back();
        }
        if (cur->child[1]!=NULL){
            s+="1";
            DFS(cur->child[1],s,cnt);
            s.pop_back();
        }
    }
};

Trie TR;

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        v.push_back({x,i});
    }
    v.push_back({0,0});
    sort(v.begin(),v.end());
    for (int i=1; i<=n; i++){
//        cout << x << endl;
        int x = v[i].fi;
//        int idx = v[i].se;
        if (TR.Root->IsFull){
            cout << "NO" << endl;
            return;
        }
        TR.Add(x);
    }
//    cout << endl << "rawr" << endl;
    cout << "YES" << endl;
    string s;
    int cnt = 0;
    TR.DFS(TR.Root,s,cnt);
    for (int i=1; i<=n; i++){
        cout << ans[i] << endl;
    }
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(0);

    return 0;
}

