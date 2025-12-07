#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e5+10;
const int INF = 2e9;

int n,ans = -1;

map<int,int> mp;
int IT[maxn*4];

void update(int idx, int l, int r, int x, int v){
    if (x < l || x > r) return;
    if (x == l && x == r){
        IT[idx] = max(IT[idx],v);
        return;
    }
    else{
        int mid = (l+r)/2;
        update(idx*2,l,mid,x,v);
        update(idx*2+1,mid+1,r,x,v);
        IT[idx] = max(IT[idx*2],IT[idx*2+1]);
    }
}

int query(int idx, int l, int r, int x, int y){
    if (y < l || x > r) return 0;
    if (l >= x  && r <= y) return IT[idx];

    else{
        int mid = (l+r)/2;
        return max(query(idx*2,l,mid,x,y),query(idx*2+1,mid+1,r,x,y));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
//        cout << endl;
//        for (int i=1; i<=10; i++){
//            cout << query(1,1,100000,1,i) << " ";
//        }
//        cout << endl << i << " ";
        int x;
        cin >> x;
//        cout << x << " ";
        mp[x] = 0;
        if (i == 1) continue;
        if (x == mp.begin()->fi){
            mp[x] = 0;
        }
        auto it = (--mp.lower_bound(x));
//        int pos = it->fi;
//        int prev = it->se;
//        cout << pos << " " << prev << " ";
        mp[x] = (it)->fi;
        update(1,1,100000,x,x+mp[x]);
        ans = max(ans,x+query(1,1,100000,1,x-1));
    }
    cout << ans;
    return 0;
}
