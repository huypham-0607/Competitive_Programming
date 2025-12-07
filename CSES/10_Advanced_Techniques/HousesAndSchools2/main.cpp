/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 3000;
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
int n,korg;
int a[N+10];
int pre[N+10],pre2[N+10],suf[N+10],suf2[N+10];
int dp[N+10][2*N+10];

struct Line{
    int a,b;
    Line (int _a = 0, int _b = 0){
        a = _a;
        b = _b;
    }
};

long double intersect(Line x, Line y){
    return (long double)(y.b-x.b)/(x.a-y.a);
}

/*Solution*/
void solve(){
    cin >> n >> korg;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        pre[i] = pre[i-1]+a[i];
        pre2[i] = pre2[i-1]+pre[i-1]+a[i];
    }
    for (int i=n; i>0; i--){
        suf[i] = suf[i+1]+a[i];
        suf2[i] = suf2[i+1]+suf[i+1]+a[i];
    }

//    for (int i=1; i<=n; i++){
//        cerr << pre[i] << " " << pre2[i] << " " << suf[i] << " " << suf2[i] << endl;
//    }

    deque<Line> dq;
    for (int k=1; k<=2*korg-1; k++){
//        cerr << "k: " << k << endl;
        if (k%2){
            dq.clear();
            int s = (k+1)/2;
            dq.push_back(Line(-pre[s-1],dp[s-1][k-1]-pre2[s-1]+pre[s-1]*(s-1)+pre[s-1]));
            for (int i=s; i<=n; i++){
//                cout << "i: " << i << " ";
                while (dq.size() > 1 && intersect(dq[0],dq[1])<i) dq.pop_front();
                dp[i][k] = dq[0].a*i + dq[0].b + pre2[i-1];
//                cout << dq[0].a << " " << dq[0].b << endl;
                if (k!=1){
                    Line tmp(-pre[i],dp[i][k-1]-pre2[i]+pre[i]*i+pre[i]);
                    while (dq.size() > 1 && intersect(dq[dq.size()-1],dq[dq.size()-2]) > intersect(dq[dq.size()-1],tmp)) dq.pop_back();
                    dq.push_back(tmp);
                }
            }
        }
        else{
            dq.clear();
//            cerr << "k: " << k << endl;
            for (int i=(k+1)/2; i<n; i++){
//                cout << "i: " << i << " ";
                Line tmp(i,dp[i][k-1]+suf2[i+1]);
                while (dq.size() > 1 && intersect(dq[dq.size()-1],dq[dq.size()-2]) < intersect(dq[dq.size()-1],tmp)) dq.pop_back();
                dq.push_back(tmp);
                while (dq.size()>1 && intersect(dq[0],dq[1])>suf[i+1]) dq.pop_front();
                dp[i][k] = dq[0].a*suf[i+1] + dq[0].b - suf2[i+1] - suf[i+1]*i;
//                cout << dq[0].a << " " << dq[0].b << endl;
            }
        }
    }
    ll ans = 1e18+10;
    for (int i=korg; i<=n; i++){
        ans = min(ans,dp[i][korg*2-1]+suf2[i+1]);
    }

//    for (int j=1; j<=korg*2-1; j++){
//        for (int i=1; i<=n; i++){
//            cerr << dp[i][j] << " ";
//        }
//        cerr << endl;
//    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

