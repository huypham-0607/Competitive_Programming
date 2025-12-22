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

//Trie
struct Trie{
    struct Node{
        Node* child[26];
        bool exist;
        int cnt;
        Node(){
            for (int i=0; i<26; i++){
                child[i] = NULL;
                exist = false;
                cnt = 0;
            }
        }
    };
    Node* Root;
    Trie(){
        Root = new Node();
    }
    void Add(string& s){
        Node* cur = Root;
        for (int i=0; i<(int)s.size(); i++){
            char c = s[i];
            int idx = c-'a';
            if (cur->child[idx] == NULL) cur->child[idx] = new Node();
            cur = cur->child[idx];
            ++cur->cnt;
        }
        cur->exist = true;
    }

    priority_queue<int>* Recur(Node* cur, int depth){
//        cout << depth << endl;
        Node* Kyrie = NULL;
        for (int i=0; i<26; i++){
            if (cur->child[i]!=NULL && (Kyrie==NULL || Kyrie->cnt < cur->child[i]->cnt)) Kyrie = cur->child[i];
        }
        priority_queue<int>* u = ((Kyrie==NULL)? new priority_queue<int>(): Recur(Kyrie,depth+1));
        for (int i=0; i<26; i++){
            if (cur->child[i]==NULL) continue;
            Node* nxt = cur->child[i];
            if (nxt==Kyrie) continue;
            priority_queue<int>* v = Recur(nxt,depth+1);
            while (!v->empty()){
                u->push(v->top());
                v->pop();
            }
            delete v;
        }
        if (!cur->exist){
            u->pop();
            u->push(depth);
        }
        else if (cur!=Root) u->push(depth);
        return u;
    }

    int Solve(){
        Root->exist = true;
        auto pq = Recur(Root,0);
        int ans = 0;
        while (!pq->empty()){
            ans+=pq->top();
            pq->pop();
        }
        delete pq;
        return ans;
    }
};

/*Global Variables*/
int n;

/*Solution*/
void solve(){
    string s;
    Trie tr;
    cin >> n;
    while (n--){
        cin >> s;
        tr.Add(s);
    }
    cout << tr.Solve() << endl;
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(0);

    return 0;
}
