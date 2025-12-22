/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
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
int n;
string s;
int cnt[26];
int woof[15];
bool vis[26];

int GetC(int n, int k){
    return woof[n]/(woof[k]*woof[n-k]);
}

/*Solution*/
void solve(){
    cin >> n;
    cin >> s;

    for (int i=0; i<n; i++){
        vis[s[i]-'a'] = true;
    }

    int realans = INF;
    string realstring;

    for (int pos=0; pos<n; pos++){
        string st = s;
        for (int cr=0; cr<26; cr++){
            if (!vis[cr]) continue;
            for (int i=0; i<26; i++){
                cnt[i] = 0;
            }
            st[pos] = char('a'+cr);
//            cout << st << endl;
            for (int i=0; i<n; i++){
                cnt[st[i]-'a']++;
            }
            int ans = 1;
            int left = n;
            for (int idx=0; idx<26; idx++){
                ans = ans*GetC(left,cnt[idx]);
                left-=cnt[idx];
            }
            if (ans<realans){
                realans = ans;
                realstring = st;
            }
        }
    }

    cout << realstring << endl;
    for (int i=0; i<26; i++){
        vis[i] = false;
        cnt[i] = 0;
    }
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    woof[0] = 1;
    for (int i=1; i<=11; i++){
        woof[i] = woof[i-1]*i;
    }
    TestCases(1);

    return 0;
}
