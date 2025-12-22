#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+15;
const int INF = 2e9;

int n,t;
int a[maxn],b[maxn],cnt[maxn];
bool ans[maxn];
deque<int> dq;

void solve(){
    memset(ans,false,n+10);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        cin >> b[i];
    }
    dq.clear();
    memset(cnt,0,sizeof(cnt));
    for (int i=1; i<=n; i++){
        while (!dq.empty() && dq.back() <= a[i]){
            --cnt[dq.back()];
            dq.pop_back();
        }
        dq.push_back(a[i]);
        cnt[a[i]]++;
        while (!dq.empty() && dq.front() > b[i]){
            --cnt[dq.front()];
            dq.pop_front();
        }
        if (cnt[b[i]]) ans[i] = true;
//        for (int i=1; i<=n; i++){
//            cout << cnt[i] << " ";
//        }
//        cout << endl;
    }
//    cout << endl;
    dq.clear();
//    for (int i=1; i<=n; i++){
//        cout << cnt[i] << " ";
//    }
//    cout << endl;
    memset(cnt,0,sizeof(cnt));
    for (int i=n; i>0; i--){
        while (!dq.empty() && dq.back() <= a[i]){
            --cnt[dq.back()];
            dq.pop_back();
        }
        dq.push_back(a[i]);
        cnt[a[i]]++;
        while (!dq.empty() && dq.front() > b[i]){
            --cnt[dq.front()];
            dq.pop_front();
        }
        if (cnt[b[i]]) ans[i] = true;
//        for (int i=1; i<=n; i++){
//            cout << cnt[i] << " ";
//        }
//        cout << endl;
    }
    int c=0;
    for (int i=1; i<=n; i++){
        if (ans[i]) ++c;
    }
    if (c == n) cout << "YES";
    else cout << "NO";
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        cout << ans[i] << " ";
//    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        solve();
        cout << "\n";
    }
    return 0;
}
