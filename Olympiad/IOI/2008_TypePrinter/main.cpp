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
string longest;

struct Trie{
    struct Node{
        Node* child[26];
        bool exist;
        Node(){
            for (int i=0; i<26; i++){
                child[i] = NULL;
            }
            exist = 0;
        };
    };

    Node* Root;
    int cnt;
    Trie(){
        cnt = 0;
        Root = new Node();
    }

    void Add(string s){
        if (s.size() > longest.size()){
            longest = s;
        }
        Node* cur = Root;
        for (char f:s){
            int idx = f-'a';
            if (cur->child[idx] == NULL){
                cur->child[idx] = new Node();
                ++cnt;
            }
            cur = cur->child[idx];
        }
        cur->exist = true;
    }
    void DFS(Node* cur, int pos, bool OnLongest){
        if (cur->exist) cout << "P" << endl;
        for (int idx=0; idx<26; idx++){
            if (cur->child[idx] != NULL){
                if (OnLongest && pos!=(int)longest.size() && idx == longest[pos]-'a') continue;
                cout << char('a'+idx) << endl;
                DFS(cur->child[idx],pos+1,false);
                cout << "-" << endl;
            }
        }
//        cout << "woof" << endl;
        if (OnLongest && pos!=(int)longest.size()){
            cout << longest[pos] << endl;
            DFS(cur->child[(longest[pos]-'a')],pos+1,true);
        }
    }
};

Trie TR;

/*Solution*/
void solve(){
    cin >> n;
    string s;
    longest = "";
    for (int i=1; i<=n; i++){
        cin >> s;
        TR.Add(s);
    }
//    cout << "rawr" << endl;
    cout << TR.cnt*2-longest.size()+n << endl;
    TR.DFS(TR.Root, 0, true);
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(0);

    return 0;
}
