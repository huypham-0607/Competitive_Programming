/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define pbiiii pair<bool,piiii>
#define fi first
#define se second

#define NAME "CIRCLE"

using namespace std;

/*Constants*/
const int N = 2e5+10;
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
int n,k;
set<pii> st;

int Getidx(pii x, int pos){
    if (pos>=50){
        return (x.se>>(pos-50))&(int)1;
    }
    else return (x.fi>>pos)&(int)1;
}

pii gawr(pii x){
    pii res = {0,0};
    for (int i=0; i<n; i++){
        int a = Getidx(x,i%n);
        int b = Getidx(x,(i+1)%n);
        if (a^b){
            if (i>=50){
                res.se^=((int)1<<(i-50));
            }
            else{
                res.fi^=((int)1<<(i));
            }
        }
    }
    return res;
}

pbiiii Nxt(pii x){
    pii res;
    int pre = 0;
    for (int i=1; i<n; i++){
        int a = Getidx(x,i);
        if (a) pre = (pre^(int)1);
        if (i>=50){
            res.se = res.se^(pre<<(i-50));
        }
        else res.fi = res.fi^(pre<<(i));
    }
    int a = Getidx(res,0);
    int b = Getidx(res,n-1);
    int c = Getidx(x,0);
    pbiiii ans = {0,{{0,0},{0,0}}};
//    cout << res.fi << " " << res.se << endl;
    if (c){
        if ((a^b) == 0) return ans;
    }
    else{
        if ((a^b) == 1) return ans;
    }
    ans.fi = 1;
    ans.se.fi = res;
    res.fi = res.fi^(((int)1<<min(n,(int)50))-1);
    if (n>50) res.se = res.se^(((int)1<<min(n-50,(int)50))-1);
    ans.se.se = res;
    return ans;
}

pii Cycle(pii x){
    x.fi<<=(int)1;
    x.se<<=(int)1;
    if (n<=50){
        if (x.fi&((int)1<<n)){
            x.fi^=((int)1<<n);
            x.fi^=((int)1);
        }
    }
    else{
        if (x.fi&((int)1<<(50))){
            x.fi^=((int)1<<50);
            x.se^=((int)1);
        }
        if (x.se&((int)1<<(n-50))){
            x.se^=((int)1<<(n-50));
            x.fi^=((int)1);
        }
    }
    return x;
}

void Opt(pii x){
    for (int i=0; i<n; i++){
        if (i>=50){
            cout << ((x.se&((int)1<<(i-50)))? 1 : 0);
        }
        else cout << ((x.fi&((int)1<<i))? 1 : 0);
    }
    cout << endl;
}

/*Solution*/
void solve(){
    cin >> n >> k;
    pii s = {0,0};
    for (int i=0; i<n; i++){
        char c;
        cin >> c;
        if (c=='W'){
            if (i>=50){
                s.se^=((int)1<<(i-50));
            }
            else s.fi^=((int)1<<(i));
        }
    }
    for (int i=1; i<=k; i++){
        s = gawr(s);
    }
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    pq.push({0,s});
    while (!pq.empty() && pq.top().fi!=k){
        piii in = pq.top();
        pq.pop();

//        cout << in.fi << " " << in.se.fi << " " << in.se.se << endl;

        pbiiii res = Nxt(in.se);
        if (!res.fi) continue;
        pq.push({in.fi+1,res.se.fi});
        pq.push({in.fi+1,res.se.se});
    }
    while (!pq.empty()){
        pii x = pq.top().se;
//        Opt(x);
        pq.pop();
        bool ver = 1;
        for (int i=1; i<=n; i++){
            x = Cycle(x);
            if (st.find(x)!=st.end()){
                ver = 0;
                break;
            }
        }
        if (ver) st.insert(x);
    }
    cout << st.size() << endl;
}

/*Driver Code*/
signed main(){
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
