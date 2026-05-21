/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
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
const int LG = 5;
const int BR = 2;
const long long LLINF = 1e18+3;

//Starts here

int a,b;
int cnt1[LG],cnt2[LG];

void solve(){
    cin >> a >> b;
    for (int lg=LG-1; lg>=0; lg--) {
        cnt1[lg] = a/(1<<lg);
        cnt2[lg] = b/(1<<lg);
        a%=(1<<lg);
        b%=(1<<lg);
    }
    string s = "A";
    int cur = 0;
    for (int lg=0; lg<LG; lg++){
        if (lg <= BR) {
            while (cur!=(1<<lg)) {
                s += 'T';
                ++cur;
            }
            if (lg == 0) {
                s += 'A';
            }
        }
        if (cur == BR) {
            cur = 1;
        }
        if (lg >= BR) {
            while (cur!=(1<<lg)) {
                s+='A';
                ++cur;
            }
        }

        for (int i=1; i<=cnt1[lg]; i++){
            s+='C';
        }
        for (int i=1; i<=cnt2[lg]; i++){
            s+='G';
        }
    }
    reverse(s.begin(),s.end());
    cout << s << endl;
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

