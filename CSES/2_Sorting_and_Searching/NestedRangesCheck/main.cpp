#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;

int child[maxn],parent[maxn];
int n;
ii in[maxn];
map<int,int> pcheck,ccheck,test;
vector<ii> v;

int main(){
    freopen("main.inp","r",stdin);
    freopen("main.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        int l,r;
        cin >> l >> r;
        in[i] = {l,r};
        ccheck[-r]++;
        v.push_back({l,i});
    }
    sort(v.begin(),v.end());
    for (int i=0; i<n; i++){
        //int left = v[i].fi;
        int idx = v[i].se;
        //cout << idx << "\n";
        int right = in[idx].se;
        ccheck[-right]--;
        if (ccheck[-right] == 0) ccheck.erase(-right);
        //cout << "meow" << "\n";
        if (n!=n-1){
            if (!(((ccheck.lower_bound(-right)) -> fi) == ((ccheck.end()) -> fi))){
                child[idx] = 1;
            }
        }
//        for (auto ptr = ccheck.begin(); ptr != ccheck.end(); ptr++){
//            cout << ptr -> fi << " ";
//        }
//        cout << "\n";
        //cout << "woof" << "\n";
        if (!((pcheck.lower_bound(right) -> fi) == (pcheck.end()-> fi ))){
            parent[idx] = 1;
        }
//        for (auto ptr = pcheck.begin(); ptr != pcheck.end(); ptr++){
//            cout << ptr -> fi << " ";
//        }
//        cout << "\n";
        pcheck[right]++;
    }
    for (int i=1; i<=n; i++){
        cout << child[i] << " ";
    }
    cout << "\n";
    for (int i=1; i<=n; i++){
        cout << parent[i] << " ";
    }
//    cout << ((--test.upper_bound(9999))) -> fi;
//    cout << lower_bound(v.begin(),v.end(),0) - v.begin();
//    cout << x;
    return 0;
}
