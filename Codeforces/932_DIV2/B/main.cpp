#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int test;
int n;
int a[maxn];
int s1[maxn],s2[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n;
        for (int i=0; i<=n+1; i++){
            s1[i] = 0;
            s2[i] = 0;
        }
        for (int i=1; i<=n; i++){
            cin >> a[i];
            s2[a[i]]++;
        }
        int mex1 = 0, mex2;
        for (int i=0; i<=n; i++){
            if (!s2[i]){
                mex2 = i;
                break;
            }
        }
//        cout << mex1 << " " << mex2 << endl;
        int v = 0;
        for (int i=1; i<=n; i++){
            s1[a[i]]++;
            while (s1[mex1]) mex1++;
            s2[a[i]]--;
            if (!s2[a[i]] && a[i] < mex2){
                mex2 = a[i];
            }
//            cout << mex1 << " " << mex2 << endl;
            if (mex1 == mex2){
                cout << 2 << endl;
                cout << 1 << " " << i << endl;
                cout << i+1 << " " << n << endl;
                v = 1;
                break;
            }
        }
        if (!v) cout << -1 << endl;
    }
    return 0;
}
