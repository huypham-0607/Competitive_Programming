#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int main(){
    freopen("cetvrta.INP","r",stdin);
    freopen("cetvrta.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<ii> p(3);
    for (int i = 0; i < 3; i++) cin >> p[i].fi >> p[i].se;
    sort(p.begin(),p.end());
    for (int i = 0; i < 3; i++){
        if (p.size() > 3) break;
        for (int j = i + 1; j < 3; j++){
            if (p[i].fi == p[j].fi) continue;
            if (p[i].se == p[j].se) continue;
            p.push_back(ii(p[i].fi,p[j].se));
            for (int k = 0; k < 3; k++){
                if (p[k] == p[3]){
                    p.pop_back();
                    p.push_back(ii(p[j].fi,p[i].se));
                    break;
                }
            }
        }
    }
    cout << p[3].fi << " " << p[3].se;
    return 0;
}
