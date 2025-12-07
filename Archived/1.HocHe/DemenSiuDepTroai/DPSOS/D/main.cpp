/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 20;
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
string s;
int F[(1<<N)];

int Getidx(int pos){
    return (s[pos]-'a');
}

/*Solution*/
void solve(){
    cin >> s;
    int n = s.size();
    int l = 0;
    int rawr = 0;
    for (int r=0; r<n; r++){
        int idx = Getidx(r);
        while ((rawr>>idx)&1){
            int i = Getidx(l);
            rawr = rawr^(1<<i);
            ++l;
        }
        rawr = rawr^(1<<idx);
//        cout << rawr << endl;
        int tmp = rawr;
        for (int i=l; i<=r; i++){
            F[tmp] = r-i+1;
            tmp = tmp^(1<<Getidx(i));
        }
    }

    for (int i=0; i<N; i++){
        for (int mask=0; mask<(1<<N); mask++){
            if ((mask>>i)&1) F[mask] = max(F[mask],F[mask^(1<<i)]);
        }
    }

    int ans = 0;
    l=0;
    rawr = 0;
    for (int r=0; r<n; r++){
        int idx = Getidx(r);
        while ((rawr>>idx)&1){
            int i = Getidx(l);
            rawr = rawr^(1<<i);
            ++l;
        }
        rawr = rawr^(1<<idx);
        int tmp = rawr;
        for (int i=l; i<=r; i++){
            ans = max(ans,r-i+1+F[((1<<N)-1)^tmp]);
            tmp = tmp^(1<<Getidx(i));
        }
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
