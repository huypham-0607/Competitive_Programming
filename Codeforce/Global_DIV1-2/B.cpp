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
vector<int> tmp;

/*Solution*/
void solve(){
    cin >> n;
    if (n == 1){
        cout << 1 << " " << 1 << endl;
        return;
    }
    int maxodd = n-1 + (((n-1)%2)? 0 : -1);
    int maxeven = n-1 + (((n-1)%2)? -1 : 0);
//    cout << maxeven << " " << maxodd << endl;
    for (int i=maxeven; i>0; i-=2){
        cout << i << " ";
        tmp.push_back(i);
    }
    cout << n << " ";
    for (int i = tmp.size()-1; i>=0; i--){
        cout << tmp[i] << " ";
    }
    tmp.clear();
    for (int i=maxodd; i>1; i-=2){
        cout << i << " ";
        tmp.push_back(i);
    }
    cout << 1 << " ";
    cout << n << " ";
    for (int i = tmp.size()-1; i>=0; i--){
        cout << tmp[i] << " ";
    }
    tmp.clear();
    cout << 1 << " ";
    cout << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
