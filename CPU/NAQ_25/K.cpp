/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
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

int ask(int i, int j){
    cout << "?" << " " << i << " " << j << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}

void answer(int i, int j){
    cout << "!" << " " << i << " " << j << endl;
    cout.flush();
}

int n;

void process0(){
    int x = ask(1,2);
    int y = ask(2,1);
    if (x&&y){
        answer(1,1);
        return;
    }
    if (x){
        answer(1,2);
        return;
    }
    if (y){
        answer(2,1);
        return;
    }
    answer(2,2);
}

void process1(){
    int x = ask(1,4);
    int y = ask(2,5);
    if (x&&y){
        answer(1,4);
        return;
    }
    if (x){
        answer(1,3);
        return;
    }
    if (y){
        answer(2,4);
        return;
    }
    answer(2,3);
}

void process2(){
    int x = ask(4,1);
    int y = ask(5,2);
    if (x&&y){
        answer(4,1);
        return;
    }
    if (x){
        answer(3,1);
        return;
    }
    if (y){
        answer(4,2);
        return;
    }
    answer(3,2);
}

void process3(){
    int x = ask(5,4);
    int y = ask(4,5);
    if (x&&y){
        answer(4,4);
        return;
    }
    if (x){
        answer(4,3);
        return;
    }
    if (y){
        answer(3,4);
        return;
    }
    answer(3,3);
}

int a[4];

void solve(){
    a[0] = ask(2,2);
    a[1] = ask(2,4);
    a[2] = ask(4,2);
    for (int i=0; i<4; i++){
        if (a[0]){
            process0();
            return;
        }
        if (a[1]){
            process1();
            return;
        }
        if (a[2]){
            process2();
            return;
        }
    }
    process3();
    return;
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

