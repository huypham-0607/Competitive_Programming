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

int n;
int a[N];
vector<int> v;

/*Solution*/
int Solution(){

    n*=2;
    int ans = INF;

    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            v.clear();
            for (int idx=0; idx<n; idx++){
                if (idx!=i && idx!=j) v.push_back(a[idx]);
            }
            sort(v.begin(),v.end());

            int t = 0;

            for (int idx=0; idx<n-2; idx+=2){
                t += v[idx+1] - v[idx];
            }

            ans = min(ans,t);
        }
    }

    return ans;
}


void Gen(int testid){
    string InputFileName = "GHEPSO/input" + to_string(testid) + ".txt";
    string OutputFileName = "GHEPSO/output" + to_string(testid) + ".txt";

    if (testid<10){
        InputFileName = "GHEPSO/input0" + to_string(testid) + ".txt";
        OutputFileName = "GHEPSO/output0" + to_string(testid) + ".txt";
    }

    ofstream InputFile(InputFileName);
    ofstream OutputFile(OutputFileName);

    n = rd(testid+1,testid+1);
    for (int i=0; i<n*2; i++){
        a[i] = rd(1,10);
    }

    InputFile << n << endl;
    for (int i=0; i<n*2; i++){
        InputFile << a[i] << " ";
    }

    OutputFile << Solution();

    InputFile.close();
    OutputFile.close();
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    srand(time(NULL));
    int LTEST=0;
    int RTEST=3;
    for (int testid = LTEST; testid<RTEST; testid++){
        Gen(testid);
    }

    return 0;
}
