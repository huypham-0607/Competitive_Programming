#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int main(){
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    int n;
    cin >> n;
    vector<ii> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a.begin(),a.end());
    int curpen = 0,curtime = 0;
    string s = "";
    for (int i = 0; i < n; i++){
        if (curtime + a[i].fi > 300) break;
        cnt++;
        curtime += a[i].fi;
        curpen += curtime;
        s += ('A' + a[i].se);
    }
    cout << cnt << " " << curpen << " " << curtime << "\n";
    cout << s;
    return 0;
}
