/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#include "secret.h"
#define pb push_back
#define endl "\n"
#define ll long long
//#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const int LG = 10;
const long long LLINF = 1e18+3;

///*TestCases*/
//int test=1;
//void solve();
//void TestCases(bool v){
//    if (v) cin >> test;
//    while(test--) solve();
//}

/*Global Variables*/
int n;
int val[(1<<LG)+10];
int DNC[LG][(1<<LG)+10];
int mask[(1<<LG)+10];

void BuildDNC(int l, int r, int lg){
    if (l==r) return;
    int mid = (l+r)/2;
    DNC[lg][mid] = val[mid];
    DNC[lg][mid+1] = val[mid+1];
    for (int i=mid-1; i>=l; i--) DNC[lg][i] = Secret(val[i],DNC[lg][i+1]);
    for (int i=mid+2; i<=r; i++) DNC[lg][i] = Secret(DNC[lg][i-1],val[i]);
    for (int i=mid; i>=l; i--) mask[i]^=(1<<lg);
    BuildDNC(l,mid,lg+1); BuildDNC(mid+1,r,lg+1);
}

void Init(int _n, int a[]){
    n = _n;
    for (int i=0; i<n; i++){
        val[i] = a[i];
    }
    BuildDNC(0,n-1,0);
}

int Query(int l, int r){
    if (l==r) return val[l];
    int x = mask[l]^mask[r];
    int lg = __builtin_ctz(x);
    return Secret(DNC[lg][l],DNC[lg][r]);
}

///*Solution*/
//void solve(){
//
//}

///*Driver Code*/
//signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    TestCases(0);
//
//    return 0;
//}
