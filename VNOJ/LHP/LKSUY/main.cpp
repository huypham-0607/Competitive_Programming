/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 5010;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

class TRIE{
private:
    struct Node{
        Node* child[26];
        int exist, cnt;
        Node(){
            for (int i=0; i<26; i++) child[i] = NULL;
            exist = cnt = 0;
        }
    };
    Node* root = new Node();
public:
    int dp[N];
    void Add_String(string s){
        Node*p = root;
        for (auto f:s){
            int c = f-'a';
//            cout << c << endl;
            if (p->child[c] == NULL) p->child[c] = new Node();
            p = p->child[c];
            p->cnt++;
        }
        p->exist++;
    }
    void Bruh(string s, int idx){
        Node*p = root;
        s = s.substr(idx,s.size());
        for (int i=0; i<(int)s.size(); i++){
            char f = s[i];
            int c = f-'a';
            if (p->child[c] == NULL) return;
            p = p->child[c];
            dp[idx+i+1] = (dp[idx+i+1]+(dp[idx]*(p->exist))%INF)%INF;
        }
    }
};

/*Global Variables*/
int n;
string s;
TRIE TR;

/*Solution*/
void solve(){
    cin >> s;
    cin >> n;
    string meow;
    TR.dp[0] = 1;
    for (int i=1; i<=n; i++){
        cin >> meow;
//        cout << "{" << meow << "}" << endl;
        TR.Add_String(meow);
    }
    for (int i=0; i<(int)s.size(); i++){
        TR.Bruh(s,i);
    }
//    for (int i=0; i<=s.size(); i++){
//        cout << TR.dp[i] << " ";
//    }
//    cout << endl;
    cout << TR.dp[(int)s.size()];
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(0);

    return 0;
}
