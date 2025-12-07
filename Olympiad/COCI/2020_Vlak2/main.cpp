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
int n,m;

//Trie

struct Trie{
    struct Node{
        bool reach[2];
        Node* child[26];
        Node(){
            for (int i=0; i<26; i++) child[i] = NULL;
            reach[0] = reach[1] = 0;
        }
    };

    Node* Root;

    Trie(){
        Root = new Node();
        Root->reach[0] = Root->reach[1] = 1;
    }

    void AddString(string s, int id){
        Node* cur = Root;
        for (auto f:s){
            int idx = f-'a';
            if (cur->child[idx] == NULL) cur->child[idx] = new Node();
            cur = cur->child[idx];
            cur -> reach[id] = true;
        }
    }

    bool Magic(int pos, Node* cur, string &s){
        if (!(cur->reach[pos%2])) return 0;
        bool res = true;
//        cout << s << " " << res << " " <<  pos << endl;
        for (int i=0; i<26; i++){
            if (cur->child[i]!=NULL){
//                cout << s << " " << res << " " <<  pos << endl;
                s += char('a'+i);
                res = (res && !(Magic(pos+1,cur->child[i],s)));
                s.pop_back();
            }
        }
//        cout << s << " " << pos << " " << res << endl;
//        cout << s << " " << res << " " <<  pos << endl;
        return res;
    }

    bool Solve(){
        bool ans = 0;
        string s;
        for (int i=0; i<26; i++){
            if (Root->child[i]!=NULL){
                s += char('a'+i);
                ans = (Magic(0,Root->child[i],s) || ans);
                s.pop_back();
            }
        }
        return ans;
    }
};

Trie TR;

/*Solution*/
void solve(){
    cin >> n;
    string s;
    for (int i=1; i<=n; i++){
        cin >> s;
        TR.AddString(s,0);
    }
    cin >> m;
    for (int i=1; i<=m; i++){
        cin >> s;
        TR.AddString(s,1);
    }
    if (TR.Solve()){
        cout << "Nina" << endl;
    }
    else cout << "Emilija" << endl;
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(0);

    return 0;
}
