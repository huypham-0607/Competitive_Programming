/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
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
int la[26], ra[26];
int lb[26], rb[26];
string a[N];
string b[N];
int assa[N];
int assb[N];

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        cin >> b[i];
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);

    int prev = -1;
    for (int i=1; i<=n; i++){
        int val = a[i][0] - 'A';
        if (val != prev) {
            if (prev != -1) ra[prev] = i-1;
            la[val] = i;
            prev = val;
        }
    }
    if (prev != -1) {
        ra[prev] = n;
    }

    for (int i=1; i<=n; i++){
        int val = b[i][0] - 'A';
        if (val != prev) {
            if (prev != -1) rb[prev] = i-1;
            lb[val] = i;
            prev = val;
        }
    }
    if (prev != -1) {
        rb[prev] = n;
    }


    for (int val=0; val<26; val++){
        int* tag1 = assa;
        int* tag2 = assb;

        int l1 = la[val];
        int r1 = ra[val];
        int l2 = lb[val];
        int r2 = rb[val];

        // cout << l1 << " " << l2 << endl;

        if ((l1 == 0) || (l2 == 0)) continue;
        int cnt1 = ra[val] - la[val]+1;
        int cnt2 = rb[val] - lb[val]+1;

        // cout << "meow" << endl;

        if (cnt2 < cnt1) {
            swap(tag1,tag2);
            swap(cnt1,cnt2);
            swap(l1,l2);
            swap(r1,r2);
        }

        // cout << "cnt: " << cnt1 << " " << cnt2 << endl;

        if (l2 <= l1 && r1 <= r2) {
            for (int i=0; i<cnt1; i++) {
                tag1[l1+i] = l1 + i;
                tag2[l1+i] = l1 + i;
            }
        }
        else {
            if (l2 < l1) {
                for (int i=0; i<cnt1; i++){
                    tag1[l1+i] = r2-cnt1+1+i;
                    tag2[r2-cnt1+1+i] = l1+i;
                }
            }
            else {
                for (int i=0; i<cnt1; i++) {
                    tag1[l1+i] = l2+i;
                    tag2[l2+i] = l1+i;
                }
            }
        }
    }

    // for (int i = 0; i < 26; i++) {
    //     cout << la[i] << " " << ra[i] << " " << lb[i] << " " << rb[i] << endl;
    // }

    // for (int i=1; i<=n; i++) {
    //     cout << assa[i] << " ";
    // }
    // cout << endl;

    int idx = 1;
    for (int i=1; i<=n; i++){
        if (assa[i]) continue;
        while (assb[idx]) ++idx;
        assa[i] = idx;
        assb[idx] = i;
    }

    for (int i=1; i<=n; i++){
        cout << a[i] << " " << b[assa[i]];
        if (i!=n) cout << ", ";
    }
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

