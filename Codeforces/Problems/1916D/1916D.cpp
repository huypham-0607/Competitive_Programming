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

void solve(){
    cin >> n;
    if (n==1) {
        cout << 1 << endl;
        return;
    }
    else {
        vector<string> v;
        v.push_back("169");
        v.push_back("196");
        v.push_back("961");
        for (int idx=2; idx<=(n-1)/2; idx++){
            frep(i,0,v.size()){
                v[i].push_back('0');
                v[i].push_back('0');
            }
            string s = "1";
            ffor(i,1,idx-1){
                s.push_back('0');
            }
            s.push_back('6');
            ffor(i,1,idx-1){
                s.push_back('0');
            }
            s.push_back('9');
            v.push_back(s);
            swap(s[0],s[s.size()-1]);
            v.push_back(s);
        }
        frep(i,0,v.size()){
            cout << v[i] << endl;
        }
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
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

