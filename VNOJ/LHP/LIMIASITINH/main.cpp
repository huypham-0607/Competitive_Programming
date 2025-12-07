/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,q;
int last = 0;

/*IT*/
vector<int> IT[N*4];
vector<int> value[N];

void build(int idx, int l, int r){
    if (l == r){
        for (auto x:value[l]){
            IT[idx].pb(x);
        }
        return;
    }
    int mid = (l+r)/2;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);
    int pos1=0,pos2=0;
    int l1= IT[idx*2].size(), l2 = IT[idx*2+1].size();
    while (pos1!=l1 || pos2!=l2){
        if (pos1 == l1){
            IT[idx].pb(IT[idx*2+1][pos2]);
            pos2++;
        }
        else if (pos2 == l2){
            IT[idx].pb(IT[idx*2][pos1]);
            pos1++;
        }
        else{
            int val1 = IT[idx*2][pos1];
            int val2 = IT[idx*2+1][pos2];
            if (val1<=val2){
                IT[idx].pb(val1);
                pos1++;
            }
            else{
                IT[idx].pb(val2);
                pos2++;
            }
        }
    }
}

int query(int idx, int l, int r, int x, int y, int val){
//    cout << idx << " " << l << " " << r << endl;
//    for (auto i:IT[idx]){
//        cout << i << " ";
//    }
//    cout << endl;
    int cnt = 0;
    if (!IT[idx].empty()){
        cnt+=((upper_bound(IT[idx].begin(),IT[idx].end(),y))-IT[idx].begin());
        cnt-=((lower_bound(IT[idx].begin(),IT[idx].end(),x))-IT[idx].begin());
    }
//    cout << cnt << " " << val << endl << endl;
    if (l == r){
        if (cnt>=val){
            last = l-1;
            cout << l-1 << endl;
        }
        return cnt;
    }
    if (cnt>=val){
        int mid = (l+r)/2;
        int temp = query(idx*2,l,mid,x,y,val);
        if (temp<val){
            temp = query(idx*2+1,mid+1,r,x,y,val-temp);
            return cnt;
        }
        else return cnt;
    }
    return cnt;
}

/*Solution*/
void solve(){

    cin >> n >> q;
    int mx = 1;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        value[x+1].pb(i);
        mx = max(mx,x+1);
    }
    build(1,1,mx);
    last = 0;
    while (q--){
        int l,r,x,y;
//        cin >> l >> r;
        cin >> x >> y;
        l = ((x^last))%n+1;
        r = ((y^last))%n+1;
        if (l>r) swap(l,r);
        int mid = ((r-l+1)+1)/2;
//        cout << "ppp " << mid << " " << l << " " << r << endl;
//        cout << "{" << l << "," << r << "}" << endl;
        query(1,1,mx,l,r,mid);
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

