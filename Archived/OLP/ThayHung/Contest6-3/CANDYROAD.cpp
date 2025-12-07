#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 1e9;
const int mod = 998244353;

int test;
int n,m;
int a[maxn];
map<int,int> mp;

int epic(int x){
    if (x<0) return x+mod*(abs(x)/mod + ((abs(x)%mod)? 1 : 0));
    else return x%mod;
}

signed main(){
    freopen("CANDYROAD.INP","r",stdin);
    freopen("CANDYROAD.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    int res = ((((1+m)*m/2)%mod)*((n*(n-1)/2+n)%mod))%mod;
//    cout << res << endl;
    int total_sub = 0;
//    int total_num = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];

        if (mp.find(a[i]) == mp.end()){
            mp[a[i]] = i;
            total_sub += a[i]*(i)%mod;
            total_sub = epic(total_sub);
//            total_num+=i;
        }
        else{
            int pos = mp[a[i]];
            total_sub+=a[i]*(i-pos)%mod;
            mp[a[i]] = i;
        }
//        total_sub+=total_num;
//        cout << a[i] << " " << total_sub << " " << total_num << endl;
        res-=total_sub;
        res = epic(res);
    }
    cout << res;
//    cout << endl;
//    cout << epic(-mod*5+69420);
//    cout << endl;
    return 0;
}
