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
int a[maxn],color[maxn],lvl[maxn];

int main(){
    freopen("art2.in","r",stdin);
    freopen("art2.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        ++color[a[i]];
    }
    int ans = 0;
    int cnt = 0;
    stack<int> s;
    for (int i=1; i<=n; i++){
//        cout << a[i] << " " << ((s.empty())? 0 : s.top()) << " " << lvl[a[i]] << endl;
        if (a[i] == 0){
            if (cnt){
                ans = -1;
                break;
            }
        }
        else{
            int x = a[i];
            if (!lvl[x]){
                lvl[x] = ++cnt;
                ans = max(ans,cnt);
                s.push(x);
//                cout << s.size() << endl;
//                cout << s.top() << endl;
            }
            if (s.empty() || x!=s.top()){
                ans = -1;
                break;
            }
            --color[x];
            if (!color[x]){
                s.pop();
                --cnt;
            }
        }
    }
    cout << ans;
    return 0;
}
