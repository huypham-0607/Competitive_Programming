#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define fi first
#define se second

using namespace std;

const int maxsieve = 1e7;
const ll INF = 1e13;

vector<int> prime;
int primediv[maxsieve+4];
ll mul[maxsieve+4];
int a[maxsieve];

void sieve(){
    primediv[0] = -1;
    primediv[1] = -1;
    for (ll i=2; i*i<=maxsieve; i++){
        if (!primediv[i]){
            for (ll j=i*i; j<=maxsieve; j+=i){
                primediv[j] = i;
            }
        }
    }
    for (int i=2; i<=maxsieve; i++){
        if (!primediv[i]){
            primediv[i] = i;
            prime.push_back(i);
        }
    }
}

ll getexp(ll n, ll p){
    ll temp = 0, pw = p;
    while (true){
        temp+=n/pw;
        if (n / p < pw) return temp;
        pw*=p;
    }
    return 0;
}

ll check(ll n){
    for (int p:prime) if (getexp(n,p) < mul[p]) return false;
    return true;
}

long long bsearch(){
    long long l = 1, r = INF,res = -1;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid)){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return res;
}

signed main(){
    freopen("factorial.INP","r",stdin);
    freopen("factorial.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    //cout << prime.size() << "\n";
    int n;
    int cntspec = 0;
    cin >> n;
    a[0] = 0;
    for (ll i=1; i<=n; i++){
        cin >> a[i];
        if (a[i] == 1) cntspec++;
    }
    if (cntspec == n){
        cout << 0;
        return 0;
    }
    sort(a,a+n+1);
    //cout << "meow" << "\n";
    for (int i=0; i<=n-1; i++){
        for (int j = a[i]+1; j<=a[i+1]; j++){
            //cout << i << " " << j << "\n";
            int t=j;
            while (t>1){
                mul[primediv[t]]+=(n-i);
                t/=primediv[t];
                //cout << t << "\n";
            }
        }
    }
    cout << bsearch();
//    cout << "\n";
//    for (ll i=0; i<=15; i++){
//        cout << prime[i] << " " << mul[prime[i]] << "\n";
//    }
    return 0;
}
