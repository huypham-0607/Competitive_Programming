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
const int N = 3000+10;
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
int a[N];
int preval[N],precnt[N];
int sufval[N],sufcnt[N];
int f[N],g[N];
deque<int> dq;
vector<int> coef(N),cst(N),coefcur(N),cstcur(N);

long double intersect (int i, int j){
    return (long double) (cst[j] - cst[i])/(coef[i] - coef[j]);
}

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        precnt[i] = precnt[i-1]+a[i];
        preval[i] = preval[i-1]+a[i]*i;
    }
    for (int i=n; i>0; i--){
        sufcnt[i] = sufcnt[i+1]+a[i];
        sufval[i] = sufval[i+1]+a[i]*(n-i+1);
    }

//    coef[0] = 0;
//    cst[0] = -preval[0]+precnt[0]*0;

    for (int id=1; id<=k; id++){
        coef[0] = sufcnt[1];
        cst[0] = sufval[1]-sufcnt[1]*(n+1);
        while (!dq.empty()) dq.pop_back();
        dq.push_back(0);
        for (int i=1; i<=n; i++){
            if (id!=1 && dq.size()>1 && intersect(dq[dq.size()-2],dq.back()) > intersect(dq.back(),i)) dq.pop_back();
            dq.push_back(i);
            if (id!=1 && dq.size()>1 && i>intersect(dq[0],dq[1])) dq.pop_front();
            int j = dq.front();
            f[i] = i*coef[j] + cst[j] - sufval[i+1] + sufcnt[i+1]*(n-i+1);
            coefcur[i] = (-i);
            cstcur[i] = f[i]-preval[i]+precnt[i]*i;
        }
        swap(cst,cstcur);
        swap(coef,coefcur);
        while (!dq.empty()) dq.pop_back();
        dq.push_back(0);
        coef[0] = 0;
        cst[0] = -preval[0]+precnt[0]*0;
        for (int i=1; i<=n; i++){
            if (dq.size()>1 && intersect(dq[dq.size()-2],dq.back()) > intersect(dq.back(),i)) dq.pop_back();
            dq.push_back(i);
            if (dq.size()>1 && precnt[i]>intersect(dq[0],dq[1])) dq.pop_front();
            int j = dq.front();
            g[i] = precnt[i]*coef[j]+cst[j]+preval[i];
            coefcur[i] = sufcnt[i+1];
            cstcur[i] = g[i] + sufval[i+1] - sufcnt[i+1]*(n+1);
        }
        swap(cst,cstcur);
        swap(coef,coefcur);
//        for (int i=1; i<=n; i++){
//            cout << f[i] << " ";
//        }
//        cout << endl;
//        for (int i=1; i<=n; i++){
//            cout << g[i] << " ";
//        }
//        cout << endl << endl;
    }
    cout << g[n] << endl;

//    int res = 0;
//    int res2 = 0;
//    for (int i=1; i<=3000; i++){
//        res2 = res+1000000000*i;
//        res = (res+1000000000*i)%LLINF;
//    }
//    cout << res << " " << res2 << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
