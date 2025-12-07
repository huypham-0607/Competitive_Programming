/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

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
int n;
int precnt[N],predist[N],preval[N];
int dp[3][N];
int coef[3][N],cst[3][N];

long double intersect(int i, int j, int id){
    return (long double) (cst[id][j]-cst[id][i])/(coef[id][i]-coef[id][j]);
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=n; i>0; i--){
        int w,d;
        cin >> w >> d;
        precnt[i] = w;
        predist[i] = d;
    }
    for (int i=1; i<=n; i++){
        predist[i]+=predist[i-1];
        preval[i] = preval[i-1]+precnt[i]*predist[i];
        precnt[i]+=precnt[i-1];
        dp[0][i] = preval[i];
    }

////    for (int id=0; id<=2; id++){
//        for (int i=0; i<=n; i++){
//        cout << predist[i] << " " << precnt[i] << " " << preval[i] << endl;
////            cout << dp[id][i] << " ";
//        }
//        cout << endl;
////    }


    deque<int> dq;

    for (int i=1; i<=n; i++){
        dp[1][i] = preval[i-1];
    }

    for (int id=2; id<=2; id++){
        while (!dq.empty()) dq.pop_back();
        dq.push_back(0);
        for (int i=1; i<=n; i++){
            while (dq.size()>1 && intersect(dq[0],dq[1],id)<precnt[i-1]) dq.pop_front();

//            cout << dq.front() << endl;
            dp[id][i] = coef[id][dq.front()]*precnt[i-1]+cst[id][dq.front()] + preval[i-1];

            coef[id][i] = -predist[i];
            cst[id][i] = dp[id-1][i] - preval[i] + precnt[i]*predist[i];

            while (dq.size()>1 && intersect(dq[(int)dq.size()-2],dq.back(),id) > intersect(dq[(int)dq.size()-2],i,id)) dq.pop_back();
            dq.push_back(i);
        }
    }

//    for (int id=0; id<=2; id++){
//        for (int i=0; i<=n; i++){
////        cout << predist[i] << " " << precnt[i] << " " << preval[i] << endl;
//            cout << dp[id][i] << " ";
//        }
//        cout << endl;
//    }

//    for (int id=0; id<=2; id++){
//        for (int i=0; i<=n; i++){
//        cout << predist[i] << " " << precnt[i] << " " << preval[i] << endl;
//            cout << "{" << coef[id][i] << "," << cst[id][i] << "}" << " ";
//        }
//        cout << endl;
//    }

    int ans = LLINF;
    for (int i=2; i<=n; i++){
        ans = min(ans,dp[2][i] + (preval[n] - preval[i]) - (precnt[n] - precnt[i])*predist[i]);
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
