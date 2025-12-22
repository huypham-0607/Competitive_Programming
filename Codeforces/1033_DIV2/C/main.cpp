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
const int N = 1e6+10;
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
int n,m;
int used[N];


/*Solution*/
void solve(){
    cin >> n >> m;
    int ver = 0;
    for (int i=1; i<=n; i++){
        used[i] = false;
        ver+=i;
    }

    if (m < n || m > ver){
        cout << -1 << endl;
        return;
    }

    m-=n;
    ver = 0;
    int pivot = 1;
    while (ver<m){
        ver+=n-pivot;
        ++pivot;
    }

    used[pivot] = true;
    m-=pivot-1;

    for (int i=n; i>0; i--){
        if (used[i]) continue;
        if (m-(min(pivot,i)-1)<0){
            break;
        }
        m-=min(pivot,i)-1;
        used[i] = true;
//        cout << i << " " << m << endl;
    }

    cout << pivot << endl;

    for (int i=n; i>0; i--){
        if (used[i] && i!=pivot){
            cout << pivot << " " << i << endl;
        }
    }

    int pre = pivot;
    if (m){
        cout << pivot << " " << m+1 << endl;
        used[m+1] = true;
        pre = m+1;
    }
    for (int i=1; i<=n; i++){
        if (used[i]) continue;
        cout << pre << " " << i << endl;
        used[i] = true;
        pre = i;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
