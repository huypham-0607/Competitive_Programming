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

int n,q;
string samp = "#bessie";
string s;

struct Node{
    int ans;
    int dp[6],change[6],cnt[6];
    Node(){
        ans = 0;
        for (int i=0; i<6; i++){
            dp[i] = 0;
            change[i] = i;
            cnt[i] = 0;
        }
    }
    void Init(char c, int pos){
        for (int i=0; i<6; i++){
            dp[i] = 0;
            change[i] = i;
            cnt[i] = 0;
        }
        ans = 0;
        if (c == 'b') dp[1] = 1;
        else if (c!='#') dp[0] = 1;
        for (int i=0; i<6; i++){
            if (c == samp[i+1]){
                change[i] = (i+1)%6;
                if (i==5) cnt[i]+=(n-pos+1);
            }
        }
    }
};

/*Global Variables*/
Node IT[N*4];

void Comb(Node& x, Node& l, Node& r){
    x.Init('#',0);
    x.ans = l.ans+r.ans;
    for (int i=0; i<6; i++){
        x.ans+=l.dp[i]*r.cnt[i];
        x.dp[r.change[i]]+=l.dp[i];
        x.dp[i]+=r.dp[i];
        x.change[i] = r.change[l.change[i]];
        x.cnt[i] = l.cnt[i] + r.cnt[l.change[i]];
    }
}

void Build(int idx, int l, int r){
    if (l == r){
        IT[idx].Init(s[l],l);
//        cout << idx << " " << l << " " << r << endl;
//        for (int i=0; i<6; i++) cout << IT[idx].dp[i] << " ";
//        cout << endl;
//        for (int i=0; i<6; i++) cout << IT[idx].change[i] << " ";
//        cout << endl;
//        for (int i=0; i<6; i++) cout << IT[idx].cnt[i] << " ";
//        cout << endl;
        return;
    }
    int mid = (l+r)/2;
    Build(idx*2,l,mid); Build(idx*2+1,mid+1,r);
    Comb(IT[idx],IT[idx*2],IT[idx*2+1]);
}

void Update(int idx, int l, int r, int x, char c){
    if (x < l || r < x) return;
//    cout << idx << endl;
    if (l == r){
        IT[idx].Init(c,x);
        return;
    }
    int mid = (l+r)/2;
    Update(idx*2,l,mid,x,c); Update(idx*2+1,mid+1,r,x,c);
    Comb(IT[idx],IT[idx*2],IT[idx*2+1]);
}

/*Solution*/
void solve(){
    cin >> s;
    n = (int) s.size();
//    cout << n << endl;
    s = "#" + s;
    Build(1,1,n);
    cout << IT[1].ans << endl;
    cin >> q;
    while (q--){
        int x; char c;
        cin >> x >> c;
//        cout << x << " " << c << endl;
        Update(1,1,n,x,c);
        cout << IT[1].ans << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
