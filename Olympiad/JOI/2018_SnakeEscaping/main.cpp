/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
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
int n,q;
int a[(1<<20)+10];
int f[(1<<20)+10];
int g[(1<<20)+10];
int dp[(1<<6)+10];
vector<int> pos;

int BasedOne(int m, int x, vector<int>& pos){
    int res = 0;
    for (int mask=0; mask<(1<<m); mask++){
        int cnt = m-__builtin_popcount(mask);
        int val = 0;
        for (int i=0; i<m; i++){
            if (mask&(1<<i)) val = (val^(1<<pos[i]));
        }
        if (cnt%2) res-=f[x|val];
        else res+=f[x|val];
    }
    return res;
}

int BasedZero(int m, int x, vector<int>& pos){
    int res = 0;
    for (int mask=0; mask<(1<<m); mask++){
        int cnt = __builtin_popcount(mask);
        int val = 0;
        for (int i=0; i<m; i++){
            if ((mask&(1<<i))) val = (val^(1<<pos[i]));
        }
        if (cnt%2) res-=g[x|val];
        else res+=g[x|val];
    }
    return res;
}

int BasedQuestion(int m, int x, vector<int>& pos){
    int res = 0;
    for (int mask=0; mask<(1<<m); mask++){
//        int cnt = __builtin_popcount(mask);
        int val = x;
        for (int i=0; i<m; i++){
            if (mask&(1<<i)) val = (val^(1<<pos[i]));
        }
        res+=a[val];
    }
    return res;
}



/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=0; i<(1<<n); i++){
        char c; cin >> c;
        f[i] = c-'0';
        a[i] = c-'0';
        g[i] = c-'0';
    }
    for (int i=0; i<n; i++){
        for (int mask=0; mask<(1<<n); mask++){
            if (mask&(1<<i)){
                f[mask]+=f[mask^(1<<i)];
            }
        }
    }

    for (int i=0; i<n; i++){
        for (int mask=(1<<n)-1; mask>=0; mask--){
            if (!(mask&(1<<i))){
                g[mask]+=g[mask^(1<<i)];
            }
        }
    }

    string s;
    for (int i=1; i<=q; i++){
        pos.clear();
        cin >> s;
        int x=0;
        int mask0=0,mask1=0,maskq=0;
        int zerocnt=0,onecnt=0,questioncnt=0;
        for (int i=0; i<n; i++){
            int idx = n-i-1;
            if (s[i] == '?'){
                ++questioncnt;
                maskq = maskq^(1<<idx);
            }
            if (s[i] == '1'){
                ++onecnt;
                mask1 = mask1^(1<<idx);
            }
            if (s[i] == '0'){
                ++zerocnt;
                mask0 = mask0^(1<<idx);
            }
        }
        int mn = min({zerocnt,onecnt,questioncnt});
        if (zerocnt == mn){
            for (int i=n-1; i>=0; i--){
                int idx = n-i-1;
                if (s[i] == '0'){
                    pos.push_back(idx);
                }
            }
            cout << BasedZero(zerocnt,mask1,pos) << endl;
        }
        else if (onecnt == mn){
            for (int i=n-1; i>=0; i--){
                int idx = n-i-1;
                if (s[i] == '1'){
                    pos.push_back(idx);
                }
                if (s[i] == '?'){
                    x = x^(1<<idx);
                }
            }
            cout << BasedOne(onecnt,maskq,pos) << endl;
        }
        else {
            for (int i=n-1; i>=0; i--){
                int idx = n-i-1;
                if (s[i] == '?'){
                    pos.push_back(idx);
                }
            }
            cout << BasedQuestion(questioncnt,mask1,pos) << endl;
        }
//        cout << "x: " << x << " " << f[x] << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
