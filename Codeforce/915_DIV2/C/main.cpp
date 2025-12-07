#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int t,n;
vector<int> v;
vector<pii> meow;
deque<pii> dq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        v.clear();
        dq.clear();
        meow.clear();
        for (int i=0; i<n; i++){
            char c;
            cin >> c;
            int x = (c - 'a');
            v.push_back(x);
            while (!dq.empty() && dq.back().fi < x){
                dq.pop_back();
            }
            dq.push_back({x,i});
        }
        bool ver = true;
        for (int i=0; i<n-1; i++){
            if (v[i] > v[i+1]) ver = false;
        }
        if (ver){
            cout << 0 << endl;
            continue;
        }
//        for (int i=0; i<n; i++){
//            cout << v[i] << " ";
//        }
//        cout << endl;
//        cout << dq.size() << endl;
        int ans = dq.size()-1;
        while (!dq.empty()){
            meow.push_back(dq.front());
            dq.pop_front();
        }
//        for (int i=0; i<n; i++){
//            cout << v[i] << " ";
//        }
//        cout << endl;
        int cnt = 0;
        int refer = meow[0].fi;
        for (int i=1; i<ans; i++){
            if (meow[i].fi == refer) cnt++;
        }

        ver = true;
        for (int i=0; i<ans; i++){
            int j = ans-i;
            if (i >= j) break;
            v[meow[i].se] = meow[j].fi;
            v[meow[j].se] = meow[i].fi;
        }
//        for (int i=0; i<n; i++){
//            cout << v[i] << " ";
//        }
//        cout << endl;
        for (int i=0; i<n-1; i++){
            if (v[i] > v[i+1]) ver = false;
        }
        if (ver) cout << ans-cnt << endl;
        else cout << -1 << endl;
    }
    return 0;
}
