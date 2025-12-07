/*Author: NotKawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 3e5+5;
const int INF = 1e9;
const long long LLINF = 1e18+3;
const int LG = 20;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

class TRIE{
private:
    vector<int> flip;
    struct Node{
        Node* child[2];
        int level;
        bool full;
    };
    Node* makeNode(){
        Node* n = new Node;
        n->child[0] = n->child[1] = NULL;
        n->full = 0;
        n->level = 0;
        return n;
    }
    Node* root;
public:
    TRIE(){
        flip.resize(LG + 5,0);
        root = makeNode();
        root->level = LG + 1;
    }
    bool isFull(Node* t){
        if (t == NULL) return 0;
        if (t->level == 0){
            return t->full = 1;
        }
        t->full = isFull(t->child[0]) & isFull(t->child[1]);
        return t->full;
    }
    void PreProcess(){
        isFull(root);
    }
    void Add(int x){
        Node* tmp = root;
        for (int i = LG; i >= 0; i--){
            bool f = (x >> i) & 1;
            if (tmp->child[f] == NULL){
                tmp->child[f] = makeNode();
                tmp->child[f]->level = tmp->level - 1;
            }
            tmp = tmp->child[f];
        }
    }
    void Update(int x){
        for (int i = 0; i < LG; i++){
            if (x & (1 << i)) flip[i] ^= 1;
        }
    }
    int MEX(Node* t,int cur){
        if (t == NULL || t->level == 0) return cur;
        bool f = flip[t->level - 1];
        if (t->child[f] != NULL && t->child[f]->full) return MEX(t->child[f ^ 1],cur | (1 << (t->level - 1)));
        return MEX(t->child[f],cur);
    }
    int MEX(){
        return MEX(root,0);
    }
};

/*Global Variables*/
int n,m;
int a[N];
TRIE t;

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        t.Add(a[i]);
    }
    t.PreProcess();
    while(m--){
        int x;
        cin >> x;
        t.Update(x);
        cout << t.MEX() << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
