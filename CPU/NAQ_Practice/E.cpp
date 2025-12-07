/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const int LG = 20;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n;

/*Solution*/
void solve(){
    cin >> n;
    vector<int> v;
    v.push_back(0);
    for (int i=1; i<=n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    vector<int> suf(n+10,0);

    for (int i=n; i>0; i--){

        int ver = false;
        v[i] += suf[i+1];
        for (int lg=LG-1; lg>=0; lg--){
            if ((1<<lg)&v[i]){
                if (ver) suf[i]+=2;
                ver = true;
            }
            else if (ver) suf[i]+=1;
        }
        suf[i] += suf[i+1];
    }

    string ans = "";

    for (int i=1; i<=n; i++){
        int ver = false;
        for (int lg=LG-1; lg>=0; lg--){
            if ((1<<lg)&v[i]){
                if (ver) ans+="d+1+";
                else ans+="1";
                ver = true;
            }
            else if (ver) ans+="d+";
        }
    }

    cout << ans << endl;
//    for (int i=1; i<=n; i++){
//        cout << suf[i] << " " << v[i] << endl;
//    }
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
