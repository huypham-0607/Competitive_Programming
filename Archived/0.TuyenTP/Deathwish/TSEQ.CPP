#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "TSEQ"

using namespace std;

const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

int n,q;
vector<pair<int,pii>> query;

void Init(){
    cin >> q;
//    cout << q << endl;
    for (int i=1; i<=q; i++){
        int id,x,y;
        cin >> id >> x >> y;
        query.push_back({id,{x,y}});
    }
}

namespace Sub2{
    bool CheckSub(){ return true; }

    vector<pii> lst;

    int cur = 1;

    void Shift(int pos, int val){
        if (val>0){
            for (int i = (int)lst.size()-1; i>=pos; i--){
                lst[i+val] = lst[i];
            }
        }
        else{
            for (int i=pos; i<(int)lst.size(); i++){
                lst[i+val] = lst[i];
            }
        }
    }

    void SolveSub(){
        lst.push_back({0,0});
        for (auto in:query){
            int id = in.fi;
            if (id == 1){
                int x,val; tie(x,val) = in.se;
                for (int i=0; i<(int)lst.size(); i++){
                    if (lst[i].fi <= x && x <= lst[i].se){
                        if (x != lst[i].se){
                            lst.push_back({0,0});
                            lst.push_back({0,0});
                            Shift(i+1,2);
                            lst[i+2] = {x+1,lst[i].se};
                        }
                        else{
                            lst.push_back({0,0});
                            Shift(i+1,1);
                        }
                        lst[i].se = x;
                        lst[i+1] = {cur,cur+val-1};
                        cur = cur+val;
                        break;
                    }
                }
            }
            if (id == 2){
                int x,val; tie(x,val) = in.se;
                for (int i=0; i<(int)lst.size(); i++){
                    if (lst[i].fi <= x && x <= lst[i].se){

                        val-=lst[i].se-x;

                        lst[i].se = x;

                        int cnt = 0;
                        for (int idx=i+1; idx<(int)lst.size(); idx++){
                            if (lst[idx].se - lst[idx].fi+1 > val){
                                lst[idx].fi+=val;
                                Shift(idx,-cnt);
                                break;
                            }
                            else{
                                ++cnt;
                                val-=(lst[idx].se - lst[idx].fi+1);
                            }
                        }

                        lst.resize((int)lst.size()-cnt);
                        break;
                    }
                }
            }
            if (id == 3){
                ll res = 0;
                int l,r; tie(l,r) = in.se;
                int x=0,y=0;
                for (int i=0; i<(int)lst.size(); i++){
                    x = y+1;
                    y = y+(lst[i].se - lst[i].fi+1);
                    if (r<x || y<l) continue;
                    int lb = max(l,x);
                    int rb = min(r,y);
                    ll cst = ((ll)lst[i].fi+(lb-x))-1;
                    int delta = (rb-lb+1);
                    res+=(cst*delta)+((ll)1+delta)*delta/2;
                }
                cout << res << endl;
            }
//            for (int i=0; i<(int)lst.size(); i++){
//                cout << "{" << lst[i].fi << "," << lst[i].se << "}" << " ";
//            }
//            cout << endl;
        }
    }
}

namespace Sub3{
    bool CheckSub(){ return false; }

    void SolveSub(){}
}

namespace Sub4{
    bool CheckSub(){ return false; }

    void SolveSub(){}
}

signed main(){
    freopen(NAME ".inp","r",stdin);
    freopen(NAME ".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Init();
    if (Sub2::CheckSub()) return Sub2::SolveSub(),0;
    if (Sub3::CheckSub()) return Sub3::SolveSub(),0;
    if (Sub4::CheckSub()) return Sub4::SolveSub(),0;

    return 0;
}
