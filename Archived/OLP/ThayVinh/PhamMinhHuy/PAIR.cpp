#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e5+10;
const int INF = 1e9-7;

int test;
int n,m;
vector<int> a,b;

bool check(int meow){
    int length = b.size();
    int bruh = a.size();
    int i = -1;
    int cnt = 0;
    for (auto u:a){
        do {
            ++i;
            if (i == length) break;
        } while (abs(b[i]-u) > meow);
        if (i == length) break;
//        cout << u << " " << b[i] << " " << i << endl;
        ++cnt;
    }
    if (cnt == bruh) return true;
    else return false;
}

int main(){
    freopen("Pair.inp","r",stdin);
    freopen("Pair.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i=1; i<=m; i++){
        int x;
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if (m < n)  swap(a,b);
//    for (auto i:a){
//        cout << i << " ";
//    }
//    cout << endl;
//    for (auto i:b){
//        cout << i << " ";
//    }
//    cout << endl;
    int ans = INF;
    int l = 0, r = INF;
    while (l<=r){
        int mid = (l+r)/2;
//        cout << "{" << mid << "}" << endl;
        if (check(mid)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << ans;
    return 0;
}
