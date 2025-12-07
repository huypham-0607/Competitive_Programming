/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e6+10;
const int INF = 1e9+7;
const int LIM = 2e6+1;
const int SHIFT = 1e6+1;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;

//BIT
int BIT[N];
priority_queue<piii,vector<piii>,greater<piii>> Upt;
priority_queue<piii,vector<piii>,greater<piii>> Qr;

void UpdateBIT(int x, int val){
    while (x<=LIM){
        BIT[x]+=val;
        x+=(x&(-x));
    }
}

int QueryBIT(int x){
    int res = 0;
    while (x>0){
        res+=BIT[x];
        x-=(x&(-x));
    }
    return res;
}

int GetBIT(int l, int r){
    return (QueryBIT(r)-QueryBIT(l-1));
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1+=SHIFT; y1+=SHIFT; x2+=SHIFT; y2+=SHIFT;
        if (x1==x2){
            Upt.push({min(y1,y2),{x1,1}});
            Upt.push({max(y1,y2),{x1,-1}});
        }
        else{
            Qr.push({y1,{min(x1,x2),max(x1,x2)}});
        }
    }
    int res = 0;
    for (int j=1; j<=LIM; j++){
        while (!Upt.empty() && Upt.top().fi == j){
            UpdateBIT(Upt.top().se.fi,Upt.top().se.se);
            Upt.pop();
        }
        while (!Qr.empty() && Qr.top().fi == j){
            res+=GetBIT(Qr.top().se.fi,Qr.top().se.se);
            Qr.pop();
        }
    }
    cout << res << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
