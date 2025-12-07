#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "ENCODE"

using namespace std;

const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

int n,k,q;
vector<int> org;
vector<pii> query;

void Init(){
    cin >> n >> k >> q;
    for (int i=1; i<=n; i++){
        int x; cin >> x;
        org.push_back(x);
    }
    for (int i=1; i<=q; i++){
        int x,y; cin >> x >> y;
        query.push_back({x,y});
    }
}

namespace Sub1{
    bool CheckSub(){ return true; }

    map<vector<int>,int> mp;
    vector<int> tmp;
    vector<vector<int>> v;

    void Brute(int sz){
//        cout << sz << endl;
//        for (int i=0; i<sz-1; i++){
//            for (int j=0; j<(int)v[i].size(); j++){
//                cout << v[i][j];
//            }
//            cout << " ";
//        }
//        cout << endl;
        if (sz>n){
            vector<vector<int>> tmp2 = v;
            sort(all(tmp2));
            for (int i=0; i<n; i++){
                tmp[i] = tmp2[i].size();
            }
            mp[tmp]++;
            return;
        }
        for (int i=1; i<=k; i++){
            if (sz == 1){
                v.push_back(vector<int> (1,i));
            }
            else{
                vector<int> sus = {i};
                for (int id=0; id<(int)v.back().size(); id++){
                    sus.push_back(v.back()[id]);
                }
                v.push_back(sus);
            }

            Brute(sz+1);
            v.pop_back();
        }
    }

    void SolveSub(){
        for (int i=1; i<=n; i++){
            tmp.push_back(i);
        }

        do{
            mp[tmp] = 0;
        } while (next_permutation(all(tmp)));

        Brute(1);

        cout << mp[org] << endl;
        for (auto in:query){
            int l,r; tie(l,r) = in;
            --l; --r;
            swap(org[l],org[r]);
            cout << mp[org] << endl;
        }
    }
}

namespace Sub2{
    bool CheckSub(){ return false; }

    void SolveSub(){}
}

namespace Sub3{
    bool CheckSub(){ return false; }

    void SolveSub(){}
}



signed main(){
    freopen(NAME ".inp","r",stdin);
    freopen(NAME ".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Init();
    if (Sub1::CheckSub()) return Sub1::SolveSub(),0;
    if (Sub2::CheckSub()) return Sub2::SolveSub(),0;
    if (Sub3::CheckSub()) return Sub3::SolveSub(),0;

    return 0;
}
