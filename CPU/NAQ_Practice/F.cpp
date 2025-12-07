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
const long long LLINF = 1e18+3;

/*Global Variables*/
int n;

/*Solution*/
void solve(){
    string s; cin >> s;
    int rawr = 0, woof = 0;
    for (auto c:s){
        if (c == 'a') ++ rawr;
        if (c == 'e') ++ rawr;
        if (c == 'i') ++ rawr;
        if (c == 'o') ++ rawr;
        if (c == 'u') ++ rawr;
        if (c == 'y') ++ woof;
    }
    cout << rawr << " " << rawr+woof << endl;
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
