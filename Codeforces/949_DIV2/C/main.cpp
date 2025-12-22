/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
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
int a[N];

int MSB(int x){
    int ans = 0;
    while (x){
        ++ans;
        x/=2;
    }
    return ans;
}


bool rawr(int x, int y, int l, int r){
    int opt = r-l;
    int hx = MSB(x);
    int hy = MSB(y);
//    cout << x << " " << y << " " << l << " " << r << " " << hx << " " << hy << " " << opt << endl;
    bool swt = 0;
    if (hx < hy){
        swap(hx,hy);
        swap(x,y);
        swt = 1;
    }
    int res = 0;
    while (hx > hy){
        x = x/2;
        if (swt){
            --r;
            a[r] = x;
        }
        else{
            ++l;
            a[l] = x;
        }
        ++res;
        --hx;
        if (res > opt) return 0;
    }
    while (x!=y){
        x = x/2;
        y = y/2;

        if (swt){
            --r;
            a[r] = x;
            ++l;
            a[l] = y;
        }
        else{
            ++l;
            a[l] = x;
            --r;
            a[r] = y;
        }
        --hx;
        --hy;
        res+=2;
        if (res > opt) return 0;
    }
    if (res%2 != opt%2) return 0;
    else{
        int tmp = (swt)? y : x;
        while (l!=r){
            a[l+1] = tmp*2;
            a[l+2] = tmp;
            l+=2;
        }
    }
    return 1;
}

/*Solution*/
void solve(){
    cin >> n;
    int prev = -1;
    int l = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        if (a[i]!=-1){
        if (prev == -1){
            prev = a[i];
            l = i;
            for (int idx=1; i-idx>0; idx++){
                if (idx%2) a[i-idx] = prev*2;
                else a[i-idx] = prev;
            }
        }
        else{
            if (!rawr(prev,a[i],l,i)){
                cout << -1 << endl;
//                for (int i=1; i<=n; i++){
//                    cout << a[i] << " ";
//                }
//                cout << endl;
                return;
            }
            prev = a[i];
            l = i;
        }
        }
    }
    if (prev == -1){
        for (int i=1; i<=n; i++){
            if (i%2) a[i] = 1;
            else a[i] = 2;
        }
    }
    else{
    for (int idx=1; l+idx<=n; idx++){
        if (idx%2) a[l+idx] = prev*2;
        else a[l+idx] = prev;
    }
    }
    for (int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
