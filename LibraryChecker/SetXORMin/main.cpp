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
const int LG = 29;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,q;

struct Trie {
    struct Node{
        Node* child[2];
        int cnt = 0;
        Node(){
            child[0] = child[1] = NULL;
            cnt = 0;
        }
    };
    Node* Root;
    Trie(){
        Root = new Node();
    }

    bool Find(int x){
        Node* cur = Root;
        for (int i=LG; i>=0; i--){
            int idx = (x>>i)&1;
            if (cur->child[idx] == NULL) return false;
            cur = cur->child[idx];
        }
        return true;
    }

    void Add(int x){
        if (Find(x)) return;
        Node* cur = Root;
        for (int i=LG; i>=0; i--){
            int idx = (x>>i)&1;
            if (cur->child[idx] == NULL) cur->child[idx] = new Node();
            cur = cur->child[idx];
            ++cur->cnt;
        }
    }

    bool DeleteNum(Node* cur, int x, int lg){
//        cout << "meow" << endl;
        if (lg>=0){
            int idx = (x>>lg)&1;
//            if (cur->child[idx] == NULL) cout << "Beanstalk" << endl;
            if (DeleteNum(cur->child[idx],x,lg-1)) cur->child[idx] = NULL;
        }
        if (cur!=Root){
            cur->cnt--;
//            cout << lg << " " << cur->cnt << endl;
            if (!cur->cnt){
                delete cur;
                return true;
            }
        }
        return false;
    }

    void Del(int x){
        if (!Find(x)) return;
        DeleteNum(Root,x,LG);
    }

    int Get(int x){
        int res = 0;
        Node* cur = Root;
        for (int i=LG; i>=0; i--){
            int idx = (x>>i)&1;
            if (cur->child[idx] == NULL){
//                cout << i << endl;
                res+=(1<<i);
                cur = cur->child[(idx^1)];
            }
            else cur = cur->child[idx];
        }
        return res;
    }
};

Trie TR;

/*Solution*/
void solve(){
    cin >> q;
    int Beanstalk,x;
    while (q--){
        cin >> Beanstalk >> x;
        if (Beanstalk == 0) TR.Add(x);
        if (Beanstalk == 1) TR.Del(x);
        if (Beanstalk == 2) cout << TR.Get(x) << endl;
    }
//    if (TR.Find(7)) cout << "rawr" << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
