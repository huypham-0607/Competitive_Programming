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
const int N = 5e5+10;
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
int pi[N];

void KMP(){
    pi[0] = 0;
    for (int i=1; i<(int)s.size(); i++){
        int j = pi[i-1];
        while (j>0 && s[i]!=s[j]){
            j = pi[j-1];
        }
        if (s[i] == s[j]){
            pi[i] = j+1;
        }
        else pi[i] = 0;
    }
}

bool check(int pos){
//    cout << "Checked: " << pos << endl;
    int prev = 0;
    int last = -1;
    for (int i=0; i<(int)s.size(); i++){
        int j = prev;
        if (j > pos) j = pi[j-1];
        while (j>0 && s[i]!=s[j]){
            j = pi[j-1];
        }
        if (s[i] == s[j]){
            prev = j+1;
            if (prev > pos){
                last = i;
            }
        }
        else prev = 0;
//        cout << i << " " << prev << " " << last << endl;
        if (i - last > pos) return false;
    }
    return true;
}

/*Solution*/
void solve(){
    cin >> s;
    KMP();
//    for (int i=0; i<(int)s.size(); i++){
//        cout << pi[i] << " ";
//    }
//    cout << endl;
    int res = s.size();
    int ans = s.size()-1;
//    cout << ans << endl;
    while (ans>=0){
        if (2*pi[ans]<=ans+1){
            if (check(ans)){
                res = ans+1;
            }
        }
        ans = pi[ans]-1;
//        cout << ans << endl;

    }
    cout << res << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
