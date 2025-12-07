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

int n,m;
int c[N];
vector<int> v;

/*Solution*/
int Solution(int testid){
//    string INPUTFILE = "FROG2/input/input" + to_string(testid) + ".txt";
//
//    if (testid<10){
//        INPUTFILE = "FROG2/input/input0" + to_string(testid) + ".txt";
//    }
//
////    string INPUTFILE = "FROG2/input/input" + to_string(testid) + ".txt";
//
////    if (testid<10){
////        freopen("FROG2/input/input0" testid ".txt","r",stdin);
////    }
////    else{
////        freopen("FROG2/input/input"  to_string(testid)  ".txt","r",stdin);
////    }
//
//    ifstream cin (INPUTFILE);
//
//    cin >> n >> k;
//    for (int i=1; i<=n; i++){
//        cin >> h[i];
//    }
//
//    dp[1] = 0;
//
//    for (int i=2; i<=n; i++){
//        dp[i] = INF;
//        for (int j=1; j<=k; j++){
//            if (i-j<=0) break;
//            dp[i] = min(dp[i],dp[i-j]+abs(h[i] - h[i-j]));
//        }
//    }
//
//    cin.close();
//    return dp[n];
}


void Gen(int testid){
    string InputFileName = "PhanTichDuLieu1/input/input" + to_string(testid) + ".txt";
    string OutputFileName = "PhanTichDuLieu1/output/output" + to_string(testid) + ".txt";

    if (testid<10){
        InputFileName = "PhanTichDuLieu1/input/input0" + to_string(testid) + ".txt";
        OutputFileName = "PhanTichDuLieu1/output/output0" + to_string(testid) + ".txt";
    }

    ofstream InputFile(InputFileName);
    ofstream OutputFile(OutputFileName);

    int oldtestid = testid-1;

    string OldInputFileName = "ArrayDescription/input/input" + to_string(oldtestid) + ".txt";
    string OldOutputFileName = "ArrayDescription/output/output" + to_string(oldtestid) + ".txt";

    if (testid<10){
        OldInputFileName = "ArrayDescription/input/input0" + to_string(oldtestid) + ".txt";
        OldOutputFileName = "ArrayDescription/output/output0" + to_string(oldtestid) + ".txt";
    }

    ifstream OldInputFile(OldInputFileName);
    ifstream OldOutputFile(OldOutputFileName);

    OldInputFile >> n >> m;
    for (int i=1; i<=n; i++){
        OldInputFile >> c[i];
    }


    InputFile << n << " " << m << endl;
    for (int i=1; i<=n; i++){
        if (c[i] == 0){
            InputFile << "?" << " ";
        }
        else InputFile << c[i] << " ";
    }

    int ans;
    OldOutputFile >> ans;

    OutputFile << ans;

    InputFile.close();
    OutputFile.close();
    OldInputFile.close();
    OldOutputFile.close();
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    srand(time(NULL));
    int LTEST=1;
    int RTEST=29;
    for (int testid = LTEST; testid<=RTEST; testid++){
        Gen(testid);
    }

    return 0;
}
