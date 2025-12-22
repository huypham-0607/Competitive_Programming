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
int ans[maxn];
int a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    stack<pii> s;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        ans[i] = 0;
    }
    s.push({0,0});
    for (int i=1; i<=n+1; i++){
        while (!s.empty() && s.top().fi > a[i]){
            int j = s.top().se;
            int x = s.top().fi;
            s.pop();
            int l = i-s.top().se-1;
            ans[l] = max(ans[l],x);
//            cout << x << " " << l << " " << s.top().se << " " << j << " " << i << endl;
        }
        s.push({a[i],i});
    }
    for (int i=n; i>0; i--){
        ans[i] = max(ans[i],ans[i+1]);
    }
    for (int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
