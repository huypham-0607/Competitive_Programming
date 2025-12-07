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
const int N = 5e3+10;
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
int n,k;
string s;
int dp[N];

//Trie

struct Trie{
    struct Node{
        Node* child[26];
        int exist, cnt;

        Node(): exist{0}, cnt{0} {
            for (int i=0; i<26; i++){
                child[i] = NULL;
            }
        }
    };

    Node* Root;

    Trie(){
        Root = new Node();
    }

    void Add(string &s){
        Node* cur = Root;
        for (int f:s){
            int idx = f-'a';
            if (cur->child[idx] == NULL){
                cur->child[idx] = new Node();
            }

            cur = cur->child[idx];
            (cur->cnt)++;
        }
        (cur->exist)++;
//        cout << s << " " << cur->exist << endl;
    }

    void Get(string &s, int pos){
        Node* cur = Root;
        for (int i=1; i<=(int)s.size(); i++){
            int idx = s[i-1]-'a';
            if (cur->child[idx] == NULL) return;

            cur = cur->child[idx];
            dp[pos+i] = (dp[pos+i] + (dp[pos]*(cur->exist))%INF)%INF;
//            cout << cur->exist << endl;
        }
    }
};

Trie TR;

/*Solution*/
void solve(){
    cin >> s;
    n = (int) s.size();
    cin >> k;
    string x;
    for (int i=1; i<=k; i++){
        cin >> x;
        TR.Add(x);
    }
    dp[0] = 1;
    for(int i=0; i<n; i++){
        x = "";
        for (int j=i; j<n; j++){
            x+=s[j];
        }
        TR.Get(x,i);
//        cout << x << " ";
//        for (int i=0; i<=n; i++){
//            cout << dp[i] << " ";
//        }
//        cout << endl;
    }
    cout << dp[n];
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
