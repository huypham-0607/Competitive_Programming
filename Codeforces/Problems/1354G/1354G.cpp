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

int rand(int l, int r) {
    return (rd()%(r-l+1))+l;
}

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,k;

void answer(int x) {
    cout << "! " <<  x << endl;
    cout.flush();
}

void ask(vector<int> &a, vector<int>&b) {
    cout << "? " << a.size() << " " << b.size();
    cout << endl;
    for (auto x:a) {
        cout << x << " ";
    }
    cout << endl;
    for (auto x:b) {
        cout << x << " ";
    }
    cout << endl;
    cout.flush();
}

int getres() {
    string s; cin >> s;
    if (s == "FIRST") return 0;
    if (s == "SECOND") return 1;
    if (s == "EQUAL") return 2;
    if (s == "WASTED") return -1;
    return -1;
}

void solve(){
    cin >> n >> k;

    vector<int> a,b;

    int flag = true;
    for (int i=1; i<=25; i++){
        int x = rand(2,n);
        a.clear();
        b.clear();
        a.push_back(1);
        b.push_back(x);
        ask(a,b);
        int res = getres();
        if (res == -1) exit(0);
        if (res == 1) flag =false;
        if (!flag) break;
    }

    if (!flag) {
        answer(1);
        return;
    }
    
    int lg = 0;
    while ((1<<(lg+1)) <= n) {
        // cout << "range: " << (1<<(lg+1)) << endl;
        a.clear();
        b.clear();
        for (int i=1; i<=(1<<lg); i++){
            a.push_back(i);
        }
        for (int i=(1<<lg)+1; i<=(1<<(lg+1)); i++){
            b.push_back(i);
        }
        ask(a,b);
        int res = getres();
        if (res == -1) exit(0);
        assert(res != 1);
        if (res == 0) {
            break;
        }

        ++lg;
    }

    int l=1, r=(1<<lg);
    for (int lg2 = lg; lg2 >= 0; lg2--) {
        if (r + (1<<lg2) > n) continue; 
        a.clear(); b.clear();
        for (int i=1; i<=(1<<lg2); i++){
            a.push_back(i);
            b.push_back(r+i);
        }
        ask(a,b);
        int res = getres();
        if (res == -1) exit(0);
        assert(res != 1);
        if (res == 2) {
            r = r+(1<<lg2);
        }
    }

    answer(r+1);
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

