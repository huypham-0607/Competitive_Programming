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
const int N = 1e6+10;
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

int pi[N];
string s,t;

/*Solution*/
void solve(){
    cin >> t;
    cin >> s;
    pi[0] = 0;
    for (int i=1; i<(int)s.size(); i++){
        int cur = i;
        while (cur!=0){
            if (s[i]==s[pi[cur-1]]){
                pi[i] = pi[cur-1]+1;
                break;
            }
            cur = pi[cur-1];
        }
        if (cur == 0){
            if (s[i] == s[0]) pi[i] = 1;
            else pi[i] = 0;
        }
    }
//    for (int i=0; i<(int)s.size(); i++){
//        cout << pi[i] << " ";
//    }
//    cout << endl;
    s = s+"#";
    int ans = 0;
    int prev = 0;
    for (int i=0; i<(int)t.size(); i++){
        if (t[i] == s[prev]){
            prev = prev+1;
        }
        else{
            int cur = prev;
            while (cur!=0){
                if (t[i] == s[pi[cur-1]]){
                    prev = pi[cur-1]+1;
                    break;
                }
                cur = pi[cur-1];
            }
            if (cur==0){
                if (t[i] == s[0]) prev = 1;
                else prev = 0;
            }
        }
        if (prev == int(s.size())-1) ++ans;
    }
    cout << ans;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
