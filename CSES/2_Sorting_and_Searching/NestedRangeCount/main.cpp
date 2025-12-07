#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<pii,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n;
int in[maxn],out[maxn];
int cntr,cntl;
map<int,int> mpl,mpr;
vector<piii> lft,rgt;
int contain[maxn],covered[maxn];

//BIT
void update(int* BIT, int pos, int val, int cnt){
    int i = pos;
    while (i<cnt){
        BIT[i]+=val;
        //cout << i << endl;
        i+=(i&(-i));
    }
}

int query(int* BIT, int pos){
    int i = pos;
    int ans = 0;
    while (i>0){
        ans+=BIT[i];
        //cout << i << endl;
        i-=(i&(-i));
    }
    return ans;
}

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n ;i++){
        int x,y;
        cin >> x >> y;
        mpl[x] = 1;
        mpr[y] = 1;
        lft.push_back({{-x,y},i});
        rgt.push_back({{-y,x},i});
    }
    cntl = 1;
    for (auto in:mpl){
        int i = in.fi;
        mpl[i] = cntl;
        ++cntl;
    }
    cntr = 1;
    for (auto in:mpr){
        int i = in.fi;
        mpr[i] = cntr;
        ++cntr;
    }
    sort(lft.begin(),lft.end());
    sort(rgt.begin(),rgt.end());
    //cout << "meow" << endl;
    for (auto info:lft){
        int r = mpr[info.fi.se];
        int i = info.se;
        //cout << l << " " << r << endl;
        contain[i] = query(in,r);
        update(in,r,1,cntr);
//        for (int i=1; i<=6; i++){
//            cout << query(in,i) << " ";
//        }
//        cout << endl;
    }
//    cout << endl;
    for (auto info:rgt){
        int l = mpl[info.fi.se];
        int i = info.se;
        //cout << l << " " << r << endl;
        covered[i] = query(out,l);
        update(out,l,1,cntl);
    }
    for (int i=1; i<=n; i++){
        cout << contain[i] << " ";
    }
    cout << endl;
    for (int i=1; i<=n; i++){
        cout << covered[i] << " ";
    }
    return 0;
}
