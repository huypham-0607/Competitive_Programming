/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME ""

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
mt19937_64 mt(chrono::high_resolution_clock::now().time_since_epoch().count());

ll rd(ll l, ll r){
    return uniform_int_distribution<ll> (l,r) (mt);
}

int n,m,k,d;
vector<vector<int>> a;
vector<long long> v;

/*Solution*/
long long Solution(string InputFileName){
    ifstream cin(InputFileName);
    cin >> n >> m >> k >> d;
//    d+=1;
    a.clear();
    a.resize(n+1,vector<int>(m+1));
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
//            a[i][j] += 1;
        }
    }

    v.clear();
    v.resize(n+1,0);

    deque<pair<long long,int>> dq;
//    dp.resize(n+1,vector<int>(m+1));
    for (int i=1; i<=n; i++){
        dq.clear();
        dq.push_back({a[i][1],1});
        for (int j=2; j<=m; j++){
            while (!dq.empty() && dq.front().se < j-d) dq.pop_front();

            long long val = dq.front().fi + a[i][j];
            if (j==m) v[i] = val;

            while (!dq.empty() && dq.back().fi > val) dq.pop_back();
            dq.push_back({val,j});
        }
    }

    long long ans = LLINF;
    long long t = 0;
    dq.clear();
    for (int i=1; i<=n; i++){
        while (!dq.empty() && dq.front().se <= i-k) dq.pop_front();
        while (!dq.empty() && dq.back().fi < v[i]) dq.pop_back();
        dq.push_back({v[i],i});

        if (i > k) t -= v[i-k];
        t+=v[i];
        if (i >= k) ans = min(ans,t-dq.front().fi);
    }

    return ans;
    cin.close();
}


void Gen(int testid){
    string InputFileName = "XAYCAU/input" + to_string(testid) + ".txt";
    string OutputFileName = "XAYCAU/output" + to_string(testid) + ".txt";

    if (testid<10){
        InputFileName = "XAYCAU/input0" + to_string(testid) + ".txt";
        OutputFileName = "XAYCAU/output0" + to_string(testid) + ".txt";
    }

//    ofstream InputFile(InputFileName);
    ofstream OutputFile(OutputFileName);

//    n = rd(10000,100000);
//    m = 1000000/n;
//    m = rd(200000,200000);
//    n = 1000000/m;
//    k = rd(4,4);
//    d = rd(2,m);
//    InputFile << n << " " << m << " " << k << " " << d << endl;
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=m; j++){
//            int x = rd(0,1000000000);
//            InputFile << x << " ";
//        }
//        InputFile << endl;
//    }

//    InputFile.close();

    OutputFile << Solution(InputFileName);

    OutputFile.close();
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    srand(time(NULL));
    int LTEST=0;
    int RTEST=61;
    for (int testid = LTEST; testid<RTEST; testid++){
        Gen(testid);
    }

    return 0;
}
