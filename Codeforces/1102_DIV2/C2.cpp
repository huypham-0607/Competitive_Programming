/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define ffor(i, a, b) for(int i = a; i <= (b); ++i)
#define rfor(i, a, b) for(int i = a; i >= (b); --i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i > (b); --i)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

typedef int int2;
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int tmpa[N];
int offset;
int a[N];
int la[N],ra[N];
int res[N];

void solve(){
    cin >> n;
    int mx = 0;
    for (int i=1; i<=n+1; i++){
        la[i] = 0;
        ra[i] = 0;
    }
    for (int i=1; i<=n; i++){
        cin >> tmpa[i];
        mx = max(mx,tmpa[i]);
    }
    for (int i=1; i<=n; i++){
        if (tmpa[i] == mx) {
            offset = i;
            a[0] = tmpa[i];
            for (int delta=1; delta<=n; delta++){
                a[delta] = tmpa[(i+delta-1)%n+1];
            }
            break;
        }
    }

    // for (int i=0; i<=n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    stack<pair<int,int>> st;
    int t = 0;
    for (int i=1; i<=n; i++){
        int pos = i;
        t+=a[i];
        while (!st.empty() && st.top().fi <= a[i]) {
            t+=(pos-st.top().se)*(a[i]-st.top().fi);
            pos = st.top().se;
            st.pop();
        }
        st.push({a[i],pos});
        la[i] = t;
    }
    t = 0;
    while (!st.empty()) st.pop();
    for (int i=n; i>0; i--){
        int pos = i;
        t+=a[i-1];
        while (!st.empty() && st.top().fi <= a[i-1]) {
            t+=(st.top().se-pos)*(a[i-1]-st.top().fi);
            pos = st.top().se;
            st.pop();
        }
        st.push({a[i-1],pos});
        ra[i] = t;
    }

    // for (int i=1; i<=n; i++){
    //     cout << la[i] << " " << ra[i] << endl;
    // }

    for (int i=1; i<=n; i++){
        res[(offset+i-1)%n+1] = la[i-1] + ra[i+1];
    }
    for (int i=1; i<=n; i++){
        cout << res[i] << " ";
    }
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

