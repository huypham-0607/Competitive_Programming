#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 3e5;
const int INF = 2e9;

int test;
int n = maxn;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
mt19937 mt2(chrono::steady_clock::now().time_since_epoch().count());

int rd(int l, int r){
    return l+mt()%(r-l+1);
}

int sgen(){
    return mt2();
}

signed main(){
    freopen("LUOI.INP","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << n << endl;

    for (int i=2; i<=n; i++){
        cout << 1 << " " << i << endl;
    }

//    vector<int> v;
//    for (int i=1; i<=n; i++){
//        v.push_back(i);
//    }
//
//    vector<int> v2;

//    shuffle(v.begin(),v.end(),mt2);

//    cout << "meow" << endl;
    for (int i=0; i<n; i++){
        if (!i) v2.push_back(v[i]);
        else{
            int idx = rd(0,i-1);
            cout << v2[idx] << " " << v[i] << endl;
            v2.push_back(v[i]);
//            cout << idx << endl;
        }
    }

    cout << n << endl;

    for (int i=1; i<=n; i++){
        cout << rd(1,maxn) << " " << rd(1,maxn) << " " << rd(1,maxn) << endl;
    }
    return 0;
}
