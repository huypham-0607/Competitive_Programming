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
const int N = 3e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;
const int LG = 19;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

struct Trie{
    struct Node{
        int exist,cnt;
        Node* child[2];

        Node() {
            child[0] = NULL;
            child[1] = NULL;
            exist = cnt = 0;
        }
    };

    int cur;
    Node* root;
    Trie(): cur(0) {
        root = new Node();
    }

    void AddNum(Node* p, int x, int i){
        int c = (x>>i)&1;
        if (p->child[c] == NULL){
            p->child[c] = new Node();
            if (i==0) p->cnt++;
        }
        if (i!=0){
            AddNum(p->child[c],x,i-1);
            p->cnt = p->child[0]->cnt + p->child[1]->cnt;
        }
    }

    void Add(int x){
        AddNum(root,x,LG);
    }

    int Query(int x){
        Node* p = root;
        int res = 0;
        for (int i=LG; i>=0; i--){
            int c = (x>>i)&1;
            if (i == 0){
                if (p->child[c] != NULL) c = (c+1)%2;
                res+=(c<<i);
            }
            else{
//            cout << c << " " ;
                if (p->child[c] == NULL){
                    res+=(c<<i);
                    for (int j=0; j<i; j++){
                        res+=((1<<j)&x);
                        return res;
                    }
                }
                else if (p->child[c]->cnt < (1<<i)){
                    res+=(c<<i);
                    p = p->child[c];
                }
                else{
                    c = (c+1)%2;

                }
//              cout << c << endl;
                res+=(c<<i);
                p = p->child[tmp];
            }
        }
        return res;
    }
};

/*Global Variables*/
int n,q;
Trie TR;
/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        TR.AddNum(x);
    }
    while (q--){
        int x;
        cin >> x;
        cout << "meow " << x << endl;
        cout << TR.Query(x) << endl;
    }
}

/*Driver Code*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
