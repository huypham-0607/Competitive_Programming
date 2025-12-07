/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n;
int a[N];

bool DefLeft(int x, vector<char>& dir){
    for (int i=x-1; i>0; i--){
//        cout << i << endl;
        char c;
        if (a[i] != a[i+1]){
            if (a[i]>a[i+1]){
                c = 'R';
            }
            else {
                c = 'L';
            }
//            cout << c << endl;
            if (c!=dir[i+1]){
                return false;
            }
            dir[i] = c;
        }
        else{
//                            for (int i=1; i<=n; i++){
//                    cout << dir[i] << " ";
//                }
//                cout << endl;
            if (dir[i+1] == 'L') dir[i] = 'R';
            else dir[i] = 'L';

        }
    }
//                    for (int i=1; i<=n; i++){
//                    cout << dir[i] << " ";
//                }
//                cout << endl;
    return true;
}

bool DefRight(int x, vector<char>& dir){
    for (int i=x+1; i<=n; i++){
//        cout << i << endl;
        char c;
        if (a[i-1] != a[i]){
            if (a[i-1]>a[i]){
                c = 'R';
            }
            else {
                c = 'L';
            }
            if (c!=dir[i-1]){
                return false;
            }
            dir[i] = c;
        }
        else{
            if (dir[i-1] == 'L') dir[i] = 'R';
            else dir[i] = 'L';
        }
    }
//                    for (int i=1; i<=n; i++){
//                    cout << dir[i] << " ";
//                }
//                cout << endl;
    return true;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<n; i++){
        if (abs(a[i]-a[i+1])>1){
            cout << 0 << endl;
            return;
        }
    }
    vector<char> dir(n+10, 'A');
    bool isDefine = false;
    for (int i=1; i<n; i++){
        if (a[i]!=a[i+1]){
            isDefine = true;
            if (a[i]>a[i+1]){
                dir[i] = dir[i+1] = 'R';
            }
            else{
                dir[i] = dir[i+1] = 'L';
            }

//                for (int i=1; i<=n; i++){
//                    cout << dir[i] << " ";
//                }
//                cout << endl;
            if (DefLeft(i,dir) && DefRight(i+1,dir)){
//                for (int i=1; i<=n; i++){
//                    cout << dir[i] << " ";
//                }
//                cout << endl;
                vector<int> pref(n+10, 0), suf(n+10, 0);
                for (int i=1; i<=n; i++){
                    pref[i] = pref[i-1];
                    if (dir[i] == 'L') ++pref[i];
                }
                for (int i=n; i>0; i--){
                    suf[i] = suf[i+1];
                    if (dir[i] == 'R') ++suf[i];
                }
//                for (int i=1; i<=n; i++){
//                    cout << pref[i] << " " << suf[i] << endl;
//                }
                for (int i=1; i<=n; i++){
                    if (a[i] != suf[i+1] + pref[i-1] + 1){
                        cout << 0 << endl;
                        return;
                    }
                }
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
            return;
        }
    }
    int lmao = (n-1);
    if ((n-1)%2 == 0){
        if (a[1] == (n-1)/2+1){
            cout << 2 << endl;
            return;
        }
    }
    else{
        if (a[1] == (n-1)/2+1 || a[1] == (n-1)/2+2){
            cout << 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
