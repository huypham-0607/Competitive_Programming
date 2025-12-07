/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
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
string s;
vector<int> lst,packman;

bool CheckSatisfy(int l, int r, int mid, int val){
    int lrange = mid - min(l,mid);
    int rrange = max(r,mid) - mid;
    int reqtime = min(lrange,rrange)*2 + max(lrange,rrange);
    if (reqtime > val) return false;
    else return true;
}

bool Check(int x){
    int idx = 0;
    for (int i=0; i<(int)packman.size(); i++){
        int l = lst[idx];
        int r = lst[idx];
        while (idx!=(int)lst.size() && CheckSatisfy(l,r,packman[i],x)){
            ++idx;
            r = lst[idx];
        }
    }
    if (idx == (int)lst.size()) return true;
    return false;
}

/*Solution*/
void solve(){
    cin >> n;
    cin >> s;
    for (int i=0; i<n; i++){
        if (s[i] == '*') lst.push_back(i);
        if (s[i] == 'P') packman.push_back(i);
    }

//    for (auto x:lst) cout << x << " ";
//    cout << endl;
//    for (auto x:packman) cout << x << " ";
//    cout << endl;

    int ans = INF;
    int l = 0, r = (int)4e5;
    while (l<=r){
        int mid = (l+r)/2;
//        cout << mid << endl;
        if (Check(mid)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
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
