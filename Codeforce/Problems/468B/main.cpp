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
int n,a,b;
map<int,int> mp;
vector<int> v;
int ans[maxn],num[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        mp[x] = i;
        v.push_back(x);
    }
    int cnt = 0;
    num[0] = 0;
    num[1] = 1;
    if (b > a){
        swap(a,b);
        swap(num[0],num[1]);
    }
    sort(v.begin(),v.end());
    for (int i=n-1; i>=0; i--){
        int x = v[i];
        if (mp.find(x) == mp.end()) continue;
        else if(x < b && mp.find(b-x)!=mp.end()){
            ans[mp[x]] = num[1];
            mp.erase(x);
            ++cnt;
            if (x != b-x){
                ans[mp[b-x]] = num[1];
                mp.erase(b-x);
                ++cnt;
            }
        }
        else if (x < a && mp.find(a-x)!=mp.end()){
            ans[mp[x]] = num[0];
            mp.erase(x);
            ++cnt;
            if (x != a-x){
                ans[mp[a-x]] = num[0];
                mp.erase(a-x);
                ++cnt;
            }
        }
        else break;
    }
    if (cnt<n) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        for (int i=1; i<=n; i++){
            cout << ans[i] << " ";
        }
    }
//    cout << cnt << endl;
    return 0;
}
