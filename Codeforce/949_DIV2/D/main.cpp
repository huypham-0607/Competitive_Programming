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
int n,res;
vector<int> Prime;
bool NotPrime[15010];
bool adj[1510][1510];
int deg[1510];
int index[1510];
vector<int> ans;

int Edgecnt(int x){
    return (x%2)? x*(x-1)/2+x+1 : x*(x-1)/2+x+1-(x-2)/2;
}

void Sieve(){
    NotPrime[0] = NotPrime[1] = 1;
    for (int i=2; i*i<=15000; i++){
        if (!NotPrime[i]){
            for (int j=i*i; j<=15000; j+=i){
                NotPrime[j] = true;
            }
        }
    }
    for (int i=1; i<=15000; i++){
        if (!NotPrime[i]) Prime.push_back(i);
    }
}

void FindEulerPath(){
    stack<int> s;
    s.push(1);
    vector<int> cur(res+1,0);
    while (!s.empty()){
        int u = s.top();
        if (!deg[u]){
            ans.push_back(u);
            s.pop();
        }
        else{
            while (!adj[u][cur[u]]) cur[u]++;
            int v = cur[u];
            adj[u][v] = false;
            adj[v][u] = false;
            --deg[u];
            --deg[v];
            s.push(v);
        }
    }
}

/*Solution*/
void solve(){
    cin >> n;
    int l=1, r=1415;
    res = 0;
    while (l<=r){
        int mid = (l+r)/2;
        if (Edgecnt(mid)<n){
            res = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    ++res;
    for (int i=0; i<res; i++){
        index[i+1] = Prime[i];
        deg[i+1] = 0;
    }
    for (int i=1; i<=res; i++){
        for (int j=i; j<=res; j++){
            adj[i][j] = true;
            adj[j][i] = true;
            ++deg[i];
            ++deg[j];
        }
    }
    if (res%2==0){
        for (int i=3; i<=res; i+=2){
            adj[i][i+1] = false;
            adj[i+1][i] = false;
            --deg[i];
            --deg[i+1];
        }
    }
    FindEulerPath();
    for (int i=0; i<n; i++){
        cout << index[ans[i]] << " ";
    }
    cout << endl;
//    cout << res << " " << Edgecnt(res) << " " << Edgecnt(res-1) << endl;
//    cout << res << endl;
//    for (int i=1; i<=res; i++){
//        for (int j=1; j<=res; j++){
//            cout << adj[i][j] << " ";
//        }
//        cout << endl;
//    }
//    for (int i=1; i<=res; i++){
//        cout << deg[i] << endl;
//    }
//    cout << endl;
    ans.clear();
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Sieve();
    TestCases(1);

    return 0;
}
