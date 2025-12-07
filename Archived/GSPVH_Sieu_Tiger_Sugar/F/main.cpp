#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define all(x) x.begin(),x.end()

using namespace std;

int main(){
    freopen("discounts.INP","r",stdin);
    freopen("discounts.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,tscnt=0,txcnt=0;
    vector<ii> ts,tx;
    cin >> n >> n >> k;
    for (int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        if (y==1){
            txcnt++;
            tx.push_back({x,i+1});
        }
        else{
            tscnt++;
            ts.push_back({x,i+1});
        }
    }
    sort(all(tx));
    sort(all(ts));
    long long t=0;
    if (txcnt<=k-1){
        for (ii in:tx){
            t+=in.fi;
        }
        for (ii in:ts){
            t+=in.fi*2;
        }
        cout << fixed << setprecision(1) << t/2.0 << "\n";
        for (ii in:tx){
            cout << 1 << " " << in.se << "\n";
        }
        int i;
        for (i=0; i<tscnt-k-1; i++){
            cout << 1 << " " << ts[i].se << "\n";
        }
        cout << tscnt-i << " ";
        for (i=i; i<tscnt; i++){
            cout << ts[i].se << " ";
        }
    }
    else{
        int i=0;
        for (i=1; i<=k-1; i++){
            t+=tx[txcnt-i].fi;
        }
        for (i=i; i<txcnt; i++){
            t+=tx[txcnt-i].fi*2;
        }
        if (tx[0].fi < ts[0].fi){
            t+=tx[0].fi;
            for (ii in:ts){
                t+=in.fi*2;
            }
        }
        else{
            t+=tx[0].fi*2 + ts[0].fi;
            for (int j=1; j<tscnt; j++){
                t+=ts[j].fi*2;
            }
        }
        cout << fixed << setprecision(1) << t/2.0 << "\n";
        i=0;
        for (i=1; i<=k-1; i++){
            cout << 1 << " " << tx[txcnt-i].se << "\n";
        }
        cout << txcnt-i+1+tscnt << " ";
        for (i=i; i<=txcnt; i++){
            cout << tx[txcnt-i].se << " ";
        }
        for (ii in:ts){
            cout << in.se <<  " ";
        }
    }
    return 0;
}
