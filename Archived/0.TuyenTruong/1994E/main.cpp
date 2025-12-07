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
const int LG = 20;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;
int a[N];

int Update(int x, int val){
//    cout << val << endl;
    int req = (((1<<LG)-1)^x);
    for (int i=LG-1; i>=0; i--){
//        cout << i << " " << val << " " << req << endl;
        if (val >= req){
            x=x|((1<<(i+1))-1);
            return x;
        }
        if (val&(1<<i)){
            x|=(1<<i);
            val^=(1<<i);
        }
        if (req&(1<<i)){
            req^=(1<<i);
        }
    }
    return x;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        int tmp = 0;
        for (int j=1; j<a[i]; j++){
            cin >> tmp;
        }
    }
    sort(a+1,a+1+n,greater<int>());
    int ans = 0;
    for (int i=1; i<=n; i++){
        ans = Update(ans,a[i]);
    }
    cout << ans << endl;
//    for (int i=10; i>=0; i--){
//        if (ans&(1<<i)) cout << 1;
//        else cout << 0;
//    }
//    cout << endl << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
